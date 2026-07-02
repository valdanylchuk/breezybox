# Store the original PS1 before any modifications
ORIGINAL_PS1="$PS1"

# Function to update prompt with current IDF_TARGET
update_prompt() {
    # Create a custom PS1 without hostname, keeping username and working directory
    CUSTOM_PS1="\[\e]0;\u: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u\[\033[00m\]:\[\033[01;34m\]\W\[\033[00m\]\$ "
    PS1="(${IDF_TARGET:-missing-target})$CUSTOM_PS1"
}

# Set PROMPT_COMMAND to update prompt before each command
PROMPT_COMMAND="update_prompt"

# Function to set ESP32 target interactively
setchip() {
    local targets=(
        "esp32"
        "esp32s2"
        "esp32c3"
        "esp32s3"
        "esp32c2"
        "esp32c6"
        "esp32h2"
        "esp32p4"
        "esp32c5"
        "esp32c61"
    )
    
    while true; do
        echo "┌─────────────────────────────────────────────────────┐"
        echo "│                ESP32 Target Selection               │"
        echo "├─────────────────────────────────────────────────────┤"
        echo "│  1) esp32        │  6) esp32c6                      │"
        echo "│  2) esp32s2      │  7) esp32h2                      │"
        echo "│  3) esp32c3      │  8) esp32p4                      │"
        echo "│  4) esp32s3      │  9) esp32c5                      │"
        echo "│  5) esp32c2      │ 10) esp32c61                     │"
        echo "└─────────────────────────────────────────────────────┘"
        echo
        read -p "Select target (1-${#targets[@]}) or 'q' to quit: " choice
        
        # Check if user wants to quit
        if [[ "$choice" == "q" ]] || [[ "$choice" == "Q" ]]; then
            echo "Selection cancelled."
            return 0
        fi
        
        # Validate input
        if [[ ! "$choice" =~ ^[0-9]+$ ]] || [ "$choice" -lt 1 ] || [ "$choice" -gt "${#targets[@]}" ]; then
            echo "❌ Error: Invalid selection. Please choose a number between 1 and ${#targets[@]}, or 'q' to quit."
            echo
            continue
        fi
        
        # Set the target (array is 0-indexed, user input is 1-indexed)
        local selected_target="${targets[$((choice-1))]}"
        export IDF_TARGET="$selected_target"
        
        # Determine GDB path based on target
        local gdb_path
        if [ "$selected_target" = "esp32c3" ]; then
            gdb_path="/opt/esp/tools/riscv32-esp-elf-gdb/16.2_20250324/riscv32-esp-elf-gdb/bin/riscv32-esp-elf-gdb"
        else
            # For esp32 and esp32s3 (both use xtensa)
            gdb_path="/opt/esp/tools/xtensa-esp-elf-gdb/16.2_20250324/xtensa-esp-elf-gdb/bin/xtensa-esp32s3-elf-gdb"
        fi
        
        # Update VS Code workspace setting
        local settings_file="/workspaces/prod_esp32_playground/.vscode/settings.json"
        if [ -f "$settings_file" ]; then
            sed -i "s/\"idf.target\": \".*\"/\"idf.target\": \"$selected_target\"/" "$settings_file"
            sed -i "s|\"esp32.gdbPath\": \".*\"|\"esp32.gdbPath\": \"$gdb_path\"|" "$settings_file"
            
            # Add gdbPath if it doesn't exist
            if ! grep -q "esp32.gdbPath" "$settings_file"; then
                sed -i "s/\"idf.target\": \".*\"/&,\n    \"esp32.gdbPath\": \"$gdb_path\"/" "$settings_file"
            fi
        fi
        
        echo "✅ IDF_TARGET set to: $IDF_TARGET"
        echo ""
        
        # Update the prompt to reflect the new target
        update_prompt
        break
    done
    
    # Update the prompt to reflect the new target
    update_prompt
}

