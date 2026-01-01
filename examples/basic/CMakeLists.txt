# BreezyBox Basic Example
cmake_minimum_required(VERSION 3.16)

# Include component from parent directory (for development)
# When installed via component registry, this is not needed
set(EXTRA_COMPONENT_DIRS "../..")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(breezybox_basic_example)