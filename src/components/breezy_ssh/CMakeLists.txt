idf_component_register(
    SRCS
        "ssh_server.c"
        "cmd_sshd.c"
    INCLUDE_DIRS "include"
    # Default host key, embedded as a NUL-terminated string for libssh's
    # SSH_BIND_OPTIONS_IMPORT_KEY_STR.
    EMBED_TXTFILES "ssh_host_ed25519_key"
    # Leaf component: only the SSH transport (libssh), the VFS used to bridge
    # printf to the channel, and esp_netif (used by the sshd command's IP check).
    # Host integration is injected at runtime via breezy_ssh_host_t.
    PRIV_REQUIRES
        david-cermak__libssh
        vfs
        esp_netif
)