# Function to set active debug project
debugthis() {
    # 1. Check if CMakeLists.txt exists in current directory
    if [ ! -f "CMakeLists.txt" ]; then
        echo "❌ Error: No CMakeLists.txt found in current directory"
        return 1
    fi
    
    # 2. Extract project name from project(...) line
    local project_name=$(grep -oP '^\s*project\(\s*\K[^)]+' CMakeLists.txt | head -1)
    if [ -z "$project_name" ]; then
        echo "❌ Error: Could not find project() in CMakeLists.txt"
        return 1
    fi
    
    # 3. Get relative path from workspace root
    local workspace_root="/workspaces/prod_esp32_playground"
    local current_dir=$(pwd)
    local relative_path="${current_dir#$workspace_root/}"
    
    # 4. Validate we're in the workspace
    if [ "$relative_path" = "$current_dir" ]; then
        echo "❌ Error: Not in workspace directory"
        return 1
    fi
    
    # 5. Determine GDB path based on target
    local gdb_path
    if [ "${IDF_TARGET}" = "esp32c3" ]; then
        gdb_path="/opt/esp/tools/riscv32-esp-elf-gdb/16.2_20250324/riscv32-esp-elf-gdb/bin/riscv32-esp-elf-gdb"
    else
        # For esp32 and esp32s3 (both use xtensa)
        gdb_path="/opt/esp/tools/xtensa-esp-elf-gdb/16.2_20250324/xtensa-esp-elf-gdb/bin/xtensa-esp32s3-elf-gdb"
    fi
    
    # 6. Update VS Code settings
    local settings_file="$workspace_root/.vscode/settings.json"
    
    # Create settings file if it doesn't exist
    if [ ! -f "$settings_file" ]; then
        mkdir -p "$workspace_root/.vscode"
        cat > "$settings_file" << EOF
{
    "idf.target": "${IDF_TARGET:-esp32s3}",
    "esp32.activeProject": "$relative_path",
    "esp32.activeProjectName": "$project_name",
    "esp32.gdbPath": "$gdb_path"
}
EOF
        echo "✅ Created settings file and set debug target to: $project_name ($relative_path)"
        return 0
    fi
    
    # Use | as delimiter for sed since path contains /
    sed -i "s|\"esp32.activeProject\": \".*\"|\"esp32.activeProject\": \"$relative_path\"|" "$settings_file"
    sed -i "s/\"esp32.activeProjectName\": \".*\"/\"esp32.activeProjectName\": \"$project_name\"/" "$settings_file"
    sed -i "s|\"esp32.gdbPath\": \".*\"|\"esp32.gdbPath\": \"$gdb_path\"|" "$settings_file"
    
    # Add gdbPath if it doesn't exist
    if ! grep -q "esp32.gdbPath" "$settings_file"; then
        sed -i "s|\"esp32.activeProjectName\": \".*\"|&,\n    \"esp32.gdbPath\": \"$gdb_path\"|" "$settings_file"
    fi
    
    echo "✅ Debug target set to: $project_name ($relative_path)"
    echo ""
}

# Function to create a new ESP32 project from minimal_build template
np() {
    local workspace_root="/workspaces/prod_esp32_playground"
    local examples_dir="$workspace_root/examples"
    local template_dir="$examples_dir/minimal_build"
    
    # Prompt for project name
    read -p "Enter new project name: " project_name
    
    # Validate project name is not empty
    if [ -z "$project_name" ]; then
        echo "❌ Error: Project name cannot be empty"
        return 1
    fi
    
    # Create new project directory path
    local new_project_dir="$examples_dir/$project_name"
    
    # Check if directory already exists
    if [ -d "$new_project_dir" ]; then
        echo "❌ Error: Project directory already exists: $new_project_dir"
        return 1
    fi
    
    # Copy minimal_build to new project directory
    echo "📁 Creating new project from minimal_build template..."
    cp -r "$template_dir" "$new_project_dir"
    
    if [ $? -ne 0 ]; then
        echo "❌ Error: Failed to copy template"
        return 1
    fi
    
    # Remove the build folder if it exists
    if [ -d "$new_project_dir/build" ]; then
        rm -rf "$new_project_dir/build"
    fi
    
    # Update README.md with just the project name as H1
    echo "# $project_name" > "$new_project_dir/README.md"
    
    # Update CMakeLists.txt to use new project name
    sed -i "s/project(minimal_build)/project($project_name)/" "$new_project_dir/CMakeLists.txt"

    # Update main.cpp to reflect new project name
    sed -i "s/Hello, Minimal Build!/Hello, $project_name/" "$new_project_dir/main/main.cpp"
    
    echo "✅ Project '$project_name' created successfully at: $new_project_dir"
    echo ""
    
    # Change to the new project directory
    cd "$new_project_dir"
    
    # Configure debugger to point to this new project
    debugthis
}