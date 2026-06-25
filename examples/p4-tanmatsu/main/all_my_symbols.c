// Generated using:
//   python managed_components/espressif__elf_loader/tool/symbols.py -i build/esp32dos.elf -t e
// Should stay in:
//   managed_components/espressif__elf_loader/src/esp_all_symbol.c
// Copied here just for reference
/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stddef.h>

#include "private/elf_symbol.h"

/* Extern declarations from ELF symbol table */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wbuiltin-declaration-mismatch"
extern int bt_keyboard_is_pressed;
extern int bt_keyboard_get_modifiers;
extern int bt_keyboard_connected;
extern int hmac_hal_clean;
extern int pmu_sleep_enable_regdma_backup;
extern int heap_caps_realloc;
extern int esp_event_handler_register_with;
extern int es8156_write_analog_system_4;
extern int mspi_timing_psram_config_clear_tuning_regs;
extern int __multadd;
extern int pthread_detach;
extern int rpc__req__iface_mac_addr_set_get__descriptor;
extern int printf;
extern int heap_caps_calloc;
extern int regdma_link_new_branch_wait;
extern int i2c_hal_master_set_scl_timeout_val;
extern int cs_send_to_ctrl_sock;
extern int netconn_prepare_delete;
extern int es8156_write_analog_system_6;
extern int pxPortInitialiseStack;
extern int pmu_hp_system_power_param_default;
extern int mbedtls_cipher_base_lookup_table;
extern int rpc__gpio_mode__descriptor;
extern int mbedtls_cipher_set_padding_mode;
extern int rpc__resp__wifi_get_country_code__init;
extern int mld6_stop;
extern int memspi_host_read_id_hs;
extern int wifi_active_scan_time__init;
extern int mbedtls_sha512_update;
extern int rpc__req__gpio_set_level__descriptor;
extern int sleep_retention_module_init;
extern int rpc__resp__wifi_scan_start__init;
extern int rpc__req__eap_set_password__descriptor;
extern int mbedtls_ecdsa_read_signature;
extern int sdmmc_send_cmd_send_cid;
extern int rpc__resp__wifi_set_inactive_time__descriptor;
extern int dma2d_hal_tx_reset_channel;
extern int esp_psram_chip_init;
extern int rtc_spinlock;
extern int gdma_axi_hal_enable_etm_task;
extern int _ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_;
extern int exit;
extern int crc32_z;
extern int esp_time_impl_set_boot_time;
extern int mbedtls_ssl_session_free;
extern int __cxa_guard_dummy;
extern int xPortEnterCriticalTimeout;
extern int esp_mspi_pin_reserve;
extern int spi_flash_hal_supports_direct_write;
extern int sys_mutex_new;
extern int sleep_retention_get_inited_modules;
extern int __ratio;
extern int mbedtls_ecp_tls_write_point;
extern int lwip_inet_pton;
extern int cmd_sh;
extern int lwip_getsockopt;
extern int esp_netif_action_start;
extern int xTimerCreateTimerTask;
extern int wifi_event_sta_connected__descriptor;
extern int esp_vfs_opendir;
extern int esp_vfs_fstat;
extern int sdmmc_send_cmd_send_scr;
extern int rpc__req__wifi_deinit__descriptor;
extern int gdma_hal_connect_peri;
extern int sys_sem_signal_isr;
extern int pvalloc;
extern int sha_hal_wait_idle;
extern int esp_aes_crypt_xts;
extern int igmp_leavegroup_netif;
extern int wifi_scan_config__init;
extern int esp_md5_update;
extern int esp_vfs_open;
extern int mbedtls_oid_get_ec_grp;
extern int esp_netif_stop;
extern int dhcps_delete;
extern int mbedtls_ssl_get_verify_result;
extern int mbedtls_cipher_update;
extern int vterm_send_input;
extern int mbedtls_pk_get_bitlen;
extern int esp_intr_ptr_in_isr_region;
extern int mbedtls_ssl_set_hostname;
extern int spi_flash_chip_winbond_erase_sector;
extern int tcp_recv_null;
extern int vApplicationGetTimerTaskMemory;
extern int mbedtls_aria_setkey_dec;
extern int gpio_hal_intr_disable;
extern int vPortTaskPinToCore;
extern int xQueueGenericCreateStatic;
extern int sdmmc_host_init_slot;
extern int vListInitialiseItem;
extern int mbedtls_x509_get_alg;
extern int __atomic_fetch_or_8;
extern int mbedtls_md_hmac_starts;
extern int hmac_hal_configure;
extern int spi_flash_chip_generic_get_write_protect;
extern int rewind;
extern int i2c_master_transmit;
extern int raw_recv;
extern int realloc;
extern int esp_transport_tcp_init;
extern int mbedtls_ssl_ciphersuite_uses_ec;
extern int rpc__req__eap_clear_identity__descriptor;
extern int g_exc_frames;
extern int rpc__resp__wifi_set_country_code__descriptor;
extern int valid_key_length;
extern int rpc__req__wifi_scan_params__descriptor;
extern int mbedtls_pk_verify_ext;
extern int sdmmc_send_cmd_switch_func;
extern int cs_create_ctrl_sock;
extern int rpc__req__otaend__descriptor;
extern int _getpid_r;
extern int pbuf_realloc;
extern int netconn_shutdown;
extern int bsp_internal_coprocessor_faults_callback;
extern int gzclose;
extern int rpc_init;
extern int esp_aes_crypt_cbc;
extern int spi_flash_chip_generic_wait_idle;
extern int mbedtls_x509_get_sig;
extern int _ZN3nvs4Page12setSeqNumberEm;
extern int dma2d_hal_init;
extern int my_display_refresh_palette;
extern int gdma_axi_hal_get_crc_result;
extern int esp_sha_block;
extern int rpc__resp__set_dhcp_dns_status__init;
extern int esp_netif_attach;
extern int mbedtls_x509_crt_free;
extern int rpc__resp__supp_dpp_init__descriptor;
extern int bsp_display_get_parameters;
extern int i2c_release_bus_handle;
extern int strerror_l;
extern int _ZN3nvs15NVSHandleSimpleD2Ev;
extern int esprv_int_set_type;
extern int arg_dstr_catc;
extern int sha_hal_sha512_init_hash;
extern int mmu_hal_get_id_from_target;
extern int _ZN3nvs4Page15mLoadEntryTableEv;
extern int check_if_max_freq_used;
extern int mld6_leavegroup_netif;
extern int es8156_write_analog_system_2;
extern int lfs_dir_read;
extern int create_debugging_tasks;
extern int mbedtls_pem_free;
extern int mbedtls_sha512_finish;
extern int esp_crypto_mpi_enable_periph_clk;
extern int g_hosted_osi_funcs;
extern int esp_time_impl_get_boot_time;
extern int rpc__req__supp_dpp_stop_listen__init;
extern int rtc_dig_clk8m_enable;
extern int rpc__resp__wifi_sta_get_ap_info__init;
extern int g_panic_abort;
extern int memmove;
extern int gpio_set_intr_type;
extern int rtc_clk_cpu_freq_set_config;
extern int mbedtls_oid_get_pkcs12_pbe_alg;
extern int rtc_gpio_init;
extern int hosted_unlock_mempool;
extern int esp_timer_impl_get_min_period_us;
extern int pbuf_chain;
extern int rpc_wifi_sta_get_ap_info;
extern int esp_clk_tree_lp_slow_get_freq_hz;
extern int ip4_route_src;
extern int esp_aes_crypt_ofb;
extern int rpc__resp__set_mac_address__init;
extern int gdma_del_link_list;
extern int mbedtls_gcm_update_soft;
extern int capture_tcp_transport_error;
extern int mbedtls_ssl_send_alert_message;
extern int udp_bind_netif;
extern int bmi2_set_i2c_configuration;
extern int fgetc;
extern int bsp_device_initialize_custom;
extern int esp_netif_get_desc;
extern int hosted_for_loop_delay;
extern int esp_libc_init;
extern int memp_FRAG_PBUF;
extern int __wrap_rewinddir;
extern int httpd_req_handle_err;
extern int regdma_find_module_link_tail;
extern int rpc__resp__wifi_sta_get_rssi__descriptor;
extern int wifi_ap_record__descriptor;
extern int heap_caps_free;
extern int console_fcntl;
extern int esp_fill_random;
extern int esp_flash_encryption_enabled;
extern int sha_hal_hash_block;
extern int esp_task_wdt_init;
extern int mbedtls_ssl_setup;
extern int rpc__resp__wifi_scan_get_ap_record__descriptor;
extern int mpi_hal_enable_search;
extern int labs;
extern int lwip_getsockname;
extern int xTaskResumeAll;
extern int rpc__resp__wifi_restore__init;
extern int tcp_send_empty_ack;
extern int etharp_output;
extern int esp_aes_gcm_init;
extern int nvs_flash_erase;
extern int esp_flash_app_init;
extern int esp_wifi_remote_scan_get_ap_num;
extern int get_vfs_for_index;
extern int registered_heaps;
extern int rmdir;
extern int rpc__resp__wifi_set_country_code__init;
extern int xTaskCreatePinnedToCoreWithCaps;
extern int _ZN10__cxxabiv119__terminate_handlerE;
extern int rpc__req__wifi_sta_get_rssi__init;
extern int fabsf;
extern int esp_md5_clone;
extern int nvs_sec_provider_include_impl;
extern int igmp_input;
extern int localeconv;
extern int mbedtls_asn1_write_tag;
extern int http_should_keep_alive;
extern int default_router_list;
extern int es8156_write_mode_config;
extern int rpc__event__wifi_dpp_fail__init;
extern int esp_libc_include_init_funcs;
extern int sdmmc_io_enable_int;
extern int sys_timeouts_init;
extern int _kill_r;
extern int hosted_post_semaphore;
extern int pmu_lp_system_init;
extern int tzset;
extern int esp_system_include_startup_funcs;
extern int mbedtls_rsa_pkcs1_verify;
extern int rpc__resp__wifi_get_protocol__init;
extern int setlocale;
extern int esp_lcd_dpi_panel_register_event_callbacks;
extern int arg_parse;
extern int ip6_frag;
extern int vListInsert;
extern int ip4_route_src_hook;
extern int esp_tls_internal_event_tracker_destroy;
extern int i2c_new_master_bus;
extern int esp_aes_gcm_update_ad;
extern int rgb_display_refresh_palette;
extern int mbedtls_ssl_conf_renegotiation;
extern int mbedtls_entropy_init;
extern int esp_crypto_ds_lock_release;
extern int is_event_callback_registered;
extern int esp_set_time_from_rtc;
extern int esp_mpi_mult_mpi_failover_mod_mult_hw_op;
extern int netif_get_by_index;
extern int vterm_set_palette;
extern int __sprint_r;
extern int s_register_config_driver;
extern int dw_gdma_channel_enable_ctrl;
extern int esp_vfs_register_fd_range;
extern int sdmmc_init_sd_if_cond;
extern int rpc__resp__gpio_reset_pin__init;
extern int vterm_switch;
extern int rpc__req__wifi_set_protocols__descriptor;
extern int igmp_lookfor_group;
extern int mbedtls_mpi_copy;
extern int rpc__resp__wifi_set_storage__descriptor;
extern int rpc__resp__wifi_sta_enterprise_enable__descriptor;
extern int mbedtls_ecdh_make_public;
extern int strcspn;
extern int netif_set_down;
extern int rpc__req__gpio_set_direction__init;
extern int ds_hal_write_message;
extern int esp_mspi_pin_init;
extern int mbedtls_ccm_starts;
extern int rpc__event__mem_monitor__init;
extern int rpc_slaveif_wifi_get_mac;
extern int xTaskGenericNotifyWait;
extern int spi_flash_chip_generic_detect_size;
extern int esp_intr_disable;
extern int es8156_write_time_control_1;
extern int mbedtls_mpi_is_prime_ext;
extern int pbuf_take;
extern int gpio_reset_pin;
extern int esp_transport_list_destroy;
extern int esp_transport_ssl_set_client_cert_data;
extern int strstr;
extern int breezybox_exec_init;
extern int nan;
extern int clock_gettime;
extern int vApplicationGetIdleTaskMemory;
extern int rpc__req__set_mode__init;
extern int bsp_input_initialize;
extern int sleep_clock_system_retention_init;
extern int mbedtls_ssl_ciphersuite_from_id;
extern int mbedtls_entropy_free;
extern int i2s_hal_init;
extern int get_vfs_for_path;
extern int rpc__req__wifi_sta_enterprise_enable__init;
extern int gdma_axi_hal_get_eof_desc_addr;
extern int gdma_config_transfer;
extern int es8156_write_register_page;
extern int rpc__resp__wifi_restore__descriptor;
extern int mmu_hal_vaddr_to_paddr;
extern int xRingbufferSendFromISR;
extern int _ZN3nvs4Page15alterEntryStateEjNS0_10EntryStateE;
extern int rpc__req__eap_set_ttls_phase2_method__init;
extern int dhcp_coarse_tmr;
extern int mbedtls_ecp_muladd_restartable;
extern int wifi_config__descriptor;
extern int esp_transport_ssl_set_addr_family;
extern int fread;
extern int rpc__resp__get_dhcp_dns_status__init;
extern int netif_init;
extern int pmu_sleep_disable_regdma_backup;
extern int spi_flash_common_write_status_16b_wrsr;
extern int rpc__req__wifi_ap_get_sta_aid__descriptor;
extern int rpc__event__sta_itwt_setup__init;
extern int vRingbufferDelete;
extern int esp_transport_ssl_set_interface_name;
extern int __mprec_tinytens;
extern int rpc__resp__wifi_set_bandwidths__descriptor;
extern int _ZdlPv;
extern int mbedtls_ecdsa_write_signature;
extern int esp_lcd_new_panel_dpi;
extern int sinf;
extern int esp_vfs_register;
extern int spi_flash_hal_suspend;
extern int rpc__resp__wifi_disconnect__init;
extern int tcp_pcb_lists;
extern int sdmmc_init_sd_uhs1;
extern int netif_get_ip6_addr_match;
extern int raw_bind;
extern int mbedtls_ssl_list_ciphersuites;
extern int esp_partition_read_raw;
extern int gpio_od_enable;
extern int mem_malloc;
extern int esp_libc_init_global_stdio;
extern int tcp_bind_netif;
extern int wifi_scan_threshold__descriptor;
extern int _ZNK3nvs15NVSHandleSimple18get_partition_nameEv;
extern int wifi_country__descriptor;
extern int rpc__req__wifi_restore__init;
extern int __atexit_recursive_mutex;
extern int g_i2s;
extern int netif_set_addr;
extern int esp_dma_calculate_node_count;
extern int _ZN3nvs7StorageD2Ev;
extern int mbedtls_mpi_core_bigendian_to_host;
extern int rpc__req__wifi_deinit__init;
extern int mbedtls_mpi_fill_random;
extern int rpc__event__wifi_event_no_args__descriptor;
extern int esp_wifi_remote_sta_get_ap_info;
extern int tanmatsu_coprocessor_get_radio_state;
extern int memspi_host_flush_cache;
extern int mbedtls_gcm_starts_soft;
extern int aes_hal_gcm_read_tag;
extern int pbuf_copy_partial_pbuf;
extern int _ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE;
extern int spi_flash_disable_interrupts_caches_and_other_cpu;
extern int cJSON_GetObjectItem;
extern int esp_transport_poll_write;
extern int esp_hw_stack_guard_get_bounds;
extern int sdmmc_init_sd_wait_data_ready;
extern int esp_tls_plain_tcp_connect;
extern int rpc__resp__supp_dpp_stop_listen__descriptor;
extern int _calloc_r;
extern int compose_rpc_req;
extern int esp_psram_is_initialized;
extern int gdma_axi_hal_init;
extern int linenoiseInsertPastedChar;
extern int heap_caps_check_add_region_allowed;
extern int argtable3_xfree;
extern int esp_ecc_point_multiply;
extern int esp_pm_lock_delete;
extern int sdmmc_host_set_cclk_always_on;
extern int pthread_attr_setstacksize;
extern int gdma_ahb_hal_get_eof_desc_addr;
extern int xQueueCreateMutex;
extern int esp_ptr_external_ram;
extern int rpc__pack;
extern int rpc__req__wifi_scan_get_ap_records__descriptor;
extern int mbedtls_md;
extern int clock;
extern int mbedtls_ccm_update;
extern int sdmmc_io_wait_int;
extern int _free_r;
extern int console_fsync;
extern int xQueueIsQueueFullFromISR;
extern int __retarget_lock_release;
extern int strtoull;
extern int mbedtls_sha1_init;
extern int _ZN3nvs8HashList5clearEv;
extern int fgets;
extern int mipi_dsi_hal_host_dpi_calculate_divider;
extern int efuse_hal_get_major_chip_version;
extern int __wrap_mkdir;
extern int mbedtls_mpi_cmp_mpi;
extern int rpc__resp__eap_set_identity__init;
extern int systimer_ticks_to_us;
extern int rpc__req__get_ps__descriptor;
extern int set_transport_state;
extern int esp_cache_err_get_panic_info;
extern int _ZN3nvs11PageManager12activatePageEv;
extern int rpc__req__eap_clear_certificate_and_key__init;
extern int esp_sha_acquire_hardware;
extern int arg_str0;
extern int rpc__req__otaactivate__init;
extern int _lock_acquire;
extern int mbedtls_gcm_setkey_soft;
extern int inflate;
extern int rpc__req__wifi_set_band__descriptor;
extern int bsp_power_set_radio_state;
extern int close;
extern int gpio_config;
extern int feof;
extern int sdmmc_decode_scr;
extern int regdma_link_new_continuous_default;
extern int _ZN3nvs15NVSHandleSimple8set_blobEPKcPKvj;
extern int ecc_hal_write_verify_param;
extern int mbedtls_ccm_set_lengths;
extern int i2c_acquire_bus_handle;
extern int rpc__resp__custom_rpc__init;
extern int gdma_axi_hal_set_crc_poly;
extern int gdma_hal_read_intr_status;
extern int mld6_input;
extern int gpio_func_sel;
extern int g_startup_time;
extern int _ZN3nvs7Storage15getItemDataSizeEhNS_8ItemTypeEPKcRj;
extern int esp_psram_impl_get_available_size;
extern int sdmmc_io_enable_hs_mode;
extern int tlsf_create;
extern int __kernel_cosf;
extern int sdmmc_host_check_buffer_alignment;
extern int intr_handler_set;
extern int sdmmc_decode_ssr;
extern int nd6_find_route;
extern int rpc__req__eap_clear_new_password__init;
extern int scalbnf;
extern int hosted_usleep;
extern int sys_arch_sem_wait;
extern int esp_flash_chip_winbond;
extern int mbedtls_ssl_handle_pending_alert;
extern int rpc__req__set_ps__descriptor;
extern int __action_table;
extern int arg_print_syntax_ds;
extern int rpc__resp__wifi_scan_start__descriptor;
extern int gdma_new_ahb_channel;
extern int __ssvfiscanf_r;
extern int strchr;
extern int mbedtls_ecdsa_can_do;
extern int cache_error_msg;
extern int hosted_timer_start;
extern int esp_vfs_rewinddir;
extern int spi_flash_mmap;
extern int ip4addr_ntoa;
extern int rpc__req__wifi_scan_params__init;
extern int rpc__req__wifi_set_okc_support__init;
extern int httpd_sess_new;
extern int ipaddr_addr;
extern int bootloader_flash_reset_chip;
extern int esp_config_l2_cache_mode;
extern int sdmmc_send_cmd;
extern int transport_drv_serial_tx;
extern int rpc__req__iface_mac_addr_len_get__init;
extern int xQueueCreateCountingSemaphoreStatic;
extern int netif_list;
extern int __match;
extern int mbedtls_ecp_gen_privkey;
extern int regdma_link_get_owner_bitmap;
extern int http_auth_basic;
extern int esp_isr_names;
extern int wifi_active_scan_time__descriptor;
extern int sdmmc_select_driver_strength;
extern int _ZN17__eh_globals_init7_S_initE;
extern int cmd_tail;
extern int lfs_mkdir;
extern int tcp_netif_ip_addr_changed;
extern int httpd_sess_close_all;
extern int mbedtls_asn1_write_mpi;
extern int xTaskGetCurrentTaskHandle;
extern int set_event_callback;
extern int esp_log_default_level;
extern int esp_netif_init;
extern int rpc__resp__get_ps__descriptor;
extern int sdmmc_host_get_clk_dividers;
extern int _ZN10__cxxabiv117__class_type_infoD0Ev;
extern int _panic_handler;
extern int memp_TCP_PCB_LISTEN;
extern int spi_flash_hal_resume;
extern int mspi_timing_flash_config_clear_tuning_regs;
extern int esp_flash_chip_generic;
extern int esp_mbedtls_read;
extern int httpd_recv;
extern int spi_flash_chip_generic_probe;
extern int sdmmc_send_cmd_all_send_cid;
extern int __chclass;
extern int esp_transport_ssl_set_cert_data;
extern int rpc__req__eap_set_password__init;
extern int aes_hal_transform_dma_finish;
extern int httpd_sess_get;
extern int gzclose_r;
extern int lwip_netconn_do_listen;
extern int vQueueDelete;
extern int esp_partition_next;
extern int httpd_sess_close_lru;
extern int calloc;
extern int spi_flash_chip_generic_timeout;
extern int httpd_stop;
extern int mbedtls_pkcs12_pbe_ext;
extern int esp_psram_check_ptr_addr;
extern int _ZN3nvs4Page8findItemEhNS_8ItemTypeEPKcRjRNS_4ItemEhNS_9VerOffsetE;
extern int nvs_set_str;
extern int mbedtls_x509_crt_profile_default;
extern int esp_netif_action_got_ip;
extern int rpc__req__wifi_deauth_sta__descriptor;
extern int memspi_host_erase_chip;
extern int _ZN3nvs4Page20updateFirstUsedEntryEjj;
extern int panic_soc_check_pseudo_cause;
extern int esp_vfs_register_fs;
extern int rpc__event__supp_dpp_cfg_recvd__init;
extern int hosted_memset;
extern int mbedtls_cipher_init;
extern int __sfp_lock_release;
extern int mbedtls_mpi_core_bitlen;
extern int s_head;
extern int esp_event_loop_create_default;
extern int mbedtls_cipher_crypt;
extern int sleep_retention_get_created_modules;
extern int esp_elf_deinit;
extern int ip_addr_any_type;
extern int icmp6_input;
extern int rpc__req__wifi_scan_get_ap_record__descriptor;
extern int tcp_active_pcbs_changed;
extern int cache_hal_invalidate_addr;
extern int xQueueGenericSendFromISR;
extern int esp_clk_cpu_freq;
extern int strncmp;
extern int heap_caps_get_largest_free_block;
extern int nd6_input;
extern int esp_mmu_map_get_max_consecutive_free_block_size;
extern int ldexp;
extern int esp_partition_write_raw;
extern int mbedtls_sha256;
extern int esp_aes_crypt_cfb128;
extern int xRingbufferGetCurFreeSize;
extern int rpc__resp__eap_set_pac_file__init;
extern int memp_TCP_PCB;
extern int rpc__resp__wifi_set_inactive_time__init;
extern int atexit;
extern int rpc_core_deinit;
extern int gz_error;
extern int i2s_output_gpio_revoke;
extern int pbuf_copy;
extern int gdma_hal_disconnect_peri;
extern int i2c_bus_occupied;
extern int sdmmc_io_init_check_card_cap;
extern int rpc__req__set_mac_address__descriptor;
extern int httpd_start;
extern int __wrap_fopen;
extern int rpc__resp__iface_mac_addr_set_get__init;
extern int esp_transport_ssl_enable_global_ca_store;
extern int esp_psram_extram_add_to_heap_allocator;
extern int xTaskCreatePinnedToCore;
extern int rpc__resp__eap_set_password__init;
extern int esp_transport_capture_errno;
extern int aes_hal_set_iv;
extern int dw_gdma_channel_register_event_callbacks;
extern int wifi_twt_config__descriptor;
extern int _rename_r;
extern int lwip_netconn_do_bind;
extern int rpc__resp__wifi_sta_itwt_set_target_wake_time_offset__descriptor;
extern int tcp_shutdown;
extern int mbedtls_mpi_add_mpi;
extern int mbedtls_ccm_free;
extern int esp_crosscore_int_send_yield;
extern int multi_heap_get_info;
extern int regi2c_exit_critical;
extern int _fclose_r;
extern int mbedtls_md_get_size;
extern int netif_remove;
extern int mbedtls_ssl_conf_own_cert;
extern int rpc__req__wifi_sta_itwt_get_flow_id_status__init;
extern int rpc__req__eap_set_domain_name__init;
extern int fputc;
extern int _ZN3nvs15NVSHandleSimple10set_stringEPKcS2_;
extern int gdma_hal_get_data_mask_from_matrix;
extern int tlsf_malloc;
extern int rpc__req__wifi_set_config__descriptor;
extern int sdmmc_host_dma_resume;
extern int __cxa_end_catch;
extern int bsp_audio_initialize;
extern int esp_http_client_close;
extern int rtc_clk_fast_src_set;
extern int strrchr;
extern int _ZN3nvs4Page20alterEntryRangeStateEjjNS0_10EntryStateE;
extern int esp_crypto_sha_aes_lock_acquire;
extern int tcp_tmr;
extern int regdma_link_new_continuous;
extern int rpc__req__eap_clear_identity__init;
extern int rom_flash_chip_dummy_hpm;
extern int mbedtls_sha512_free;
extern int ecc_hal_set_mode;
extern int rpc__resp__config_heartbeat__descriptor;
extern int stat;
extern int mbedtls_ssl_start_handshake_msg;
extern int arg_intn;
extern int _vprintf_r;
extern int rpc__req__wifi_get_protocols__init;
extern int esp_ipc_isr_port_init;
extern int gdma_get_group_channel_id;
extern int my_console_init;
extern int rpc__req__wifi_sta_itwt_send_probe_req__descriptor;
extern int esp_transport_read;
extern int mbedtls_ssl_prepare_handshake_record;
extern int cmd_rm;
extern int __pow5mult;
extern int _ZNKSt9type_info14__is_pointer_pEv;
extern int gdma_ahb_hal_init;
extern int gpio_pullup_dis;
extern int rpc__resp__wifi_sta_itwt_get_flow_id_status__descriptor;
extern int vterm_getchar;
extern int dhcp_stop;
extern int ethernet_input;
extern int scalbn;
extern int spi_flash_common_read_status_8b_rdsr2;
extern int tanmatsu_lcd_set_buffer;
extern int rpc__req__eap_set_pac_file__init;
extern int transport_pserial_close;
extern int __lo0bits;
extern int esp_crypto_aes_enable_periph_clk;
extern int netif_loop_output;
extern int rpc__req__supp_dpp_start_listen__init;
extern int dma2d_acquire_pool;
extern int valloc;
extern int mbedtls_oid_get_x509_ext_type;
extern int breezybox_vfs_init;
extern int crc32;
extern int esp_async_fbcpy;
extern int _findenv;
extern int vQueueWaitForMessageRestricted;
extern int mbedtls_ssl_set_bio;
extern int rpc__resp__wifi_sta_get_ap_info__descriptor;
extern int rpc__event__sta_itwt_setup__descriptor;
extern int dhcps_pbuf_alloc;
extern int multi_heap_set_lock;
extern int netconn_recv_udp_raw_netbuf_flags;
extern int rpc__resp__wifi_deauth_sta__descriptor;
extern int tcp_accept;
extern int esp_libc_include_getentropy_impl;
extern int spi_flash_enable_high_performance_mode;
extern int netconn_alloc;
extern int periph_rtc_mpll_acquire;
extern int esp_hosted_add_channel;
extern int gdma_default_rx_isr;
extern int es8156_write_reset_control;
extern int sdmmc_init_io;
extern int rpc__req__wifi_get_country__init;
extern int rpc__resp__supp_dpp_bootstrap_gen__descriptor;
extern int mbedtls_zeroize_and_free;
extern int _printf_r;
extern int sdmmc_init_host_bus_width;
extern int esp_console_run;
extern int sys_check_timeouts;
extern int esp_crypto_shared_gdma_start_axi_ahb;
extern int http_header_clean;
extern int mbedtls_ecdsa_write_signature_restartable;
extern int rpc__resp__mem_monitor__init;
extern int mbedtls_ssl_optimize_checksum;
extern int mbedtls_mpi_core_get_mont_r2_unsafe;
extern int rpc__resp__wifi_get_protocols__init;
extern int esp_timer_impl_set_alarm_id;
extern int strerror;
extern int esp_hosted_init;
extern int lwip_netconn_do_connect;
extern int regi2c_enter_critical;
extern int free;
extern int lwip_setsockopt;
extern int s_active_vt;
extern int _vfiprintf_r;
extern int littlefs_esp_part_write;
extern int __ieee754_fmodf;
extern int esp_crypto_hmac_lock_release;
extern int rpc__resp__wifi_deinit__init;
extern int elf_get_cycle_count;
extern int tcpip_send_msg_wait_sem;
extern int rpc__resp__wifi_start__init;
extern int rpc__event__custom_rpc__descriptor;
extern int xSemaphoreCreateGenericWithCaps;
extern int _ZSt15get_new_handlerv;
extern int esp_netif_next_unsafe;
extern int regdma_link_new_wait_default;
extern int _ZN3nvs15NVSHandleSimple14set_typed_itemENS_8ItemTypeEPKcPKvj;
extern int i2c_master_bus_rm_device;
extern int rpc__req__wifi_sta_get_aid__descriptor;
extern int esp_sync_timekeeping_timers;
extern int my_console_set_output_mode;
extern int esp_hosted_tx;
extern int rpc_wifi_get_mac;
extern int mspi_timing_get_psram_tuning_delaylines;
extern int rpc_slaveif_wifi_scan_get_ap_num;
extern int __swhatbuf_r;
extern int bmi2_i2c_read;
extern int esp_flash_app_enable_os_functions;
extern int mbedtls_mpi_sub_int;
extern int sha_hal_read_digest;
extern int esp_crypto_ecc_lock_release;
extern int _fdopen_r;
extern int gpio_hal_hysteresis_soft_enable;
extern int vterm_get_size;
extern int mem_free;
extern int tcpip_inpkt;
extern int esp_wifi_remote_disconnect;
extern int gpio_set_drive_capability;
extern int mbedtls_pk_sign;
extern int breezybox_set_cwd;
extern int cJSON_ParseWithOpts;
extern int esp_netif_create_default_wifi_sta;
extern int tcp_connect;
extern int rpc__req__wifi_sta_itwt_send_probe_req__init;
extern int sdmmc_host_transaction_handler_deinit;
extern int nvs_commit;
extern int _ZN3nvs15NVSHandleSimpleD1Ev;
extern int mbedtls_hmac_drbg_reseed;
extern int _ZNSt9bad_allocD1Ev;
extern int inflateResetKeep;
extern int esp_intr_disable_source;
extern int pbuf_add_header_force;
extern int rpc__resp__wifi_scan_stop__descriptor;
extern int netconn_free;
extern int wifi_protocols__descriptor;
extern int _i2s_hal_set_tx_clock;
extern int mbedtls_ctr_drbg_free;
extern int dw_gdma_lli_config_transfer;
extern int mbedtls_rsa_public;
extern int rpc__resp__wifi_get_band_mode__init;
extern int bmi270_map_int;
extern int rpc__req__iface_mac_addr_set_get__init;
extern int panic_print_registers;
extern int wifi_sta_info__descriptor;
extern int prefix_list;
extern int esp_hosted_transport_set_default_config;
extern int rpc__req__wifi_get_band__descriptor;
extern int lcd_com_remove_device;
extern int mbedtls_asn1_get_bool;
extern int hosted_malloc_align;
extern int rpc__event__supp_dpp_cfg_recvd__descriptor;
extern int rpc__req__supp_dpp_start_listen__descriptor;
extern int _tr_init;
extern int sdmmc_send_cmd_read_ocr;
extern int serial_ll_rx_handler;
extern int hosted_sdio_write_reg;
extern int gdma_axi_hal_set_burst_size;
extern int rpc__req__wifi_set_channel__descriptor;
extern int _ZN3nvs4Page9writeItemEhNS_8ItemTypeEPKcPKvjh;
extern int ip4_output_if_opt;
extern int strlcat;
extern int esp_lcd_new_panel_st7701_rgb;
extern int mbedtls_pk_verify;
extern int mbedtls_mpi_read_binary_le;
extern int esp_chip_info;
extern int console_tcdrain;
extern int vPortYieldOtherCore;
extern int _ZdlPvj;
extern int rpc__resp__gpio_reset_pin__descriptor;
extern int rpc__resp__otaactivate__descriptor;
extern int rpc__req__iface_mac_addr_len_get__descriptor;
extern int rpc__resp__eap_set_new_password__descriptor;
extern int mbedtls_pk_ecc_set_pubkey_from_prv;
extern int pthread_internal_local_storage_destructor_callback;
extern int esp_hosted_get_default_sdio_config;
extern int mbedtls_oid_get_pk_alg;
extern int memp_NETBUF;
extern int mbedtls_ccm_setkey;
extern int esp_vfs_console_register;
extern int terminus16_glyph_bitmap;
extern int netconn_recv_tcp_pbuf_flags;
extern int panic_get_cause;
extern int rtc_clk_apll_coeff_calc;
extern int _open_r;
extern int rpc__req__wifi_stop__descriptor;
extern int strndup;
extern int spi_flash_op_block_func;
extern int mbedtls_sha1;
extern int spi_flash_hal_erase_block;
extern int esp_timer_start_once;
extern int regdma_link_init;
extern int esp_psram_impl_get_cs_io;
extern int mspi_timing_enter_high_speed_mode;
extern int mbedtls_ecdh_read_public;
extern int rtc_gpio_pulldown_dis;
extern int linenoiseSetMultiLine;
extern int mbedtls_ssl_handshake_step;
extern int netif_remove_ext_callback;
extern int rpc__req__wifi_get_max_tx_power__descriptor;
extern int rpc__descriptor;
extern int periph_rcc_exit;
extern int cJSON_Delete;
extern int protobuf_c_message_pack;
extern int mbedtls_hmac_drbg_random_with_add;
extern int vPortCoprocUsedInISR;
extern int rpc__resp__wifi_set_bandwidth__descriptor;
extern int mbedtls_rsa_rsaes_oaep_decrypt;
extern int _remove_r;
extern int sdmmc_host_io_int_wait;
extern int icmp6_dest_unreach;
extern int rpc__req__gpio_reset_pin__init;
extern int _tzset_unlocked;
extern int mbedtls_mpi_core_montmul_init;
extern int esp_register_freertos_tick_hook_for_cpu;
extern int sdmmc_do_timing_tuning;
extern int _close_r;
extern int __wrap_getcwd;
extern int hosted_sdio_read_reg;
extern int rpc__event__sta_itwt_probe__init;
extern int _ZN3nvs8HashList13HashListBlockC1Ev;
extern int protobuf_c_message_init;
extern int sdmmc_host_set_card_clk;
extern int xQueueCreateMutexStatic;
extern int __lock___sinit_recursive_mutex;
extern int fputs;
extern int sdmmc_send_cmd_set_bus_width;
extern int esp_mbedtls_mem_free;
extern int _ZN3nvs15NVSHandleSimple20get_used_entry_countERj;
extern int mbedtls_ssl_write_record;
extern int protobuf_c_enum_descriptor_get_value;
extern int lwip_bind;
extern int pvTaskGetThreadLocalStoragePointer;
extern int rpc__resp__gpio_input_enable__init;
extern int vprintf;
extern int rpc__req__wifi_set_country_code__init;
extern int rgb_display_get_fb_height;
extern int lwip_strnicmp;
extern int esp_wifi_remote_stop;
extern int i2s_channel_init_std_mode;
extern int i2s_gpio_loopback_set;
extern int rpc__resp__wifi_get_bandwidths__descriptor;
extern int mspi_timing_psram_tuning;
extern int console_open;
extern int brownout_hal_config;
extern int sdmmc_init_select_card;
extern int rpc__resp__wifi_set_max_tx_power__descriptor;
extern int sdmmc_host_set_bus_ddr_mode;
extern int esp_vfs_write;
extern int sys_now;
extern int esp_crypto_mpi_lock_release;
extern int mpi_hal_set_mode;
extern int mbedtls_mpi_add_int;
extern int pmu_hp_system_retention_param_default;
extern int __atomic_fetch_and_8;
extern int esp_netif_receive;
extern int esp_crt_bundle_attach;
extern int esp_log_level_get_timeout;
extern int esp_netif_get_nr_of_ifs;
extern int panic_print_dec;
extern int rpc_cmd__descriptor;
extern int rpc__req__set_mac_address__init;
extern int lwip_connect;
extern int mbedtls_mpi_core_lt_ct;
extern int raw_netif_ip_addr_changed;
extern int xPortcheckValidStackMem;
extern int rpc_slaveif_wifi_start;
extern int efuse_hal_chip_revision;
extern int esp_transport_set_errors;
extern int esp_flash_noos_functions;
extern int __sfvwrite_r;
extern int rpc__event__ap__sta_connected__init;
extern int abort;
extern int sdmmc_io_get_cis_data;
extern int hosted_log_write;
extern int linenoiseEditBackspace;
extern int regdma_find_module_link_head;
extern int igmp_leavegroup;
extern int esp_console_init;
extern int esp_mbedtls_handshake;
extern int esp_transport_ssl_set_client_key_data_der;
extern int esp_task_wdt_print_triggered_tasks;
extern int memspi_host_init_pointers;
extern int rpc__resp__app_get_desc__init;
extern int esp_ecc_point_verify;
extern int regdma_link_new_branch_continuous_default;
extern int rtc_isr_noniram_enable;
extern int hosted_create_semaphore;
extern int tcp_err;
extern int rpc__resp__supp_dpp_start_listen__init;
extern int __adddf3;
extern int pmu_hal_hp_set_sleep_active_backup_disable;
extern int esp_unregister_shutdown_handler;
extern int esp_mmu_map_init;
extern int vQueueDeleteWithCaps;
extern int unlink;
extern int cache_hal_resume;
extern int _system_r;
extern int esp_transport_ssl_set_client_cert_data_der;
extern int __locale_mb_cur_max;
extern int regi2c_write_impl;
extern int rpc__resp__otawrite__init;
extern int gdma_hal_start_with_desc;
extern int mbedtls_ssl_add_hs_hdr_to_checksum;
extern int __divdi3;
extern int efuse_hal_get_disable_wafer_version_major;
extern int esp_vfs_fsync;
extern int esp_vfs_stat;
extern int restart_after_slave_ota;
extern int esp_tls_get_conn_sockfd;
extern int rpc__req__wifi_set_inactive_time__init;
extern int strtoll;
extern int esp_restart;
extern int mbedtls_ecp_keypair_init;
extern int esp_rom_regi2c_write_mask;
extern int tcp_new_ip_type;
extern int _unlink_r;
extern int rpc__resp__wifi_scan_stop__init;
extern int rpc__event__dhcp_dns_status__init;
extern int regi2c_read_impl;
extern int __umoddi3;
extern int hosted_restart_slave;
extern int esp_hosted_cli_start;
extern int cosf;
extern int sdmmc_slot_gpio_num;
extern int mbedtls_mpi_core_shift_l;
extern int vPortSetupTimer;
extern int icmp_dest_unreach;
extern int mbedtls_mpi_sub_abs;
extern int mbedtls_mpi_size;
extern int vTaskInternalSetTimeOutState;
extern int hosted_pull_gpio;
extern int uxListRemove;
extern int xPortSetInterruptMaskFromISR;
extern int transport_drv_reconfigure;
extern int esp_timer_create;
extern int esp_psram_init;
extern int mbedtls_mpi_core_cond_swap;
extern int usb_serial_jtag_write_bytes;
extern int esp_mbedtls_get_bytes_avail;
extern int i2s_channel_enable;
extern int arg_dstr_destroy;
extern int mbedtls_mpi_core_random;
extern int __hi0bits;
extern int lfs_setattr;
extern int vterm_exit_graphics_mode;
extern int esp_crypto_hmac_enable_periph_clk;
extern int __sglue;
extern int esp_clk_slowclk_cal_get;
extern int esp_newlib_time_init;
extern int esp_newlib_locks_init;
extern int mpi_hal_calc_hardware_words;
extern int rpc__resp__eap_set_fast_params__descriptor;
extern int memspi_host_set_write_protect;
extern int hosted_calloc;
extern int mpi_hal_wait_op_complete;
extern int mbedtls_x509_get_time;
extern int mbedtls_mpi_core_to_mont_rep;
extern int mbedtls_rsa_alt_info;
extern int rpc__req__set_ps__init;
extern int gdma_hal_deinit;
extern int getchar;
extern int mbedtls_mpi_core_sub;
extern int rpc__req__eap_set_ca_cert__init;
extern int sdmmc_card_init;
extern int esp_elf_malloc;
extern int mbedtls_x509_crt_verify_restartable;
extern int opterr;
extern int esp_wifi_remote_scan_get_ap_records;
extern int pbuf_add_header;
extern int mbedtls_ccm_finish;
extern int sdmmc_send_cmd_set_blocklen;
extern int i2c_hal_master_trans_start;
extern int esp_flash_init_default_chip;
extern int esp_intr_get_cpu;
extern int rpc__req__wifi_sta_enterprise_enable__descriptor;
extern int esp_netif_netstack_buf_free;
extern int mbedtls_ssl_check_cert_usage;
extern int _ZNKSt9type_info15__is_function_pEv;
extern int lfs_file_seek;
extern int mbedtls_ssl_write_version;
extern int heap_caps_aligned_calloc;
extern int mbedtls_ecdsa_sign_det_restartable;
extern int esp_netif_dhcpc_start;
extern int g_spi_lock_main_flash_dev;
extern int esp_hosted_is_config_valid;
extern int mbedtls_aria_crypt_cbc;
extern int bus_init_internal;
extern int cmd_mv;
extern int spi_timing_get_flash_timing_param;
extern int pthread_exit;
extern int mbedtls_ecp_group_load;
extern int rpc__req__wifi_sta_get_aid__init;
extern int heap_caps_check_integrity;
extern int lfs_file_opencfg;
extern int lwip_htons;
extern int rpc__resp__ext_coex__descriptor;
extern int spi_flash_chip_generic_set_write_protect;
extern int esp_netif_down;
extern int rpc__resp__custom_rpc__descriptor;
extern int lwip_close;
extern int usb_serial_jtag_write_ready;
extern int fflush;
extern int lfs_rename;
extern int pthread_include_pthread_cond_var_impl;
extern int rpc__req__eap_set_new_password__descriptor;
extern int dw_gdma_new_channel;
extern int multi_heap_minimum_free_size;
extern int __sfp;
extern int aes_hal_mode_init;
extern int __sinit;
extern int retrans_timer;
extern int netif_invoke_ext_callback;
extern int periph_rtc_apll_freq_set;
extern int _esp_error_check_failed;
extern int rpc__req__wifi_connect__init;
extern int mbedtls_sha1_clone;
extern int xTaskGetTickCountFromISR;
extern int netconn_disconnect;
extern int http_header_generate_string;
extern int rpc_feature__descriptor;
extern int _lock_try_acquire_recursive;
extern int div;
extern int sdmmc_host_wait_for_event;
extern int arg_end;
extern int dhcps_set_option_info;
extern int __atexit;
extern int tlsf_alloc_overhead;
extern int rpc__event__wifi_dpp_cfg_recvd__descriptor;
extern int esp_netif_add_to_list_unsafe;
extern int esp_crypto_hmac_lock_acquire;
extern int __fixdfsi;
extern int lfs_dir_close;
extern int rtc_io_num_map;
extern int etharp_add_static_entry;
extern int sys_arch_mbox_fetch;
extern int clk_hal_cpu_get_freq_hz;
extern int rpc__req__eap_use_default_cert_bundle__init;
extern int pau_hal_set_regdma_wait_timeout;
extern int rpc__req__wifi_get_country_code__descriptor;
extern int wifi_remote_initialize;
extern int mbedtls_ssl_conf_endpoint;
extern int soc_memory_types;
extern int mbedtls_x509_get_subject_alt_name_ext;
extern int dw_gdma_lli_set_block_markers;
extern int heap_caps_calloc_base;
extern int esp_event_handler_register;
extern int rpc__resp__iface_mac_addr_len_get__descriptor;
extern int __eqdf2;
extern int _ZN3nvs4Page4loadEPNS_9PartitionEm;
extern int mbedtls_rsa_get_bitlen;
extern int strtof_l;
extern int rpc__resp__get_coprocessor_fw_version__init;
extern int rpc__req__wifi_set_max_tx_power__init;
extern int sys_init;
extern int arg_dstr_create;
extern int rpc__req__wifi_get_channel__init;
extern int rpc__resp__wifi_connect__init;
extern int esp_cpu_intr_get_desc;
extern int _write_r;
extern int _fprintf_r;
extern int clk_hal_apll_get_freq_hz;
extern int _exit;
extern int hosted_msleep;
extern int lfs_file_read;
extern int sdmmc_slot_gpio_sig;
extern int bmi2_set_regs;
extern int esp_cpu_wait_for_intr;
extern int fprintf;
extern int sdmmc_card_print_info;
extern int wifi_sta_config__descriptor;
extern int wifi_event_sta_scan_done__init;
extern int tlsf_size;
extern int __retarget_lock_try_acquire_recursive;
extern int cache_hal_writeback_addr;
extern int esp_transport_list_get_transport;
extern int esp_transport_ssl_set_common_name;
extern int esp_transport_init;
extern int mbedtls_sha256_finish;
extern int __multiply;
extern int esp_cache_get_alignment;
extern int _ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_;
extern int tcp_listen_with_backlog_and_err;
extern int tanmatsu_lcd_mark_dirty;
extern int mbedtls_mpi_cmp_abs;
extern int rpc__event__espinit__descriptor;
extern int _rewind_r;
extern int vTaskGetSnapshot;
extern int xRingbufferCreate;
extern int esp_deep_sleep_wakeup_io_reset;
extern int udp_new;
extern int netconn_listen_with_backlog;
extern int rtos_int_exit;
extern int ecc_hal_enable_constant_time_point_mul;
extern int nvs_flash_init_partition;
extern int lwip_netconn_do_join_leave_group_netif;
extern int mbedtls_ecdsa_sign_restartable;
extern int mbedtls_ecp_curve_info_from_grp_id;
extern int rtc_gpio_hold_dis;
extern int lwip_netconn_do_gethostbyname;
extern int sdmmc_init_mmc_check_ext_csd;
extern int multi_heap_minimum_free_size_impl;
extern int pthread_include_pthread_rwlock_impl;
extern int esp_http_client_set_url;
extern int esp_console_register_help_command;
extern int rpc__resp__gpio_get_level__descriptor;
extern int memp_SYS_TIMEOUT;
extern int rpc__resp__wifi_stop__descriptor;
extern int esp_cpu_configure_region_protection;
extern int mbedtls_entropy_add_source;
extern int mbedtls_ssl_sig_from_pk_alg;
extern int esp_partition_mmap;
extern int esp_mpi_mul_mpi_hw_op;
extern int mbedtls_mpi_mod_mpi;
extern int dhcp_cleanup;
extern int esp_partition_munmap;
extern int esp_startup_start_app_other_cores;
extern int esp_event_handler_unregister_with;
extern int bmi2_soft_reset;
extern int xTaskGetCoreID;
extern int lwip_recvfrom;
extern int mbedtls_pk_verify_restartable;
extern int mbedtls_ssl_get_max_out_record_payload;
extern int mbedtls_sha512_init;
extern int sdmmc_init_cid;
extern int pthread_getspecific;
extern int mbedtls_oid_get_ec_grp_algid;
extern int rpc__resp__eap_set_eap_methods__descriptor;
extern int esp_vfs_littlefs_register;
extern int sdmmc_init_ocr;
extern int esp_transport_init_foundation_transport;
extern int rpc__gpio_config__init;
extern int memcpy;
extern int mbedtls_net_init;
extern int rpc__event__wifi_dpp_uri_ready__descriptor;
extern int gpio_install_isr_service;
extern int refreshShowHints;
extern int vTaskPrioritySet;
extern int mbedtls_mpi_write_binary;
extern int mbedtls_x509_get_alg_null;
extern int mbedtls_mpi_core_shift_r;
extern int mbedtls_net_send;
extern int ip_input;
extern int vRingbufferReturnItem;
extern int __cxa_get_globals_fast;
extern int __mcmp;
extern int esp_transport_write;
extern int multi_heap_get_info_impl;
extern int rpc_parse_rsp;
extern int esp_psram_impl_enable;
extern int mbedtls_ssl_conf_authmode;
extern int xQueueGetMutexHolder;
extern int pau_hal_set_regdma_work_timeout;
extern int _vfprintf_r;
extern int vSystimerSetup;
extern int ip4_frag;
extern int esp_wifi_remote_set_mode;
extern int esp_mmu_vaddr_to_paddr;
extern int cJSON_Parse;
extern int esp_transport_ssl_set_tls_version;
extern int rpc__resp__wifi_sta_enterprise_enable__init;
extern int mbedtls_net_recv;
extern int vPortFree;
extern int rpc__resp__wifi_sta_get_negotiated_phymode__descriptor;
extern int esp_cache_err_has_active_err;
extern int _ZSt7nothrow;
extern int esp_crypto_shared_gdma_done;
extern int rpc_core_init;
extern int rpc__resp__get_dhcp_dns_status__descriptor;
extern int esp_transport_list_clean;
extern int spi_flash_chip_generic_page_program;
extern int tcp_output;
extern int esp_intr_alloc_intrstatus;
extern int breezybox_register_commands;
extern int __swbuf;
extern int esp_libc_locks_init;
extern int __floatdidf;
extern int g_startup_fn;
extern int _user_strerror;
extern int wifi_bandwidths__init;
extern int arg_print_glossary_ds;
extern int rpc_slaveif_wifi_scan_start;
extern int rpc__req__wifi_ap_get_sta_list__init;
extern int frexp;
extern int esp_aes_gcm_update;
extern int rpc__req__supp_dpp_bootstrap_gen__descriptor;
extern int netif_default;
extern int lwip_netconn_do_close;
extern int mbedtls_x509_crt_parse;
extern int __assert_func;
extern int esp_crosscore_int_send_print_backtrace;
extern int usleep;
extern int mld6_leavegroup;
extern int pbuf_alloc;
extern int pmu_init;
extern int _global_interrupt_handler;
extern int rpc__req__wifi_sta_get_rssi__descriptor;
extern int esp_wifi_remote_connect;
extern int wifi_ap_config__descriptor;
extern int esp_log_cache_clean;
extern int __retarget_lock_acquire;
extern int __ieee754_sqrtf;
extern int rtcio_hal_set_direction;
extern int srand;
extern int esp_vfs_close;
extern int udp_disconnect;
extern int esp_netif_set_driver_config;
extern int mmu_hal_check_valid_ext_vaddr_region;
extern int inet_chksum_pbuf;
extern int rtc_io_number_get;
extern int _tr_flush_block;
extern int mbedtls_ssl_config_defaults;
extern int call_start_cpu0;
extern int multi_heap_malloc_impl;
extern int _ZSt13get_terminatev;
extern int multi_heap_aligned_alloc_impl_offs;
extern int mspi_timing_psram_select_best_tuning_delayline;
extern int dns_init;
extern int esp_ota_get_running_partition;
extern int _i2c_hal_set_bus_timing;
extern int netif_add;
extern int mbedtls_mpi_core_add;
extern int mpi_hal_start_op;
extern int rpc__req__gpio_set_level__init;
extern int spi_flash_hal_gpspi_check_status;
extern int aes_hal_read_iv;
extern int mbedtls_ssl_read_version;
extern int esp_ipc_isr_end_fl;
extern int deflateReset;
extern int esp_hosted_set_default_config;
extern int pthread_include_pthread_impl;
extern int wifi_scan_channel_bitmap__descriptor;
extern int mbedtls_mpi_core_montmul;
extern int rpc_copy_wifi_sta_config;
extern int rpc__resp__eap_set_disable_time_check__descriptor;
extern int rpc__req__wifi_clear_fast_connect__init;
extern int esp_transport_ssl_set_client_key_password;
extern int esp_hw_stack_guard_get_pc;
extern int is_transport_rx_ready;
extern int gdma_hal_enable_intr;
extern int mbedtls_ms_time;
extern int netconn_connect;
extern int fmodf;
extern int bootloader_flash_execute_command_common;
extern int rpc__req__wifi_get_protocols__descriptor;
extern int __retarget_lock_init_recursive;
extern int rpc__req__supp_dpp_stop_listen__descriptor;
extern int tcp_zero_window_probe;
extern int mbedtls_aria_crypt_ecb;
extern int mempool_alloc;
extern int rpc__resp__get_mac_address__descriptor;
extern int dma2d_get_trans_elm_size;
extern int wifi_config__init;
extern int tcp_rexmit_rto_commit;
extern int _gettimeofday_r;
extern int esp_aes_gcm_finish;
extern int esp_libc_include_heap_impl;
extern int rpc__resp__ext_coex__init;
extern int memp_NETDB;
extern int esp_console_split_argv;
extern int __fp_unlock_all;
extern int udp_input;
extern int rpc__resp__wifi_sta_itwt_setup__descriptor;
extern int _ZN3nvs7Storage15clearNamespacesEv;
extern int mbedtls_ecdsa_info;
extern int set_client_config;
extern int _ZN3nvs7Storage20eraseOrphanDataBlobsER14intrusive_listINS0_13BlobIndexNodeEE;
extern int usb_serial_jtag_set_select_notif_callback;
extern int ip6addr_ntoa_r;
extern int mbedtls_pk_encrypt;
extern int esp_lcd_del_dsi_bus;
extern int rand;
extern int sdmmc_check_scr;
extern int rpc__req__wifi_set_bandwidth__descriptor;
extern int httpd_register_uri_handler;
extern int esp_gpio_revoke;
extern int i2s_new_channel;
extern int console_tcgetattr;
extern int arg_print_errors_ds;
extern int rpc__req__wifi_sta_itwt_suspend__init;
extern int gdma_new_channel;
extern int rpc__resp__wifi_get_inactive_time__init;
extern int g_flash_guard_default_ops;
extern int mbedtls_md_hmac_update;
extern int esp_partition_find_first;
extern int esp_transport_set_func;
extern int mbedtls_gcm_finish_soft;
extern int netconn_gethostbyname_addrtype;
extern int esp_ipc_isr_start_fl;
extern int esp_ipc_call_blocking;
extern int wifi_scan_time__init;
extern int rpc__resp__eap_clear_new_password__init;
extern int es8156_write_sdp_interface_config_1;
extern int nd6_tmr;
extern int xTaskGenericNotify;
extern int rpc_wifi_set_config;
extern int esp_log_set_vprintf;
extern int cache_hal_get_cache_line_size;
extern int rpc_wifi_disconnect;
extern int mbedtls_x509_crt_check_key_usage;
extern int regi2c_read_mask_impl;
extern int mbedtls_ssl_verify_certificate;
extern int st7701_get_parameters;
extern int esp_clk_tree_src_get_freq_hz;
extern int lfs_fs_size;
extern int _g_esp_netif_netstack_default_wifi_sta;
extern int mbedtls_free;
extern int rtc_clk_apll_enable;
extern int _tzname;
extern int _ZN3nvs4Page8SEC_SIZEE;
extern int _ZN3nvs15NVSHandleSimple8find_keyEPKcR10nvs_type_t;
extern int __ashldi3;
extern int mktime;
extern int http_utils_trim_whitespace;
extern int spi_flash_encryption_hal_destroy;
extern int esp_log_impl_lock_timeout;
extern int i2s_output_gpio_reserve;
extern int rpc__event__wifi_event_no_args__init;
extern int esp_panic_handler_disable_timg_wdts;
extern int deflate;
extern int gz_intmax;
extern int vTaskDeleteWithCaps;
extern int wifi_twt_config__init;
extern int _ZN3nvs8HashList13HashListBlockC2Ev;
extern int sd_pwr_ctrl_set_io_voltage;
extern int rpc__resp__mem_monitor__descriptor;
extern int esp_flash_write;
extern int mbedtls_ssl_parse_alpn_ext;
extern int esp_vfs_include_console_register;
extern int esp_pbuf_allocate;
extern int my_console_get_output_mode;
extern int breezybox_cwd;
extern int esp_partition_find;
extern int localtime;
extern int rpc__req__wifi_sta_itwt_setup__init;
extern int esp_tls_conn_new_async;
extern int mbedtls_x509_crt_is_revoked;
extern int port_uxInterruptNesting;
extern int qsort;
extern int rpc__resp__gpio_set_pull_mode__descriptor;
extern int _sungetc_r;
extern int wifi_he_ap_info__init;
extern int acd_start;
extern int mbedtls_ecp_set_zero;
extern int rpc__req__otawrite__init;
extern int esp_vfs_dev_usb_serial_jtag_register;
extern int mbedtls_x509_get_subject_alt_name;
extern int rpc__unpack;
extern int mipi_dsi_hal_host_gen_write_short_packet;
extern int tcp_seg_free;
extern int dma2d_set_desc_addr;
extern int esp_event_loop_create;
extern int netconn_accept;
extern int rgb_display_get_framebuffer;
extern int esp_setup_newlib_syscalls;
extern int esp_partition_read;
extern int cmd_free;
extern int cmd_date;
extern int spi_flash_encryption_hal_done;
extern int _ftell_r;
extern int littlefs_esp_part_erase;
extern int arg_strn;
extern int panicHandler;
extern int rtc_time_get;
extern int _tr_stored_block;
extern int rpc__req__wifi_init__init;
extern int esp_partition_main_flash_region_safe;
extern int sys_mutex_lock;
extern int esp_aes_gcm_auth_decrypt;
extern int mbedtls_ecdh_free;
extern int rpc__resp__wifi_sta_itwt_teardown__descriptor;
extern int rtc_clk_slow_src_get;
extern int lwip_sendto;
extern int utoa;
extern int esp_tls_internal_event_tracker_create;
extern int httpd_recv_with_opt;
extern int mspi_timing_get_psram_tuning_phases;
extern int esp_netif_get_handle_from_ifkey_unsafe;
extern int rtc_clk_cpu_freq_mhz_to_config;
extern int gdma_apply_strategy;
extern int rpc__event__wifi_dpp_fail__descriptor;
extern int _tzset_r;
extern int esp_libc_include_pthread_impl;
extern int sdmmc_init_mmc_bus_width;
extern int esp_aes_intr_alloc;
extern int lfs_remove;
extern int tcp_input;
extern int sys_mbox_new;
extern int send_slave_config;
extern int cs_free_ctrl_sock;
extern int esp_http_client_add_auth;
extern int protobuf_c_message_unpack;
extern int spi_flash_needs_reset_check;
extern int rpc__req__get_dhcp_dns_status__init;
extern int gpio_output_enable;
extern int pmu_hp_system_analog_param_default;
extern int rpc__event__heartbeat__descriptor;
extern int fstat;
extern int rpc__resp__wifi_ap_get_sta_list__init;
extern int sys_sem_new;
extern int aes_hal_transform_dma_gcm_start;
extern int mbedtls_gcm_update_ad_soft;
extern int strtoll_l;
extern int gpio_output_disable;
extern int _getc_r;
extern int ip4_route;
extern int vRingbufferGetInfo;
extern int __ltdf2;
extern int httpd_default_recv;
extern int esp_crt_verify_callback;
extern int mbedtls_rsa_deduce_crt;
extern int __wrap_chdir;
extern int esp_transport_get_error_handle;
extern int xQueueCreateCountingSemaphore;
extern int __udivdi3;
extern int mipi_dsi_hal_init;
extern int gdma_axi_hal_read_intr_status;
extern int lwip_send;
extern int mbedtls_cipher_definitions;
extern int mbedtls_ccm_update_ad;
extern int spi_flash_chip_generic_get_caps;
extern int esp_psram_impl_get_physical_size;
extern int esp_system_abort;
extern int sdmmc_init_spi_crc;
extern int serial_rx_handler;
extern int mbedtls_mpi_init;
extern int getMillis;
extern int esp_transport_esp_tls_destroy;
extern int rpc__resp__wifi_set_band_mode__init;
extern int esp_vfs_access;
extern int esp_vApplicationTickHook;
extern int esp_mpi_disable_hardware_hw_op;
extern int rpc__get_packed_size;
extern int httpd_resp_set_status;
extern int _ftello_r;
extern int spi_flash_chip_winbond_probe;
extern int esp_wifi_remote_scan_start;
extern int rpc__req__get_mac_address__descriptor;
extern int ip4_addr_isbroadcast_u32;
extern int _Znwj;
extern int esp_hosted_sdio_set_config;
extern int gdma_axi_hal_set_priority;
extern int httpd_sess_pending;
extern int rpc__req__app_get_desc__descriptor;
extern int mpi_hal_enable_constant_time;
extern int periph_rtc_apll_acquire;
extern int _ZN3nvs12NVSPartition9write_rawEjPKvj;
extern int mbedtls_ssl_write_alpn_ext;
extern int soc_get_available_memory_region_max_count;
extern int esp_cache_msync;
extern int netconn_new_with_proto_and_callback;
extern int nvs_close;
extern int esp_wifi_set_default_wifi_sta_handlers;
extern int esp_netif_update_default_netif;
extern int inet_chksum_pseudo;
extern int _sniprintf_r;
extern int io_mux_enable_lp_io_clock;
extern int hosted_sdio_write_block;
extern int rpc__resp__wifi_set_protocols__descriptor;
extern int __register_exitproc;
extern int console_close;
extern int panic_restart;
extern int esp_register_shutdown_handler;
extern int nvs_open;
extern int neighbor_cache;
extern int esp_panic_handler;
extern int eap_fast_config__init;
extern int wifi_sta_list__descriptor;
extern int _ZN3nvs19NVSPartitionManager12get_instanceEv;
extern int cJSON_GetArraySize;
extern int netbuf_free;
extern int xQueueGiveFromISR;
extern int tcp_pcb_remove;
extern int mbedtls_ssl_conf_session_tickets;
extern int regi2c_write_mask_impl;
extern int mbedtls_ecdh_setup;
extern int xTaskRemoveFromEventList;
extern int rpc__resp__get_mode__descriptor;
extern int _ZN3nvs7Storage22calcEntriesInNamespaceEhRj;
extern int g_h;
extern int __bswapsi2;
extern int hosted_setup_gpio_interrupt;
extern int __gedf2;
extern int _fstat_r;
extern int mbedtls_sha512_starts;
extern int tanmatsu_coprocessor_set_radio_state;
extern int abs;
extern int rpc__event__sta_connected__init;
extern int mipi_dsi_hal_host_gen_write_dcs_command;
extern int mbedtls_mpi_shrink;
extern int netif_set_link_up;
extern int strtok;
extern int rewinddir;
extern int dns_mquery_v4group;
extern int _ZN3nvs19NVSPartitionManager12close_handleEPNS_15NVSHandleSimpleE;
extern int esp_tls_init;
extern int closedir;
extern int esp_transport_ssl_skip_common_name_check;
extern int hosted_destroy_lock_mempool;
extern int udp_pcbs;
extern int mbedtls_ecp_is_zero;
extern int linenoiseEditDeletePrevWord;
extern int mpi_hal_interrupt_enable;
extern int fileno;
extern int mbedtls_x509_get_serial;
extern int mbedtls_rsa_info;
extern int hosted_free_align;
extern int environ;
extern int startup_resume_other_cores;
extern int mbedtls_ecp_read_key;
extern int esp_http_client_perform;
extern int sdmmc_enter_higher_speed_mode;
extern int esp_intr_free;
extern int tcp_rexmit_fast;
extern int esp_vApplicationIdleHook;
extern int _mprec_log10;
extern int rpc__req__supp_dpp_init__init;
extern int vterm_get_active;
extern int _ZN3nvs4Page11markFreeingEv;
extern int ds_hal_start_sign;
extern int esp_newlib_init;
extern int mbedtls_aria_init;
extern int gdma_axi_hal_stop;
extern int http_parser_execute;
extern int rpc__req__eap_set_disable_time_check__init;
extern int rpc__resp__wifi_sta_enterprise_disable__descriptor;
extern int multi_heap_free;
extern int _sbrk_r;
extern int hosted_reset_queue;
extern int rpc__resp__otawrite__descriptor;
extern int sha_hal_set_mode;
extern int efuse_hal_blk_version;
extern int esp_log_cache_set_level;
extern int mbedtls_ecp_check_pubkey_soft;
extern int _ZN3nvs16partition_lookup20lookup_nvs_partitionEPKcPPNS_12NVSPartitionE;
extern int _ZN3nvs7Storage18writeMultiPageBlobEhPKcPKvjNS_9VerOffsetE;
extern int tanmatsu_lcd_set_palette;
extern int bmi270_config_file;
extern int sdmmc_send_app_cmd;
extern int gdma_axi_hal_connect_peri;
extern int tcp_poll;
extern int putchar;
extern int mspi_timing_config_psram_set_tuning_delayline;
extern int cmd_du;
extern int mbedtls_pk_ecc_set_pubkey;
extern int ip4addr_ntoa_r;
extern int __getopt_long_only_r;
extern int rpc__event__supp_dpp_fail__descriptor;
extern int wifi_pmf_config__init;
extern int mbedtls_mpi_write_binary_le;
extern int netconn_write_partly;
extern int destination_cache;
extern int rpc__req__eap_set_fast_params__descriptor;
extern int lwip_cyclic_timers;
extern int cmd_wifi;
extern int bsp_tanmatsu_coprocessor_get_handle;
extern int g_panic_abort_details;
extern int _ZN3nvs4Lock4initEv;
extern int rpc__req__wifi_set_country__init;
extern int mbedtls_gcm_init_soft;
extern int mbedtls_ssl_update_out_pointers;
extern int igmp_tmr;
extern int mbedtls_ssl_parse_sig_alg_ext;
extern int __gettzinfo;
extern int sdmmc_io_read_blocks;
extern int bsp_display_set_backlight_brightness;
extern int mbedtls_ecdh_compute_shared;
extern int es8156_write_misc_control_3;
extern int _puts_r;
extern int _ZN3nvs4Page7cmpItemEhNS_8ItemTypeEPKcPKvjhNS_9VerOffsetE;
extern int rpc__req__wifi_set_inactive_time__descriptor;
extern int esp_netif_free_rx_buffer;
extern int esp_netif_set_mac;
extern int mspi_timing_config_psram_write_data;
extern int rpc__req__supp_dpp_bootstrap_gen__init;
extern int arg_print_glossary;
extern int spi_flash_common_read_status_16b_rdsr_rdsr2;
extern int esp_hosted_transport_get_config;
extern int httpd_is_sess_available;
extern int rpc__req__gpio_input_enable__init;
extern int mmu_hal_get_id_from_vaddr;
extern int rpc__init;
extern int esp_lcd_new_dsi_bus;
extern int gdma_hal_build_parallel_crc_matrix;
extern int etharp_query;
extern int esp_log_impl_lock;
extern int cmd_ls;
extern int tcp_fasttmr;
extern int ensure_slave_bus_ready;
extern int mbedtls_gcm_crypt_and_tag_soft;
extern int mbedtls_pkcs12_derivation;
extern int mbedtls_ecdh_calc_secret;
extern int xPortStartScheduler;
extern int stpcpy;
extern int esp_http_client_fetch_headers;
extern int ipaddr_aton;
extern int _ZN3nvs12NVSPartition8read_rawEjPvj;
extern int dhcp_renew;
extern int rpc_parse_evt;
extern int heap_caps_enable_nonos_stack_heaps;
extern int rpc__req__wifi_set_band_mode__descriptor;
extern int __copybits;
extern int lwip_select;
extern int rpc_slaveif_wifi_stop;
extern int _ZN3nvs8HashListD2Ev;
extern int rgb_display_get_mode;
extern int mbedtls_md_info_from_ctx;
extern int linenoiseEditMoveLeft;
extern int _ZN3nvs15NVSHandleSimple10get_stringEPKcPcj;
extern int serial_drv_write;
extern int esp_netif_is_netif_listed;
extern int rgb_gfx_blit_flip;
extern int vterm_write;
extern int sdmmc_init_sd_blocklen;
extern int dma2d_connect;
extern int lp_timer_hal_get_cycle_count;
extern int floorf;
extern int rpc__resp__wifi_deinit__descriptor;
extern int esp_efuse_check_errors;
extern int __ssprint_r;
extern int lwip_netconn_do_join_leave_group;
extern int mpi_hal_write_at_offset;
extern int __s2b;
extern int esp_sha_512_t_init_hash;
extern int mbedtls_rsa_validate_crt;
extern int mbedtls_ctr_drbg_random;
extern int memset;
extern int i2s_free_dma_desc;
extern int sdmmc_select_current_limit;
extern int mpi_hal_enable_hardware_hw_op;
extern int hosted_read_gpio;
extern int rpc__resp__eap_set_fast_params__init;
extern int gpio_isr_register;
extern int spi_flash_chip_winbond_erase_block;
extern int esp_ds_set_session_timeout;
extern int rpc__req__get_dhcp_dns_status__descriptor;
extern int _ZNSt9bad_allocD0Ev;
extern int esp_timer_impl_init_system_time;
extern int sdmmc_send_cmd_send_status;
extern int xQueueGenericReset;
extern int xIsrStack;
extern int gdma_axi_hal_reset;
extern int rtc_clk_slow_src_set;
extern int heap_caps_malloc_extmem_enable;
extern int bmi2_get_feature_data;
extern int clk_hal_xtal_get_freq_mhz;
extern int __kernel_sin;
extern int esp_vfs_rmdir;
extern int ip_data;
extern int regdma_link_new_branch_addr_map_default;
extern int deflateInit2_;
extern int gdma_ahb_hal_enable_burst;
extern int pbuf_alloced_custom;
extern int sys_sem_signal;
extern int mbedtls_rsa_rsassa_pss_sign;
extern int udp_connect;
extern int vTaskPriorityDisinheritAfterTimeout;
extern int mbedtls_ssl_conf_ciphersuites;
extern int mbedtls_pk_parse_public_key;
extern int icmp6_param_problem;
extern int rpc__req__wifi_scan_start__descriptor;
extern int getenv;
extern int nd6_get_next_hop_addr_or_queue;
extern int mbedtls_sha256_clone;
extern int pau_regdma_set_entry_link_addr;
extern int transport_esp_hosted_up_cb;
extern int mbedtls_ssl_flush_output;
extern int esp_netif_is_valid_static_ip;
extern int breezybox_get_cwd;
extern int esp_netif_get_hostname;
extern int esp_aes_process_dma;
extern int rpc__req__supp_dpp_init__descriptor;
extern int dhcps_stop;
extern int lwip_netconn_do_disconnect;
extern int gdma_hal_stop;
extern int vfs_include_syscalls_impl;
extern int nvs_open_from_partition;
extern int memspi_host_write_data_slicer;
extern int bmi2_delay_us;
extern int sdmmc_decode_csd;
extern int _localeconv_r;
extern int multi_heap_internal_lock;
extern int mbedtls_ctr_drbg_reseed;
extern int dma2d_start;
extern int rpc__req__eap_set_suiteb192bit_certification__descriptor;
extern int rpc_wifi_init;
extern int mbedtls_asn1_get_bitstring;
extern int spi_flash_hal_gpspi_common_command;
extern int es8156_select_page;
extern int __lock___tz_mutex;
extern int lfs_mount;
extern int bmi270_init;
extern int gpio_od_disable;
extern int rpc__resp__otaend__descriptor;
extern int regi2c_ctrl_write_reg_mask;
extern int hosted_lock_mutex;
extern int setvbuf;
extern int sdmmc_init_host_frequency;
extern int esp_ds_release_ds_lock;
extern int sdmmc_mmc_send_ext_csd_data;
extern int __lock___env_recursive_mutex;
extern int hosted_config_gpio;
extern int wifi_event_sta_disconnected__descriptor;
extern int _ZN3nvs4Page17eraseEntryAndSpanEj;
extern int rpc__req__wifi_scan_get_ap_record__init;
extern int app_main;
extern int esp_md5_starts;
extern int esp_mmu_unmap;
extern int esp_log_level_get;
extern int esp_pm_lock_release;
extern int esp_http_client_set_header;
extern int esp_elf_request;
extern int hosted_create_queue;
extern int esp_partition_write;
extern int i2s_del_channel;
extern int strtok_r;
extern int bsp_display_initialize;
extern int sdmmc_host_deinit;
extern int mmu_hal_pages_to_bytes;
extern int sdmmc_io_send_op_cond;
extern int mbedtls_ssl_handshake_wrapup_free_hs_transform;
extern int rtc_gpio_hold_en;
extern int mbedtls_x509_get_key_usage;
extern int rpc__resp__eap_get_disable_time_check__descriptor;
extern int xTaskCreateStaticPinnedToCore;
extern int pbuf_ref;
extern int rpc__resp__wifi_sta_itwt_teardown__init;
extern int esp_vfs_mkdir;
extern int netconn_delete;
extern int rpc__event__sta_disconnected__descriptor;
extern int httpd_queue_work;
extern int netconn_send;
extern int mbedtls_x509_get_ext;
extern int esp_mpi_exp_mpi_mod_hw_op;
extern int __extenddftf2;
extern int __mdiff;
extern int sdmmc_host_reset;
extern int _ZN3nvs4Page8markFullEv;
extern int gdma_periph_signals;
extern int spi_flash_hal_poll_cmd_done;
extern int esp_sleep_pd_config;
extern int igmp_joingroup;
extern int multi_heap_register_impl;
extern int rpc__resp__feature_control__init;
extern int lwip_netconn_do_getaddr;
extern int __kernel_rem_pio2f;
extern int gdma_link_mount_buffers;
extern int mbedtls_cipher_free;
extern int hosted_teardown_gpio_interrupt;
extern int sha_hal_write_digest;
extern int dma2d_enqueue;
extern int esp_aes_dma_done;
extern int systimer_us_to_ticks;
extern int dw_gdma_channel_use_link_list;
extern int mspi_timing_config_set_psram_clock;
extern int esp_cpu_stall;
extern int mbedtls_ssl_validate_ciphersuite;
extern int rpc__resp__wifi_sta_get_rssi__init;
extern int esp_elf_arch_relocate;
extern int mld6_lookfor_group;
extern int breezy_http_download;
extern int wifi_protocols__init;
extern int sys_thread_new;
extern int mipi_dsi_hal_host_gen_read_short_packet;
extern int rpc__resp__wifi_deauth_sta__init;
extern int mbedtls_ssl_reset_checksum;
extern int mem_init;
extern int mbedtls_ccm_encrypt_and_tag;
extern int rtc_clk_mpll_configure;
extern int mbedtls_ct_memcpy_if;
extern int esp_vfs_rename;
extern int esp_task_wdt_impl_timer_feed;
extern int i2c_master_config_internal;
extern int mbedtls_pk_info_from_type;
extern int _lock_init_recursive;
extern int rpc__free_unpacked;
extern int rpc__resp__get_mac_address__init;
extern int rpc__req__wifi_get_config__descriptor;
extern int rpc__req__set_dhcp_dns_status__init;
extern int heap_caps_malloc;
extern int esp_aes_dma_start;
extern int esp_psram_io_get_cs_io;
extern int es8156_configure;
extern int rpc__resp__eap_set_eap_methods__init;
extern int regdma_link_destroy;
extern int bsp_power_get_radio_state;
extern int rpc_rsp_callback;
extern int arg_dstr_free;
extern int rpc_wait_and_parse_sync_resp;
extern int bsp_display_get_default_rotation;
extern int wifi_ap_record__init;
extern int dw_gdma_link_list_get_item;
extern int spi_flash_chip_generic_set_io_mode;
extern int _svfiprintf_r;
extern int esp_event_handler_unregister_with_internal;
extern int asprintf;
extern int rpc__resp__wifi_clear_fast_connect__descriptor;
extern int rpc__resp__wifi_scan_get_ap_records__init;
extern int gdma_ahb_hal_set_priority;
extern int _ZN3nvs8HashListD1Ev;
extern int _ZN3nvs7Storage14eraseNamespaceEh;
extern int tcp_close;
extern int __hexnan;
extern int __moddi3;
extern int freopen;
extern int lcd_hal_cal_pclk_freq;
extern int rpc__req__eap_set_new_password__init;
extern int __i2b;
extern int httpd_resp_send_err;
extern int hosted_config_host_power_save;
extern int rpc__req__wifi_disconnect__descriptor;
extern int mbedtls_ccm_init;
extern int hal_utils_calc_clk_div_frac_fast;
extern int esp_crypto_ecc_lock_acquire;
extern int gdma_new_axi_channel;
extern int i2s_init_dma_intr;
extern int wdt_hal_init;
extern int _fgets_r;
extern int fabs;
extern int mbedtls_md_get_type;
extern int esp_netif_action_stop;
extern int s_update_cache_state;
extern int mbedtls_mpi_core_fill_random;
extern int pau_hal_set_regdma_entry_link_addr;
extern int _ZN3nvs8HashListC2Ev;
extern int rtc_isr_noniram_disable;
extern int _link_r;
extern int bmi2_get_gyro_cross_sense;
extern int hosted_reset_slave_callback;
extern int bootloader_flash_update_id;
extern int _lock_release;
extern int i2c_master_bus_add_device;
extern int esp_lcd_new_panel_st7701;
extern int rpc__req__eap_set_username__descriptor;
extern int mpi_hal_clear_interrupt;
extern int gdma_default_tx_isr;
extern int tcp_bind;
extern int strtod_l;
extern int mbedtls_ecdh_make_params;
extern int bsp_display_blit;
extern int esp_aes_crypt_ecb;
extern int _ZnajRKSt9nothrow_t;
extern int esp_clk_slowclk_cal_set;
extern int sdmmc_host_io_int_enable;
extern int tanmatsu_coprocessor_set_display_backlight;
extern int gdma_ahb_hal_disconnect_peri;
extern int gpio_input_enable;
extern int rpc__req__wifi_init__descriptor;
extern int rpc__resp__wifi_sta_get_negotiated_phymode__init;
extern int _lock_close;
extern int arg_print_option_ds;
extern int xIsrStackBottom;
extern int esp_netif_action_disconnected;
extern int esp_mmu_paddr_find_caps;
extern int __getopt_r;
extern int aes_hal_wait_done;
extern int gdma_ahb_hal_clear_intr;
extern int __ffssi2;
extern int pbuf_free;
extern int transport_pserial_read;
extern int hosted_destroy_mutex;
extern int xTaskGetStaticBuffers;
extern int breezybox_resolve_path;
extern int _ZN3nvs4Page9copyItemsERS0_;
extern int spi_flash_hal_supports_direct_read;
extern int multi_heap_free_impl;
extern int __sread;
extern int _ZNK3nvs4Item22checkHeaderConsistencyEh;
extern int rpc__resp__wifi_scan_get_ap_num__init;
extern int spi_flash_restore_cache;
extern int i2c_common_set_pins;
extern int rpc__req__feature_control__descriptor;
extern int acd_remove;
extern int __bswapdi2;
extern int tcp_rst;
extern int _ZNSt9bad_allocD2Ev;
extern int esp_vfs_select_triggered_isr;
extern int periph_rcc_acquire_exit;
extern int rpc__resp__eap_set_ca_cert__descriptor;
extern int rpc__req__wifi_stop__init;
extern int zcfree;
extern int vTaskStartScheduler;
extern int spi_flash_chip_generic_yield;
extern int strtol_l;
extern int mspi_timing_psram_select_best_tuning_phase;
extern int heap_caps_get_free_size;
extern int gdma_hal_get_eof_desc_addr;
extern int dhcp_append_extra_opts;
extern int linenoiseEditMoveRight;
extern int esp_elf_init;
extern int esp_timer_impl_get_time;
extern int mbedtls_rsa_rsassa_pss_verify;
extern int lfs_file_sync;
extern int esp_ipc_isr_init;
extern int _ZN10__cxxabiv117__class_type_infoD2Ev;
extern int bmi2_i2c_write;
extern int pvPortMalloc;
extern int rpc__resp__set_ps__descriptor;
extern int rpc__resp__eap_set_suiteb192bit_certification__descriptor;
extern int linenoiseSetCompletionCallback;
extern int esp_elf_arch_flush;
extern int rpc__event__ap__sta_disconnected__init;
extern int esp_netif_get_ip_info;
extern int rpc__req__get_ps__init;
extern int mbedtls_md_finish;
extern int __ascii_wctomb;
extern int esp_hosted_power_save_start;
extern int rpc__resp__wifi_sta_enterprise_disable__init;
extern int esp_netif_get_io_driver;
extern int rpc__req__eap_set_fast_params__init;
extern int _perror_r;
extern int gdma_link_concat;
extern int rgb_display_set_vga_palette_entry;
extern int hosted_create_lock_mempool;
extern int __retarget_lock_close;
extern int process_priv_communication;
extern int gzread;
extern int sdmmc_io_rw_extended;
extern int esp_cache_err_int_init;
extern int multi_heap_check;
extern int esp_http_server_dispatch_event;
extern int regdma_link_new_write;
extern int esp_ds_finish_sign;
extern int vterm_set_switch_callback;
extern int esp_tls_conn_new_sync;
extern int _length_code;
extern int esp_transport_ssl_set_ds_data;
extern int esp_task_wdt_impl_timer_allocate;
extern int __lock___sfp_recursive_mutex;
extern int tcp_recved;
extern int __lshift;
extern int ds_hal_write_private_key_params;
extern int mbedtls_cipher_setkey;
extern int mbedtls_rsa_get_len;
extern int mbedtls_sha256_free;
extern int cmd_echo;
extern int esp_netif_action_connected;
extern int esp_aes_gcm_setkey;
extern int rpc__resp__eap_clear_certificate_and_key__init;
extern int _ZN3nvs4PageC1Ev;
extern int rpc__req__supp_dpp_deinit__init;
extern int transport_pserial_open;
extern int mbedtls_ecp_group_init;
extern int rpc__resp__eap_clear_username__init;
extern int mbedtls_pk_decrypt;
extern int mspi_timing_psram_set_best_tuning_phase;
extern int _ZNK3nvs4Page12getSeqNumberERm;
extern int __ieee754_sqrt;
extern int esp_aes_release_hardware;
extern int dhcp_fine_timeout_cb;
extern int panic_print_char;
extern int netif_set_link_down;
extern int esp_lcd_panel_io_del;
extern int rpc__event__sta_itwt_suspend__init;
extern int pthread_key_create;
extern int dhcps_start;
extern int mbedtls_ssl_check_curve_tls_id;
extern int periph_rtc_apll_release;
extern int tlsf_block_size;
extern int multi_heap_free_size_impl;
extern int esp_crypto_mpi_lock_acquire;
extern int sys_timeouts_sleeptime;
extern int spi_flash_op_unlock;
extern int mbedtls_ecp_copy;
extern int hosted_sdio_card_init;
extern int __wrap_opendir;
extern int hosted_start_host_power_save;
extern int mmu_hal_paddr_to_vaddr;
extern int tcp_active_pcbs;
extern int lwip_socket;
extern int gdma_ahb_hal_reset;
extern int mbedtls_cipher_auth_decrypt_ext;
extern int nd6_reachability_hint;
extern int mbedtls_sha256_init;
extern int mbedtls_ssl_init;
extern int esp_startup_start_app;
extern int rpc__req__wifi_set_bandwidths__descriptor;
extern int _ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj;
extern int bmi2_get_regs;
extern int spi_flash_hal_set_write_protect;
extern int _ZN3nvs12NVSPartition5writeEjPKvj;
extern int sdmmc_host_transaction_handler_init;
extern int netif_poll;
extern int tanmatsu_lcd_set_cursor;
extern int _ZN3nvs4LockC2Ev;
extern int rpc__req__eap_get_disable_time_check__init;
extern int rpc__mem_monitor_config__descriptor;
extern int spi_flash_chip_generic_write;
extern int spi_flash_hal_erase_sector;
extern int esp_log_early_timestamp;
extern int xTaskGetTickCount;
extern int mbedtls_ecp_group_copy;
extern int esp_task_wdt_impl_timeout_triggered;
extern int spi_flash_hal_disable_auto_suspend_mode;
extern int esp_vfs_seekdir;
extern int rpc__event__heartbeat__init;
extern int multi_heap_free_size;
extern int esp_transport_ssl_crt_bundle_attach;
extern int linenoise;
extern int uxTaskPriorityGet;
extern int heap_caps_match;
extern int xTaskIncrementTickOtherCores;
extern int esp_transport_connect_async;
extern int perror;
extern int _ZN3nvs19NVSPartitionManager8instanceE;
extern int vterm_get_cursor;
extern int systimer_hal_init;
extern int sin;
extern int multi_heap_aligned_free;
extern int _malloc_r;
extern int esp_task_wdt_add;
extern int esp_log_level_set;
extern int tcp_init;
extern int _ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE;
extern int rpc__req__get_coprocessor_fw_version__descriptor;
extern int rpc__resp__wifi_clear_ap_list__descriptor;
extern int esp_timer_get_time;
extern int mbedtls_ssl_parse_certificate;
extern int _ZN3nvs12NVSPartitionC2EPK15esp_partition_t;
extern int mbedtls_ecp_tls_read_group_id;
extern int MPI_BLOCK_BASES;
extern int mbedtls_rsa_check_pub_priv;
extern int hosted_sleep;
extern int _interrupt_handler;
extern int mbedtls_mpi_safe_cond_swap;
extern int mbedtls_mpi_div_mpi;
extern int esp_console_get_completion;
extern int rpc__req__eap_set_domain_name__descriptor;
extern int esp_tls_get_platform_time;
extern int spi_flash_hal_program_page;
extern int mbedtls_md_update;
extern int mbedtls_ecp_keypair_free;
extern int mbedtls_x509_free_subject_alt_name;
extern int mbedtls_mpi_exp_mod_unsafe;
extern int bmi2_get_internal_status;
extern int rpc__req__wifi_get_band_mode__descriptor;
extern int rpc__resp__wifi_get_country__init;
extern int esp_wifi_remote_set_config;
extern int i2c_select_periph_clock;
extern int port_uxCriticalNesting;
extern int esp_partition_get;
extern int _esp_error_check_failed_without_abort;
extern int __global_locale_ptr;
extern int esp_rom_regi2c_write;
extern int ip4_output_if_opt_src;
extern int pbuf_copy_partial;
extern int longjmp;
extern int gdma_ahb_hal_set_strategy;
extern int regdma_link_new_wait;
extern int sdmmc_io_rw_direct;
extern int mbedtls_md_free;
extern int esp_vfs_readdir;
extern int sdmmc_decode_cid;
extern int rpc__resp__eap_set_password__descriptor;
extern int mbedtls_entropy_func;
extern int rpc__req__gpio_config__init;
extern int mbedtls_mpi_shift_r;
extern int heap_caps_get_minimum_free_size;
extern int mbedtls_asn1_get_alg_null;
extern int esp_libc_init_funcs;
extern int mempool_destroy;
extern int wlanif_init_sta;
extern int rpc_slaveif_wifi_init;
extern int __cxa_get_globals;
extern int vasprintf;
extern int i2c_common_deinit_pins;
extern int __wrap___cxa_throw;
extern int lwip_init_tcp_isn;
extern int rpc__req__wifi_restore__descriptor;
extern int xQueueGenericCreate;
extern int ethernet_output;
extern int rtc_clk_rc32k_enable;
extern int esp_rom_regi2c_read_mask;
extern int esp_crypto_sha_aes_lock_release;
extern int rpc__resp__wifi_get_channel__init;
extern int __d2b;
extern int rpc__req__wifi_start__init;
extern int mmu_hal_map_region;
extern int pbuf_remove_header;
extern int spi_flash_hal_setup_auto_resume_mode;
extern int mbedtls_mpi_shift_l;
extern int rtc_dig_clk8m_disable;
extern int gdma_ahb_hal_get_crc_result;
extern int ip6_output_if_src;
extern int xQueueGenericGetStaticBuffers;
extern int gdma_reset;
extern int lfs_getattr;
extern int _getchar_r;
extern int tcp_arg;
extern int __sflags;
extern int lwip_standard_chksum;
extern int i2c_master_multi_buffer_transmit;
extern int mbedtls_mpi_set_bit;
extern int num_of_soc_mipi_dsi_phy_pll_ranges;
extern int nanf;
extern int esp_wifi_remote_init;
extern int rtos_int_enter;
extern int sys_thread_sem_get;
extern int tcp_abort;
extern int rpc__req__eap_set_eap_methods__init;
extern int rpc__req__eap_set_identity__init;
extern int rpc__resp__wifi_ap_get_sta_aid__descriptor;
extern int mbedtls_ssl_conf_transport;
extern int dw_gdma_channel_default_isr;
extern int my_console_usb_connected;
extern int strncasecmp;
extern int mbedtls_pk_setup_rsa_alt;
extern int esp_aes_gcm_starts;
extern int esp_transport_list_add;
extern int rpc__resp__set_dhcp_dns_status__descriptor;
extern int mbedtls_ssl_handshake_free;
extern int rpc__resp__wifi_scan_get_ap_num__descriptor;
extern int strcpy;
extern int heap_info__descriptor;
extern int s_time_update_lock;
extern int _ZN3nvs15NVSHandleSimple6commitEv;
extern int spi_flash_hal_erase_chip;
extern int gdma_axi_hal_start_with_desc;
extern int es8156_write_analog_system_3;
extern int sdmmc_slot_info;
extern int rpc__req__supp_dpp_deinit__descriptor;
extern int rpc__resp__wifi_get_band_mode__descriptor;
extern int lwip_netconn_do_accepted;
extern int sdmmc_mmc_decode_cid;
extern int mbedtls_cipher_setup;
extern int esp_wifi_remote_start;
extern int rpc_slaveif_wifi_set_config;
extern int http_utils_append_string;
extern int mbedtls_oid_get_sig_alg;
extern int mbedtls_cipher_info_from_values;
extern int es8156_write_analog_system_5;
extern int ip_addr_broadcast;
extern int my_console_usb_reconnect;
extern int lfs_file_close;
extern int rpc__resp__eap_set_pac_file__descriptor;
extern int esp_ipc_isr_stall_abort;
extern int console_access;
extern int gdma_ahb_hal_clear_crc;
extern int dns_gethostbyname_addrtype;
extern int linenoiseFree;
extern int read;
extern int mbedtls_mpi_cmp_int;
extern int esp_reent_init;
extern int _wctomb_r;
extern int tlsf_realloc;
extern int esp_transport_get_errno;
extern int inflateEnd;
extern int cmd_clear;
extern int inflate_fast;
extern int _snprintf_r;
extern int _siscanf_r;
extern int esp_transport_destroy_foundation_transport;
extern int spi_flash_common_set_io_mode;
extern int lwip_shutdown;
extern int rpc__req__eap_clear_certificate_and_key__descriptor;
extern int __mprec_bigtens;
extern int spi_flash_hal_setup_read_suspend;
extern int mspi_timing_flash_config_set_tuning_regs;
extern int xTimerPendFunctionCallFromISR;
extern int netconn_join_leave_group_netif;
extern int ethzero;
extern int bsp_led_initialize;
extern int rpc__req__wifi_scan_get_ap_num__descriptor;
extern int rpc__req__eap_set_eap_methods__descriptor;
extern int wifi_scan_config__descriptor;
extern int udp_netif_ip_addr_changed;
extern int _putchar_r;
extern int mbedtls_gcm_auth_decrypt_soft;
extern int regi2c_ctrl_read_reg_mask;
extern int mipi_dsi_hal_host_dpi_set_color_coding;
extern int _asprintf_r;
extern int esp_restart_noos;
extern int rpc__resp__wifi_set_country__init;
extern int rtc_clk_cal;
extern int __ieee754_rem_pio2;
extern int esp_wifi_get_if_mac;
extern int raw_bind_netif;
extern int mbedtls_ecp_check_pub_priv;
extern int esp_vfs_fcntl_r;
extern int __ctzsi2;
extern int clk_hal_soc_root_get_freq_mhz;
extern int esp_task_wdt_reset;
extern int i2s_get_source_clk_freq;
extern int esp_transport_tcp_set_interface_name;
extern int linenoiseHistorySetMaxLen;
extern int rpc__req__eap_clear_password__descriptor;
extern int pbuf_free_ooseq_pending;
extern int gpio_isr_handler_add;
extern int mbedtls_ssl_set_calc_verify_md;
extern int serial_handle;
extern int gpio_isr_handler_remove;
extern int mbedtls_ssl_handshake_wrapup;
extern int _Bfree;
extern int _isatty_r;
extern int mbedtls_ecp_get_type;
extern int lwip_listen;
extern int hosted_get_time_ms;
extern int mbedtls_pk_sign_restartable;
extern int tcp_process_refused_data;
extern int rpc__req__wifi_sta_itwt_teardown__init;
extern int rpc__req__wifi_sta_get_negotiated_phymode__descriptor;
extern int _sfread_r;
extern int lwip_accept;
extern int rpc__resp__wifi_set_config__init;
extern int lwip_setsockopt_impl_ext;
extern int vListInitialise;
extern int esp_aes_setkey;
extern int ip6addr_aton;
extern int __tzcalc_limits;
extern int sdmmc_host_init;
extern int hosted_sdio_card_deinit;
extern int mbedtls_ssl_write_handshake_msg_ext;
extern int heap_caps_malloc_default;
extern int rpc__resp__eap_set_certificate_and_key__init;
extern int linenoiseEditInsert;
extern int g_twdt_isr;
extern int mbedtls_x509_get_sig_alg;
extern int rpc_slaveif_wifi_set_mode;
extern int call_start_cpu1;
extern int http_parser_init;
extern int raw_sendto_if_src;
extern int esp_tls_conn_read;
extern int bsp_input_get_queue;
extern int ip6_select_source_address;
extern int linenoiseHistoryAdd;
extern int usb_serial_jtag_vfs_include_dev_init;
extern int mbedtls_cipher_finish;
extern int esp_cache_suspend_ext_mem_cache;
extern int arg_dstr_catf;
extern int __default_global_locale;
extern int es8156_write_analog_system_1;
extern int mbedtls_ecp_point_read_binary;
extern int _ZN3nvs11PageManager14requestNewPageEv;
extern int rpc__req__wifi_set_max_tx_power__descriptor;
extern int mbedtls_x509_get_rsassa_pss_params;
extern int esp_transport_close;
extern int mbedtls_ecp_point_free;
extern int hosted_queue_msg_waiting;
extern int rpc__req__otawrite__descriptor;
extern int rpc__resp__wifi_set_country__descriptor;
extern int linenoiseSetHintsCallback;
extern int hosted_restart_host;
extern int esp_intr_alloc;
extern int i2s_hal_std_set_tx_slot;
extern int raw_new;
extern int esp_mmu_map_reserve_block_with_caps;
extern int esprv_int_set_vectored;
extern int pxCurrentTCBs;
extern int ip4_output_if_src;
extern int rpc__req__eap_clear_ca_cert__init;
extern int ethbroadcast;
extern int rpc__event__sta_scan_done__descriptor;
extern int wifi_he_ap_info__descriptor;
extern int setup_transport;
extern int esp_time_impl_get_time;
extern int _C_time_locale;
extern int hosted_unlock_mutex;
extern int xRingbufferReceiveUpToFromISR;
extern int rpc__req__wifi_scan_get_ap_records__init;
extern int xTaskGetIdleTaskHandleForCore;
extern int mbedtls_ctr_drbg_init;
extern int esp_flash_default_chip;
extern int bootloader_read_flash_id;
extern int sdmmc_send_cmd_select_card;
extern int cmd_testgfx;
extern int mbedtls_ssl_get_hostname_pointer;
extern int rpc_wifi_stop;
extern int rpc__event__sta_itwt_suspend__descriptor;
extern int gdma_ahb_hal_connect_peri;
extern int spi_flash_enable_cache;
extern int es8156_write_p2s_control;
extern int gdma_del_channel;
extern int rgb_display_set_vga_palette;
extern int esp_md5_free;
extern int esp_crypto_ds_enable_periph_clk;
extern int panic_prepare_frame_from_ctx;
extern int hosted_sdio_read_block;
extern int esp_intr_enable;
extern int esp_transport_ssl_set_client_key_data;
extern int rgb_gfx_hline;
extern int efuse_hal_flash_encryption_enabled;
extern int sdmmc_send_cmd_crc_on_off;
extern int _ZN3nvs4Page8readItemEhNS_8ItemTypeEPKcPvjhNS_9VerOffsetE;
extern int dhcp_parse_extra_opts;
extern int panic_print_hex;
extern int SysTickIsrHandler;
extern int strcat;
extern int __lock___arc4random_mutex;
extern int rpc__resp__wifi_set_protocols__init;
extern int sdmmc_io_init_read_card_cap;
extern int littlefs_esp_part_read;
extern int mbedtls_ssl_get_ecp_group_id_from_tls_id;
extern int hosted_sdio_wait_slave_intr;
extern int adler32;
extern int spi_flash_op_lock;
extern int memp_init;
extern int rpc__resp__eap_clear_username__descriptor;
extern int mbedtls_rsa_free;
extern int rpc__resp__wifi_get_max_tx_power__descriptor;
extern int heap_caps_get_info;
extern int nd6_get_destination_mtu;
extern int mbedtls_asn1_get_bitstring_null;
extern int rpc_slaveif_wifi_sta_get_ap_info;
extern int __ssrefill_r;
extern int spi_flash_guard_set;
extern int rpc__resp__supp_dpp_bootstrap_gen__init;
extern int ecc_hal_start_calc;
extern int rtc_clk_cal_internal;
extern int esp_netif_netstack_buf_ref;
extern int sdmmc_init_csd;
extern int mbedtls_ctr_drbg_seed;
extern int mmu_hal_unmap_region;
extern int lwip_netconn_do_delconn;
extern int esp_http_client_init;
extern int rtc_clk_freq_to_period;
extern int rv_utils_dbgr_is_attached;
extern int spi_flash_chip_winbond_read;
extern int rpc__req__wifi_set_band__init;
extern int __muldf3;
extern int mbedtls_ssl_write_change_cipher_spec;
extern int esp_aes_gcm_free;
extern int i2s_check_set_mclk;
extern int _ZNK3nvs4Item26calculateCrc32WithoutValueEv;
extern int lwip_read;
extern int esp_create_mbedtls_handle;
extern int heap_caps_malloc_prefer;
extern int esp_littlefs_info;
extern int mbedtls_sha1_free;
extern int sdmmc_check_host_function_ptr_integrity;
extern int esp_system_get_time;
extern int mbedtls_rsa_complete;
extern int rpc__event__espinit__init;
extern int sys_mutex_unlock;
extern int udp_bind;
extern int es8156_write_time_control_2;
extern int esp_flash_registered_chips;
extern int __wrap_readdir;
extern int esp_flash_read;
extern int ESP_HOSTED_EVENT;
extern int http_parser_pause;
extern int strtoul_l;
extern int rpc__req__wifi_set_bandwidths__init;
extern int tcp_backlog_accepted;
extern int rpc__event__wifi_dpp_uri_ready__init;
extern int compose_tlv;
extern int _lock_release_recursive;
extern int rpc__resp__otabegin__init;
extern int _daylight;
extern int multi_heap_aligned_alloc_offs;
extern int breezy_p4_export_symbols;
extern int rpc__req__mem_monitor__init;
extern int g_wifi_default_wpa_crypto_funcs;
extern int rpc__resp__wifi_set_okc_support__init;
extern int mbedtls_md_hmac_reset;
extern int esp_mspi_32bit_address_flash_feature_check;
extern int optind;
extern int mbedtls_ssl_parse_server_name_ext;
extern int esp_timer_init_include_func;
extern int rpc__event__ap__sta_disconnected__descriptor;
extern int mbedtls_ecp_check_pubkey;
extern int cJSON_GetArrayItem;
extern int sdmmc_send_cmd_set_relative_addr;
extern int rpc__resp__otabegin__descriptor;
extern int rpc__resp__wifi_get_bandwidths__init;
extern int sdmmc_init_mmc_read_ext_csd;
extern int esp_log_linked_list_clean;
extern int httpd_req_recv;
extern int mbedtls_aria_crypt_ctr;
extern int __env_unlock;
extern int tlsf_check_pool;
extern int httpd_sess_init;
extern int esp_transport_utils_ms_to_timeval;
extern int mbedtls_mpi_lset;
extern int rpc__resp__eap_set_suiteb192bit_certification__init;
extern int esp_md5_init;
extern int rpc__req__otabegin__descriptor;
extern int gdma_ahb_hal_enable_etm_task;
extern int rtc_clk_32k_enable;
extern int i2s_alloc_dma_desc;
extern int __subdf3;
extern int panic_print_str;
extern int esp_hosted_sdio_get_config;
extern int bsp_power_initialize;
extern int rpc__resp__eap_set_ttls_phase2_method__init;
extern int __sclose;
extern int __wrap___cxa_allocate_exception;
extern int tcp_free;
extern int mbedtls_ssl_get_mode_from_ciphersuite;
extern int mbedtls_asn1_get_tag;
extern int vterm_input_flush;
extern int rpc__req__wifi_set_country__descriptor;
extern int mpi_hal_disable_hardware_hw_op;
extern int mipi_dsi_hal_host_dpi_set_horizontal_timing;
extern int mempool_free;
extern int mbedtls_pk_setup;
extern int wifi_bss_max_idle_config__init;
extern int rpc__req__wifi_scan_stop__descriptor;
extern int mbedtls_ecdh_get_params;
extern int esp_tls_get_error_handle;
extern int protobuf_c_message_get_packed_size;
extern int lfs_format;
extern int rpc__resp__gpio_get_level__init;
extern int sdmmc_init_sd_timing_tuning;
extern int rpc__resp__wifi_scan_get_ap_records__descriptor;
extern int littlefs_esp_part_sync;
extern int bsp_i2c_primary_bus_get_handle;
extern int _ZdaPv;
extern int gdma_axi_hal_append;
extern int rpc__resp__supp_dpp_deinit__descriptor;
extern int mbedtls_rsa_parse_pubkey;
extern int mbedtls_ssl_get_mode_from_transform;
extern int esp_transport_ssl_set_alpn_protocol;
extern int mbedtls_x509_get_name;
extern int i2s_hal_calc_mclk_precise_division;
extern int _timezone;
extern int rpc__resp__wifi_sta_itwt_setup__init;
extern int __mprec_tens;
extern int netconn_err;
extern int tcp_input_pcb;
extern int sys_thread_sem_init;
extern int esp_log_util_set_cache_enabled_cb;
extern int raw_send;
extern int rpc__resp__wifi_start__descriptor;
extern int esp_vfs_select_triggered;
extern int __truncdfsf2;
extern int tcsetattr;
extern int cJSON_ParseWithLengthOpts;
extern int mbedtls_ssl_write_finished;
extern int rpc__req__wifi_get_country__descriptor;
extern int dhcp_fine_tmr;
extern int esp_log_timestamp;
extern int esp_sha_release_hardware;
extern int dhcp_network_changed_link_up;
extern int esp_clk_tree_rc_fast_get_freq_hz;
extern int esp_efuse_startup_include_func;
extern int heap_info__init;
extern int netconn_join_leave_group;
extern int lfs_crc;
extern int rpc__resp__eap_set_domain_name__init;
extern int lwip_inet_ntop;
extern int rpc__req__wifi_sta_enterprise_disable__descriptor;
extern int spi_flash_enable_interrupts_caches_and_other_cpu;
extern int lwip_netconn_do_write;
extern int regi2c_ctrl_write_reg;
extern int mbedtls_ssl_read;
extern int i2s_platform_acquire_occupation;
extern int esp_cache_resume_ext_mem_cache;
extern int pbuf_cat;
extern int ulTaskGenericNotifyTake;
extern int multi_heap_realloc_impl;
extern int mspi_timing_config_psram_read_data;
extern int rpc__resp__eap_clear_password__init;
extern int httpd_resp_set_type;
extern int rpc__event__sta_itwt_teardown__descriptor;
extern int gpio_get_level;
extern int vterm_enter_graphics_mode;
extern int esp_event_loop_run;
extern int gpio_hold_dis;
extern int httpd_sess_get_free;
extern int tcp_free_ooseq;
extern int _ZN3nvs15NVSHandleSimple14get_typed_itemENS_8ItemTypeEPKcPvj;
extern int dns_mquery_v6group;
extern int pbuf_clen;
extern int __kernel_cos;
extern int rpc__req__wifi_get_config__init;
extern int GPIO_HOLD_MASK;
extern int http_parser_settings_init;
extern int gzerror;
extern int mbedtls_ssl_transform_free;
extern int sdmmc_mmc_enable_hs_mode;
extern int mempool_create;
extern int _Znaj;
extern int rpc_core_start;
extern int esp_lcd_panel_reset;
extern int esp_vfs_usb_serial_jtag_use_driver;
extern int mbedtls_mpi_core_write_be;
extern int mbedtls_x509_crt_parse_cn_inet_pton;
extern int esp_mbedtls_conn_delete;
extern int vPortTCBPreDeleteHook;
extern int rpc__event__wifi_dpp_cfg_recvd__init;
extern int spi_flash_chip_generic_config_host_io_mode;
extern int atoi;
extern int gpio_intr_enable;
extern int _fputs_r;
extern int _ZN3nvs19NVSPartitionManager16deinit_partitionEPKc;
extern int aes_hal_gcm_init;
extern int rgb_gfx_rectfill;
extern int mbedtls_ecp_point_init;
extern int gdma_hal_enable_access_encrypt_mem;
extern int mbedtls_mpi_random;
extern int nd6_clear_destination_cache;
extern int gdma_ahb_hal_read_intr_status;
extern int mbedtls_mpi_core_sub_int;
extern int rpc__resp__eap_set_certificate_and_key__descriptor;
extern int ESP_LITTLEFS_TAG;
extern int rpc__event__sta_itwt_probe__descriptor;
extern int mbedtls_ecp_tls_read_point;
extern int esp_transport_ssl_set_keep_alive;
extern int mbedtls_rsa_parse_key;
extern int _ZN3nvs7Storage26eraseMismatchedBlobIndexesER14intrusive_listINS0_13BlobIndexNodeEE;
extern int vPortYieldFromISR;
extern int spi_flash_munmap;
extern int tanmatsu_keyboard_start;
extern int __ieee754_rem_pio2f;
extern int usb_serial_jtag_driver_install;
extern int soc_get_available_memory_regions;
extern int esp_pthread_set_cfg;
extern int rpc_id__descriptor;
extern int esp_netif_get_event_id;
extern int tcp_pcb_purge;
extern int mbedtls_pem_init;
extern int mbedtls_oid_get_cipher_alg;
extern int mspi_timing_psram_init;
extern int mbedtls_aria_setkey_enc;
extern int __fixunsdfsi;
extern int mbedtls_ssl_update_handshake_status;
extern int mbedtls_cipher_set_iv;
extern int rpc__resp__wifi_sta_itwt_get_flow_id_status__init;
extern int esp_intr_alloc_intrstatus_bind;
extern int prvTaskCreateDynamicPinnedToCoreWithCaps;
extern int strftime;
extern int gdma_ahb_hal_set_crc_poly;
extern int i2s_hal_std_set_rx_slot;
extern int httpd_unrecv;
extern int rpc__req__wifi_set_config__init;
extern int mbedtls_pem_read_buffer;
extern int spi_flash_hal_check_status;
extern int igmp_report_groups;
extern int __trunctfdf2;
extern int __wrap_remove;
extern int esp_sha_write_digest_state;
extern int esp_netif_get_ifkey;
extern int xQueueCreateWithCaps;
extern int rpc__req__eap_set_username__init;
extern int ets_isr_mask;
extern int rgb_display_get_fb_width;
extern int _sprintf_r;
extern int esp_deregister_freertos_idle_hook_for_cpu;
extern int mbedtls_md5;
extern int rtos_save_fpu_coproc;
extern int sdmmc_host_do_transaction;
extern int esp_vfs_register_common;
extern int usb_serial_jtag_vfs_register;
extern int esp_console_cmd_register;
extern int rpc__resp__wifi_set_band__descriptor;
extern int opendir;
extern int port_uxCoprocOwner;
extern int spi_flash_hal_gpspi_configure_host_io_mode;
extern int esp_rtc_get_time_us;
extern int optopt;
extern int rgb_gfx_clear;
extern int sqrtf;
extern int cmd_more;
extern int __cxx_init_dummy;
extern int regdma_link_new_branch_write_default;
extern int tcp_eff_send_mss_netif;
extern int tcdrain;
extern int pthread_setspecific;
extern int rpc__resp__eap_get_disable_time_check__init;
extern int mbedtls_pkcs5_pbes2_ext;
extern int rtc_gpio_pullup_en;
extern int httpd_sess_free_ctx;
extern int mbedtls_ssl_reset_in_pointers;
extern int clk_hal_lp_slow_get_freq_hz;
extern int __wrap__Unwind_DeleteException;
extern int sdmmc_flip_byte_order;
extern int spi_flash_hal_gpspi_supports_direct_write;
extern int gdma_hal_get_lfsr_mask_from_matrix;
extern int rpc__resp__wifi_set_max_tx_power__init;
extern int _freopen_r;
extern int sdmmc_init_sd_driver_strength;
extern int sdmmc_init_mmc_decode_cid;
extern int regdma_link_new_addr_map_default;
extern int wifi_bss_max_idle_config__descriptor;
extern int ecc_hal_read_mul_result;
extern int realpath;
extern int spi_flash_hal_device_config;
extern int vTaskSuspend;
extern int esp_tls_get_and_clear_error_type;
extern int rpc__event__supp_dpp_uri_ready__init;
extern int esp_ds_get_keylen;
extern int fwrite;
extern int strspn;
extern int esp_transport_ssl_init;
extern int rpc__req__wifi_connect__descriptor;
extern int rtc_gpio_pullup_dis;
extern int es8156_write_volume_control;
extern int sdmmc_init_card_hs_mode;
extern int _ZN3nvs19NVSPartitionManager11init_customEPNS_9PartitionEmm;
extern int esp_cache_err_get_cpuid;
extern int _ZN3nvs4Page14alterPageStateENS0_9PageStateE;
extern int regdma_link_new_addr_map;
extern int rpc__resp__eap_clear_identity__init;
extern int esp_libc_include_reent_syscalls_impl;
extern int wdt_hal_deinit;
extern int _svfprintf_r;
extern int lcd_periph_rgb_signals;
extern int xIsrStackTop;
extern int _ZN3nvs4Page6Header14calculateCrc32Ev;
extern int spi_flash_hal_configure_host_io_mode;
extern int hosted_timer_stop;
extern int sdmmc_host_set_bus_width;
extern int linenoiseAddCompletion;
extern int heap_caps_init;
extern int pbuf_take_at;
extern int gzclose_w;
extern int raw_new_ip_type;
extern int rpc__resp__gpio_set_pull_mode__init;
extern int tlsf_get_pool;
extern int puts;
extern int pbuf_clone;
extern int _i2s_hal_set_rx_clock;
extern int tlsf_pool_overhead;
extern int udp_new_ip_type;
extern int vsnprintf;
extern int bmi270_feat_out;
extern int rpc__req__eap_set_ca_cert__descriptor;
extern int rpc__req__wifi_disconnect__init;
extern int linenoiseEditMoveHome;
extern int mbedtls_mpi_exp_mod;
extern int esp_tls_get_bytes_avail;
extern int lfs_fs_grow;
extern int __retarget_lock_acquire_recursive;
extern int _ZNSt9type_infoD1Ev;
extern int esp_log_linked_list_set_level;
extern int _mtvt_table;
extern int _ZN3nvs7Storage17readMultiPageBlobEhPKcPvj;
extern int strlcpy;
extern int getopt_long;
extern int fopen;
extern int port_xSchedulerRunning;
extern int rpc__resp__gpio_set_direction__descriptor;
extern int rpc__req__custom_rpc__descriptor;
extern int _fread_r;
extern int rpc__resp__wifi_scan_params__init;
extern int rpc__req__eap_set_suiteb192bit_certification__init;
extern int __errno;
extern int multi_heap_get_allocated_size;
extern int esp_tls_conn_destroy;
extern int bmi2_sec_init;
extern int hci_drv_show_configuration;
extern int spi_flash_chip_generic_erase_block;
extern int tcp_rst_netif;
extern int bmi2_get_feat_config;
extern int _ZN3nvs7Storage8findItemEhNS_8ItemTypeEPKcRPNS_4PageERNS_4ItemEhNS_9VerOffsetE;
extern int dw_gdma_del_link_list;
extern int _strtoul_r;
extern int sdmmc_init_sd_bus_width;
extern int _sscanf_r;
extern int mbedtls_mpi_core_mla;
extern int mbedtls_sha512_clone;
extern int rpc__req__wifi_set_band_mode__init;
extern int rpc__resp__config_heartbeat__init;
extern int gdma_ahb_hal_enable_intr;
extern int igmp_start;
extern int mbedtls_mpi_get_bit;
extern int spi_flash_timing_is_tuned;
extern int rpc__req__wifi_set_protocol__descriptor;
extern int lwip_netconn_do_send;
extern int mbedtls_ssl_config_init;
extern int periph_rcc_release_exit;
extern int _i2c_hal_init;
extern int getc;
extern int sdmmc_init_sd_scr;
extern int mbedtls_ssl_get_bytes_avail;
extern int esp_ipc_call_nonblocking;
extern int rpc__req__wifi_set_okc_support__descriptor;
extern int esp_netif_transmit_wrap;
extern int http_header_get_item;
extern int deflateEnd;
extern int httpd_sess_trigger_close_;
extern int mbedtls_cipher_auth_encrypt_ext;
extern int rpc__resp__wifi_get_inactive_time__descriptor;
extern int rpc__resp__supp_dpp_stop_listen__init;
extern int mbedtls_asn1_get_int;
extern int mbedtls_rsa_rsassa_pkcs1_v15_verify;
extern int tanmatsu_coprocessor_get_pmic_faults;
extern int rpc__resp__eap_set_ttls_phase2_method__descriptor;
extern int strtoull_l;
extern int multi_heap_get_allocated_size_impl;
extern int _ZN3nvs4Page5eraseEv;
extern int tcp_segs_free;
extern int esp_crypto_base64_encode;
extern int spi_flash_chip_generic_read;
extern int esp_partition_is_flash_region_writable;
extern int mbedtls_ecdh_init;
extern int xRingbufferReceiveUpTo;
extern int esp_mbedtls_cleanup;
extern int rpc__resp__iface_mac_addr_len_get__init;
extern int esp_lcd_panel_draw_bitmap;
extern int mkdir;
extern int rpc__resp__wifi_init__init;
extern int io_mux_force_disable_lp_io_clock;
extern int sdmmc_mmc_decode_csd;
extern int gdma_hal_set_burst_size;
extern int mbedtls_net_free;
extern int esp_sha_dma_start;
extern int esp_netif_new;
extern int _ZN3nvs8HashListC1Ev;
extern int __divdf3;
extern int _ZN3nvs8HashList4findEjRKNS_4ItemE;
extern int mbedtls_mpi_core_uint_le_mpi;
extern int getopt_long_only;
extern int netif_ip6_addr_set_state;
extern int _ZN3nvs12NVSPartition18get_partition_nameEv;
extern int igmp_joingroup_netif;
extern int rpc__resp__gpio_input_enable__descriptor;
extern int mbedtls_cipher_info_from_type;
extern int esp_netif_remove_from_list_unsafe;
extern int pbuf_put_at;
extern int esp_netif_dhcpc_get_status;
extern int tcp_send_fin;
extern int mbedtls_x509_crt_check_extended_key_usage;
extern int siscanf;
extern int esp_security_init_include_impl;
extern int tcp_rexmit_rto_prepare;
extern int pmu_lp_system_power_param_default;
extern int putc;
extern int esp_log;
extern int mbedtls_mpi_core_write_le;
extern int gzwrite;
extern int s_microseconds_offset;
extern int rpc_slaveif_start;
extern int mbedtls_ssl_start_renegotiation;
extern int _strtoull_r;
extern int tcp_bound_pcbs;
extern int rpc__resp__set_mac_address__descriptor;
extern int esp_clk_tree_lp_fast_get_freq_hz;
extern int rgb_gfx_pixel;
extern int esp_pm_lock_acquire;
extern int mbedtls_ecp_grp_id_list;
extern int memp_IGMP_GROUP;
extern int gdma_ahb_hal_stop;
extern int gdma_ahb_hal_get_intr_status_reg;
extern int sdmmc_init_rca;
extern int _ZN3nvs15NVSHandleSimple9erase_allEv;
extern int esp_transport_tcp_set_keep_alive;
extern int httpd_uri_match_wildcard;
extern int ecc_hal_read_verify_result;
extern int tcp_ticks;
extern int esp_aes_xts_setkey_dec;
extern int mbedtls_pk_can_do;
extern int regdma_find_next_module_link_head;
extern int ferror;
extern int tcp_trigger_input_pcb_close;
extern int __getopt_long_r;
extern int soc_mipi_dsi_phy_pll_ranges;
extern int snprintf;
extern int mbedtls_ssl_write_client_hello;
extern int etharp_input;
extern int spi_flash_guard_get;
extern int tcp_close_ext;
extern int _ZN3nvs11PageManager4loadEPNS_9PartitionEmm;
extern int rpc_slaveif_init;
extern int raw_connect;
extern int tcp_recv;
extern int gdma_ahb_hal_start_with_desc;
extern int rpc_start;
extern int __month_lengths;
extern int eTaskGetState;
extern int mbedtls_ssl_hash_from_md_alg;
extern int eap_fast_config__descriptor;
extern int lwip_getaddrinfo;
extern int lwip_getpeername;
extern int __lock___atexit_recursive_mutex;
extern int esp_log_cache_add;
extern int rpc__gpio_config__descriptor;
extern int _ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE;
extern int esp_timer_impl_early_init;
extern int es8156_write_clock_off;
extern int rpc__req__wifi_clear_ap_list__init;
extern int rpc__req__eap_set_identity__descriptor;
extern int xPortSwitchFlag;
extern int fcntl;
extern int __cxa_begin_catch;
extern int rpc__resp__wifi_set_band_mode__descriptor;
extern int multi_heap_internal_unlock;
extern int _lseek_r;
extern int gpio_pullup_en;
extern int rpc__req__config_heartbeat__descriptor;
extern int rpc__resp__eap_clear_ca_cert__init;
extern int _strtoll_r;
extern int _ZN3nvs7Storage21createOrOpenNamespaceEPKcbRh;
extern int spi_flash_chip_list_check;
extern int rpc__resp__wifi_set_bandwidths__init;
extern int memp_ND6_QUEUE;
extern int access;
extern int spi_flash_chip_generic_read_unique_id;
extern int mbedtls_pk_init;
extern int gdma_hal_set_strategy;
extern int _vector_table;
extern int heap_caps_get_allocated_size;
extern int esp_panic_handler_increment_entry_count;
extern int _findenv_r;
extern int mbedtls_ssl_parse_change_cipher_spec;
extern int xTaskCheckForTimeOut;
extern int rpc__req__wifi_set_protocol__init;
extern int __retarget_lock_try_acquire;
extern int esp_cpu_set_breakpoint;
extern int dma2d_rx_channel_reserved_mask;
extern int hosted_get_host_wakeup_or_reboot_reason;
extern int gdma_register_tx_event_callbacks;
extern int mbedtls_rsa_pkcs1_encrypt;
extern int pthread_attr_init;
extern int vTaskGenericNotifyGiveFromISR;
extern int esp_mbedtls_write;
extern int i2c_periph_signal;
extern int usb_serial_jtag_connection_monitor_include;
extern int rpc__req__eap_set_pac_file__descriptor;
extern int sdmmc_mmc_switch;
extern int tcpip_api_call;
extern int ds_hal_busy;
extern int rgb_gfx_vline;
extern int vRingbufferReturnItemFromISR;
extern int xTaskIncrementTick;
extern int cache_hal_suspend;
extern int rpc__req__wifi_sta_twt_config__init;
extern int sleep_retention_entries_create;
extern int hosted_write_gpio;
extern int tcp_enqueue_flags;
extern int lwip_fcntl;
extern int http_header_delete;
extern int _raise_r;
extern int rpc__event__dhcp_dns_status__descriptor;
extern int hosted_post_semaphore_from_isr;
extern int dhcp_release;
extern int mbedtls_rsa_rsassa_pkcs1_v15_sign;
extern int lfs_file_truncate;
extern int vSemaphoreDeleteWithCaps;
extern int sdmmc_host_deinit_slot;
extern int vterm_get_palette;
extern int __kernel_sinf;
extern int _ZN3nvs4LockC1Ev;
extern int __ledf2;
extern int serial_drv_close;
extern int gpio_set_level;
extern int esp_heap_adjust_alignment_to_hw;
extern int esp_gpio_reserve;
extern int rpc_type__descriptor;
extern int pmu_hp_system_init;
extern int esp_event_handler_unregister;
extern int usb_serial_jtag_is_driver_installed;
extern int rpc__resp__eap_use_default_cert_bundle__init;
extern int rpc__resp__wifi_get_protocol__descriptor;
extern int _getenv_r;
extern int mbedtls_mpi_grow;
extern int lp_gpio_connect_out_signal;
extern int i2s_gpio_check_and_set;
extern int mbedtls_ecp_mul_restartable;
extern int spi_flash_hal_gpspi_supports_direct_read;
extern int rpc__resp__app_get_desc__descriptor;
extern int rgb_display_set_callbacks;
extern int rpc__resp__eap_set_new_password__init;
extern int mspi_timing_config_psram_set_tuning_phase;
extern int __floatsidf;
extern int _fopen_r;
extern int esp_timer_stop;
extern int ecc_hal_write_mul_param;
extern int rpc__resp__otaend__init;
extern int hosted_destroy_queue;
extern int esp_system_reset_modules_on_exit;
extern int __lshrdi3;
extern int mpi_hal_write_to_mem_block;
extern int mbedtls_ct_memcpy_offset;
extern int rpc__resp__wifi_sta_itwt_suspend__init;
extern int rpc__req__ext_coex__init;
extern int rpc__resp__eap_clear_identity__descriptor;
extern int rpc__req__wifi_sta_itwt_get_flow_id_status__descriptor;
extern int _ZN3nvs7Storage18eraseMultiPageBlobEhPKcNS_9VerOffsetE;
extern int wifi_itwt_setup_config__descriptor;
extern int esp_mmu_map;
extern int heap_caps_aligned_alloc_base;
extern int mbedtls_oid_get_oid_by_md;
extern int __submore;
extern int hosted_dequeue_item;
extern int mbedtls_ssl_get_tls_id_from_ecp_group_id;
extern int panic_arch_fill_info;
extern int int_wdt_cpu1_ticked;
extern int heap_caps_aligned_alloc;
extern int rpc_wifi_scan_get_ap_num;
extern int dma2d_release_pool;
extern int gpio_iomux_output;
extern int bus_handle;
extern int gdma_axi_hal_set_strategy;
extern int mbedtls_mpi_core_read_be;
extern int mbedtls_eckey_info;
extern int _ZN10__cxxabiv120__si_class_type_infoD1Ev;
extern int esp_event_post;
extern int rpc__req__eap_get_disable_time_check__descriptor;
extern int mbedtls_mpi_mul_mpi;
extern int vPortExitCriticalMultiCore;
extern int mbedtls_x509_crt_parse_der;
extern int hosted_thread_cancel;
extern int mbedtls_base64_decode;
extern int rpc__req__wifi_scan_stop__init;
extern int rpc__req__otabegin__init;
extern int bsearch;
extern int rtc_clk_slow_freq_get_hz;
extern int netbuf_delete;
extern int gdma_axi_hal_enable_access_encrypt_mem;
extern int esp_vfs_select;
extern int s_get_cache_state;
extern int mpi_hal_read_result_hw_op;
extern int _ZN14NVSHandleEntry17s_nvs_next_handleE;
extern int rpc__resp__wifi_clear_ap_list__init;
extern int gdma_connect;
extern int mbedtls_ssl_config_free;
extern int nd6_restart_netif;
extern int esp_lcd_new_panel_st7701_mipi;
extern int rpc__req__wifi_sta_get_negotiated_phymode__init;
extern int etharp_remove_static_entry;
extern int __gethex;
extern int mld6_tmr;
extern int esp_hw_stack_guard_get_fired_cpu;
extern int mbedtls_ssl_fetch_input;
extern int lwip_ioctl;
extern int memchr;
extern int sys_thread_tcpip;
extern int _ZN10__cxxabiv111__terminateEPFvvE;
extern int netif_set_default;
extern int gdma_hal_get_intr_status_reg;
extern int xQueueGenericSend;
extern int mbedtls_ecp_group_free;
extern int __b2d;
extern int rtc_gpio_is_valid_gpio;
extern int _ungetc_r;
extern int cmd_eget;
extern int rpc__req__ext_coex__descriptor;
extern int vterm_input_feed;
extern int rpc__resp__eap_clear_ca_cert__descriptor;
extern int port_uxOldInterruptState;
extern int mbedtls_rsa_import_raw;
extern int wlanif_input;
extern int _fflush_r;
extern int esp_transport_connect;
extern int sys_timeout;
extern int esp_vfs_lseek;
extern int panic_print_backtrace;
extern int rpc__req__wifi_clear_ap_list__descriptor;
extern int rpc__req__wifi_get_bandwidths__descriptor;
extern int hosted_queue_item;
extern int write;
extern int mbedtls_ssl_write_certificate;
extern int mbedtls_ecdh_gen_public;
extern int mbedtls_oid_get_md_hmac;
extern int strcasecmp;
extern int rpc__resp__wifi_sta_twt_config__init;
extern int __ascii_mbtowc;
extern int __ffsdi2;
extern int vfprintf;
extern int rtc_gpio_set_direction;
extern int __swbuf_r;
extern int httpd_sess_process;
extern int vPortYield;
extern int tcpip_init;
extern int rpc__resp__wifi_set_bandwidth__init;
extern int mbedtls_sha1_finish;
extern int esp_aes_acquire_hardware;
extern int netconn_write_vectors_partly;
extern int mbedtls_md_setup;
extern int gpio_pulldown_en;
extern int mbedtls_x509_parse_subject_alt_name;
extern int esp_ipc_func;
extern int wifi_country__init;
extern int etharp_cleanup_netif;
extern int inflate_table;
extern int esp_vfs_link;
extern int lcd_com_register_device;
extern int mbedtls_rsa_init;
extern int rpc__resp__gpio_config__descriptor;
extern int mbedtls_mpi_lsb;
extern int pthread_join;
extern int rpc__event__ap__sta_connected__descriptor;
extern int esp_async_fbcpy_uninstall;
extern int mbedtls_ssl_update_in_pointers;
extern int usb_serial_jtag_vfs_use_driver;
extern int mbedtls_ssl_parse_finished;
extern int __env_lock;
extern int hosted_get_semaphore;
extern int hosted_memcpy;
extern int usb_serial_jtag_driver_uninstall;
extern int __hexdig_fun;
extern int esp_vfs_closedir;
extern int wifi_sta_config__init;
extern int wifi_scan_time__descriptor;
extern int esp_log_is_tag_loggable;
extern int mbedtls_ssl_conf_rng;
extern int esp_cpu_compare_and_set;
extern int esp_timer_start_periodic;
extern int sdmmc_host_dma_prepare;
extern int esp_aes_xts_setkey_enc;
extern int dns_setserver;
extern int lwip_write;
extern int rtc_clk_apb_freq_get;
extern int ungetc;
extern int esp_mbedtls_verify_certificate;
extern int MPI_OPERATIONS_REG;
extern int nvs_get_str;
extern int cos;
extern int pmu_hp_system_digital_param_default;
extern int xQueueReceive;
extern int mbedtls_oid_get_md_alg;
extern int esp_http_client_get_status_code;
extern int __nedf2;
extern int mbedtls_sha1_update;
extern int __ssvfscanf_r;
extern int mbedtls_md_info_from_type;
extern int mbedtls_ssl_get_output_max_frag_len;
extern int rpc__req__wifi_ap_get_sta_list__descriptor;
extern int __swsetup_r;
extern int lwip_netconn_do_recv;
extern int linenoiseEditDelete;
extern int ip6_output_if;
extern int rpc__resp__wifi_ap_get_sta_list__descriptor;
extern int mbedtls_cipher_reset;
extern int mbedtls_pk_free;
extern int wifi_itwt_setup_config__init;
extern int udp_recv;
extern int rpc__req__eap_clear_new_password__descriptor;
extern int ip6_route;
extern int i2s_platform_release_occupation;
extern int _ZN3nvs7Storage9eraseItemEhNS_8ItemTypeEPKc;
extern int _fseeko_r;
extern int gzopen;
extern int mbedtls_ecdsa_read_signature_restartable;
extern int memspi_host_read_data_slicer;
extern int mspi_timing_flash_tuning;
extern int es8156_write_register;
extern int mbedtls_ssl_set_timer;
extern int cache_hal_vaddr_to_cache_level_id;
extern int esp_intr_noniram_disable;
extern int tlsf_free;
extern int spi_flash_hal_common_command;
extern int esp_console_rm_item_free_hint;
extern int _ZN3nvs15NVSHandleSimple13get_item_sizeENS_8ItemTypeEPKcRj;
extern int wifi_sta_list__init;
extern int usb_serial_jtag_wait_tx_done;
extern int _impure_ptr;
extern int esp_app_desc__descriptor;
extern int rpc__req__get_mac_address__init;
extern int power_supply_periph_signal;
extern int httpd_sess_enum;
extern int sdmmc_send_cmd_send_csd;
extern int rpc__event__sta_itwt_teardown__init;
extern int mbedtls_rsa_deduce_private_exponent;
extern int __sfp_lock_acquire;
extern int esp_ipc_isr_handler;
extern int esp_lcd_panel_io_rx_param;
extern int heap_caps_malloc_base;
extern int mbedtls_mpi_safe_cond_assign;
extern int lwip_getsockopt_impl_ext;
extern int tcpip_callback;
extern int cmd_df;
extern int _fgetc_r;
extern int ip_addr_any;
extern int _mbrtowc_r;
extern int arg_print_formatted;
extern int pthread_create;
extern int _setlocale_r;
extern int pbuf_get_at;
extern int pthread_include_pthread_semaphore_impl;
extern int chan_arr;
extern int rpc__resp__wifi_get_config__descriptor;
extern int pvTaskIncrementMutexHeldCount;
extern int lwip_netconn_do_newconn;
extern int mbedtls_ecp_point_write_binary;
extern int gettimeofday;
extern int sdmmc_io_read_bytes;
extern int mbedtls_pk_get_type;
extern int rpc__req__wifi_set_channel__init;
extern int st7701_get_panel;
extern int esp_transport_destroy;
extern int bsp_orientation_initialize;
extern int esp_ptr_executable;
extern int rpc__resp__wifi_get_country_code__descriptor;
extern int esp_hosted_transport_is_config_valid;
extern int _ZN3nvs8HashList5eraseEj;
extern int tcp_timer_needed;
extern int rtc_clk_8m_enable;
extern int lwip_htonl;
extern int rpc__req__wifi_scan_get_ap_num__init;
extern int mbedtls_mpi_core_clz;
extern int time;
extern int rpc__req__wifi_set_country_code__descriptor;
extern int mspi_timing_config_psram_prepare_reference_data;
extern int rpc__req__config_heartbeat__init;
extern int regdma_link_new_branch_wait_default;
extern int cache_hal_init;
extern int fseek;
extern int rpc__resp__feature_control__descriptor;
extern int _ZN3nvs8HashList6insertERKNS_4ItemEj;
extern int __wrap_stat;
extern int __srget_r;
extern int gdma_axi_hal_clear_intr;
extern int vTaskDelay;
extern int __wrap_rmdir;
extern int __atexit0;
extern int rpc__event__supp_dpp_fail__init;
extern int _ZNK3nvs4Item14calculateCrc32Ev;
extern int esp_aes_gcm_crypt_and_tag;
extern int spi_flash_hal_read;
extern int esp_netif_get_flags;
extern int mbedtls_hardware_poll;
extern int esp_transport_ssl_set_cert_data_der;
extern int remove;
extern int IP_EVENT;
extern int httpd_sess_delete_invalid;
extern int gdma_start;
extern int mbedtls_mpi_gcd;
extern int wifi_bandwidths__descriptor;
extern int i2s_get_buf_size;
extern int mbedtls_ssl_handshake_server_step;
extern int strncpy;
extern int _ZNSt9exceptionD2Ev;
extern int mbedtls_aria_crypt_cfb128;
extern int memcmp;
extern int rpc__resp__wifi_get_country__descriptor;
extern int _ZN3nvs4LockD2Ev;
extern int __floatundidf;
extern int rpc__resp__wifi_sta_get_aid__descriptor;
extern int fclose;
extern int arg_dstr_reset;
extern int httpd_unregister_all_uri_handlers;
extern int memp_NETCONN;
extern int esp_flash_init_main;
extern int tanmatsu_coprocessor_get_inputs;
extern int __getreent;
extern int s_cache_hal_init_ctx;
extern int _ZN3nvs4Page10writeEntryERKNS_4ItemE;
extern int gdma_axi_hal_enable_burst;
extern int mem_info__init;
extern int mbedtls_ssl_renegotiate;
extern int mem_info__descriptor;
extern int acd_add;
extern int mbedtls_ssl_handshake_client_step;
extern int gdma_hal_enable_burst;
extern int rpc__req__wifi_sta_itwt_setup__descriptor;
extern int netconn_getaddr;
extern int esp_aes_crypt_ctr;
extern int esp_sha_read_digest_state;
extern int sdmmc_init_sd_current_limit;
extern int nvs_flash_init;
extern int rpc_wifi_scan_get_ap_records;
extern int esp_rtc_init;
extern int g_wifi_osi_funcs;
extern int mspi_timing_enter_low_speed_mode;
extern int spi_flash_brownout_need_reset;
extern int heap_caps_realloc_base;
extern int _Balloc;
extern int rpc__resp__wifi_set_protocol__init;
extern int esp_clk_tree_enable_src;
extern int esp_crypto_ds_lock_acquire;
extern int rpc__event__custom_rpc__init;
extern int rpc__resp__eap_clear_certificate_and_key__descriptor;
extern int mbedtls_hmac_drbg_init;
extern int esp_brownout_init;
extern int rpc__req__wifi_sta_itwt_set_target_wake_time_offset__descriptor;
extern int esp_ds_rsa_sign;
extern int esp_app_get_elf_sha256;
extern int http_header_destroy;
extern int rpc__req__wifi_get_channel__descriptor;
extern int mbedtls_asn1_get_alg;
extern int rpc__resp__eap_set_domain_name__descriptor;
extern int esp_aes_xts_init;
extern int release_slave_reset_gpio_post_wakeup;
extern int strdup;
extern int aes_hal_setkey;
extern int rpc__resp__supp_dpp_start_listen__descriptor;
extern int rpc__req__wifi_get_band__init;
extern int mbedtls_rsa_check_privkey;
extern int uxQueueMessagesWaiting;
extern int node_remove_from_list;
extern int mbedtls_sha512;
extern int xQueueSemaphoreTake;
extern int wifi_event_sta_connected__init;
extern int hosted_malloc;
extern int tlsf_fit_size;
extern int sdmmc_enable_hs_mode_and_check;
extern int pbuf_skip;
extern int ip6_chksum_pseudo;
extern int __wrap_realpath;
extern int sdmmc_io_write_byte;
extern int vterm_init;
extern int mbedtls_ssl_tls12_write_client_hello_exts;
extern int protobuf_c_message_free_unpacked;
extern int mbedtls_gcm_free_soft;
extern int i2c_master_probe;
extern int rpc__resp__eap_set_disable_time_check__init;
extern int lwip_freeaddrinfo;
extern int inflateInit2_;
extern int xRingbufferSend;
extern int mbedtls_asn1_traverse_sequence_of;
extern int sdmmc_host_dma_stop;
extern int rpc__resp__wifi_stop__init;
extern int esp_time_impl_get_time_since_boot;
extern int _strtod_l;
extern int __lock___dd_hash_mutex;
extern int tlsf_add_pool;
extern int esp_vfs_unlink;
extern int wifi_sta_info__init;
extern int rtc_clk_cpu_set_to_default_config;
extern int mbedtls_md_clone;
extern int mbedtls_ssl_conf_verify;
extern int rpc__resp__wifi_init__descriptor;
extern int rpc__resp__eap_set_identity__descriptor;
extern int rpc__req__mem_monitor__descriptor;
extern int mbedtls_ecdsa_verify_restartable;
extern int heap_caps_add_region_with_caps;
extern int __sflush_r;
extern int _fseek_r;
extern int rpc__req__wifi_sta_get_ap_info__descriptor;
extern int rpc__resp__wifi_get_bandwidth__descriptor;
extern int nvs_flash_erase_partition;
extern int memp_malloc;
extern int ip4_output_if;
extern int sdmmc_io_write_blocks;
extern int __retarget_lock_release_recursive;
extern int esp_intr_enable_source;
extern int __fp_lock_all;
extern int zcalloc;
extern int rpc__req__wifi_set_storage__descriptor;
extern int ip4_input;
extern int bmi2_write_config_file;
extern int mbedtls_rsa_rsaes_pkcs1_v15_encrypt;
extern int ip6_options_add_hbh_ra;
extern int rpc__resp__eap_use_default_cert_bundle__descriptor;
extern int rpc_slaveif_wifi_disconnect;
extern int __srget;
extern int http_header_set;
extern int regdma_link_new_branch_addr_map;
extern int memp_free;
extern int rpc_slaveif_wifi_scan_get_ap_records;
extern int memp_TCP_SEG;
extern int esp_netif_get_handle_from_ifkey;
extern int __wrap_closedir;
extern int bmi2_set_adv_power_save;
extern int mbedtls_ssl_reset_out_pointers;
extern int acd_arp_reply;
extern int rpc__resp__wifi_sta_twt_config__descriptor;
extern int rpc_wifi_connect;
extern int lwip_recv;
extern int _strtol_r;
extern int rpc__resp__eap_set_username__init;
extern int s_keys;
extern int memp_MLD6_GROUP;
extern int gdma_axi_hal_enable_intr;
extern int es8156_initialize;
extern int regdma_link_new_branch_write;
extern int _mbtowc_r;
extern int mbedtls_ssl_read_record;
extern int rpc__resp__supp_dpp_init__init;
extern int _ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE;
extern int tcpip_try_callback;
extern int panic_abort;
extern int esp_partition_get_main_flash_sector_size;
extern int tcp_slowtmr;
extern int http_header_init;
extern int rpc__resp__wifi_get_config__init;
extern int rpc__resp__wifi_sta_itwt_suspend__descriptor;
extern int efuse_hal_get_minor_chip_version;
extern int hosted_sdio_init;
extern int multi_heap_malloc;
extern int esp_tls_internal_event_tracker_capture;
extern int gpio_hold_en;
extern int ethip6_output;
extern int tanmatsu_coprocessor_get_keyboard_keys;
extern int rtc_clk_mpll_enable;
extern int _vasprintf_r;
extern int _tr_align;
extern int ets_isr_unmask;
extern int rpc__resp__set_mode__descriptor;
extern int mbedtls_hmac_drbg_update;
extern int console_tcflush;
extern int rpc__resp__wifi_set_protocol__descriptor;
extern int rpc__resp__wifi_scan_get_ap_record__init;
extern int rpc__req__set_mode__descriptor;
extern int rpc__resp__wifi_sta_itwt_send_probe_req__init;
extern int mbedtls_mpi_sub_mpi;
extern int esp_cpu_reset;
extern int gdma_axi_hal_get_intr_status_reg;
extern int gpio_hal_iomux_out;
extern int wifi_ap_config__init;
extern int sys_arch_unprotect;
extern int sdmmc_send_cmd_go_idle_state;
extern int udp_send;
extern int _ZN3nvs7Storage7findKeyEhPKcPNS_8ItemTypeE;
extern int vTaskSuspendAll;
extern int esp_elf_relocate;
extern int esp_register_freertos_tick_hook;
extern int sys_mbox_post;
extern int xPortCheckValidTCBMem;
extern int rgb_display_get_vga_palette_entry;
extern int rpc_platform_deinit;
extern int nd6_cleanup_netif;
extern int sdmmc_host_get_real_freq;
extern int spi_flash_chip_winbond_get_caps;
extern int gpio_intr_disable;
extern int sdmmc_host_set_input_delay;
extern int sdmmc_allocate_aligned_buf;
extern int regdma_link_stats;
extern int tcp_tw_pcbs;
extern int _lock_close_recursive;
extern int _vsnprintf_r;
extern int esp_mpi_enable_hardware_hw_op;
extern int mbedtls_ssl_sig_from_pk;
extern int esp_netif_start;
extern int _realloc_r;
extern int esp_task_wdt_impl_timer_restart;
extern int vTaskSetThreadLocalStoragePointerAndDelCallback;
extern int spi_flash_chip_generic_suspend_cmd_conf;
extern int esp_wifi_create_if_driver;
extern int esp_wifi_register_if_rxcb;
extern int vTaskDelayUntil;
extern int uxTopUsedPriority;
extern int rpc__resp__wifi_set_channel__init;
extern int acd_netif_ip_addr_changed;
extern int mipi_dsi_hal_phy_write_register;
extern int esp_libc_include_syscalls_impl;
extern int rgb_gfx_blit;
extern int st7701_initialize;
extern int tcp_seg_copy;
extern int mbedtls_md_starts;
extern int _ZN3nvs12NVSPartition8get_sizeEv;
extern int netif_ip6_addr_set;
extern int esp_int_wdt_cpu_init;
extern int _lock_acquire_recursive;
extern int rpc__resp__supp_dpp_deinit__init;
extern int __strtok_r;
extern int httpd_req_new;
extern int spi_flash_encryption_hal_enable;
extern int dw_gdma_hal_deinit;
extern int mbedtls_rsa_pkcs1_decrypt;
extern int console_write;
extern int is_transport_tx_ready;
extern int mbedtls_ssl_get_key_exchange_md_tls1_2;
extern int rpc__resp__wifi_scan_params__descriptor;
extern int cmd_httpd;
extern int mbedtls_ssl_conf_ca_chain;
extern int tlsf_create_with_pool;
extern int bmi270_feat_in;
extern int esp_netif_is_netif_up;
extern int dhcp_start;
extern int argtable3_xmalloc;
extern int __smakebuf_r;
extern int pmu_hal_hp_set_sleep_active_backup_enable;
extern int esp_netif_get_default_netif;
extern int http_message_needs_eof;
extern int mbedtls_ssl_pend_fatal_alert;
extern int esp_flash_write_encrypted;
extern int _g_esp_netif_inherent_sta_config;
extern int mem_calloc;
extern int esp_log_impl_unlock;
extern int rpc__event__sta_scan_done__init;
extern int _putc_r;
extern int __stdio_exit_handler;
extern int spi_flash_hal_gpspi_device_config;
extern int rpc_send_req;
extern int mbedtls_ssl_derive_keys;
extern int gdma_stop;
extern int udp_init;
extern int g_mmu_mem_regions;
extern int _ZN3nvs7Storage4initEmm;
extern int gdma_axi_hal_disconnect_peri;
extern int sdmmc_hal_init;
extern int sdmmc_io_reset;
extern int memp_ARP_QUEUE;
extern int sys_arch_mbox_tryfetch;
extern int lfs_file_write;
extern int regdma_find_prev_module_link_tail;
extern int mbedtls_ssl_write;
extern int rpc__req__gpio_set_pull_mode__descriptor;
extern int mbedtls_ctr_drbg_random_with_add;
extern int mbedtls_ssl_check_curve;
extern int reachable_time;
extern int xt_unhandled_exception;
extern int netconn_bind;
extern int rpc__resp__get_coprocessor_fw_version__descriptor;
extern int tcp_write;
extern int spi_flash_chip_generic_get_io_mode;
extern int mbedtls_ecp_check_privkey;
extern int raw_sendto;
extern int lcd_hal_init;
extern int tcp_listen_pcbs;
extern int esp_vfs_include_nullfs_register;
extern int wifi_init_config__init;
extern int netif_set_up;
extern int strcasestr;
extern int esp_vfs_null_register;
extern int ecp_mul_restartable_internal_soft;
extern int udp_sendto_if_src;
extern int rpc__resp__wifi_get_band__init;
extern int cfree;
extern int rpc__resp__wifi_get_band__descriptor;
extern int rpc__req__eap_set_ttls_phase2_method__descriptor;
extern int _strtod_r;
extern int esp_aes_free;
extern int sys_mbox_trypost;
extern int mbedtls_sha256_starts;
extern int mbedtls_ssl_tls12_get_preferred_hash_for_sig_alg;
extern int regdma_link_new_branch_continuous;
extern int pthread_include_pthread_local_storage_impl;
extern int tcp_next_iss;
extern int arg_dstr_cat;
extern int rpc__req__eap_clear_username__init;
extern int rpc__req__gpio_set_direction__descriptor;
extern int spi_flash_chip_generic_read_reg;
extern int ip_chksum_pseudo;
extern int esp_log_writev;
extern int _ZN3nvs12NVSPartition11erase_rangeEjj;
extern int sdmmc_io_print_cis_info;
extern int mbedtls_md_hmac_finish;
extern int vPortClearInterruptMaskFromISR;
extern int hosted_thread_create;
extern int mbedtls_ssl_get_ciphersuite_sig_alg;
extern int igmp_stop;
extern int sqrt;
extern int breezybox_exec;
extern int xQueueTakeMutexRecursive;
extern int vTaskSetTimeOutState;
extern int tlsf_walk_pool;
extern int mbedtls_ssl_transform_init;
extern int mbedtls_mpi_inv_mod;
extern int bsp_input_hooks_init;
extern int sdmmc_host_is_slot_set_to_uhs1;
extern int mbedtls_ssl_encrypt_buf;
extern int _ZN3nvs7Storage9writeItemEhNS_8ItemTypeEPKcPKvj;
extern int bootloader_execute_flash_command;
extern int sem_to_slave_queue;
extern int mipi_dsi_hal_host_dpi_set_vertical_timing;
extern int rom_flash_chip_dummy;
extern int pcTaskGetName;
extern int _ZNSt9exceptionD1Ev;
extern int xQueueReceiveFromISR;
extern int lseek;
extern int udp_sendto_if;
extern int _ZN3nvs15NVSHandleSimple10erase_itemEPKc;
extern int gpio_uninstall_isr_service;
extern int mld6_joingroup_netif;
extern int __fixdfdi;
extern int httpd_uri;
extern int rpc__resp__wifi_clear_fast_connect__init;
extern int rpc__req__eap_set_disable_time_check__descriptor;
extern int _times_r;
extern int spi_flash_chip_generic_erase_sector;
extern int hosted_hold_gpio;
extern int sys_mbox_free;
extern int esp_sha_set_mode;
extern int rgb_display_wait_vsync;
extern int fsync;
extern int acd_network_changed_link_down;
extern int rpc__req__eap_clear_ca_cert__descriptor;
extern int tcp_backlog_delayed;
extern int strtof;
extern int esp_deep_sleep_register_hook;
extern int rpc__resp__wifi_get_protocols__descriptor;
extern int rpc__resp__wifi_sta_itwt_set_target_wake_time_offset__init;
extern int cmd_cd;
extern int mbedtls_rsa_deduce_primes;
extern int rpc__req__get_coprocessor_fw_version__init;
extern int memp_PBUF;
extern int inflateReset;
extern int tlsf_memalign_offs;
extern int hmac_hal_start;
extern int mbedtls_rsa_rsaes_pkcs1_v15_decrypt;
extern int _ctype_;
extern int memspi_host_erase_sector;
extern int mbedtls_ct_zeroize_if;
extern int lwip_init;
extern int rpc__req__wifi_set_storage__init;
extern int rpc_feature_option__descriptor;
extern int multi_heap_register;
extern int __retarget_lock_init;
extern int rpc__resp__gpio_set_level__descriptor;
extern int esp_ipc_func_arg;
extern int _ZN3nvs4Page14writeEntryDataEPKhj;
extern int esp_event_post_to;
extern int spi_flash_hal_setup_auto_suspend_mode;
extern int rpc__resp__get_ps__init;
extern int getopt;
extern int strtoul;
extern int esp_lcd_new_rgb_panel;
extern int esp_log_cache_get_level;
extern int memp_pools;
extern int mbedtls_ssl_write_sig_alg_ext;
extern int console_read;
extern int mpi_hal_set_search_position;
extern int rpc__req__wifi_scan_start__init;
extern int spi_flash_hal_init;
extern int rpc__req__wifi_sta_itwt_suspend__descriptor;
extern int esp_netif_set_old_ip_info;
extern int rpc__resp__wifi_sta_get_aid__init;
extern int rpc_wifi_start;
extern int _ZN3nvs7StorageD1Ev;
extern int memspi_host_read_status_hs;
extern int sdmmc_host_get_slot_width;
extern int cJSON_IsArray;
extern int pbuf_free_header;
extern int iswspace;
extern int sdmmc_host_enable_clk_cmd11;
extern int esp_hosted_woke_from_power_save;
extern int transport_pserial_send;
extern int rpc_wifi_set_mode;
extern int rtc_clk_apll_coeff_set;
extern int rpc__req__wifi_get_bandwidth__init;
extern int esp_transport_poll_read;
extern int parse_tlv;
extern int _ZN3nvs4Item14calculateCrc32EPKhj;
extern int heap_caps_check_integrity_all;
extern int mbedtls_rsa_import;
extern int wifi_scan_default_params__descriptor;
extern int aes_hal_gcm_calc_hash;
extern int mbedtls_x509_crt_init;
extern int open;
extern int esp_crypto_ecc_enable_periph_clk;
extern int rgb_gfx_rect;
extern int spi_flash_chip_winbond_suspend_cmd_conf;
extern int spi_flash_hal_gpspi_read;
extern int rpc_wifi_scan_start;
extern int netif_ip6_addr_set_parts;
extern int gdma_hal_clear_intr;
extern int serial_drv_read;
extern int esp_ds_init_data_ctx;
extern int esp_flash_get_physical_size;
extern int esp_timer_early_init;
extern int spi_flash_init_lock;
extern int sprintf;
extern int pxPortUpdateCoprocOwner;
extern int rpc__req__eap_clear_password__init;
extern int rpc__req__gpio_get_level__descriptor;
extern int spi_flash_set_erasing_flag;
extern int hosted_event_post;
extern int __localeconv_l;
extern int ip6_input;
extern int sdmmc_io_read_byte;
extern int dhcp_supplied_address;
extern int rpc__resp__wifi_disconnect__descriptor;
extern int rpc__resp__gpio_set_direction__init;
extern int linenoiseClearScreen;
extern int iswspace_l;
extern int ds_hal_configure_iv;
extern int wifi_event_sta_disconnected__init;
extern int esp_mspi_get_io;
extern int __lock___malloc_recursive_mutex;
extern int z_errmsg;
extern int memp_UDP_PCB;
extern int http_parser_url_init;
extern int mbedtls_sha1_starts;
extern int sdmmc_host_start_command;
extern int rpc__resp__wifi_get_bandwidth__init;
extern int tcp_keepalive;
extern int mbedtls_mpi_core_read_le;
extern int __kernel_rem_pio2;
extern int mbedtls_ssl_handle_message_type;
extern int pmu_lp_system_analog_param_default;
extern int mbedtls_ssl_decrypt_buf;
extern int esp_mbedtls_mem_calloc;
extern int sleep;
extern int xPortSysTickHandler;
extern int rpc__req__wifi_sta_itwt_teardown__descriptor;
extern int _ZN3nvs12NVSPartition4readEjPvj;
extern int mbedtls_rsa_private;
extern int rpc__req__wifi_get_inactive_time__descriptor;
extern int sys_sem_free;
extern int mbedtls_ecp_curve_info_from_tls_id;
extern int mspi_timing_config_set_flash_clock;
extern int gpio_hal_intr_enable_on_core;
extern int pxPortGetCoprocArea;
extern int esp_intr_noniram_enable;
extern int gpio_set_direction;
extern int sys_arch_protect;
extern int _dtoa_r;
extern int esp_libc_time_init;
extern int __sseek;
extern int esp_tls_conn_write;
extern int dns_tmr;
extern int rpc__req__app_get_desc__init;
extern int __any_on;
extern int fseeko;
extern int rpc__req__gpio_config__descriptor;
extern int bsp_internal_coprocessor_keyboard_callback;
extern int xTaskGetSchedulerState;
extern int cmd_cp;
extern int spi_flash_cache2phys;
extern int tanmatsu_coprocessor_get_interrupt;
extern int mbedtls_ssl_finish_handshake_msg;
extern int rpc__req__gpio_set_pull_mode__init;
extern int sdmmc_fix_host_flags;
extern int __state_table;
extern int esp_int_wdt_init;
extern int esp_sha_dma;
extern int hosted_lock_mempool;
extern int _stat_r;
extern int wlanif_init;
extern int esp_timer_delete;
extern int pbuf_alloc_reference;
extern int esp_elf_map_sym;
extern int dma2d_periph_signals;
extern int rpc__req__otaactivate__descriptor;
extern int _ZNK3nvs4Page9readEntryEjRNS_4ItemE;
extern int __retarget_lock_close_recursive;
extern int breezybox_export_symbols;
extern int deflateResetKeep;
extern int rpc__resp__gpio_set_level__init;
extern int rpc__req__eap_use_default_cert_bundle__descriptor;
extern int __wrap_rename;
extern int rpc__req__feature_control__init;
extern int regdma_link_get_config_mode;
extern int roundf;
extern int gdma_axi_hal_clear_crc;
extern int rom_spiflash_api_funcs;
extern int __wrap_open;
extern int esp_err_to_name;
extern int rpc__resp__eap_clear_password__descriptor;
extern int _ZN3nvs4PageC2Ev;
extern int rpc__req__wifi_get_max_tx_power__init;
extern int esp_wifi_is_if_ready_when_started;
extern int dma2d_tx_channel_reserved_mask;
extern int tcp_update_rcv_ann_wnd;
extern int tcpip_input;
extern int esp_http_client_write;
extern int bmi2_error_codes_print_result;
extern int select;
extern int __gtdf2;
extern int inflateReset2;
extern int soc_memory_region_count;
extern int mbedtls_hmac_drbg_random;
extern int mbedtls_asn1_get_len;
extern int gdma_ahb_hal_append;
extern int _impure_data;
extern int sscanf;
extern int esp_panic_handler_feed_wdts;
extern int mbedtls_ccm_auth_decrypt;
extern int lfs_dir_open;
extern int mbedtls_hmac_drbg_free;
extern int pbuf_header_force;
extern int linenoiseEditHistoryNext;
extern int strlen;
extern int esp_event_handler_register_with_internal;
extern int memspi_host_program_page;
extern int _ZN3nvs19NVSPartitionManager24lookup_storage_from_nameEPKc;
extern int rpc__resp__set_mode__init;
extern int strtod;
extern int esp_ptr_dma_ext_capable;
extern int mbedtls_rsa_rsassa_pss_verify_ext;
extern int mbedtls_asn1_free_named_data_list_shallow;
extern int panic_soc_fill_info;
extern int esp_timer_init;
extern int sdmmc_send_cmd_send_op_cond;
extern int breezy_net_up;
extern int mbedtls_pk_ecc_set_key;
extern int cmd_head;
extern int cJSON_IsString;
extern int mbedtls_platform_zeroize;
extern int rpc__resp__eap_clear_new_password__descriptor;
extern int __popcountsi2;
extern int httpd_sess_delete;
extern int tcp_split_unsent_seg;
extern int http_parser_parse_url;
extern int __tz_unlock;
extern int bsp_device_initialize;
extern int mbedtls_ssl_free;
extern int hosted_init_hook;
extern int rpc__resp__wifi_connect__descriptor;
extern int __seofread;
extern int strtol;
extern int rpc__resp__wifi_sta_itwt_send_probe_req__descriptor;
extern int heap_size_threshold__init;
extern int esp_netif_get_old_ip_info;
extern int dhcps_set_new_lease_cb;
extern int bmi2_interface_init;
extern int _dist_code;
extern int spi_flash_chip_generic_reset;
extern int esp_log_va;
extern int rpc__resp__wifi_set_channel__descriptor;
extern int spi_flash_encryption_hal_check;
extern int mspi_timing_psram_config_set_tuning_regs;
extern int strchrnul;
extern int gdma_hal_reset;
extern int rpc__req__wifi_start__descriptor;
extern int esp_vfs_read;
extern int mbedtls_base64_encode;
extern int i2c_hal_master_init;
extern int esp_http_client_set_redirection;
extern int linenoiseEditMoveEnd;
extern int rtc_gpio_deinit;
extern int esp_partition_erase_range;
extern int mbedtls_mpi_read_binary;
extern int vTaskPlaceOnEventList;
extern int wifi_tx_throttling;
extern int _ZNSt9type_infoD2Ev;
extern int pau_hal_lp_sys_initialize;
extern int hci_drv_init;
extern int bsp_internal_coprocessor_input_callback;
extern int strncat;
extern int wifi_scan_default_params__init;
extern int hosted_realloc;
extern int memp_TCPIP_MSG_API;
extern int heap_caps_get_total_size;
extern int httpd_req_delete;
extern int mipi_dsi_hal_host_gen_read_dcs_command;
extern int usb_serial_jtag_read_bytes;
extern int memp_RAW_PCB;
extern int rpc__resp__eap_set_username__descriptor;
extern int rpc__req__custom_rpc__init;
extern int esp_md5_finish;
extern int esp_netif_attach_wifi_station;
extern int vTaskSwitchContext;
extern int xTaskGetCurrentTaskHandleForCore;
extern int itoa;
extern int tcp_alloc;
extern int mbedtls_x509_crt_profile_suiteb;
extern int rpc_set_wifi_mode;
extern int tcp_sent;
extern int mbedtls_ct_memcmp;
extern int __ulp;
extern int mbedtls_hmac_drbg_seed_buf;
extern int rpc__resp__wifi_ap_get_sta_aid__init;
extern int mbedtls_mpi_mul_int;
extern int _fputc_r;
extern int _read_r;
extern int mbedtls_pk_parse_key;
extern int spi_flash_init_chip_state;
extern int lp_gpio_connect_in_signal;
extern int __srefill_r;
extern int mbedtls_calloc;
extern int rpc__req__wifi_clear_fast_connect__descriptor;
extern int spi_flash_chip_generic_erase_chip;
extern int esp_crypto_sha_enable_periph_clk;
extern int rpc__req__wifi_get_protocol__init;
extern int spi_flash_cache_enabled;
extern int rpc_slaveif_wifi_connect;
extern int _ZNK3nvs4Page18getVarDataTailroomEv;
extern int esp_http_client_cleanup;
extern int rpc__resp__wifi_set_config__descriptor;
extern int esp_libc_include_assert_impl;
extern int rpc__resp__wifi_get_channel__descriptor;
extern int dw_gdma_del_channel;
extern int esp_aes_process_dma_gcm;
extern int __ubsan_include;
extern int dhcp_release_and_stop;
extern int dhcps_new;
extern int hal_utils_calc_clk_div_frac_accurate;
extern int _ZN10__cxxabiv120__si_class_type_infoD2Ev;
extern int serial_ll_init;
extern int netconn_tcp_recvd;
extern int _ZN3nvs4Lock10mSemaphoreE;
extern int rpc__req__wifi_deauth_sta__init;
extern int rpc__req__otaend__init;
extern int mbedtls_rsa_check_pubkey;
extern int xTaskPriorityDisinherit;
extern int rpc__resp__iface_mac_addr_set_get__descriptor;
extern int rpc__req__wifi_get_protocol__descriptor;
extern int rpc__event__supp_dpp_uri_ready__descriptor;
extern int dma2d_register_rx_event_callbacks;
extern int mbedtls_ssl_handshake;
extern int esp_transport_set_async_connect_func;
extern int hosted_sdio_deinit;
extern int mbedtls_mpi_free;
extern int udp_sendto;
extern int mbedtls_asn1_get_sequence_of;
extern int rpc__gpio_pull_mode__descriptor;
extern int mbedtls_ssl_conf_alpn_protocols;
extern int esp_clk_apb_freq;
extern int sniprintf;
extern int sys_untimeout;
extern int mbedtls_rsa_validate_params;
extern int icmp_input;
extern int vfiprintf;
extern int _ZN3nvs4Page9eraseItemEhNS_8ItemTypeEPKchNS_9VerOffsetE;
extern int esp_cpu_unstall;
extern int rpc__req__gpio_get_level__init;
extern int sdmmc_init_io_bus_width;
extern int rpc__req__wifi_sta_enterprise_disable__init;
extern int hosted_free;
extern int spi_flash_chip_winbond_page_program;
extern int netif_add_ext_callback;
extern int _fwalk_sglue;
extern int timestamp_id;
extern int FreeRTOS_openocd_params;
extern int regdma_link_update_next;
extern int mbedtls_mpi_add_abs;
extern int gdma_new_link_list;
extern int usb_serial_jtag_read_ready;
extern int setjmp;
extern int esp_rom_regi2c_read;
extern int mbedtls_ssl_session_init;
extern int mbedtls_mpi_bitlen;
extern int mbedtls_pkcs5_pbkdf2_hmac_ext;
extern int ip4addr_aton;
extern int sdmmc_host_card_busy;
extern int esp_crosscore_int_init;
extern int mbedtls_asn1_sequence_free;
extern int mem_trim;
extern int soc_memory_regions;
extern int bsp_i2c_primary_bus_initialize;
extern int rtc_clk_cpu_freq_get_config;
extern int clearerr;
extern int spi_flash_hal_gpspi_poll_cmd_done;
extern int rpc__req__set_dhcp_dns_status__descriptor;
extern int serial_drv_open;
extern int _ZN3nvs19NVSPartitionManager11open_handleEPKcS2_15nvs_open_mode_tPPNS_15NVSHandleSimpleE;
extern int __ctzdi2;
extern int periph_rtc_dig_clk8m_enable;
extern int esp_log_linked_list_get_level;
extern int transport_drv_add_channel;
extern int rename;
extern int _ZN3nvs19NVSPartitionManager14init_partitionEPKc;
extern int sdmmc_io_write_bytes;
extern int rpc__req__wifi_set_protocols__init;
extern int mbedtls_ssl_md_alg_from_hash;
extern int mbedtls_sha256_update;
extern int _lock_try_acquire;
extern int esp_get_free_heap_size;
extern int i2s_periph_signal;
extern int adler32_z;
extern int seekdir;
extern int netif_find;
extern int rpc__req__wifi_sta_twt_config__descriptor;
extern int cmd_pwd;
extern int esp_littlefs_format_partition;
extern int mpi_hal_write_m_prime;
extern int heap_caps_realloc_default;
extern int fdopen;
extern int mbedtls_aria_free;
extern int esp_partition_iterator_release;
extern int rpc__resp__wifi_get_max_tx_power__init;
extern int _ZSt9terminatev;
extern int esp_wifi_remote_get_mac;
extern int multi_heap_realloc;
extern int ecc_hal_is_calc_finished;
extern int inet_chksum;
extern int rtc_clk_freq_cal;
extern int cmd_cat;
extern int _ZN3nvs12NVSPartition12get_readonlyEv;
extern int rpc__resp__set_ps__init;
extern int rpc__req__wifi_get_inactive_time__init;
extern int xPortInIsrContext;
extern int __floatunsidf;
extern int tcgetattr;
extern int esp_console_get_hint;
extern int _reclaim_reent;
extern int _tr_flush_bits;
extern int rpc__req__eap_set_certificate_and_key__init;
extern int mspi_timing_psram_set_best_tuning_delayline;
extern int _tzset_unlocked_r;
extern int arg_dstr_cstr;
extern int ds_hal_finish;
extern int inflate_fixed;
extern int netbuf_alloc;
extern int __swrite;
extern int etharp_request;
extern int mbedtls_asn1_write_len;
extern int esp_transport_set_default_port;
extern int tanmatsu_coprocessor_initialize;
extern int vTaskPlaceOnEventListRestricted;
extern int vListInsertEnd;
extern int esp_register_freertos_idle_hook_for_cpu;
extern int dw_gdma_new_link_list;
extern int tlsf_check;
extern int tcflush;
extern int esp_lcd_panel_init;
extern int localtime_r;
extern int esp_psram_extram_test;
extern int aes_hal_transform_dma_start;
extern int gpio_pulldown_dis;
extern int udp_remove;
extern int bootloader_init_mem;
extern int _ZN3nvs7Storage19populateBlobIndicesER14intrusive_listINS0_13BlobIndexNodeEE;
extern int esp_log_vprint_func;
extern int esp_crosscore_int_send_twdt_abort;
extern int rpc__req__wifi_sta_get_ap_info__init;
extern int esp_timer_impl_init;
extern int strftime_l;
extern int xTaskPriorityInherit;
extern int httpd_sess_set_descriptors;
extern int hosted_wifi_event_post;
extern int rpc__event__mem_monitor__descriptor;
extern int rpc__req__get_mode__init;
extern int rpc__req__gpio_input_enable__descriptor;
extern int ecp_mul_restartable_internal;
extern int console_tcsetattr;
extern int esp_panic_handler_enable_rtc_wdt;
extern int httpd_resp_send;
extern int ftello;
extern int spi_flash_encryption_hal_prepare;
extern int _ZN10__cxxabiv117__class_type_infoD1Ev;
extern int __wrap___gxx_personality_v0;
extern int rtos_save_pie_coproc;
extern int rpc__req__eap_clear_username__descriptor;
extern int rpc_feature_command__descriptor;
extern int __lock___at_quick_exit_mutex;
extern int memp_PBUF_POOL;
extern int finite;
extern int console_end_select;
extern int rgb_display_set_mode;
extern int _fwrite_r;
extern int lfs_unmount;
extern int vTaskDelete;
extern int vPortAssertIfInISR;
extern int esp_aes_xts_free;
extern int wifi_event_sta_scan_done__descriptor;
extern int i2c_master_transmit_receive;
extern int ds_hal_start;
extern int mbedtls_rsa_rsaes_oaep_encrypt;
extern int wifi_scan_channel_bitmap__init;
extern int rpc__req__wifi_get_bandwidths__init;
extern int gmtime_r;
extern int _fcntl_r;
extern int __unorddf2;
extern int httpd_sess_clear_ctx;
extern int mbedtls_ct_memmove_left;
extern int vterm_get_direct_buffer;
extern int rpc__req__gpio_reset_pin__descriptor;
extern int mbedtls_x509_get_ns_cert_type;
extern int esp_ds_start_sign;
extern int rpc__resp__wifi_set_band__init;
extern int rpc__resp__eap_set_ca_cert__init;
extern int regdma_link_new_write_default;
extern int periph_rcc_acquire_enter;
extern int heap_size_threshold__descriptor;
extern int tcp_rexmit;
extern int tcp_rexmit_rto;
extern int lwip_netconn_is_deallocated_msg;
extern int mbrtowc;
extern int esp_elf_free;
extern int __sf;
extern int tanmatsu_lcd_init;
extern int rpc__event__sta_connected__descriptor;
extern int rpc__req__get_mode__descriptor;
extern int cmd_mkdir;
extern int httpd_default_send;
extern int wifi_pmf_config__descriptor;
extern int breezybox_start_stdio;
extern int rpc_platform_init;
extern int floor;
extern int lfs_dir_rewind;
extern int __tz_lock;
extern int _strerror_r;
extern int rpc__event__sta_disconnected__init;
extern int _ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv;
extern int __extendsfdf2;
extern int lfs_stat;
extern int esp_psram_extram_reserve_dma_pool;
extern int pmu_hp_system_clock_param_default;
extern int periph_rtc_dig_clk8m_disable;
extern int __call_exitprocs;
extern int http_header_set_format;
extern int ip6_addr_any;
extern int _ZN3nvs15NVSHandleSimpleD0Ev;
extern int esp_vfs_lwip_sockets_register;
extern int esp_log_set_default_level;
extern int gdma_link_get_head_addr;
extern int mbedtls_ssl_check_timer;
extern int _ZN3nvs4LockD1Ev;
extern int mbedtls_ssl_pk_alg_from_sig;
extern int spi_flash_encryption_hal_disable;
extern int _ZN3nvs12NVSPartitionC1EPK15esp_partition_t;
extern int esp_async_fbcpy_install;
extern int dw_gdma_hal_init;
extern int mbedtls_mpi_core_cond_assign;
extern int pbuf_try_get_at;
extern int rpc__req__wifi_get_band_mode__init;
extern int periph_rcc_release_enter;
extern int raw_input;
extern int console_fstat;
extern int _ZN3nvs7Storage16cmpMultiPageBlobEhPKcPKvj;
extern int _ZN3nvs4Page10initializeEv;
extern int hosted_create_mutex;
extern int rpc__resp__wifi_set_okc_support__descriptor;
extern int arg_print_errors;
extern int esp_netif_set_mac_api;
extern int mbedtls_ecp_mul;
extern int esp_ptr_byte_accessible;
extern int gdma_register_rx_event_callbacks;
extern int lwip_netconn_is_err_msg;
extern int rtc_clk_xtal_freq_get;
extern int s_lcd_platform;
extern int gdma_hal_set_priority;
extern int rpc__req__eap_set_certificate_and_key__descriptor;
extern int raw_remove;
extern int mbedtls_ssl_get_ciphersuite_sig_pk_alg;
extern int wifi_init_config__descriptor;
extern int memspi_host_erase_block;
extern int wifi_scan_threshold__init;
extern int mbedtls_ecdh_read_params;
extern int bsp_input_hooks_process;
extern int color_hal_pixel_format_get_bit_depth;
extern int optarg;
extern int esp_random;
extern int esp_efuse_utility_check_errors;
extern int esp_flash_read_chip_id;
extern int es8156_write_page_select;
extern int __clzsi2;
extern int spi_flash_hal_disable_auto_resume_mode;
extern int etharp_tmr;
extern int mbedtls_ecp_tls_write_group;
extern int esp_netif_up;
extern int esp_flash_chip_driver_initialized;
extern int rpc_register_event_callbacks;
extern int esp_transport_list_init;
extern int memp_TCPIP_MSG_INPKT;
extern int rpc__resp__otaactivate__init;
extern int esp_clk_tree_xtal32k_get_freq_hz;
extern int gdma_disconnect;
extern int mbedtls_eckeydh_info;
extern int __sccl;
extern int mbedtls_mpi_mod_int;
extern int malloc;
extern int nd6_adjust_mld_membership;
extern int cache_hal_is_cache_enabled;
extern int rpc__resp__gpio_config__init;
extern int periph_rtc_mpll_freq_set;
extern int rpc__req__wifi_set_bandwidth__init;
extern int mld6_report_groups;
extern int lwip_hook_tcp_isn;
extern int mbedtls_pk_ecc_set_group;
extern int mbedtls_ecp_curve_list;
extern int mld6_joingroup;
extern int mbedtls_md_init;
extern int task_wdt_timeout_abort;
extern int rpc__resp__get_mode__init;
extern int strcmp;
extern int xQueueGiveMutexRecursive;
extern int esp_aes_init;
extern int spi_flash_chip_generic_write_encrypted;
extern int es8156_read_page_select;
extern int esp_lcd_new_panel_io_dbi;
extern int spi_flash_check_and_flush_cache;
extern int ftell;
extern int rpc__req__wifi_sta_itwt_set_target_wake_time_offset__init;
extern int sdmmc_init_sd_ssr;
extern int spi_flash_disable_cache;
extern int bsp_i2c_primary_bus_get_semaphore;
extern int intr_handler_get;
extern int esp_app_desc__init;
extern int mipi_dsi_hal_configure_phy_pll;
extern int app_elf_sha256_str;
extern int cmd_wc;
extern int _ZN3nvs12NVSPartition11get_addressEv;
extern int sha_hal_hash_dma;
extern int settimeofday;
extern int esp_backtrace_print;
extern int _ZN10__cxxabiv120__si_class_type_infoD0Ev;
extern int http_utils_assign_string;
extern int esp_ldo_acquire_channel;
extern int rpc__req__wifi_get_country_code__init;
extern int _ZN3nvs7Storage8readItemEhNS_8ItemTypeEPKcPvj;
extern int httpd_resp_send_chunk;
extern int gdma_get_alignment_constraints;
extern int mbedtls_asn1_get_mpi;
extern int dma2d_hal_rx_reset_channel;
extern int mbedtls_pk_parse_subpubkey;
extern int es8156_read_register;
extern int esp_lcd_panel_io_tx_param;
extern int mpi_hal_write_rinv;
extern int rpc__req__wifi_get_bandwidth__descriptor;
extern int rpc__req__wifi_ap_get_sta_aid__init;
extern int igmp_init;
extern int sem_from_slave_queue;
extern int ds_hal_read_result;
extern int esp_flash_erase_region;
extern int esp_vfs_usb_serial_jtag_get_vfs;
extern int hosted_destroy_semaphore;
extern int periph_rcc_enter;
extern int nvs_erase_key;
extern int sdmmc_send_cmd_send_if_cond;
extern int err_to_errno;
extern int rpc__resp__wifi_set_storage__init;
extern int _ZNKSt9bad_alloc4whatEv;
extern int tcp_abandon;
extern int readdir;
extern int _ZN3nvs15NVSHandleSimple8get_blobEPKcPvj;
extern int mbedtls_rsa_pkcs1_sign;
#pragma GCC diagnostic pop

/* Available ELF symbols table: g_customer_elfsyms */

const struct esp_elfsym g_customer_elfsyms[] = {
    ESP_ELFSYM_EXPORT(bt_keyboard_is_pressed),
    ESP_ELFSYM_EXPORT(bt_keyboard_get_modifiers),
    ESP_ELFSYM_EXPORT(bt_keyboard_connected),
    ESP_ELFSYM_EXPORT(hmac_hal_clean),
    ESP_ELFSYM_EXPORT(pmu_sleep_enable_regdma_backup),
    ESP_ELFSYM_EXPORT(heap_caps_realloc),
    ESP_ELFSYM_EXPORT(esp_event_handler_register_with),
    ESP_ELFSYM_EXPORT(es8156_write_analog_system_4),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_config_clear_tuning_regs),
    ESP_ELFSYM_EXPORT(__multadd),
    ESP_ELFSYM_EXPORT(pthread_detach),
    ESP_ELFSYM_EXPORT(rpc__req__iface_mac_addr_set_get__descriptor),
    ESP_ELFSYM_EXPORT(printf),
    ESP_ELFSYM_EXPORT(heap_caps_calloc),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_wait),
    ESP_ELFSYM_EXPORT(i2c_hal_master_set_scl_timeout_val),
    ESP_ELFSYM_EXPORT(cs_send_to_ctrl_sock),
    ESP_ELFSYM_EXPORT(netconn_prepare_delete),
    ESP_ELFSYM_EXPORT(es8156_write_analog_system_6),
    ESP_ELFSYM_EXPORT(pxPortInitialiseStack),
    ESP_ELFSYM_EXPORT(pmu_hp_system_power_param_default),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_base_lookup_table),
    ESP_ELFSYM_EXPORT(rpc__gpio_mode__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_set_padding_mode),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_country_code__init),
    ESP_ELFSYM_EXPORT(mld6_stop),
    ESP_ELFSYM_EXPORT(memspi_host_read_id_hs),
    ESP_ELFSYM_EXPORT(wifi_active_scan_time__init),
    ESP_ELFSYM_EXPORT(mbedtls_sha512_update),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_set_level__descriptor),
    ESP_ELFSYM_EXPORT(sleep_retention_module_init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_start__init),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_password__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_read_signature),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_send_cid),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_inactive_time__descriptor),
    ESP_ELFSYM_EXPORT(dma2d_hal_tx_reset_channel),
    ESP_ELFSYM_EXPORT(esp_psram_chip_init),
    ESP_ELFSYM_EXPORT(rtc_spinlock),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_enable_etm_task),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv117__class_type_info20__do_find_public_srcEiPKvPKS0_S2_),
    ESP_ELFSYM_EXPORT(exit),
    ESP_ELFSYM_EXPORT(crc32_z),
    ESP_ELFSYM_EXPORT(esp_time_impl_set_boot_time),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_session_free),
    ESP_ELFSYM_EXPORT(__cxa_guard_dummy),
    ESP_ELFSYM_EXPORT(xPortEnterCriticalTimeout),
    ESP_ELFSYM_EXPORT(esp_mspi_pin_reserve),
    ESP_ELFSYM_EXPORT(spi_flash_hal_supports_direct_write),
    ESP_ELFSYM_EXPORT(sys_mutex_new),
    ESP_ELFSYM_EXPORT(sleep_retention_get_inited_modules),
    ESP_ELFSYM_EXPORT(__ratio),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_tls_write_point),
    ESP_ELFSYM_EXPORT(lwip_inet_pton),
    ESP_ELFSYM_EXPORT(cmd_sh),
    ESP_ELFSYM_EXPORT(lwip_getsockopt),
    ESP_ELFSYM_EXPORT(esp_netif_action_start),
    ESP_ELFSYM_EXPORT(xTimerCreateTimerTask),
    ESP_ELFSYM_EXPORT(wifi_event_sta_connected__descriptor),
    ESP_ELFSYM_EXPORT(esp_vfs_opendir),
    ESP_ELFSYM_EXPORT(esp_vfs_fstat),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_send_scr),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_deinit__descriptor),
    ESP_ELFSYM_EXPORT(gdma_hal_connect_peri),
    ESP_ELFSYM_EXPORT(sys_sem_signal_isr),
    ESP_ELFSYM_EXPORT(pvalloc),
    ESP_ELFSYM_EXPORT(sha_hal_wait_idle),
    ESP_ELFSYM_EXPORT(esp_aes_crypt_xts),
    ESP_ELFSYM_EXPORT(igmp_leavegroup_netif),
    ESP_ELFSYM_EXPORT(wifi_scan_config__init),
    ESP_ELFSYM_EXPORT(esp_md5_update),
    ESP_ELFSYM_EXPORT(esp_vfs_open),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_ec_grp),
    ESP_ELFSYM_EXPORT(esp_netif_stop),
    ESP_ELFSYM_EXPORT(dhcps_delete),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_verify_result),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_update),
    ESP_ELFSYM_EXPORT(vterm_send_input),
    ESP_ELFSYM_EXPORT(mbedtls_pk_get_bitlen),
    ESP_ELFSYM_EXPORT(esp_intr_ptr_in_isr_region),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_set_hostname),
    ESP_ELFSYM_EXPORT(spi_flash_chip_winbond_erase_sector),
    ESP_ELFSYM_EXPORT(tcp_recv_null),
    ESP_ELFSYM_EXPORT(vApplicationGetTimerTaskMemory),
    ESP_ELFSYM_EXPORT(mbedtls_aria_setkey_dec),
    ESP_ELFSYM_EXPORT(gpio_hal_intr_disable),
    ESP_ELFSYM_EXPORT(vPortTaskPinToCore),
    ESP_ELFSYM_EXPORT(xQueueGenericCreateStatic),
    ESP_ELFSYM_EXPORT(sdmmc_host_init_slot),
    ESP_ELFSYM_EXPORT(vListInitialiseItem),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_alg),
    ESP_ELFSYM_EXPORT(__atomic_fetch_or_8),
    ESP_ELFSYM_EXPORT(mbedtls_md_hmac_starts),
    ESP_ELFSYM_EXPORT(hmac_hal_configure),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_get_write_protect),
    ESP_ELFSYM_EXPORT(rewind),
    ESP_ELFSYM_EXPORT(i2c_master_transmit),
    ESP_ELFSYM_EXPORT(raw_recv),
    ESP_ELFSYM_EXPORT(realloc),
    ESP_ELFSYM_EXPORT(esp_transport_tcp_init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_ciphersuite_uses_ec),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_identity__descriptor),
    ESP_ELFSYM_EXPORT(g_exc_frames),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_country_code__descriptor),
    ESP_ELFSYM_EXPORT(valid_key_length),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_params__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_pk_verify_ext),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_switch_func),
    ESP_ELFSYM_EXPORT(cs_create_ctrl_sock),
    ESP_ELFSYM_EXPORT(rpc__req__otaend__descriptor),
    ESP_ELFSYM_EXPORT(_getpid_r),
    ESP_ELFSYM_EXPORT(pbuf_realloc),
    ESP_ELFSYM_EXPORT(netconn_shutdown),
    ESP_ELFSYM_EXPORT(bsp_internal_coprocessor_faults_callback),
    ESP_ELFSYM_EXPORT(gzclose),
    ESP_ELFSYM_EXPORT(rpc_init),
    ESP_ELFSYM_EXPORT(esp_aes_crypt_cbc),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_wait_idle),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_sig),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page12setSeqNumberEm),
    ESP_ELFSYM_EXPORT(dma2d_hal_init),
    ESP_ELFSYM_EXPORT(my_display_refresh_palette),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_get_crc_result),
    ESP_ELFSYM_EXPORT(esp_sha_block),
    ESP_ELFSYM_EXPORT(rpc__resp__set_dhcp_dns_status__init),
    ESP_ELFSYM_EXPORT(esp_netif_attach),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_free),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_init__descriptor),
    ESP_ELFSYM_EXPORT(bsp_display_get_parameters),
    ESP_ELFSYM_EXPORT(i2c_release_bus_handle),
    ESP_ELFSYM_EXPORT(strerror_l),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimpleD2Ev),
    ESP_ELFSYM_EXPORT(esprv_int_set_type),
    ESP_ELFSYM_EXPORT(arg_dstr_catc),
    ESP_ELFSYM_EXPORT(sha_hal_sha512_init_hash),
    ESP_ELFSYM_EXPORT(mmu_hal_get_id_from_target),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page15mLoadEntryTableEv),
    ESP_ELFSYM_EXPORT(check_if_max_freq_used),
    ESP_ELFSYM_EXPORT(mld6_leavegroup_netif),
    ESP_ELFSYM_EXPORT(es8156_write_analog_system_2),
    ESP_ELFSYM_EXPORT(lfs_dir_read),
    ESP_ELFSYM_EXPORT(create_debugging_tasks),
    ESP_ELFSYM_EXPORT(mbedtls_pem_free),
    ESP_ELFSYM_EXPORT(mbedtls_sha512_finish),
    ESP_ELFSYM_EXPORT(esp_crypto_mpi_enable_periph_clk),
    ESP_ELFSYM_EXPORT(g_hosted_osi_funcs),
    ESP_ELFSYM_EXPORT(esp_time_impl_get_boot_time),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_stop_listen__init),
    ESP_ELFSYM_EXPORT(rtc_dig_clk8m_enable),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_ap_info__init),
    ESP_ELFSYM_EXPORT(g_panic_abort),
    ESP_ELFSYM_EXPORT(memmove),
    ESP_ELFSYM_EXPORT(gpio_set_intr_type),
    ESP_ELFSYM_EXPORT(rtc_clk_cpu_freq_set_config),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_pkcs12_pbe_alg),
    ESP_ELFSYM_EXPORT(rtc_gpio_init),
    ESP_ELFSYM_EXPORT(hosted_unlock_mempool),
    ESP_ELFSYM_EXPORT(esp_timer_impl_get_min_period_us),
    ESP_ELFSYM_EXPORT(pbuf_chain),
    ESP_ELFSYM_EXPORT(rpc_wifi_sta_get_ap_info),
    ESP_ELFSYM_EXPORT(esp_clk_tree_lp_slow_get_freq_hz),
    ESP_ELFSYM_EXPORT(ip4_route_src),
    ESP_ELFSYM_EXPORT(esp_aes_crypt_ofb),
    ESP_ELFSYM_EXPORT(rpc__resp__set_mac_address__init),
    ESP_ELFSYM_EXPORT(gdma_del_link_list),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_update_soft),
    ESP_ELFSYM_EXPORT(capture_tcp_transport_error),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_send_alert_message),
    ESP_ELFSYM_EXPORT(udp_bind_netif),
    ESP_ELFSYM_EXPORT(bmi2_set_i2c_configuration),
    ESP_ELFSYM_EXPORT(fgetc),
    ESP_ELFSYM_EXPORT(bsp_device_initialize_custom),
    ESP_ELFSYM_EXPORT(esp_netif_get_desc),
    ESP_ELFSYM_EXPORT(hosted_for_loop_delay),
    ESP_ELFSYM_EXPORT(esp_libc_init),
    ESP_ELFSYM_EXPORT(memp_FRAG_PBUF),
    ESP_ELFSYM_EXPORT(__wrap_rewinddir),
    ESP_ELFSYM_EXPORT(httpd_req_handle_err),
    ESP_ELFSYM_EXPORT(regdma_find_module_link_tail),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_rssi__descriptor),
    ESP_ELFSYM_EXPORT(wifi_ap_record__descriptor),
    ESP_ELFSYM_EXPORT(heap_caps_free),
    ESP_ELFSYM_EXPORT(console_fcntl),
    ESP_ELFSYM_EXPORT(esp_fill_random),
    ESP_ELFSYM_EXPORT(esp_flash_encryption_enabled),
    ESP_ELFSYM_EXPORT(sha_hal_hash_block),
    ESP_ELFSYM_EXPORT(esp_task_wdt_init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_setup),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_get_ap_record__descriptor),
    ESP_ELFSYM_EXPORT(mpi_hal_enable_search),
    ESP_ELFSYM_EXPORT(labs),
    ESP_ELFSYM_EXPORT(lwip_getsockname),
    ESP_ELFSYM_EXPORT(xTaskResumeAll),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_restore__init),
    ESP_ELFSYM_EXPORT(tcp_send_empty_ack),
    ESP_ELFSYM_EXPORT(etharp_output),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_init),
    ESP_ELFSYM_EXPORT(nvs_flash_erase),
    ESP_ELFSYM_EXPORT(esp_flash_app_init),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_scan_get_ap_num),
    ESP_ELFSYM_EXPORT(get_vfs_for_index),
    ESP_ELFSYM_EXPORT(registered_heaps),
    ESP_ELFSYM_EXPORT(rmdir),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_country_code__init),
    ESP_ELFSYM_EXPORT(xTaskCreatePinnedToCoreWithCaps),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv119__terminate_handlerE),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_rssi__init),
    ESP_ELFSYM_EXPORT(fabsf),
    ESP_ELFSYM_EXPORT(esp_md5_clone),
    ESP_ELFSYM_EXPORT(nvs_sec_provider_include_impl),
    ESP_ELFSYM_EXPORT(igmp_input),
    ESP_ELFSYM_EXPORT(localeconv),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_write_tag),
    ESP_ELFSYM_EXPORT(http_should_keep_alive),
    ESP_ELFSYM_EXPORT(default_router_list),
    ESP_ELFSYM_EXPORT(es8156_write_mode_config),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_dpp_fail__init),
    ESP_ELFSYM_EXPORT(esp_libc_include_init_funcs),
    ESP_ELFSYM_EXPORT(sdmmc_io_enable_int),
    ESP_ELFSYM_EXPORT(sys_timeouts_init),
    ESP_ELFSYM_EXPORT(_kill_r),
    ESP_ELFSYM_EXPORT(hosted_post_semaphore),
    ESP_ELFSYM_EXPORT(pmu_lp_system_init),
    ESP_ELFSYM_EXPORT(tzset),
    ESP_ELFSYM_EXPORT(esp_system_include_startup_funcs),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_pkcs1_verify),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_protocol__init),
    ESP_ELFSYM_EXPORT(setlocale),
    ESP_ELFSYM_EXPORT(esp_lcd_dpi_panel_register_event_callbacks),
    ESP_ELFSYM_EXPORT(arg_parse),
    ESP_ELFSYM_EXPORT(ip6_frag),
    ESP_ELFSYM_EXPORT(vListInsert),
    ESP_ELFSYM_EXPORT(ip4_route_src_hook),
    ESP_ELFSYM_EXPORT(esp_tls_internal_event_tracker_destroy),
    ESP_ELFSYM_EXPORT(i2c_new_master_bus),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_update_ad),
    ESP_ELFSYM_EXPORT(rgb_display_refresh_palette),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_renegotiation),
    ESP_ELFSYM_EXPORT(mbedtls_entropy_init),
    ESP_ELFSYM_EXPORT(esp_crypto_ds_lock_release),
    ESP_ELFSYM_EXPORT(is_event_callback_registered),
    ESP_ELFSYM_EXPORT(esp_set_time_from_rtc),
    ESP_ELFSYM_EXPORT(esp_mpi_mult_mpi_failover_mod_mult_hw_op),
    ESP_ELFSYM_EXPORT(netif_get_by_index),
    ESP_ELFSYM_EXPORT(vterm_set_palette),
    ESP_ELFSYM_EXPORT(__sprint_r),
    ESP_ELFSYM_EXPORT(s_register_config_driver),
    ESP_ELFSYM_EXPORT(dw_gdma_channel_enable_ctrl),
    ESP_ELFSYM_EXPORT(esp_vfs_register_fd_range),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_if_cond),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_reset_pin__init),
    ESP_ELFSYM_EXPORT(vterm_switch),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_protocols__descriptor),
    ESP_ELFSYM_EXPORT(igmp_lookfor_group),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_copy),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_storage__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_enterprise_enable__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_make_public),
    ESP_ELFSYM_EXPORT(strcspn),
    ESP_ELFSYM_EXPORT(netif_set_down),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_set_direction__init),
    ESP_ELFSYM_EXPORT(ds_hal_write_message),
    ESP_ELFSYM_EXPORT(esp_mspi_pin_init),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_starts),
    ESP_ELFSYM_EXPORT(rpc__event__mem_monitor__init),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_get_mac),
    ESP_ELFSYM_EXPORT(xTaskGenericNotifyWait),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_detect_size),
    ESP_ELFSYM_EXPORT(esp_intr_disable),
    ESP_ELFSYM_EXPORT(es8156_write_time_control_1),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_is_prime_ext),
    ESP_ELFSYM_EXPORT(pbuf_take),
    ESP_ELFSYM_EXPORT(gpio_reset_pin),
    ESP_ELFSYM_EXPORT(esp_transport_list_destroy),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_client_cert_data),
    ESP_ELFSYM_EXPORT(strstr),
    ESP_ELFSYM_EXPORT(breezybox_exec_init),
    ESP_ELFSYM_EXPORT(nan),
    ESP_ELFSYM_EXPORT(clock_gettime),
    ESP_ELFSYM_EXPORT(vApplicationGetIdleTaskMemory),
    ESP_ELFSYM_EXPORT(rpc__req__set_mode__init),
    ESP_ELFSYM_EXPORT(bsp_input_initialize),
    ESP_ELFSYM_EXPORT(sleep_clock_system_retention_init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_ciphersuite_from_id),
    ESP_ELFSYM_EXPORT(mbedtls_entropy_free),
    ESP_ELFSYM_EXPORT(i2s_hal_init),
    ESP_ELFSYM_EXPORT(get_vfs_for_path),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_enterprise_enable__init),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_get_eof_desc_addr),
    ESP_ELFSYM_EXPORT(gdma_config_transfer),
    ESP_ELFSYM_EXPORT(es8156_write_register_page),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_restore__descriptor),
    ESP_ELFSYM_EXPORT(mmu_hal_vaddr_to_paddr),
    ESP_ELFSYM_EXPORT(xRingbufferSendFromISR),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page15alterEntryStateEjNS0_10EntryStateE),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_ttls_phase2_method__init),
    ESP_ELFSYM_EXPORT(dhcp_coarse_tmr),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_muladd_restartable),
    ESP_ELFSYM_EXPORT(wifi_config__descriptor),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_addr_family),
    ESP_ELFSYM_EXPORT(fread),
    ESP_ELFSYM_EXPORT(rpc__resp__get_dhcp_dns_status__init),
    ESP_ELFSYM_EXPORT(netif_init),
    ESP_ELFSYM_EXPORT(pmu_sleep_disable_regdma_backup),
    ESP_ELFSYM_EXPORT(spi_flash_common_write_status_16b_wrsr),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_ap_get_sta_aid__descriptor),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_setup__init),
    ESP_ELFSYM_EXPORT(vRingbufferDelete),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_interface_name),
    ESP_ELFSYM_EXPORT(__mprec_tinytens),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_bandwidths__descriptor),
    ESP_ELFSYM_EXPORT(_ZdlPv),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_write_signature),
    ESP_ELFSYM_EXPORT(esp_lcd_new_panel_dpi),
    ESP_ELFSYM_EXPORT(sinf),
    ESP_ELFSYM_EXPORT(esp_vfs_register),
    ESP_ELFSYM_EXPORT(spi_flash_hal_suspend),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_disconnect__init),
    ESP_ELFSYM_EXPORT(tcp_pcb_lists),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_uhs1),
    ESP_ELFSYM_EXPORT(netif_get_ip6_addr_match),
    ESP_ELFSYM_EXPORT(raw_bind),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_list_ciphersuites),
    ESP_ELFSYM_EXPORT(esp_partition_read_raw),
    ESP_ELFSYM_EXPORT(gpio_od_enable),
    ESP_ELFSYM_EXPORT(mem_malloc),
    ESP_ELFSYM_EXPORT(esp_libc_init_global_stdio),
    ESP_ELFSYM_EXPORT(tcp_bind_netif),
    ESP_ELFSYM_EXPORT(wifi_scan_threshold__descriptor),
    ESP_ELFSYM_EXPORT(_ZNK3nvs15NVSHandleSimple18get_partition_nameEv),
    ESP_ELFSYM_EXPORT(wifi_country__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_restore__init),
    ESP_ELFSYM_EXPORT(__atexit_recursive_mutex),
    ESP_ELFSYM_EXPORT(g_i2s),
    ESP_ELFSYM_EXPORT(netif_set_addr),
    ESP_ELFSYM_EXPORT(esp_dma_calculate_node_count),
    ESP_ELFSYM_EXPORT(_ZN3nvs7StorageD2Ev),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_bigendian_to_host),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_deinit__init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_fill_random),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_event_no_args__descriptor),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_sta_get_ap_info),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_get_radio_state),
    ESP_ELFSYM_EXPORT(memspi_host_flush_cache),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_starts_soft),
    ESP_ELFSYM_EXPORT(aes_hal_gcm_read_tag),
    ESP_ELFSYM_EXPORT(pbuf_copy_partial_pbuf),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv120__si_class_type_info11__do_upcastEPKNS_17__class_type_infoEPKvRNS1_15__upcast_resultE),
    ESP_ELFSYM_EXPORT(spi_flash_disable_interrupts_caches_and_other_cpu),
    ESP_ELFSYM_EXPORT(cJSON_GetObjectItem),
    ESP_ELFSYM_EXPORT(esp_transport_poll_write),
    ESP_ELFSYM_EXPORT(esp_hw_stack_guard_get_bounds),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_wait_data_ready),
    ESP_ELFSYM_EXPORT(esp_tls_plain_tcp_connect),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_stop_listen__descriptor),
    ESP_ELFSYM_EXPORT(_calloc_r),
    ESP_ELFSYM_EXPORT(compose_rpc_req),
    ESP_ELFSYM_EXPORT(esp_psram_is_initialized),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_init),
    ESP_ELFSYM_EXPORT(linenoiseInsertPastedChar),
    ESP_ELFSYM_EXPORT(heap_caps_check_add_region_allowed),
    ESP_ELFSYM_EXPORT(argtable3_xfree),
    ESP_ELFSYM_EXPORT(esp_ecc_point_multiply),
    ESP_ELFSYM_EXPORT(esp_pm_lock_delete),
    ESP_ELFSYM_EXPORT(sdmmc_host_set_cclk_always_on),
    ESP_ELFSYM_EXPORT(pthread_attr_setstacksize),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_get_eof_desc_addr),
    ESP_ELFSYM_EXPORT(xQueueCreateMutex),
    ESP_ELFSYM_EXPORT(esp_ptr_external_ram),
    ESP_ELFSYM_EXPORT(rpc__pack),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_get_ap_records__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_md),
    ESP_ELFSYM_EXPORT(clock),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_update),
    ESP_ELFSYM_EXPORT(sdmmc_io_wait_int),
    ESP_ELFSYM_EXPORT(_free_r),
    ESP_ELFSYM_EXPORT(console_fsync),
    ESP_ELFSYM_EXPORT(xQueueIsQueueFullFromISR),
    ESP_ELFSYM_EXPORT(__retarget_lock_release),
    ESP_ELFSYM_EXPORT(strtoull),
    ESP_ELFSYM_EXPORT(mbedtls_sha1_init),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashList5clearEv),
    ESP_ELFSYM_EXPORT(fgets),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_dpi_calculate_divider),
    ESP_ELFSYM_EXPORT(efuse_hal_get_major_chip_version),
    ESP_ELFSYM_EXPORT(__wrap_mkdir),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_cmp_mpi),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_identity__init),
    ESP_ELFSYM_EXPORT(systimer_ticks_to_us),
    ESP_ELFSYM_EXPORT(rpc__req__get_ps__descriptor),
    ESP_ELFSYM_EXPORT(set_transport_state),
    ESP_ELFSYM_EXPORT(esp_cache_err_get_panic_info),
    ESP_ELFSYM_EXPORT(_ZN3nvs11PageManager12activatePageEv),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_certificate_and_key__init),
    ESP_ELFSYM_EXPORT(esp_sha_acquire_hardware),
    ESP_ELFSYM_EXPORT(arg_str0),
    ESP_ELFSYM_EXPORT(rpc__req__otaactivate__init),
    ESP_ELFSYM_EXPORT(_lock_acquire),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_setkey_soft),
    ESP_ELFSYM_EXPORT(inflate),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_band__descriptor),
    ESP_ELFSYM_EXPORT(bsp_power_set_radio_state),
    ESP_ELFSYM_EXPORT(close),
    ESP_ELFSYM_EXPORT(gpio_config),
    ESP_ELFSYM_EXPORT(feof),
    ESP_ELFSYM_EXPORT(sdmmc_decode_scr),
    ESP_ELFSYM_EXPORT(regdma_link_new_continuous_default),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple8set_blobEPKcPKvj),
    ESP_ELFSYM_EXPORT(ecc_hal_write_verify_param),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_set_lengths),
    ESP_ELFSYM_EXPORT(i2c_acquire_bus_handle),
    ESP_ELFSYM_EXPORT(rpc__resp__custom_rpc__init),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_set_crc_poly),
    ESP_ELFSYM_EXPORT(gdma_hal_read_intr_status),
    ESP_ELFSYM_EXPORT(mld6_input),
    ESP_ELFSYM_EXPORT(gpio_func_sel),
    ESP_ELFSYM_EXPORT(g_startup_time),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage15getItemDataSizeEhNS_8ItemTypeEPKcRj),
    ESP_ELFSYM_EXPORT(esp_psram_impl_get_available_size),
    ESP_ELFSYM_EXPORT(sdmmc_io_enable_hs_mode),
    ESP_ELFSYM_EXPORT(tlsf_create),
    ESP_ELFSYM_EXPORT(__kernel_cosf),
    ESP_ELFSYM_EXPORT(sdmmc_host_check_buffer_alignment),
    ESP_ELFSYM_EXPORT(intr_handler_set),
    ESP_ELFSYM_EXPORT(sdmmc_decode_ssr),
    ESP_ELFSYM_EXPORT(nd6_find_route),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_new_password__init),
    ESP_ELFSYM_EXPORT(scalbnf),
    ESP_ELFSYM_EXPORT(hosted_usleep),
    ESP_ELFSYM_EXPORT(sys_arch_sem_wait),
    ESP_ELFSYM_EXPORT(esp_flash_chip_winbond),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handle_pending_alert),
    ESP_ELFSYM_EXPORT(rpc__req__set_ps__descriptor),
    ESP_ELFSYM_EXPORT(__action_table),
    ESP_ELFSYM_EXPORT(arg_print_syntax_ds),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_start__descriptor),
    ESP_ELFSYM_EXPORT(gdma_new_ahb_channel),
    ESP_ELFSYM_EXPORT(__ssvfiscanf_r),
    ESP_ELFSYM_EXPORT(strchr),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_can_do),
    ESP_ELFSYM_EXPORT(cache_error_msg),
    ESP_ELFSYM_EXPORT(hosted_timer_start),
    ESP_ELFSYM_EXPORT(esp_vfs_rewinddir),
    ESP_ELFSYM_EXPORT(spi_flash_mmap),
    ESP_ELFSYM_EXPORT(ip4addr_ntoa),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_params__init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_okc_support__init),
    ESP_ELFSYM_EXPORT(httpd_sess_new),
    ESP_ELFSYM_EXPORT(ipaddr_addr),
    ESP_ELFSYM_EXPORT(bootloader_flash_reset_chip),
    ESP_ELFSYM_EXPORT(esp_config_l2_cache_mode),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd),
    ESP_ELFSYM_EXPORT(transport_drv_serial_tx),
    ESP_ELFSYM_EXPORT(rpc__req__iface_mac_addr_len_get__init),
    ESP_ELFSYM_EXPORT(xQueueCreateCountingSemaphoreStatic),
    ESP_ELFSYM_EXPORT(netif_list),
    ESP_ELFSYM_EXPORT(__match),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_gen_privkey),
    ESP_ELFSYM_EXPORT(regdma_link_get_owner_bitmap),
    ESP_ELFSYM_EXPORT(http_auth_basic),
    ESP_ELFSYM_EXPORT(esp_isr_names),
    ESP_ELFSYM_EXPORT(wifi_active_scan_time__descriptor),
    ESP_ELFSYM_EXPORT(sdmmc_select_driver_strength),
    ESP_ELFSYM_EXPORT(_ZN17__eh_globals_init7_S_initE),
    ESP_ELFSYM_EXPORT(cmd_tail),
    ESP_ELFSYM_EXPORT(lfs_mkdir),
    ESP_ELFSYM_EXPORT(tcp_netif_ip_addr_changed),
    ESP_ELFSYM_EXPORT(httpd_sess_close_all),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_write_mpi),
    ESP_ELFSYM_EXPORT(xTaskGetCurrentTaskHandle),
    ESP_ELFSYM_EXPORT(set_event_callback),
    ESP_ELFSYM_EXPORT(esp_log_default_level),
    ESP_ELFSYM_EXPORT(esp_netif_init),
    ESP_ELFSYM_EXPORT(rpc__resp__get_ps__descriptor),
    ESP_ELFSYM_EXPORT(sdmmc_host_get_clk_dividers),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv117__class_type_infoD0Ev),
    ESP_ELFSYM_EXPORT(_panic_handler),
    ESP_ELFSYM_EXPORT(memp_TCP_PCB_LISTEN),
    ESP_ELFSYM_EXPORT(spi_flash_hal_resume),
    ESP_ELFSYM_EXPORT(mspi_timing_flash_config_clear_tuning_regs),
    ESP_ELFSYM_EXPORT(esp_flash_chip_generic),
    ESP_ELFSYM_EXPORT(esp_mbedtls_read),
    ESP_ELFSYM_EXPORT(httpd_recv),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_probe),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_all_send_cid),
    ESP_ELFSYM_EXPORT(__chclass),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_cert_data),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_password__init),
    ESP_ELFSYM_EXPORT(aes_hal_transform_dma_finish),
    ESP_ELFSYM_EXPORT(httpd_sess_get),
    ESP_ELFSYM_EXPORT(gzclose_r),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_listen),
    ESP_ELFSYM_EXPORT(vQueueDelete),
    ESP_ELFSYM_EXPORT(esp_partition_next),
    ESP_ELFSYM_EXPORT(httpd_sess_close_lru),
    ESP_ELFSYM_EXPORT(calloc),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_timeout),
    ESP_ELFSYM_EXPORT(httpd_stop),
    ESP_ELFSYM_EXPORT(mbedtls_pkcs12_pbe_ext),
    ESP_ELFSYM_EXPORT(esp_psram_check_ptr_addr),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page8findItemEhNS_8ItemTypeEPKcRjRNS_4ItemEhNS_9VerOffsetE),
    ESP_ELFSYM_EXPORT(nvs_set_str),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_profile_default),
    ESP_ELFSYM_EXPORT(esp_netif_action_got_ip),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_deauth_sta__descriptor),
    ESP_ELFSYM_EXPORT(memspi_host_erase_chip),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page20updateFirstUsedEntryEjj),
    ESP_ELFSYM_EXPORT(panic_soc_check_pseudo_cause),
    ESP_ELFSYM_EXPORT(esp_vfs_register_fs),
    ESP_ELFSYM_EXPORT(rpc__event__supp_dpp_cfg_recvd__init),
    ESP_ELFSYM_EXPORT(hosted_memset),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_init),
    ESP_ELFSYM_EXPORT(__sfp_lock_release),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_bitlen),
    ESP_ELFSYM_EXPORT(s_head),
    ESP_ELFSYM_EXPORT(esp_event_loop_create_default),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_crypt),
    ESP_ELFSYM_EXPORT(sleep_retention_get_created_modules),
    ESP_ELFSYM_EXPORT(esp_elf_deinit),
    ESP_ELFSYM_EXPORT(ip_addr_any_type),
    ESP_ELFSYM_EXPORT(icmp6_input),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_get_ap_record__descriptor),
    ESP_ELFSYM_EXPORT(tcp_active_pcbs_changed),
    ESP_ELFSYM_EXPORT(cache_hal_invalidate_addr),
    ESP_ELFSYM_EXPORT(xQueueGenericSendFromISR),
    ESP_ELFSYM_EXPORT(esp_clk_cpu_freq),
    ESP_ELFSYM_EXPORT(strncmp),
    ESP_ELFSYM_EXPORT(heap_caps_get_largest_free_block),
    ESP_ELFSYM_EXPORT(nd6_input),
    ESP_ELFSYM_EXPORT(esp_mmu_map_get_max_consecutive_free_block_size),
    ESP_ELFSYM_EXPORT(ldexp),
    ESP_ELFSYM_EXPORT(esp_partition_write_raw),
    ESP_ELFSYM_EXPORT(mbedtls_sha256),
    ESP_ELFSYM_EXPORT(esp_aes_crypt_cfb128),
    ESP_ELFSYM_EXPORT(xRingbufferGetCurFreeSize),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_pac_file__init),
    ESP_ELFSYM_EXPORT(memp_TCP_PCB),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_inactive_time__init),
    ESP_ELFSYM_EXPORT(atexit),
    ESP_ELFSYM_EXPORT(rpc_core_deinit),
    ESP_ELFSYM_EXPORT(gz_error),
    ESP_ELFSYM_EXPORT(i2s_output_gpio_revoke),
    ESP_ELFSYM_EXPORT(pbuf_copy),
    ESP_ELFSYM_EXPORT(gdma_hal_disconnect_peri),
    ESP_ELFSYM_EXPORT(i2c_bus_occupied),
    ESP_ELFSYM_EXPORT(sdmmc_io_init_check_card_cap),
    ESP_ELFSYM_EXPORT(rpc__req__set_mac_address__descriptor),
    ESP_ELFSYM_EXPORT(httpd_start),
    ESP_ELFSYM_EXPORT(__wrap_fopen),
    ESP_ELFSYM_EXPORT(rpc__resp__iface_mac_addr_set_get__init),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_enable_global_ca_store),
    ESP_ELFSYM_EXPORT(esp_psram_extram_add_to_heap_allocator),
    ESP_ELFSYM_EXPORT(xTaskCreatePinnedToCore),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_password__init),
    ESP_ELFSYM_EXPORT(esp_transport_capture_errno),
    ESP_ELFSYM_EXPORT(aes_hal_set_iv),
    ESP_ELFSYM_EXPORT(dw_gdma_channel_register_event_callbacks),
    ESP_ELFSYM_EXPORT(wifi_twt_config__descriptor),
    ESP_ELFSYM_EXPORT(_rename_r),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_bind),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_set_target_wake_time_offset__descriptor),
    ESP_ELFSYM_EXPORT(tcp_shutdown),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_add_mpi),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_free),
    ESP_ELFSYM_EXPORT(esp_crosscore_int_send_yield),
    ESP_ELFSYM_EXPORT(multi_heap_get_info),
    ESP_ELFSYM_EXPORT(regi2c_exit_critical),
    ESP_ELFSYM_EXPORT(_fclose_r),
    ESP_ELFSYM_EXPORT(mbedtls_md_get_size),
    ESP_ELFSYM_EXPORT(netif_remove),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_own_cert),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_get_flow_id_status__init),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_domain_name__init),
    ESP_ELFSYM_EXPORT(fputc),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple10set_stringEPKcS2_),
    ESP_ELFSYM_EXPORT(gdma_hal_get_data_mask_from_matrix),
    ESP_ELFSYM_EXPORT(tlsf_malloc),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_config__descriptor),
    ESP_ELFSYM_EXPORT(sdmmc_host_dma_resume),
    ESP_ELFSYM_EXPORT(__cxa_end_catch),
    ESP_ELFSYM_EXPORT(bsp_audio_initialize),
    ESP_ELFSYM_EXPORT(esp_http_client_close),
    ESP_ELFSYM_EXPORT(rtc_clk_fast_src_set),
    ESP_ELFSYM_EXPORT(strrchr),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page20alterEntryRangeStateEjjNS0_10EntryStateE),
    ESP_ELFSYM_EXPORT(esp_crypto_sha_aes_lock_acquire),
    ESP_ELFSYM_EXPORT(tcp_tmr),
    ESP_ELFSYM_EXPORT(regdma_link_new_continuous),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_identity__init),
    ESP_ELFSYM_EXPORT(rom_flash_chip_dummy_hpm),
    ESP_ELFSYM_EXPORT(mbedtls_sha512_free),
    ESP_ELFSYM_EXPORT(ecc_hal_set_mode),
    ESP_ELFSYM_EXPORT(rpc__resp__config_heartbeat__descriptor),
    ESP_ELFSYM_EXPORT(stat),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_start_handshake_msg),
    ESP_ELFSYM_EXPORT(arg_intn),
    ESP_ELFSYM_EXPORT(_vprintf_r),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_protocols__init),
    ESP_ELFSYM_EXPORT(esp_ipc_isr_port_init),
    ESP_ELFSYM_EXPORT(gdma_get_group_channel_id),
    ESP_ELFSYM_EXPORT(my_console_init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_send_probe_req__descriptor),
    ESP_ELFSYM_EXPORT(esp_transport_read),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_prepare_handshake_record),
    ESP_ELFSYM_EXPORT(cmd_rm),
    ESP_ELFSYM_EXPORT(__pow5mult),
    ESP_ELFSYM_EXPORT(_ZNKSt9type_info14__is_pointer_pEv),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_init),
    ESP_ELFSYM_EXPORT(gpio_pullup_dis),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_get_flow_id_status__descriptor),
    ESP_ELFSYM_EXPORT(vterm_getchar),
    ESP_ELFSYM_EXPORT(dhcp_stop),
    ESP_ELFSYM_EXPORT(ethernet_input),
    ESP_ELFSYM_EXPORT(scalbn),
    ESP_ELFSYM_EXPORT(spi_flash_common_read_status_8b_rdsr2),
    ESP_ELFSYM_EXPORT(tanmatsu_lcd_set_buffer),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_pac_file__init),
    ESP_ELFSYM_EXPORT(transport_pserial_close),
    ESP_ELFSYM_EXPORT(__lo0bits),
    ESP_ELFSYM_EXPORT(esp_crypto_aes_enable_periph_clk),
    ESP_ELFSYM_EXPORT(netif_loop_output),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_start_listen__init),
    ESP_ELFSYM_EXPORT(dma2d_acquire_pool),
    ESP_ELFSYM_EXPORT(valloc),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_x509_ext_type),
    ESP_ELFSYM_EXPORT(breezybox_vfs_init),
    ESP_ELFSYM_EXPORT(crc32),
    ESP_ELFSYM_EXPORT(esp_async_fbcpy),
    ESP_ELFSYM_EXPORT(_findenv),
    ESP_ELFSYM_EXPORT(vQueueWaitForMessageRestricted),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_set_bio),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_ap_info__descriptor),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_setup__descriptor),
    ESP_ELFSYM_EXPORT(dhcps_pbuf_alloc),
    ESP_ELFSYM_EXPORT(multi_heap_set_lock),
    ESP_ELFSYM_EXPORT(netconn_recv_udp_raw_netbuf_flags),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_deauth_sta__descriptor),
    ESP_ELFSYM_EXPORT(tcp_accept),
    ESP_ELFSYM_EXPORT(esp_libc_include_getentropy_impl),
    ESP_ELFSYM_EXPORT(spi_flash_enable_high_performance_mode),
    ESP_ELFSYM_EXPORT(netconn_alloc),
    ESP_ELFSYM_EXPORT(periph_rtc_mpll_acquire),
    ESP_ELFSYM_EXPORT(esp_hosted_add_channel),
    ESP_ELFSYM_EXPORT(gdma_default_rx_isr),
    ESP_ELFSYM_EXPORT(es8156_write_reset_control),
    ESP_ELFSYM_EXPORT(sdmmc_init_io),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_country__init),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_bootstrap_gen__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_zeroize_and_free),
    ESP_ELFSYM_EXPORT(_printf_r),
    ESP_ELFSYM_EXPORT(sdmmc_init_host_bus_width),
    ESP_ELFSYM_EXPORT(esp_console_run),
    ESP_ELFSYM_EXPORT(sys_check_timeouts),
    ESP_ELFSYM_EXPORT(esp_crypto_shared_gdma_start_axi_ahb),
    ESP_ELFSYM_EXPORT(http_header_clean),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_write_signature_restartable),
    ESP_ELFSYM_EXPORT(rpc__resp__mem_monitor__init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_optimize_checksum),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_get_mont_r2_unsafe),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_protocols__init),
    ESP_ELFSYM_EXPORT(esp_timer_impl_set_alarm_id),
    ESP_ELFSYM_EXPORT(strerror),
    ESP_ELFSYM_EXPORT(esp_hosted_init),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_connect),
    ESP_ELFSYM_EXPORT(regi2c_enter_critical),
    ESP_ELFSYM_EXPORT(free),
    ESP_ELFSYM_EXPORT(lwip_setsockopt),
    ESP_ELFSYM_EXPORT(s_active_vt),
    ESP_ELFSYM_EXPORT(_vfiprintf_r),
    ESP_ELFSYM_EXPORT(littlefs_esp_part_write),
    ESP_ELFSYM_EXPORT(__ieee754_fmodf),
    ESP_ELFSYM_EXPORT(esp_crypto_hmac_lock_release),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_deinit__init),
    ESP_ELFSYM_EXPORT(elf_get_cycle_count),
    ESP_ELFSYM_EXPORT(tcpip_send_msg_wait_sem),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_start__init),
    ESP_ELFSYM_EXPORT(rpc__event__custom_rpc__descriptor),
    ESP_ELFSYM_EXPORT(xSemaphoreCreateGenericWithCaps),
    ESP_ELFSYM_EXPORT(_ZSt15get_new_handlerv),
    ESP_ELFSYM_EXPORT(esp_netif_next_unsafe),
    ESP_ELFSYM_EXPORT(regdma_link_new_wait_default),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple14set_typed_itemENS_8ItemTypeEPKcPKvj),
    ESP_ELFSYM_EXPORT(i2c_master_bus_rm_device),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_aid__descriptor),
    ESP_ELFSYM_EXPORT(esp_sync_timekeeping_timers),
    ESP_ELFSYM_EXPORT(my_console_set_output_mode),
    ESP_ELFSYM_EXPORT(esp_hosted_tx),
    ESP_ELFSYM_EXPORT(rpc_wifi_get_mac),
    ESP_ELFSYM_EXPORT(mspi_timing_get_psram_tuning_delaylines),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_scan_get_ap_num),
    ESP_ELFSYM_EXPORT(__swhatbuf_r),
    ESP_ELFSYM_EXPORT(bmi2_i2c_read),
    ESP_ELFSYM_EXPORT(esp_flash_app_enable_os_functions),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_sub_int),
    ESP_ELFSYM_EXPORT(sha_hal_read_digest),
    ESP_ELFSYM_EXPORT(esp_crypto_ecc_lock_release),
    ESP_ELFSYM_EXPORT(_fdopen_r),
    ESP_ELFSYM_EXPORT(gpio_hal_hysteresis_soft_enable),
    ESP_ELFSYM_EXPORT(vterm_get_size),
    ESP_ELFSYM_EXPORT(mem_free),
    ESP_ELFSYM_EXPORT(tcpip_inpkt),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_disconnect),
    ESP_ELFSYM_EXPORT(gpio_set_drive_capability),
    ESP_ELFSYM_EXPORT(mbedtls_pk_sign),
    ESP_ELFSYM_EXPORT(breezybox_set_cwd),
    ESP_ELFSYM_EXPORT(cJSON_ParseWithOpts),
    ESP_ELFSYM_EXPORT(esp_netif_create_default_wifi_sta),
    ESP_ELFSYM_EXPORT(tcp_connect),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_send_probe_req__init),
    ESP_ELFSYM_EXPORT(sdmmc_host_transaction_handler_deinit),
    ESP_ELFSYM_EXPORT(nvs_commit),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimpleD1Ev),
    ESP_ELFSYM_EXPORT(mbedtls_hmac_drbg_reseed),
    ESP_ELFSYM_EXPORT(_ZNSt9bad_allocD1Ev),
    ESP_ELFSYM_EXPORT(inflateResetKeep),
    ESP_ELFSYM_EXPORT(esp_intr_disable_source),
    ESP_ELFSYM_EXPORT(pbuf_add_header_force),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_stop__descriptor),
    ESP_ELFSYM_EXPORT(netconn_free),
    ESP_ELFSYM_EXPORT(wifi_protocols__descriptor),
    ESP_ELFSYM_EXPORT(_i2s_hal_set_tx_clock),
    ESP_ELFSYM_EXPORT(mbedtls_ctr_drbg_free),
    ESP_ELFSYM_EXPORT(dw_gdma_lli_config_transfer),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_public),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_band_mode__init),
    ESP_ELFSYM_EXPORT(bmi270_map_int),
    ESP_ELFSYM_EXPORT(rpc__req__iface_mac_addr_set_get__init),
    ESP_ELFSYM_EXPORT(panic_print_registers),
    ESP_ELFSYM_EXPORT(wifi_sta_info__descriptor),
    ESP_ELFSYM_EXPORT(prefix_list),
    ESP_ELFSYM_EXPORT(esp_hosted_transport_set_default_config),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_band__descriptor),
    ESP_ELFSYM_EXPORT(lcd_com_remove_device),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_bool),
    ESP_ELFSYM_EXPORT(hosted_malloc_align),
    ESP_ELFSYM_EXPORT(rpc__event__supp_dpp_cfg_recvd__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_start_listen__descriptor),
    ESP_ELFSYM_EXPORT(_tr_init),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_read_ocr),
    ESP_ELFSYM_EXPORT(serial_ll_rx_handler),
    ESP_ELFSYM_EXPORT(hosted_sdio_write_reg),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_set_burst_size),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_channel__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page9writeItemEhNS_8ItemTypeEPKcPKvjh),
    ESP_ELFSYM_EXPORT(ip4_output_if_opt),
    ESP_ELFSYM_EXPORT(strlcat),
    ESP_ELFSYM_EXPORT(esp_lcd_new_panel_st7701_rgb),
    ESP_ELFSYM_EXPORT(mbedtls_pk_verify),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_read_binary_le),
    ESP_ELFSYM_EXPORT(esp_chip_info),
    ESP_ELFSYM_EXPORT(console_tcdrain),
    ESP_ELFSYM_EXPORT(vPortYieldOtherCore),
    ESP_ELFSYM_EXPORT(_ZdlPvj),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_reset_pin__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__otaactivate__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__iface_mac_addr_len_get__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_new_password__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_pk_ecc_set_pubkey_from_prv),
    ESP_ELFSYM_EXPORT(pthread_internal_local_storage_destructor_callback),
    ESP_ELFSYM_EXPORT(esp_hosted_get_default_sdio_config),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_pk_alg),
    ESP_ELFSYM_EXPORT(memp_NETBUF),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_setkey),
    ESP_ELFSYM_EXPORT(esp_vfs_console_register),
    ESP_ELFSYM_EXPORT(terminus16_glyph_bitmap),
    ESP_ELFSYM_EXPORT(netconn_recv_tcp_pbuf_flags),
    ESP_ELFSYM_EXPORT(panic_get_cause),
    ESP_ELFSYM_EXPORT(rtc_clk_apll_coeff_calc),
    ESP_ELFSYM_EXPORT(_open_r),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_stop__descriptor),
    ESP_ELFSYM_EXPORT(strndup),
    ESP_ELFSYM_EXPORT(spi_flash_op_block_func),
    ESP_ELFSYM_EXPORT(mbedtls_sha1),
    ESP_ELFSYM_EXPORT(spi_flash_hal_erase_block),
    ESP_ELFSYM_EXPORT(esp_timer_start_once),
    ESP_ELFSYM_EXPORT(regdma_link_init),
    ESP_ELFSYM_EXPORT(esp_psram_impl_get_cs_io),
    ESP_ELFSYM_EXPORT(mspi_timing_enter_high_speed_mode),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_read_public),
    ESP_ELFSYM_EXPORT(rtc_gpio_pulldown_dis),
    ESP_ELFSYM_EXPORT(linenoiseSetMultiLine),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handshake_step),
    ESP_ELFSYM_EXPORT(netif_remove_ext_callback),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_max_tx_power__descriptor),
    ESP_ELFSYM_EXPORT(rpc__descriptor),
    ESP_ELFSYM_EXPORT(periph_rcc_exit),
    ESP_ELFSYM_EXPORT(cJSON_Delete),
    ESP_ELFSYM_EXPORT(protobuf_c_message_pack),
    ESP_ELFSYM_EXPORT(mbedtls_hmac_drbg_random_with_add),
    ESP_ELFSYM_EXPORT(vPortCoprocUsedInISR),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_bandwidth__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsaes_oaep_decrypt),
    ESP_ELFSYM_EXPORT(_remove_r),
    ESP_ELFSYM_EXPORT(sdmmc_host_io_int_wait),
    ESP_ELFSYM_EXPORT(icmp6_dest_unreach),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_reset_pin__init),
    ESP_ELFSYM_EXPORT(_tzset_unlocked),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_montmul_init),
    ESP_ELFSYM_EXPORT(esp_register_freertos_tick_hook_for_cpu),
    ESP_ELFSYM_EXPORT(sdmmc_do_timing_tuning),
    ESP_ELFSYM_EXPORT(_close_r),
    ESP_ELFSYM_EXPORT(__wrap_getcwd),
    ESP_ELFSYM_EXPORT(hosted_sdio_read_reg),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_probe__init),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashList13HashListBlockC1Ev),
    ESP_ELFSYM_EXPORT(protobuf_c_message_init),
    ESP_ELFSYM_EXPORT(sdmmc_host_set_card_clk),
    ESP_ELFSYM_EXPORT(xQueueCreateMutexStatic),
    ESP_ELFSYM_EXPORT(__lock___sinit_recursive_mutex),
    ESP_ELFSYM_EXPORT(fputs),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_set_bus_width),
    ESP_ELFSYM_EXPORT(esp_mbedtls_mem_free),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple20get_used_entry_countERj),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_record),
    ESP_ELFSYM_EXPORT(protobuf_c_enum_descriptor_get_value),
    ESP_ELFSYM_EXPORT(lwip_bind),
    ESP_ELFSYM_EXPORT(pvTaskGetThreadLocalStoragePointer),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_input_enable__init),
    ESP_ELFSYM_EXPORT(vprintf),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_country_code__init),
    ESP_ELFSYM_EXPORT(rgb_display_get_fb_height),
    ESP_ELFSYM_EXPORT(lwip_strnicmp),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_stop),
    ESP_ELFSYM_EXPORT(i2s_channel_init_std_mode),
    ESP_ELFSYM_EXPORT(i2s_gpio_loopback_set),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_bandwidths__descriptor),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_tuning),
    ESP_ELFSYM_EXPORT(console_open),
    ESP_ELFSYM_EXPORT(brownout_hal_config),
    ESP_ELFSYM_EXPORT(sdmmc_init_select_card),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_max_tx_power__descriptor),
    ESP_ELFSYM_EXPORT(sdmmc_host_set_bus_ddr_mode),
    ESP_ELFSYM_EXPORT(esp_vfs_write),
    ESP_ELFSYM_EXPORT(sys_now),
    ESP_ELFSYM_EXPORT(esp_crypto_mpi_lock_release),
    ESP_ELFSYM_EXPORT(mpi_hal_set_mode),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_add_int),
    ESP_ELFSYM_EXPORT(pmu_hp_system_retention_param_default),
    ESP_ELFSYM_EXPORT(__atomic_fetch_and_8),
    ESP_ELFSYM_EXPORT(esp_netif_receive),
    ESP_ELFSYM_EXPORT(esp_crt_bundle_attach),
    ESP_ELFSYM_EXPORT(esp_log_level_get_timeout),
    ESP_ELFSYM_EXPORT(esp_netif_get_nr_of_ifs),
    ESP_ELFSYM_EXPORT(panic_print_dec),
    ESP_ELFSYM_EXPORT(rpc_cmd__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__set_mac_address__init),
    ESP_ELFSYM_EXPORT(lwip_connect),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_lt_ct),
    ESP_ELFSYM_EXPORT(raw_netif_ip_addr_changed),
    ESP_ELFSYM_EXPORT(xPortcheckValidStackMem),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_start),
    ESP_ELFSYM_EXPORT(efuse_hal_chip_revision),
    ESP_ELFSYM_EXPORT(esp_transport_set_errors),
    ESP_ELFSYM_EXPORT(esp_flash_noos_functions),
    ESP_ELFSYM_EXPORT(__sfvwrite_r),
    ESP_ELFSYM_EXPORT(rpc__event__ap__sta_connected__init),
    ESP_ELFSYM_EXPORT(abort),
    ESP_ELFSYM_EXPORT(sdmmc_io_get_cis_data),
    ESP_ELFSYM_EXPORT(hosted_log_write),
    ESP_ELFSYM_EXPORT(linenoiseEditBackspace),
    ESP_ELFSYM_EXPORT(regdma_find_module_link_head),
    ESP_ELFSYM_EXPORT(igmp_leavegroup),
    ESP_ELFSYM_EXPORT(esp_console_init),
    ESP_ELFSYM_EXPORT(esp_mbedtls_handshake),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_client_key_data_der),
    ESP_ELFSYM_EXPORT(esp_task_wdt_print_triggered_tasks),
    ESP_ELFSYM_EXPORT(memspi_host_init_pointers),
    ESP_ELFSYM_EXPORT(rpc__resp__app_get_desc__init),
    ESP_ELFSYM_EXPORT(esp_ecc_point_verify),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_continuous_default),
    ESP_ELFSYM_EXPORT(rtc_isr_noniram_enable),
    ESP_ELFSYM_EXPORT(hosted_create_semaphore),
    ESP_ELFSYM_EXPORT(tcp_err),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_start_listen__init),
    ESP_ELFSYM_EXPORT(__adddf3),
    ESP_ELFSYM_EXPORT(pmu_hal_hp_set_sleep_active_backup_disable),
    ESP_ELFSYM_EXPORT(esp_unregister_shutdown_handler),
    ESP_ELFSYM_EXPORT(esp_mmu_map_init),
    ESP_ELFSYM_EXPORT(vQueueDeleteWithCaps),
    ESP_ELFSYM_EXPORT(unlink),
    ESP_ELFSYM_EXPORT(cache_hal_resume),
    ESP_ELFSYM_EXPORT(_system_r),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_client_cert_data_der),
    ESP_ELFSYM_EXPORT(__locale_mb_cur_max),
    ESP_ELFSYM_EXPORT(regi2c_write_impl),
    ESP_ELFSYM_EXPORT(rpc__resp__otawrite__init),
    ESP_ELFSYM_EXPORT(gdma_hal_start_with_desc),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_add_hs_hdr_to_checksum),
    ESP_ELFSYM_EXPORT(__divdi3),
    ESP_ELFSYM_EXPORT(efuse_hal_get_disable_wafer_version_major),
    ESP_ELFSYM_EXPORT(esp_vfs_fsync),
    ESP_ELFSYM_EXPORT(esp_vfs_stat),
    ESP_ELFSYM_EXPORT(restart_after_slave_ota),
    ESP_ELFSYM_EXPORT(esp_tls_get_conn_sockfd),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_inactive_time__init),
    ESP_ELFSYM_EXPORT(strtoll),
    ESP_ELFSYM_EXPORT(esp_restart),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_keypair_init),
    ESP_ELFSYM_EXPORT(esp_rom_regi2c_write_mask),
    ESP_ELFSYM_EXPORT(tcp_new_ip_type),
    ESP_ELFSYM_EXPORT(_unlink_r),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_stop__init),
    ESP_ELFSYM_EXPORT(rpc__event__dhcp_dns_status__init),
    ESP_ELFSYM_EXPORT(regi2c_read_impl),
    ESP_ELFSYM_EXPORT(__umoddi3),
    ESP_ELFSYM_EXPORT(hosted_restart_slave),
    ESP_ELFSYM_EXPORT(esp_hosted_cli_start),
    ESP_ELFSYM_EXPORT(cosf),
    ESP_ELFSYM_EXPORT(sdmmc_slot_gpio_num),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_shift_l),
    ESP_ELFSYM_EXPORT(vPortSetupTimer),
    ESP_ELFSYM_EXPORT(icmp_dest_unreach),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_sub_abs),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_size),
    ESP_ELFSYM_EXPORT(vTaskInternalSetTimeOutState),
    ESP_ELFSYM_EXPORT(hosted_pull_gpio),
    ESP_ELFSYM_EXPORT(uxListRemove),
    ESP_ELFSYM_EXPORT(xPortSetInterruptMaskFromISR),
    ESP_ELFSYM_EXPORT(transport_drv_reconfigure),
    ESP_ELFSYM_EXPORT(esp_timer_create),
    ESP_ELFSYM_EXPORT(esp_psram_init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_cond_swap),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_write_bytes),
    ESP_ELFSYM_EXPORT(esp_mbedtls_get_bytes_avail),
    ESP_ELFSYM_EXPORT(i2s_channel_enable),
    ESP_ELFSYM_EXPORT(arg_dstr_destroy),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_random),
    ESP_ELFSYM_EXPORT(__hi0bits),
    ESP_ELFSYM_EXPORT(lfs_setattr),
    ESP_ELFSYM_EXPORT(vterm_exit_graphics_mode),
    ESP_ELFSYM_EXPORT(esp_crypto_hmac_enable_periph_clk),
    ESP_ELFSYM_EXPORT(__sglue),
    ESP_ELFSYM_EXPORT(esp_clk_slowclk_cal_get),
    ESP_ELFSYM_EXPORT(esp_newlib_time_init),
    ESP_ELFSYM_EXPORT(esp_newlib_locks_init),
    ESP_ELFSYM_EXPORT(mpi_hal_calc_hardware_words),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_fast_params__descriptor),
    ESP_ELFSYM_EXPORT(memspi_host_set_write_protect),
    ESP_ELFSYM_EXPORT(hosted_calloc),
    ESP_ELFSYM_EXPORT(mpi_hal_wait_op_complete),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_time),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_to_mont_rep),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_alt_info),
    ESP_ELFSYM_EXPORT(rpc__req__set_ps__init),
    ESP_ELFSYM_EXPORT(gdma_hal_deinit),
    ESP_ELFSYM_EXPORT(getchar),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_sub),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_ca_cert__init),
    ESP_ELFSYM_EXPORT(sdmmc_card_init),
    ESP_ELFSYM_EXPORT(esp_elf_malloc),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_verify_restartable),
    ESP_ELFSYM_EXPORT(opterr),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_scan_get_ap_records),
    ESP_ELFSYM_EXPORT(pbuf_add_header),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_finish),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_set_blocklen),
    ESP_ELFSYM_EXPORT(i2c_hal_master_trans_start),
    ESP_ELFSYM_EXPORT(esp_flash_init_default_chip),
    ESP_ELFSYM_EXPORT(esp_intr_get_cpu),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_enterprise_enable__descriptor),
    ESP_ELFSYM_EXPORT(esp_netif_netstack_buf_free),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_check_cert_usage),
    ESP_ELFSYM_EXPORT(_ZNKSt9type_info15__is_function_pEv),
    ESP_ELFSYM_EXPORT(lfs_file_seek),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_version),
    ESP_ELFSYM_EXPORT(heap_caps_aligned_calloc),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_sign_det_restartable),
    ESP_ELFSYM_EXPORT(esp_netif_dhcpc_start),
    ESP_ELFSYM_EXPORT(g_spi_lock_main_flash_dev),
    ESP_ELFSYM_EXPORT(esp_hosted_is_config_valid),
    ESP_ELFSYM_EXPORT(mbedtls_aria_crypt_cbc),
    ESP_ELFSYM_EXPORT(bus_init_internal),
    ESP_ELFSYM_EXPORT(cmd_mv),
    ESP_ELFSYM_EXPORT(spi_timing_get_flash_timing_param),
    ESP_ELFSYM_EXPORT(pthread_exit),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_group_load),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_aid__init),
    ESP_ELFSYM_EXPORT(heap_caps_check_integrity),
    ESP_ELFSYM_EXPORT(lfs_file_opencfg),
    ESP_ELFSYM_EXPORT(lwip_htons),
    ESP_ELFSYM_EXPORT(rpc__resp__ext_coex__descriptor),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_set_write_protect),
    ESP_ELFSYM_EXPORT(esp_netif_down),
    ESP_ELFSYM_EXPORT(rpc__resp__custom_rpc__descriptor),
    ESP_ELFSYM_EXPORT(lwip_close),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_write_ready),
    ESP_ELFSYM_EXPORT(fflush),
    ESP_ELFSYM_EXPORT(lfs_rename),
    ESP_ELFSYM_EXPORT(pthread_include_pthread_cond_var_impl),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_new_password__descriptor),
    ESP_ELFSYM_EXPORT(dw_gdma_new_channel),
    ESP_ELFSYM_EXPORT(multi_heap_minimum_free_size),
    ESP_ELFSYM_EXPORT(__sfp),
    ESP_ELFSYM_EXPORT(aes_hal_mode_init),
    ESP_ELFSYM_EXPORT(__sinit),
    ESP_ELFSYM_EXPORT(retrans_timer),
    ESP_ELFSYM_EXPORT(netif_invoke_ext_callback),
    ESP_ELFSYM_EXPORT(periph_rtc_apll_freq_set),
    ESP_ELFSYM_EXPORT(_esp_error_check_failed),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_connect__init),
    ESP_ELFSYM_EXPORT(mbedtls_sha1_clone),
    ESP_ELFSYM_EXPORT(xTaskGetTickCountFromISR),
    ESP_ELFSYM_EXPORT(netconn_disconnect),
    ESP_ELFSYM_EXPORT(http_header_generate_string),
    ESP_ELFSYM_EXPORT(rpc_feature__descriptor),
    ESP_ELFSYM_EXPORT(_lock_try_acquire_recursive),
    ESP_ELFSYM_EXPORT(div),
    ESP_ELFSYM_EXPORT(sdmmc_host_wait_for_event),
    ESP_ELFSYM_EXPORT(arg_end),
    ESP_ELFSYM_EXPORT(dhcps_set_option_info),
    ESP_ELFSYM_EXPORT(__atexit),
    ESP_ELFSYM_EXPORT(tlsf_alloc_overhead),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_dpp_cfg_recvd__descriptor),
    ESP_ELFSYM_EXPORT(esp_netif_add_to_list_unsafe),
    ESP_ELFSYM_EXPORT(esp_crypto_hmac_lock_acquire),
    ESP_ELFSYM_EXPORT(__fixdfsi),
    ESP_ELFSYM_EXPORT(lfs_dir_close),
    ESP_ELFSYM_EXPORT(rtc_io_num_map),
    ESP_ELFSYM_EXPORT(etharp_add_static_entry),
    ESP_ELFSYM_EXPORT(sys_arch_mbox_fetch),
    ESP_ELFSYM_EXPORT(clk_hal_cpu_get_freq_hz),
    ESP_ELFSYM_EXPORT(rpc__req__eap_use_default_cert_bundle__init),
    ESP_ELFSYM_EXPORT(pau_hal_set_regdma_wait_timeout),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_country_code__descriptor),
    ESP_ELFSYM_EXPORT(wifi_remote_initialize),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_endpoint),
    ESP_ELFSYM_EXPORT(soc_memory_types),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_subject_alt_name_ext),
    ESP_ELFSYM_EXPORT(dw_gdma_lli_set_block_markers),
    ESP_ELFSYM_EXPORT(heap_caps_calloc_base),
    ESP_ELFSYM_EXPORT(esp_event_handler_register),
    ESP_ELFSYM_EXPORT(rpc__resp__iface_mac_addr_len_get__descriptor),
    ESP_ELFSYM_EXPORT(__eqdf2),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page4loadEPNS_9PartitionEm),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_get_bitlen),
    ESP_ELFSYM_EXPORT(strtof_l),
    ESP_ELFSYM_EXPORT(rpc__resp__get_coprocessor_fw_version__init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_max_tx_power__init),
    ESP_ELFSYM_EXPORT(sys_init),
    ESP_ELFSYM_EXPORT(arg_dstr_create),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_channel__init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_connect__init),
    ESP_ELFSYM_EXPORT(esp_cpu_intr_get_desc),
    ESP_ELFSYM_EXPORT(_write_r),
    ESP_ELFSYM_EXPORT(_fprintf_r),
    ESP_ELFSYM_EXPORT(clk_hal_apll_get_freq_hz),
    ESP_ELFSYM_EXPORT(_exit),
    ESP_ELFSYM_EXPORT(hosted_msleep),
    ESP_ELFSYM_EXPORT(lfs_file_read),
    ESP_ELFSYM_EXPORT(sdmmc_slot_gpio_sig),
    ESP_ELFSYM_EXPORT(bmi2_set_regs),
    ESP_ELFSYM_EXPORT(esp_cpu_wait_for_intr),
    ESP_ELFSYM_EXPORT(fprintf),
    ESP_ELFSYM_EXPORT(sdmmc_card_print_info),
    ESP_ELFSYM_EXPORT(wifi_sta_config__descriptor),
    ESP_ELFSYM_EXPORT(wifi_event_sta_scan_done__init),
    ESP_ELFSYM_EXPORT(tlsf_size),
    ESP_ELFSYM_EXPORT(__retarget_lock_try_acquire_recursive),
    ESP_ELFSYM_EXPORT(cache_hal_writeback_addr),
    ESP_ELFSYM_EXPORT(esp_transport_list_get_transport),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_common_name),
    ESP_ELFSYM_EXPORT(esp_transport_init),
    ESP_ELFSYM_EXPORT(mbedtls_sha256_finish),
    ESP_ELFSYM_EXPORT(__multiply),
    ESP_ELFSYM_EXPORT(esp_cache_get_alignment),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv120__si_class_type_info20__do_find_public_srcEiPKvPKNS_17__class_type_infoES2_),
    ESP_ELFSYM_EXPORT(tcp_listen_with_backlog_and_err),
    ESP_ELFSYM_EXPORT(tanmatsu_lcd_mark_dirty),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_cmp_abs),
    ESP_ELFSYM_EXPORT(rpc__event__espinit__descriptor),
    ESP_ELFSYM_EXPORT(_rewind_r),
    ESP_ELFSYM_EXPORT(vTaskGetSnapshot),
    ESP_ELFSYM_EXPORT(xRingbufferCreate),
    ESP_ELFSYM_EXPORT(esp_deep_sleep_wakeup_io_reset),
    ESP_ELFSYM_EXPORT(udp_new),
    ESP_ELFSYM_EXPORT(netconn_listen_with_backlog),
    ESP_ELFSYM_EXPORT(rtos_int_exit),
    ESP_ELFSYM_EXPORT(ecc_hal_enable_constant_time_point_mul),
    ESP_ELFSYM_EXPORT(nvs_flash_init_partition),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_join_leave_group_netif),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_sign_restartable),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_curve_info_from_grp_id),
    ESP_ELFSYM_EXPORT(rtc_gpio_hold_dis),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_gethostbyname),
    ESP_ELFSYM_EXPORT(sdmmc_init_mmc_check_ext_csd),
    ESP_ELFSYM_EXPORT(multi_heap_minimum_free_size_impl),
    ESP_ELFSYM_EXPORT(pthread_include_pthread_rwlock_impl),
    ESP_ELFSYM_EXPORT(esp_http_client_set_url),
    ESP_ELFSYM_EXPORT(esp_console_register_help_command),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_get_level__descriptor),
    ESP_ELFSYM_EXPORT(memp_SYS_TIMEOUT),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_stop__descriptor),
    ESP_ELFSYM_EXPORT(esp_cpu_configure_region_protection),
    ESP_ELFSYM_EXPORT(mbedtls_entropy_add_source),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_sig_from_pk_alg),
    ESP_ELFSYM_EXPORT(esp_partition_mmap),
    ESP_ELFSYM_EXPORT(esp_mpi_mul_mpi_hw_op),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_mod_mpi),
    ESP_ELFSYM_EXPORT(dhcp_cleanup),
    ESP_ELFSYM_EXPORT(esp_partition_munmap),
    ESP_ELFSYM_EXPORT(esp_startup_start_app_other_cores),
    ESP_ELFSYM_EXPORT(esp_event_handler_unregister_with),
    ESP_ELFSYM_EXPORT(bmi2_soft_reset),
    ESP_ELFSYM_EXPORT(xTaskGetCoreID),
    ESP_ELFSYM_EXPORT(lwip_recvfrom),
    ESP_ELFSYM_EXPORT(mbedtls_pk_verify_restartable),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_max_out_record_payload),
    ESP_ELFSYM_EXPORT(mbedtls_sha512_init),
    ESP_ELFSYM_EXPORT(sdmmc_init_cid),
    ESP_ELFSYM_EXPORT(pthread_getspecific),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_ec_grp_algid),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_eap_methods__descriptor),
    ESP_ELFSYM_EXPORT(esp_vfs_littlefs_register),
    ESP_ELFSYM_EXPORT(sdmmc_init_ocr),
    ESP_ELFSYM_EXPORT(esp_transport_init_foundation_transport),
    ESP_ELFSYM_EXPORT(rpc__gpio_config__init),
    ESP_ELFSYM_EXPORT(memcpy),
    ESP_ELFSYM_EXPORT(mbedtls_net_init),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_dpp_uri_ready__descriptor),
    ESP_ELFSYM_EXPORT(gpio_install_isr_service),
    ESP_ELFSYM_EXPORT(refreshShowHints),
    ESP_ELFSYM_EXPORT(vTaskPrioritySet),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_write_binary),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_alg_null),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_shift_r),
    ESP_ELFSYM_EXPORT(mbedtls_net_send),
    ESP_ELFSYM_EXPORT(ip_input),
    ESP_ELFSYM_EXPORT(vRingbufferReturnItem),
    ESP_ELFSYM_EXPORT(__cxa_get_globals_fast),
    ESP_ELFSYM_EXPORT(__mcmp),
    ESP_ELFSYM_EXPORT(esp_transport_write),
    ESP_ELFSYM_EXPORT(multi_heap_get_info_impl),
    ESP_ELFSYM_EXPORT(rpc_parse_rsp),
    ESP_ELFSYM_EXPORT(esp_psram_impl_enable),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_authmode),
    ESP_ELFSYM_EXPORT(xQueueGetMutexHolder),
    ESP_ELFSYM_EXPORT(pau_hal_set_regdma_work_timeout),
    ESP_ELFSYM_EXPORT(_vfprintf_r),
    ESP_ELFSYM_EXPORT(vSystimerSetup),
    ESP_ELFSYM_EXPORT(ip4_frag),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_set_mode),
    ESP_ELFSYM_EXPORT(esp_mmu_vaddr_to_paddr),
    ESP_ELFSYM_EXPORT(cJSON_Parse),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_tls_version),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_enterprise_enable__init),
    ESP_ELFSYM_EXPORT(mbedtls_net_recv),
    ESP_ELFSYM_EXPORT(vPortFree),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_negotiated_phymode__descriptor),
    ESP_ELFSYM_EXPORT(esp_cache_err_has_active_err),
    ESP_ELFSYM_EXPORT(_ZSt7nothrow),
    ESP_ELFSYM_EXPORT(esp_crypto_shared_gdma_done),
    ESP_ELFSYM_EXPORT(rpc_core_init),
    ESP_ELFSYM_EXPORT(rpc__resp__get_dhcp_dns_status__descriptor),
    ESP_ELFSYM_EXPORT(esp_transport_list_clean),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_page_program),
    ESP_ELFSYM_EXPORT(tcp_output),
    ESP_ELFSYM_EXPORT(esp_intr_alloc_intrstatus),
    ESP_ELFSYM_EXPORT(breezybox_register_commands),
    ESP_ELFSYM_EXPORT(__swbuf),
    ESP_ELFSYM_EXPORT(esp_libc_locks_init),
    ESP_ELFSYM_EXPORT(__floatdidf),
    ESP_ELFSYM_EXPORT(g_startup_fn),
    ESP_ELFSYM_EXPORT(_user_strerror),
    ESP_ELFSYM_EXPORT(wifi_bandwidths__init),
    ESP_ELFSYM_EXPORT(arg_print_glossary_ds),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_scan_start),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_ap_get_sta_list__init),
    ESP_ELFSYM_EXPORT(frexp),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_update),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_bootstrap_gen__descriptor),
    ESP_ELFSYM_EXPORT(netif_default),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_close),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_parse),
    ESP_ELFSYM_EXPORT(__assert_func),
    ESP_ELFSYM_EXPORT(esp_crosscore_int_send_print_backtrace),
    ESP_ELFSYM_EXPORT(usleep),
    ESP_ELFSYM_EXPORT(mld6_leavegroup),
    ESP_ELFSYM_EXPORT(pbuf_alloc),
    ESP_ELFSYM_EXPORT(pmu_init),
    ESP_ELFSYM_EXPORT(_global_interrupt_handler),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_rssi__descriptor),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_connect),
    ESP_ELFSYM_EXPORT(wifi_ap_config__descriptor),
    ESP_ELFSYM_EXPORT(esp_log_cache_clean),
    ESP_ELFSYM_EXPORT(__retarget_lock_acquire),
    ESP_ELFSYM_EXPORT(__ieee754_sqrtf),
    ESP_ELFSYM_EXPORT(rtcio_hal_set_direction),
    ESP_ELFSYM_EXPORT(srand),
    ESP_ELFSYM_EXPORT(esp_vfs_close),
    ESP_ELFSYM_EXPORT(udp_disconnect),
    ESP_ELFSYM_EXPORT(esp_netif_set_driver_config),
    ESP_ELFSYM_EXPORT(mmu_hal_check_valid_ext_vaddr_region),
    ESP_ELFSYM_EXPORT(inet_chksum_pbuf),
    ESP_ELFSYM_EXPORT(rtc_io_number_get),
    ESP_ELFSYM_EXPORT(_tr_flush_block),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_config_defaults),
    ESP_ELFSYM_EXPORT(call_start_cpu0),
    ESP_ELFSYM_EXPORT(multi_heap_malloc_impl),
    ESP_ELFSYM_EXPORT(_ZSt13get_terminatev),
    ESP_ELFSYM_EXPORT(multi_heap_aligned_alloc_impl_offs),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_select_best_tuning_delayline),
    ESP_ELFSYM_EXPORT(dns_init),
    ESP_ELFSYM_EXPORT(esp_ota_get_running_partition),
    ESP_ELFSYM_EXPORT(_i2c_hal_set_bus_timing),
    ESP_ELFSYM_EXPORT(netif_add),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_add),
    ESP_ELFSYM_EXPORT(mpi_hal_start_op),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_set_level__init),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_check_status),
    ESP_ELFSYM_EXPORT(aes_hal_read_iv),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_read_version),
    ESP_ELFSYM_EXPORT(esp_ipc_isr_end_fl),
    ESP_ELFSYM_EXPORT(deflateReset),
    ESP_ELFSYM_EXPORT(esp_hosted_set_default_config),
    ESP_ELFSYM_EXPORT(pthread_include_pthread_impl),
    ESP_ELFSYM_EXPORT(wifi_scan_channel_bitmap__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_montmul),
    ESP_ELFSYM_EXPORT(rpc_copy_wifi_sta_config),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_disable_time_check__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_clear_fast_connect__init),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_client_key_password),
    ESP_ELFSYM_EXPORT(esp_hw_stack_guard_get_pc),
    ESP_ELFSYM_EXPORT(is_transport_rx_ready),
    ESP_ELFSYM_EXPORT(gdma_hal_enable_intr),
    ESP_ELFSYM_EXPORT(mbedtls_ms_time),
    ESP_ELFSYM_EXPORT(netconn_connect),
    ESP_ELFSYM_EXPORT(fmodf),
    ESP_ELFSYM_EXPORT(bootloader_flash_execute_command_common),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_protocols__descriptor),
    ESP_ELFSYM_EXPORT(__retarget_lock_init_recursive),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_stop_listen__descriptor),
    ESP_ELFSYM_EXPORT(tcp_zero_window_probe),
    ESP_ELFSYM_EXPORT(mbedtls_aria_crypt_ecb),
    ESP_ELFSYM_EXPORT(mempool_alloc),
    ESP_ELFSYM_EXPORT(rpc__resp__get_mac_address__descriptor),
    ESP_ELFSYM_EXPORT(dma2d_get_trans_elm_size),
    ESP_ELFSYM_EXPORT(wifi_config__init),
    ESP_ELFSYM_EXPORT(tcp_rexmit_rto_commit),
    ESP_ELFSYM_EXPORT(_gettimeofday_r),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_finish),
    ESP_ELFSYM_EXPORT(esp_libc_include_heap_impl),
    ESP_ELFSYM_EXPORT(rpc__resp__ext_coex__init),
    ESP_ELFSYM_EXPORT(memp_NETDB),
    ESP_ELFSYM_EXPORT(esp_console_split_argv),
    ESP_ELFSYM_EXPORT(__fp_unlock_all),
    ESP_ELFSYM_EXPORT(udp_input),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_setup__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage15clearNamespacesEv),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_info),
    ESP_ELFSYM_EXPORT(set_client_config),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage20eraseOrphanDataBlobsER14intrusive_listINS0_13BlobIndexNodeEE),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_set_select_notif_callback),
    ESP_ELFSYM_EXPORT(ip6addr_ntoa_r),
    ESP_ELFSYM_EXPORT(mbedtls_pk_encrypt),
    ESP_ELFSYM_EXPORT(esp_lcd_del_dsi_bus),
    ESP_ELFSYM_EXPORT(rand),
    ESP_ELFSYM_EXPORT(sdmmc_check_scr),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_bandwidth__descriptor),
    ESP_ELFSYM_EXPORT(httpd_register_uri_handler),
    ESP_ELFSYM_EXPORT(esp_gpio_revoke),
    ESP_ELFSYM_EXPORT(i2s_new_channel),
    ESP_ELFSYM_EXPORT(console_tcgetattr),
    ESP_ELFSYM_EXPORT(arg_print_errors_ds),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_suspend__init),
    ESP_ELFSYM_EXPORT(gdma_new_channel),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_inactive_time__init),
    ESP_ELFSYM_EXPORT(g_flash_guard_default_ops),
    ESP_ELFSYM_EXPORT(mbedtls_md_hmac_update),
    ESP_ELFSYM_EXPORT(esp_partition_find_first),
    ESP_ELFSYM_EXPORT(esp_transport_set_func),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_finish_soft),
    ESP_ELFSYM_EXPORT(netconn_gethostbyname_addrtype),
    ESP_ELFSYM_EXPORT(esp_ipc_isr_start_fl),
    ESP_ELFSYM_EXPORT(esp_ipc_call_blocking),
    ESP_ELFSYM_EXPORT(wifi_scan_time__init),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_new_password__init),
    ESP_ELFSYM_EXPORT(es8156_write_sdp_interface_config_1),
    ESP_ELFSYM_EXPORT(nd6_tmr),
    ESP_ELFSYM_EXPORT(xTaskGenericNotify),
    ESP_ELFSYM_EXPORT(rpc_wifi_set_config),
    ESP_ELFSYM_EXPORT(esp_log_set_vprintf),
    ESP_ELFSYM_EXPORT(cache_hal_get_cache_line_size),
    ESP_ELFSYM_EXPORT(rpc_wifi_disconnect),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_check_key_usage),
    ESP_ELFSYM_EXPORT(regi2c_read_mask_impl),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_verify_certificate),
    ESP_ELFSYM_EXPORT(st7701_get_parameters),
    ESP_ELFSYM_EXPORT(esp_clk_tree_src_get_freq_hz),
    ESP_ELFSYM_EXPORT(lfs_fs_size),
    ESP_ELFSYM_EXPORT(_g_esp_netif_netstack_default_wifi_sta),
    ESP_ELFSYM_EXPORT(mbedtls_free),
    ESP_ELFSYM_EXPORT(rtc_clk_apll_enable),
    ESP_ELFSYM_EXPORT(_tzname),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page8SEC_SIZEE),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple8find_keyEPKcR10nvs_type_t),
    ESP_ELFSYM_EXPORT(__ashldi3),
    ESP_ELFSYM_EXPORT(mktime),
    ESP_ELFSYM_EXPORT(http_utils_trim_whitespace),
    ESP_ELFSYM_EXPORT(spi_flash_encryption_hal_destroy),
    ESP_ELFSYM_EXPORT(esp_log_impl_lock_timeout),
    ESP_ELFSYM_EXPORT(i2s_output_gpio_reserve),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_event_no_args__init),
    ESP_ELFSYM_EXPORT(esp_panic_handler_disable_timg_wdts),
    ESP_ELFSYM_EXPORT(deflate),
    ESP_ELFSYM_EXPORT(gz_intmax),
    ESP_ELFSYM_EXPORT(vTaskDeleteWithCaps),
    ESP_ELFSYM_EXPORT(wifi_twt_config__init),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashList13HashListBlockC2Ev),
    ESP_ELFSYM_EXPORT(sd_pwr_ctrl_set_io_voltage),
    ESP_ELFSYM_EXPORT(rpc__resp__mem_monitor__descriptor),
    ESP_ELFSYM_EXPORT(esp_flash_write),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_parse_alpn_ext),
    ESP_ELFSYM_EXPORT(esp_vfs_include_console_register),
    ESP_ELFSYM_EXPORT(esp_pbuf_allocate),
    ESP_ELFSYM_EXPORT(my_console_get_output_mode),
    ESP_ELFSYM_EXPORT(breezybox_cwd),
    ESP_ELFSYM_EXPORT(esp_partition_find),
    ESP_ELFSYM_EXPORT(localtime),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_setup__init),
    ESP_ELFSYM_EXPORT(esp_tls_conn_new_async),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_is_revoked),
    ESP_ELFSYM_EXPORT(port_uxInterruptNesting),
    ESP_ELFSYM_EXPORT(qsort),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_set_pull_mode__descriptor),
    ESP_ELFSYM_EXPORT(_sungetc_r),
    ESP_ELFSYM_EXPORT(wifi_he_ap_info__init),
    ESP_ELFSYM_EXPORT(acd_start),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_set_zero),
    ESP_ELFSYM_EXPORT(rpc__req__otawrite__init),
    ESP_ELFSYM_EXPORT(esp_vfs_dev_usb_serial_jtag_register),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_subject_alt_name),
    ESP_ELFSYM_EXPORT(rpc__unpack),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_gen_write_short_packet),
    ESP_ELFSYM_EXPORT(tcp_seg_free),
    ESP_ELFSYM_EXPORT(dma2d_set_desc_addr),
    ESP_ELFSYM_EXPORT(esp_event_loop_create),
    ESP_ELFSYM_EXPORT(netconn_accept),
    ESP_ELFSYM_EXPORT(rgb_display_get_framebuffer),
    ESP_ELFSYM_EXPORT(esp_setup_newlib_syscalls),
    ESP_ELFSYM_EXPORT(esp_partition_read),
    ESP_ELFSYM_EXPORT(cmd_free),
    ESP_ELFSYM_EXPORT(cmd_date),
    ESP_ELFSYM_EXPORT(spi_flash_encryption_hal_done),
    ESP_ELFSYM_EXPORT(_ftell_r),
    ESP_ELFSYM_EXPORT(littlefs_esp_part_erase),
    ESP_ELFSYM_EXPORT(arg_strn),
    ESP_ELFSYM_EXPORT(panicHandler),
    ESP_ELFSYM_EXPORT(rtc_time_get),
    ESP_ELFSYM_EXPORT(_tr_stored_block),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_init__init),
    ESP_ELFSYM_EXPORT(esp_partition_main_flash_region_safe),
    ESP_ELFSYM_EXPORT(sys_mutex_lock),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_auth_decrypt),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_free),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_teardown__descriptor),
    ESP_ELFSYM_EXPORT(rtc_clk_slow_src_get),
    ESP_ELFSYM_EXPORT(lwip_sendto),
    ESP_ELFSYM_EXPORT(utoa),
    ESP_ELFSYM_EXPORT(esp_tls_internal_event_tracker_create),
    ESP_ELFSYM_EXPORT(httpd_recv_with_opt),
    ESP_ELFSYM_EXPORT(mspi_timing_get_psram_tuning_phases),
    ESP_ELFSYM_EXPORT(esp_netif_get_handle_from_ifkey_unsafe),
    ESP_ELFSYM_EXPORT(rtc_clk_cpu_freq_mhz_to_config),
    ESP_ELFSYM_EXPORT(gdma_apply_strategy),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_dpp_fail__descriptor),
    ESP_ELFSYM_EXPORT(_tzset_r),
    ESP_ELFSYM_EXPORT(esp_libc_include_pthread_impl),
    ESP_ELFSYM_EXPORT(sdmmc_init_mmc_bus_width),
    ESP_ELFSYM_EXPORT(esp_aes_intr_alloc),
    ESP_ELFSYM_EXPORT(lfs_remove),
    ESP_ELFSYM_EXPORT(tcp_input),
    ESP_ELFSYM_EXPORT(sys_mbox_new),
    ESP_ELFSYM_EXPORT(send_slave_config),
    ESP_ELFSYM_EXPORT(cs_free_ctrl_sock),
    ESP_ELFSYM_EXPORT(esp_http_client_add_auth),
    ESP_ELFSYM_EXPORT(protobuf_c_message_unpack),
    ESP_ELFSYM_EXPORT(spi_flash_needs_reset_check),
    ESP_ELFSYM_EXPORT(rpc__req__get_dhcp_dns_status__init),
    ESP_ELFSYM_EXPORT(gpio_output_enable),
    ESP_ELFSYM_EXPORT(pmu_hp_system_analog_param_default),
    ESP_ELFSYM_EXPORT(rpc__event__heartbeat__descriptor),
    ESP_ELFSYM_EXPORT(fstat),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_ap_get_sta_list__init),
    ESP_ELFSYM_EXPORT(sys_sem_new),
    ESP_ELFSYM_EXPORT(aes_hal_transform_dma_gcm_start),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_update_ad_soft),
    ESP_ELFSYM_EXPORT(strtoll_l),
    ESP_ELFSYM_EXPORT(gpio_output_disable),
    ESP_ELFSYM_EXPORT(_getc_r),
    ESP_ELFSYM_EXPORT(ip4_route),
    ESP_ELFSYM_EXPORT(vRingbufferGetInfo),
    ESP_ELFSYM_EXPORT(__ltdf2),
    ESP_ELFSYM_EXPORT(httpd_default_recv),
    ESP_ELFSYM_EXPORT(esp_crt_verify_callback),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_deduce_crt),
    ESP_ELFSYM_EXPORT(__wrap_chdir),
    ESP_ELFSYM_EXPORT(esp_transport_get_error_handle),
    ESP_ELFSYM_EXPORT(xQueueCreateCountingSemaphore),
    ESP_ELFSYM_EXPORT(__udivdi3),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_init),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_read_intr_status),
    ESP_ELFSYM_EXPORT(lwip_send),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_definitions),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_update_ad),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_get_caps),
    ESP_ELFSYM_EXPORT(esp_psram_impl_get_physical_size),
    ESP_ELFSYM_EXPORT(esp_system_abort),
    ESP_ELFSYM_EXPORT(sdmmc_init_spi_crc),
    ESP_ELFSYM_EXPORT(serial_rx_handler),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_init),
    ESP_ELFSYM_EXPORT(getMillis),
    ESP_ELFSYM_EXPORT(esp_transport_esp_tls_destroy),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_band_mode__init),
    ESP_ELFSYM_EXPORT(esp_vfs_access),
    ESP_ELFSYM_EXPORT(esp_vApplicationTickHook),
    ESP_ELFSYM_EXPORT(esp_mpi_disable_hardware_hw_op),
    ESP_ELFSYM_EXPORT(rpc__get_packed_size),
    ESP_ELFSYM_EXPORT(httpd_resp_set_status),
    ESP_ELFSYM_EXPORT(_ftello_r),
    ESP_ELFSYM_EXPORT(spi_flash_chip_winbond_probe),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_scan_start),
    ESP_ELFSYM_EXPORT(rpc__req__get_mac_address__descriptor),
    ESP_ELFSYM_EXPORT(ip4_addr_isbroadcast_u32),
    ESP_ELFSYM_EXPORT(_Znwj),
    ESP_ELFSYM_EXPORT(esp_hosted_sdio_set_config),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_set_priority),
    ESP_ELFSYM_EXPORT(httpd_sess_pending),
    ESP_ELFSYM_EXPORT(rpc__req__app_get_desc__descriptor),
    ESP_ELFSYM_EXPORT(mpi_hal_enable_constant_time),
    ESP_ELFSYM_EXPORT(periph_rtc_apll_acquire),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition9write_rawEjPKvj),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_alpn_ext),
    ESP_ELFSYM_EXPORT(soc_get_available_memory_region_max_count),
    ESP_ELFSYM_EXPORT(esp_cache_msync),
    ESP_ELFSYM_EXPORT(netconn_new_with_proto_and_callback),
    ESP_ELFSYM_EXPORT(nvs_close),
    ESP_ELFSYM_EXPORT(esp_wifi_set_default_wifi_sta_handlers),
    ESP_ELFSYM_EXPORT(esp_netif_update_default_netif),
    ESP_ELFSYM_EXPORT(inet_chksum_pseudo),
    ESP_ELFSYM_EXPORT(_sniprintf_r),
    ESP_ELFSYM_EXPORT(io_mux_enable_lp_io_clock),
    ESP_ELFSYM_EXPORT(hosted_sdio_write_block),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_protocols__descriptor),
    ESP_ELFSYM_EXPORT(__register_exitproc),
    ESP_ELFSYM_EXPORT(console_close),
    ESP_ELFSYM_EXPORT(panic_restart),
    ESP_ELFSYM_EXPORT(esp_register_shutdown_handler),
    ESP_ELFSYM_EXPORT(nvs_open),
    ESP_ELFSYM_EXPORT(neighbor_cache),
    ESP_ELFSYM_EXPORT(esp_panic_handler),
    ESP_ELFSYM_EXPORT(eap_fast_config__init),
    ESP_ELFSYM_EXPORT(wifi_sta_list__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager12get_instanceEv),
    ESP_ELFSYM_EXPORT(cJSON_GetArraySize),
    ESP_ELFSYM_EXPORT(netbuf_free),
    ESP_ELFSYM_EXPORT(xQueueGiveFromISR),
    ESP_ELFSYM_EXPORT(tcp_pcb_remove),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_session_tickets),
    ESP_ELFSYM_EXPORT(regi2c_write_mask_impl),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_setup),
    ESP_ELFSYM_EXPORT(xTaskRemoveFromEventList),
    ESP_ELFSYM_EXPORT(rpc__resp__get_mode__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage22calcEntriesInNamespaceEhRj),
    ESP_ELFSYM_EXPORT(g_h),
    ESP_ELFSYM_EXPORT(__bswapsi2),
    ESP_ELFSYM_EXPORT(hosted_setup_gpio_interrupt),
    ESP_ELFSYM_EXPORT(__gedf2),
    ESP_ELFSYM_EXPORT(_fstat_r),
    ESP_ELFSYM_EXPORT(mbedtls_sha512_starts),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_set_radio_state),
    ESP_ELFSYM_EXPORT(abs),
    ESP_ELFSYM_EXPORT(rpc__event__sta_connected__init),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_gen_write_dcs_command),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_shrink),
    ESP_ELFSYM_EXPORT(netif_set_link_up),
    ESP_ELFSYM_EXPORT(strtok),
    ESP_ELFSYM_EXPORT(rewinddir),
    ESP_ELFSYM_EXPORT(dns_mquery_v4group),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager12close_handleEPNS_15NVSHandleSimpleE),
    ESP_ELFSYM_EXPORT(esp_tls_init),
    ESP_ELFSYM_EXPORT(closedir),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_skip_common_name_check),
    ESP_ELFSYM_EXPORT(hosted_destroy_lock_mempool),
    ESP_ELFSYM_EXPORT(udp_pcbs),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_is_zero),
    ESP_ELFSYM_EXPORT(linenoiseEditDeletePrevWord),
    ESP_ELFSYM_EXPORT(mpi_hal_interrupt_enable),
    ESP_ELFSYM_EXPORT(fileno),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_serial),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_info),
    ESP_ELFSYM_EXPORT(hosted_free_align),
    ESP_ELFSYM_EXPORT(environ),
    ESP_ELFSYM_EXPORT(startup_resume_other_cores),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_read_key),
    ESP_ELFSYM_EXPORT(esp_http_client_perform),
    ESP_ELFSYM_EXPORT(sdmmc_enter_higher_speed_mode),
    ESP_ELFSYM_EXPORT(esp_intr_free),
    ESP_ELFSYM_EXPORT(tcp_rexmit_fast),
    ESP_ELFSYM_EXPORT(esp_vApplicationIdleHook),
    ESP_ELFSYM_EXPORT(_mprec_log10),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_init__init),
    ESP_ELFSYM_EXPORT(vterm_get_active),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page11markFreeingEv),
    ESP_ELFSYM_EXPORT(ds_hal_start_sign),
    ESP_ELFSYM_EXPORT(esp_newlib_init),
    ESP_ELFSYM_EXPORT(mbedtls_aria_init),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_stop),
    ESP_ELFSYM_EXPORT(http_parser_execute),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_disable_time_check__init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_enterprise_disable__descriptor),
    ESP_ELFSYM_EXPORT(multi_heap_free),
    ESP_ELFSYM_EXPORT(_sbrk_r),
    ESP_ELFSYM_EXPORT(hosted_reset_queue),
    ESP_ELFSYM_EXPORT(rpc__resp__otawrite__descriptor),
    ESP_ELFSYM_EXPORT(sha_hal_set_mode),
    ESP_ELFSYM_EXPORT(efuse_hal_blk_version),
    ESP_ELFSYM_EXPORT(esp_log_cache_set_level),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_check_pubkey_soft),
    ESP_ELFSYM_EXPORT(_ZN3nvs16partition_lookup20lookup_nvs_partitionEPKcPPNS_12NVSPartitionE),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage18writeMultiPageBlobEhPKcPKvjNS_9VerOffsetE),
    ESP_ELFSYM_EXPORT(tanmatsu_lcd_set_palette),
    ESP_ELFSYM_EXPORT(bmi270_config_file),
    ESP_ELFSYM_EXPORT(sdmmc_send_app_cmd),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_connect_peri),
    ESP_ELFSYM_EXPORT(tcp_poll),
    ESP_ELFSYM_EXPORT(putchar),
    ESP_ELFSYM_EXPORT(mspi_timing_config_psram_set_tuning_delayline),
    ESP_ELFSYM_EXPORT(cmd_du),
    ESP_ELFSYM_EXPORT(mbedtls_pk_ecc_set_pubkey),
    ESP_ELFSYM_EXPORT(ip4addr_ntoa_r),
    ESP_ELFSYM_EXPORT(__getopt_long_only_r),
    ESP_ELFSYM_EXPORT(rpc__event__supp_dpp_fail__descriptor),
    ESP_ELFSYM_EXPORT(wifi_pmf_config__init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_write_binary_le),
    ESP_ELFSYM_EXPORT(netconn_write_partly),
    ESP_ELFSYM_EXPORT(destination_cache),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_fast_params__descriptor),
    ESP_ELFSYM_EXPORT(lwip_cyclic_timers),
    ESP_ELFSYM_EXPORT(cmd_wifi),
    ESP_ELFSYM_EXPORT(bsp_tanmatsu_coprocessor_get_handle),
    ESP_ELFSYM_EXPORT(g_panic_abort_details),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Lock4initEv),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_country__init),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_init_soft),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_update_out_pointers),
    ESP_ELFSYM_EXPORT(igmp_tmr),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_parse_sig_alg_ext),
    ESP_ELFSYM_EXPORT(__gettzinfo),
    ESP_ELFSYM_EXPORT(sdmmc_io_read_blocks),
    ESP_ELFSYM_EXPORT(bsp_display_set_backlight_brightness),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_compute_shared),
    ESP_ELFSYM_EXPORT(es8156_write_misc_control_3),
    ESP_ELFSYM_EXPORT(_puts_r),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page7cmpItemEhNS_8ItemTypeEPKcPKvjhNS_9VerOffsetE),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_inactive_time__descriptor),
    ESP_ELFSYM_EXPORT(esp_netif_free_rx_buffer),
    ESP_ELFSYM_EXPORT(esp_netif_set_mac),
    ESP_ELFSYM_EXPORT(mspi_timing_config_psram_write_data),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_bootstrap_gen__init),
    ESP_ELFSYM_EXPORT(arg_print_glossary),
    ESP_ELFSYM_EXPORT(spi_flash_common_read_status_16b_rdsr_rdsr2),
    ESP_ELFSYM_EXPORT(esp_hosted_transport_get_config),
    ESP_ELFSYM_EXPORT(httpd_is_sess_available),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_input_enable__init),
    ESP_ELFSYM_EXPORT(mmu_hal_get_id_from_vaddr),
    ESP_ELFSYM_EXPORT(rpc__init),
    ESP_ELFSYM_EXPORT(esp_lcd_new_dsi_bus),
    ESP_ELFSYM_EXPORT(gdma_hal_build_parallel_crc_matrix),
    ESP_ELFSYM_EXPORT(etharp_query),
    ESP_ELFSYM_EXPORT(esp_log_impl_lock),
    ESP_ELFSYM_EXPORT(cmd_ls),
    ESP_ELFSYM_EXPORT(tcp_fasttmr),
    ESP_ELFSYM_EXPORT(ensure_slave_bus_ready),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_crypt_and_tag_soft),
    ESP_ELFSYM_EXPORT(mbedtls_pkcs12_derivation),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_calc_secret),
    ESP_ELFSYM_EXPORT(xPortStartScheduler),
    ESP_ELFSYM_EXPORT(stpcpy),
    ESP_ELFSYM_EXPORT(esp_http_client_fetch_headers),
    ESP_ELFSYM_EXPORT(ipaddr_aton),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition8read_rawEjPvj),
    ESP_ELFSYM_EXPORT(dhcp_renew),
    ESP_ELFSYM_EXPORT(rpc_parse_evt),
    ESP_ELFSYM_EXPORT(heap_caps_enable_nonos_stack_heaps),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_band_mode__descriptor),
    ESP_ELFSYM_EXPORT(__copybits),
    ESP_ELFSYM_EXPORT(lwip_select),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_stop),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashListD2Ev),
    ESP_ELFSYM_EXPORT(rgb_display_get_mode),
    ESP_ELFSYM_EXPORT(mbedtls_md_info_from_ctx),
    ESP_ELFSYM_EXPORT(linenoiseEditMoveLeft),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple10get_stringEPKcPcj),
    ESP_ELFSYM_EXPORT(serial_drv_write),
    ESP_ELFSYM_EXPORT(esp_netif_is_netif_listed),
    ESP_ELFSYM_EXPORT(rgb_gfx_blit_flip),
    ESP_ELFSYM_EXPORT(vterm_write),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_blocklen),
    ESP_ELFSYM_EXPORT(dma2d_connect),
    ESP_ELFSYM_EXPORT(lp_timer_hal_get_cycle_count),
    ESP_ELFSYM_EXPORT(floorf),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_deinit__descriptor),
    ESP_ELFSYM_EXPORT(esp_efuse_check_errors),
    ESP_ELFSYM_EXPORT(__ssprint_r),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_join_leave_group),
    ESP_ELFSYM_EXPORT(mpi_hal_write_at_offset),
    ESP_ELFSYM_EXPORT(__s2b),
    ESP_ELFSYM_EXPORT(esp_sha_512_t_init_hash),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_validate_crt),
    ESP_ELFSYM_EXPORT(mbedtls_ctr_drbg_random),
    ESP_ELFSYM_EXPORT(memset),
    ESP_ELFSYM_EXPORT(i2s_free_dma_desc),
    ESP_ELFSYM_EXPORT(sdmmc_select_current_limit),
    ESP_ELFSYM_EXPORT(mpi_hal_enable_hardware_hw_op),
    ESP_ELFSYM_EXPORT(hosted_read_gpio),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_fast_params__init),
    ESP_ELFSYM_EXPORT(gpio_isr_register),
    ESP_ELFSYM_EXPORT(spi_flash_chip_winbond_erase_block),
    ESP_ELFSYM_EXPORT(esp_ds_set_session_timeout),
    ESP_ELFSYM_EXPORT(rpc__req__get_dhcp_dns_status__descriptor),
    ESP_ELFSYM_EXPORT(_ZNSt9bad_allocD0Ev),
    ESP_ELFSYM_EXPORT(esp_timer_impl_init_system_time),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_send_status),
    ESP_ELFSYM_EXPORT(xQueueGenericReset),
    ESP_ELFSYM_EXPORT(xIsrStack),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_reset),
    ESP_ELFSYM_EXPORT(rtc_clk_slow_src_set),
    ESP_ELFSYM_EXPORT(heap_caps_malloc_extmem_enable),
    ESP_ELFSYM_EXPORT(bmi2_get_feature_data),
    ESP_ELFSYM_EXPORT(clk_hal_xtal_get_freq_mhz),
    ESP_ELFSYM_EXPORT(__kernel_sin),
    ESP_ELFSYM_EXPORT(esp_vfs_rmdir),
    ESP_ELFSYM_EXPORT(ip_data),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_addr_map_default),
    ESP_ELFSYM_EXPORT(deflateInit2_),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_enable_burst),
    ESP_ELFSYM_EXPORT(pbuf_alloced_custom),
    ESP_ELFSYM_EXPORT(sys_sem_signal),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsassa_pss_sign),
    ESP_ELFSYM_EXPORT(udp_connect),
    ESP_ELFSYM_EXPORT(vTaskPriorityDisinheritAfterTimeout),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_ciphersuites),
    ESP_ELFSYM_EXPORT(mbedtls_pk_parse_public_key),
    ESP_ELFSYM_EXPORT(icmp6_param_problem),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_start__descriptor),
    ESP_ELFSYM_EXPORT(getenv),
    ESP_ELFSYM_EXPORT(nd6_get_next_hop_addr_or_queue),
    ESP_ELFSYM_EXPORT(mbedtls_sha256_clone),
    ESP_ELFSYM_EXPORT(pau_regdma_set_entry_link_addr),
    ESP_ELFSYM_EXPORT(transport_esp_hosted_up_cb),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_flush_output),
    ESP_ELFSYM_EXPORT(esp_netif_is_valid_static_ip),
    ESP_ELFSYM_EXPORT(breezybox_get_cwd),
    ESP_ELFSYM_EXPORT(esp_netif_get_hostname),
    ESP_ELFSYM_EXPORT(esp_aes_process_dma),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_init__descriptor),
    ESP_ELFSYM_EXPORT(dhcps_stop),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_disconnect),
    ESP_ELFSYM_EXPORT(gdma_hal_stop),
    ESP_ELFSYM_EXPORT(vfs_include_syscalls_impl),
    ESP_ELFSYM_EXPORT(nvs_open_from_partition),
    ESP_ELFSYM_EXPORT(memspi_host_write_data_slicer),
    ESP_ELFSYM_EXPORT(bmi2_delay_us),
    ESP_ELFSYM_EXPORT(sdmmc_decode_csd),
    ESP_ELFSYM_EXPORT(_localeconv_r),
    ESP_ELFSYM_EXPORT(multi_heap_internal_lock),
    ESP_ELFSYM_EXPORT(mbedtls_ctr_drbg_reseed),
    ESP_ELFSYM_EXPORT(dma2d_start),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_suiteb192bit_certification__descriptor),
    ESP_ELFSYM_EXPORT(rpc_wifi_init),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_bitstring),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_common_command),
    ESP_ELFSYM_EXPORT(es8156_select_page),
    ESP_ELFSYM_EXPORT(__lock___tz_mutex),
    ESP_ELFSYM_EXPORT(lfs_mount),
    ESP_ELFSYM_EXPORT(bmi270_init),
    ESP_ELFSYM_EXPORT(gpio_od_disable),
    ESP_ELFSYM_EXPORT(rpc__resp__otaend__descriptor),
    ESP_ELFSYM_EXPORT(regi2c_ctrl_write_reg_mask),
    ESP_ELFSYM_EXPORT(hosted_lock_mutex),
    ESP_ELFSYM_EXPORT(setvbuf),
    ESP_ELFSYM_EXPORT(sdmmc_init_host_frequency),
    ESP_ELFSYM_EXPORT(esp_ds_release_ds_lock),
    ESP_ELFSYM_EXPORT(sdmmc_mmc_send_ext_csd_data),
    ESP_ELFSYM_EXPORT(__lock___env_recursive_mutex),
    ESP_ELFSYM_EXPORT(hosted_config_gpio),
    ESP_ELFSYM_EXPORT(wifi_event_sta_disconnected__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page17eraseEntryAndSpanEj),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_get_ap_record__init),
    ESP_ELFSYM_EXPORT(app_main),
    ESP_ELFSYM_EXPORT(esp_md5_starts),
    ESP_ELFSYM_EXPORT(esp_mmu_unmap),
    ESP_ELFSYM_EXPORT(esp_log_level_get),
    ESP_ELFSYM_EXPORT(esp_pm_lock_release),
    ESP_ELFSYM_EXPORT(esp_http_client_set_header),
    ESP_ELFSYM_EXPORT(esp_elf_request),
    ESP_ELFSYM_EXPORT(hosted_create_queue),
    ESP_ELFSYM_EXPORT(esp_partition_write),
    ESP_ELFSYM_EXPORT(i2s_del_channel),
    ESP_ELFSYM_EXPORT(strtok_r),
    ESP_ELFSYM_EXPORT(bsp_display_initialize),
    ESP_ELFSYM_EXPORT(sdmmc_host_deinit),
    ESP_ELFSYM_EXPORT(mmu_hal_pages_to_bytes),
    ESP_ELFSYM_EXPORT(sdmmc_io_send_op_cond),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handshake_wrapup_free_hs_transform),
    ESP_ELFSYM_EXPORT(rtc_gpio_hold_en),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_key_usage),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_get_disable_time_check__descriptor),
    ESP_ELFSYM_EXPORT(xTaskCreateStaticPinnedToCore),
    ESP_ELFSYM_EXPORT(pbuf_ref),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_teardown__init),
    ESP_ELFSYM_EXPORT(esp_vfs_mkdir),
    ESP_ELFSYM_EXPORT(netconn_delete),
    ESP_ELFSYM_EXPORT(rpc__event__sta_disconnected__descriptor),
    ESP_ELFSYM_EXPORT(httpd_queue_work),
    ESP_ELFSYM_EXPORT(netconn_send),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_ext),
    ESP_ELFSYM_EXPORT(esp_mpi_exp_mpi_mod_hw_op),
    ESP_ELFSYM_EXPORT(__extenddftf2),
    ESP_ELFSYM_EXPORT(__mdiff),
    ESP_ELFSYM_EXPORT(sdmmc_host_reset),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page8markFullEv),
    ESP_ELFSYM_EXPORT(gdma_periph_signals),
    ESP_ELFSYM_EXPORT(spi_flash_hal_poll_cmd_done),
    ESP_ELFSYM_EXPORT(esp_sleep_pd_config),
    ESP_ELFSYM_EXPORT(igmp_joingroup),
    ESP_ELFSYM_EXPORT(multi_heap_register_impl),
    ESP_ELFSYM_EXPORT(rpc__resp__feature_control__init),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_getaddr),
    ESP_ELFSYM_EXPORT(__kernel_rem_pio2f),
    ESP_ELFSYM_EXPORT(gdma_link_mount_buffers),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_free),
    ESP_ELFSYM_EXPORT(hosted_teardown_gpio_interrupt),
    ESP_ELFSYM_EXPORT(sha_hal_write_digest),
    ESP_ELFSYM_EXPORT(dma2d_enqueue),
    ESP_ELFSYM_EXPORT(esp_aes_dma_done),
    ESP_ELFSYM_EXPORT(systimer_us_to_ticks),
    ESP_ELFSYM_EXPORT(dw_gdma_channel_use_link_list),
    ESP_ELFSYM_EXPORT(mspi_timing_config_set_psram_clock),
    ESP_ELFSYM_EXPORT(esp_cpu_stall),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_validate_ciphersuite),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_rssi__init),
    ESP_ELFSYM_EXPORT(esp_elf_arch_relocate),
    ESP_ELFSYM_EXPORT(mld6_lookfor_group),
    ESP_ELFSYM_EXPORT(breezy_http_download),
    ESP_ELFSYM_EXPORT(wifi_protocols__init),
    ESP_ELFSYM_EXPORT(sys_thread_new),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_gen_read_short_packet),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_deauth_sta__init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_reset_checksum),
    ESP_ELFSYM_EXPORT(mem_init),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_encrypt_and_tag),
    ESP_ELFSYM_EXPORT(rtc_clk_mpll_configure),
    ESP_ELFSYM_EXPORT(mbedtls_ct_memcpy_if),
    ESP_ELFSYM_EXPORT(esp_vfs_rename),
    ESP_ELFSYM_EXPORT(esp_task_wdt_impl_timer_feed),
    ESP_ELFSYM_EXPORT(i2c_master_config_internal),
    ESP_ELFSYM_EXPORT(mbedtls_pk_info_from_type),
    ESP_ELFSYM_EXPORT(_lock_init_recursive),
    ESP_ELFSYM_EXPORT(rpc__free_unpacked),
    ESP_ELFSYM_EXPORT(rpc__resp__get_mac_address__init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_config__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__set_dhcp_dns_status__init),
    ESP_ELFSYM_EXPORT(heap_caps_malloc),
    ESP_ELFSYM_EXPORT(esp_aes_dma_start),
    ESP_ELFSYM_EXPORT(esp_psram_io_get_cs_io),
    ESP_ELFSYM_EXPORT(es8156_configure),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_eap_methods__init),
    ESP_ELFSYM_EXPORT(regdma_link_destroy),
    ESP_ELFSYM_EXPORT(bsp_power_get_radio_state),
    ESP_ELFSYM_EXPORT(rpc_rsp_callback),
    ESP_ELFSYM_EXPORT(arg_dstr_free),
    ESP_ELFSYM_EXPORT(rpc_wait_and_parse_sync_resp),
    ESP_ELFSYM_EXPORT(bsp_display_get_default_rotation),
    ESP_ELFSYM_EXPORT(wifi_ap_record__init),
    ESP_ELFSYM_EXPORT(dw_gdma_link_list_get_item),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_set_io_mode),
    ESP_ELFSYM_EXPORT(_svfiprintf_r),
    ESP_ELFSYM_EXPORT(esp_event_handler_unregister_with_internal),
    ESP_ELFSYM_EXPORT(asprintf),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_clear_fast_connect__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_get_ap_records__init),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_set_priority),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashListD1Ev),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage14eraseNamespaceEh),
    ESP_ELFSYM_EXPORT(tcp_close),
    ESP_ELFSYM_EXPORT(__hexnan),
    ESP_ELFSYM_EXPORT(__moddi3),
    ESP_ELFSYM_EXPORT(freopen),
    ESP_ELFSYM_EXPORT(lcd_hal_cal_pclk_freq),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_new_password__init),
    ESP_ELFSYM_EXPORT(__i2b),
    ESP_ELFSYM_EXPORT(httpd_resp_send_err),
    ESP_ELFSYM_EXPORT(hosted_config_host_power_save),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_disconnect__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_init),
    ESP_ELFSYM_EXPORT(hal_utils_calc_clk_div_frac_fast),
    ESP_ELFSYM_EXPORT(esp_crypto_ecc_lock_acquire),
    ESP_ELFSYM_EXPORT(gdma_new_axi_channel),
    ESP_ELFSYM_EXPORT(i2s_init_dma_intr),
    ESP_ELFSYM_EXPORT(wdt_hal_init),
    ESP_ELFSYM_EXPORT(_fgets_r),
    ESP_ELFSYM_EXPORT(fabs),
    ESP_ELFSYM_EXPORT(mbedtls_md_get_type),
    ESP_ELFSYM_EXPORT(esp_netif_action_stop),
    ESP_ELFSYM_EXPORT(s_update_cache_state),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_fill_random),
    ESP_ELFSYM_EXPORT(pau_hal_set_regdma_entry_link_addr),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashListC2Ev),
    ESP_ELFSYM_EXPORT(rtc_isr_noniram_disable),
    ESP_ELFSYM_EXPORT(_link_r),
    ESP_ELFSYM_EXPORT(bmi2_get_gyro_cross_sense),
    ESP_ELFSYM_EXPORT(hosted_reset_slave_callback),
    ESP_ELFSYM_EXPORT(bootloader_flash_update_id),
    ESP_ELFSYM_EXPORT(_lock_release),
    ESP_ELFSYM_EXPORT(i2c_master_bus_add_device),
    ESP_ELFSYM_EXPORT(esp_lcd_new_panel_st7701),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_username__descriptor),
    ESP_ELFSYM_EXPORT(mpi_hal_clear_interrupt),
    ESP_ELFSYM_EXPORT(gdma_default_tx_isr),
    ESP_ELFSYM_EXPORT(tcp_bind),
    ESP_ELFSYM_EXPORT(strtod_l),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_make_params),
    ESP_ELFSYM_EXPORT(bsp_display_blit),
    ESP_ELFSYM_EXPORT(esp_aes_crypt_ecb),
    ESP_ELFSYM_EXPORT(_ZnajRKSt9nothrow_t),
    ESP_ELFSYM_EXPORT(esp_clk_slowclk_cal_set),
    ESP_ELFSYM_EXPORT(sdmmc_host_io_int_enable),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_set_display_backlight),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_disconnect_peri),
    ESP_ELFSYM_EXPORT(gpio_input_enable),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_init__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_negotiated_phymode__init),
    ESP_ELFSYM_EXPORT(_lock_close),
    ESP_ELFSYM_EXPORT(arg_print_option_ds),
    ESP_ELFSYM_EXPORT(xIsrStackBottom),
    ESP_ELFSYM_EXPORT(esp_netif_action_disconnected),
    ESP_ELFSYM_EXPORT(esp_mmu_paddr_find_caps),
    ESP_ELFSYM_EXPORT(__getopt_r),
    ESP_ELFSYM_EXPORT(aes_hal_wait_done),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_clear_intr),
    ESP_ELFSYM_EXPORT(__ffssi2),
    ESP_ELFSYM_EXPORT(pbuf_free),
    ESP_ELFSYM_EXPORT(transport_pserial_read),
    ESP_ELFSYM_EXPORT(hosted_destroy_mutex),
    ESP_ELFSYM_EXPORT(xTaskGetStaticBuffers),
    ESP_ELFSYM_EXPORT(breezybox_resolve_path),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page9copyItemsERS0_),
    ESP_ELFSYM_EXPORT(spi_flash_hal_supports_direct_read),
    ESP_ELFSYM_EXPORT(multi_heap_free_impl),
    ESP_ELFSYM_EXPORT(__sread),
    ESP_ELFSYM_EXPORT(_ZNK3nvs4Item22checkHeaderConsistencyEh),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_get_ap_num__init),
    ESP_ELFSYM_EXPORT(spi_flash_restore_cache),
    ESP_ELFSYM_EXPORT(i2c_common_set_pins),
    ESP_ELFSYM_EXPORT(rpc__req__feature_control__descriptor),
    ESP_ELFSYM_EXPORT(acd_remove),
    ESP_ELFSYM_EXPORT(__bswapdi2),
    ESP_ELFSYM_EXPORT(tcp_rst),
    ESP_ELFSYM_EXPORT(_ZNSt9bad_allocD2Ev),
    ESP_ELFSYM_EXPORT(esp_vfs_select_triggered_isr),
    ESP_ELFSYM_EXPORT(periph_rcc_acquire_exit),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_ca_cert__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_stop__init),
    ESP_ELFSYM_EXPORT(zcfree),
    ESP_ELFSYM_EXPORT(vTaskStartScheduler),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_yield),
    ESP_ELFSYM_EXPORT(strtol_l),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_select_best_tuning_phase),
    ESP_ELFSYM_EXPORT(heap_caps_get_free_size),
    ESP_ELFSYM_EXPORT(gdma_hal_get_eof_desc_addr),
    ESP_ELFSYM_EXPORT(dhcp_append_extra_opts),
    ESP_ELFSYM_EXPORT(linenoiseEditMoveRight),
    ESP_ELFSYM_EXPORT(esp_elf_init),
    ESP_ELFSYM_EXPORT(esp_timer_impl_get_time),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsassa_pss_verify),
    ESP_ELFSYM_EXPORT(lfs_file_sync),
    ESP_ELFSYM_EXPORT(esp_ipc_isr_init),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv117__class_type_infoD2Ev),
    ESP_ELFSYM_EXPORT(bmi2_i2c_write),
    ESP_ELFSYM_EXPORT(pvPortMalloc),
    ESP_ELFSYM_EXPORT(rpc__resp__set_ps__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_suiteb192bit_certification__descriptor),
    ESP_ELFSYM_EXPORT(linenoiseSetCompletionCallback),
    ESP_ELFSYM_EXPORT(esp_elf_arch_flush),
    ESP_ELFSYM_EXPORT(rpc__event__ap__sta_disconnected__init),
    ESP_ELFSYM_EXPORT(esp_netif_get_ip_info),
    ESP_ELFSYM_EXPORT(rpc__req__get_ps__init),
    ESP_ELFSYM_EXPORT(mbedtls_md_finish),
    ESP_ELFSYM_EXPORT(__ascii_wctomb),
    ESP_ELFSYM_EXPORT(esp_hosted_power_save_start),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_enterprise_disable__init),
    ESP_ELFSYM_EXPORT(esp_netif_get_io_driver),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_fast_params__init),
    ESP_ELFSYM_EXPORT(_perror_r),
    ESP_ELFSYM_EXPORT(gdma_link_concat),
    ESP_ELFSYM_EXPORT(rgb_display_set_vga_palette_entry),
    ESP_ELFSYM_EXPORT(hosted_create_lock_mempool),
    ESP_ELFSYM_EXPORT(__retarget_lock_close),
    ESP_ELFSYM_EXPORT(process_priv_communication),
    ESP_ELFSYM_EXPORT(gzread),
    ESP_ELFSYM_EXPORT(sdmmc_io_rw_extended),
    ESP_ELFSYM_EXPORT(esp_cache_err_int_init),
    ESP_ELFSYM_EXPORT(multi_heap_check),
    ESP_ELFSYM_EXPORT(esp_http_server_dispatch_event),
    ESP_ELFSYM_EXPORT(regdma_link_new_write),
    ESP_ELFSYM_EXPORT(esp_ds_finish_sign),
    ESP_ELFSYM_EXPORT(vterm_set_switch_callback),
    ESP_ELFSYM_EXPORT(esp_tls_conn_new_sync),
    ESP_ELFSYM_EXPORT(_length_code),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_ds_data),
    ESP_ELFSYM_EXPORT(esp_task_wdt_impl_timer_allocate),
    ESP_ELFSYM_EXPORT(__lock___sfp_recursive_mutex),
    ESP_ELFSYM_EXPORT(tcp_recved),
    ESP_ELFSYM_EXPORT(__lshift),
    ESP_ELFSYM_EXPORT(ds_hal_write_private_key_params),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_setkey),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_get_len),
    ESP_ELFSYM_EXPORT(mbedtls_sha256_free),
    ESP_ELFSYM_EXPORT(cmd_echo),
    ESP_ELFSYM_EXPORT(esp_netif_action_connected),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_setkey),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_certificate_and_key__init),
    ESP_ELFSYM_EXPORT(_ZN3nvs4PageC1Ev),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_deinit__init),
    ESP_ELFSYM_EXPORT(transport_pserial_open),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_group_init),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_username__init),
    ESP_ELFSYM_EXPORT(mbedtls_pk_decrypt),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_set_best_tuning_phase),
    ESP_ELFSYM_EXPORT(_ZNK3nvs4Page12getSeqNumberERm),
    ESP_ELFSYM_EXPORT(__ieee754_sqrt),
    ESP_ELFSYM_EXPORT(esp_aes_release_hardware),
    ESP_ELFSYM_EXPORT(dhcp_fine_timeout_cb),
    ESP_ELFSYM_EXPORT(panic_print_char),
    ESP_ELFSYM_EXPORT(netif_set_link_down),
    ESP_ELFSYM_EXPORT(esp_lcd_panel_io_del),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_suspend__init),
    ESP_ELFSYM_EXPORT(pthread_key_create),
    ESP_ELFSYM_EXPORT(dhcps_start),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_check_curve_tls_id),
    ESP_ELFSYM_EXPORT(periph_rtc_apll_release),
    ESP_ELFSYM_EXPORT(tlsf_block_size),
    ESP_ELFSYM_EXPORT(multi_heap_free_size_impl),
    ESP_ELFSYM_EXPORT(esp_crypto_mpi_lock_acquire),
    ESP_ELFSYM_EXPORT(sys_timeouts_sleeptime),
    ESP_ELFSYM_EXPORT(spi_flash_op_unlock),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_copy),
    ESP_ELFSYM_EXPORT(hosted_sdio_card_init),
    ESP_ELFSYM_EXPORT(__wrap_opendir),
    ESP_ELFSYM_EXPORT(hosted_start_host_power_save),
    ESP_ELFSYM_EXPORT(mmu_hal_paddr_to_vaddr),
    ESP_ELFSYM_EXPORT(tcp_active_pcbs),
    ESP_ELFSYM_EXPORT(lwip_socket),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_reset),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_auth_decrypt_ext),
    ESP_ELFSYM_EXPORT(nd6_reachability_hint),
    ESP_ELFSYM_EXPORT(mbedtls_sha256_init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_init),
    ESP_ELFSYM_EXPORT(esp_startup_start_app),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_bandwidths__descriptor),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv117__class_type_info10__do_catchEPKSt9type_infoPPvj),
    ESP_ELFSYM_EXPORT(bmi2_get_regs),
    ESP_ELFSYM_EXPORT(spi_flash_hal_set_write_protect),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition5writeEjPKvj),
    ESP_ELFSYM_EXPORT(sdmmc_host_transaction_handler_init),
    ESP_ELFSYM_EXPORT(netif_poll),
    ESP_ELFSYM_EXPORT(tanmatsu_lcd_set_cursor),
    ESP_ELFSYM_EXPORT(_ZN3nvs4LockC2Ev),
    ESP_ELFSYM_EXPORT(rpc__req__eap_get_disable_time_check__init),
    ESP_ELFSYM_EXPORT(rpc__mem_monitor_config__descriptor),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_write),
    ESP_ELFSYM_EXPORT(spi_flash_hal_erase_sector),
    ESP_ELFSYM_EXPORT(esp_log_early_timestamp),
    ESP_ELFSYM_EXPORT(xTaskGetTickCount),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_group_copy),
    ESP_ELFSYM_EXPORT(esp_task_wdt_impl_timeout_triggered),
    ESP_ELFSYM_EXPORT(spi_flash_hal_disable_auto_suspend_mode),
    ESP_ELFSYM_EXPORT(esp_vfs_seekdir),
    ESP_ELFSYM_EXPORT(rpc__event__heartbeat__init),
    ESP_ELFSYM_EXPORT(multi_heap_free_size),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_crt_bundle_attach),
    ESP_ELFSYM_EXPORT(linenoise),
    ESP_ELFSYM_EXPORT(uxTaskPriorityGet),
    ESP_ELFSYM_EXPORT(heap_caps_match),
    ESP_ELFSYM_EXPORT(xTaskIncrementTickOtherCores),
    ESP_ELFSYM_EXPORT(esp_transport_connect_async),
    ESP_ELFSYM_EXPORT(perror),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager8instanceE),
    ESP_ELFSYM_EXPORT(vterm_get_cursor),
    ESP_ELFSYM_EXPORT(systimer_hal_init),
    ESP_ELFSYM_EXPORT(sin),
    ESP_ELFSYM_EXPORT(multi_heap_aligned_free),
    ESP_ELFSYM_EXPORT(_malloc_r),
    ESP_ELFSYM_EXPORT(esp_task_wdt_add),
    ESP_ELFSYM_EXPORT(esp_log_level_set),
    ESP_ELFSYM_EXPORT(tcp_init),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv117__class_type_info12__do_dyncastEiNS0_10__sub_kindEPKS0_PKvS3_S5_RNS0_16__dyncast_resultE),
    ESP_ELFSYM_EXPORT(rpc__req__get_coprocessor_fw_version__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_clear_ap_list__descriptor),
    ESP_ELFSYM_EXPORT(esp_timer_get_time),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_parse_certificate),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartitionC2EPK15esp_partition_t),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_tls_read_group_id),
    ESP_ELFSYM_EXPORT(MPI_BLOCK_BASES),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_check_pub_priv),
    ESP_ELFSYM_EXPORT(hosted_sleep),
    ESP_ELFSYM_EXPORT(_interrupt_handler),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_safe_cond_swap),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_div_mpi),
    ESP_ELFSYM_EXPORT(esp_console_get_completion),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_domain_name__descriptor),
    ESP_ELFSYM_EXPORT(esp_tls_get_platform_time),
    ESP_ELFSYM_EXPORT(spi_flash_hal_program_page),
    ESP_ELFSYM_EXPORT(mbedtls_md_update),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_keypair_free),
    ESP_ELFSYM_EXPORT(mbedtls_x509_free_subject_alt_name),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_exp_mod_unsafe),
    ESP_ELFSYM_EXPORT(bmi2_get_internal_status),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_band_mode__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_country__init),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_set_config),
    ESP_ELFSYM_EXPORT(i2c_select_periph_clock),
    ESP_ELFSYM_EXPORT(port_uxCriticalNesting),
    ESP_ELFSYM_EXPORT(esp_partition_get),
    ESP_ELFSYM_EXPORT(_esp_error_check_failed_without_abort),
    ESP_ELFSYM_EXPORT(__global_locale_ptr),
    ESP_ELFSYM_EXPORT(esp_rom_regi2c_write),
    ESP_ELFSYM_EXPORT(ip4_output_if_opt_src),
    ESP_ELFSYM_EXPORT(pbuf_copy_partial),
    ESP_ELFSYM_EXPORT(longjmp),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_set_strategy),
    ESP_ELFSYM_EXPORT(regdma_link_new_wait),
    ESP_ELFSYM_EXPORT(sdmmc_io_rw_direct),
    ESP_ELFSYM_EXPORT(mbedtls_md_free),
    ESP_ELFSYM_EXPORT(esp_vfs_readdir),
    ESP_ELFSYM_EXPORT(sdmmc_decode_cid),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_password__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_entropy_func),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_config__init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_shift_r),
    ESP_ELFSYM_EXPORT(heap_caps_get_minimum_free_size),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_alg_null),
    ESP_ELFSYM_EXPORT(esp_libc_init_funcs),
    ESP_ELFSYM_EXPORT(mempool_destroy),
    ESP_ELFSYM_EXPORT(wlanif_init_sta),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_init),
    ESP_ELFSYM_EXPORT(__cxa_get_globals),
    ESP_ELFSYM_EXPORT(vasprintf),
    ESP_ELFSYM_EXPORT(i2c_common_deinit_pins),
    ESP_ELFSYM_EXPORT(__wrap___cxa_throw),
    ESP_ELFSYM_EXPORT(lwip_init_tcp_isn),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_restore__descriptor),
    ESP_ELFSYM_EXPORT(xQueueGenericCreate),
    ESP_ELFSYM_EXPORT(ethernet_output),
    ESP_ELFSYM_EXPORT(rtc_clk_rc32k_enable),
    ESP_ELFSYM_EXPORT(esp_rom_regi2c_read_mask),
    ESP_ELFSYM_EXPORT(esp_crypto_sha_aes_lock_release),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_channel__init),
    ESP_ELFSYM_EXPORT(__d2b),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_start__init),
    ESP_ELFSYM_EXPORT(mmu_hal_map_region),
    ESP_ELFSYM_EXPORT(pbuf_remove_header),
    ESP_ELFSYM_EXPORT(spi_flash_hal_setup_auto_resume_mode),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_shift_l),
    ESP_ELFSYM_EXPORT(rtc_dig_clk8m_disable),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_get_crc_result),
    ESP_ELFSYM_EXPORT(ip6_output_if_src),
    ESP_ELFSYM_EXPORT(xQueueGenericGetStaticBuffers),
    ESP_ELFSYM_EXPORT(gdma_reset),
    ESP_ELFSYM_EXPORT(lfs_getattr),
    ESP_ELFSYM_EXPORT(_getchar_r),
    ESP_ELFSYM_EXPORT(tcp_arg),
    ESP_ELFSYM_EXPORT(__sflags),
    ESP_ELFSYM_EXPORT(lwip_standard_chksum),
    ESP_ELFSYM_EXPORT(i2c_master_multi_buffer_transmit),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_set_bit),
    ESP_ELFSYM_EXPORT(num_of_soc_mipi_dsi_phy_pll_ranges),
    ESP_ELFSYM_EXPORT(nanf),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_init),
    ESP_ELFSYM_EXPORT(rtos_int_enter),
    ESP_ELFSYM_EXPORT(sys_thread_sem_get),
    ESP_ELFSYM_EXPORT(tcp_abort),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_eap_methods__init),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_identity__init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_ap_get_sta_aid__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_transport),
    ESP_ELFSYM_EXPORT(dw_gdma_channel_default_isr),
    ESP_ELFSYM_EXPORT(my_console_usb_connected),
    ESP_ELFSYM_EXPORT(strncasecmp),
    ESP_ELFSYM_EXPORT(mbedtls_pk_setup_rsa_alt),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_starts),
    ESP_ELFSYM_EXPORT(esp_transport_list_add),
    ESP_ELFSYM_EXPORT(rpc__resp__set_dhcp_dns_status__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handshake_free),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_get_ap_num__descriptor),
    ESP_ELFSYM_EXPORT(strcpy),
    ESP_ELFSYM_EXPORT(heap_info__descriptor),
    ESP_ELFSYM_EXPORT(s_time_update_lock),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple6commitEv),
    ESP_ELFSYM_EXPORT(spi_flash_hal_erase_chip),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_start_with_desc),
    ESP_ELFSYM_EXPORT(es8156_write_analog_system_3),
    ESP_ELFSYM_EXPORT(sdmmc_slot_info),
    ESP_ELFSYM_EXPORT(rpc__req__supp_dpp_deinit__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_band_mode__descriptor),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_accepted),
    ESP_ELFSYM_EXPORT(sdmmc_mmc_decode_cid),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_setup),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_start),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_set_config),
    ESP_ELFSYM_EXPORT(http_utils_append_string),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_sig_alg),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_info_from_values),
    ESP_ELFSYM_EXPORT(es8156_write_analog_system_5),
    ESP_ELFSYM_EXPORT(ip_addr_broadcast),
    ESP_ELFSYM_EXPORT(my_console_usb_reconnect),
    ESP_ELFSYM_EXPORT(lfs_file_close),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_pac_file__descriptor),
    ESP_ELFSYM_EXPORT(esp_ipc_isr_stall_abort),
    ESP_ELFSYM_EXPORT(console_access),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_clear_crc),
    ESP_ELFSYM_EXPORT(dns_gethostbyname_addrtype),
    ESP_ELFSYM_EXPORT(linenoiseFree),
    ESP_ELFSYM_EXPORT(read),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_cmp_int),
    ESP_ELFSYM_EXPORT(esp_reent_init),
    ESP_ELFSYM_EXPORT(_wctomb_r),
    ESP_ELFSYM_EXPORT(tlsf_realloc),
    ESP_ELFSYM_EXPORT(esp_transport_get_errno),
    ESP_ELFSYM_EXPORT(inflateEnd),
    ESP_ELFSYM_EXPORT(cmd_clear),
    ESP_ELFSYM_EXPORT(inflate_fast),
    ESP_ELFSYM_EXPORT(_snprintf_r),
    ESP_ELFSYM_EXPORT(_siscanf_r),
    ESP_ELFSYM_EXPORT(esp_transport_destroy_foundation_transport),
    ESP_ELFSYM_EXPORT(spi_flash_common_set_io_mode),
    ESP_ELFSYM_EXPORT(lwip_shutdown),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_certificate_and_key__descriptor),
    ESP_ELFSYM_EXPORT(__mprec_bigtens),
    ESP_ELFSYM_EXPORT(spi_flash_hal_setup_read_suspend),
    ESP_ELFSYM_EXPORT(mspi_timing_flash_config_set_tuning_regs),
    ESP_ELFSYM_EXPORT(xTimerPendFunctionCallFromISR),
    ESP_ELFSYM_EXPORT(netconn_join_leave_group_netif),
    ESP_ELFSYM_EXPORT(ethzero),
    ESP_ELFSYM_EXPORT(bsp_led_initialize),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_get_ap_num__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_eap_methods__descriptor),
    ESP_ELFSYM_EXPORT(wifi_scan_config__descriptor),
    ESP_ELFSYM_EXPORT(udp_netif_ip_addr_changed),
    ESP_ELFSYM_EXPORT(_putchar_r),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_auth_decrypt_soft),
    ESP_ELFSYM_EXPORT(regi2c_ctrl_read_reg_mask),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_dpi_set_color_coding),
    ESP_ELFSYM_EXPORT(_asprintf_r),
    ESP_ELFSYM_EXPORT(esp_restart_noos),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_country__init),
    ESP_ELFSYM_EXPORT(rtc_clk_cal),
    ESP_ELFSYM_EXPORT(__ieee754_rem_pio2),
    ESP_ELFSYM_EXPORT(esp_wifi_get_if_mac),
    ESP_ELFSYM_EXPORT(raw_bind_netif),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_check_pub_priv),
    ESP_ELFSYM_EXPORT(esp_vfs_fcntl_r),
    ESP_ELFSYM_EXPORT(__ctzsi2),
    ESP_ELFSYM_EXPORT(clk_hal_soc_root_get_freq_mhz),
    ESP_ELFSYM_EXPORT(esp_task_wdt_reset),
    ESP_ELFSYM_EXPORT(i2s_get_source_clk_freq),
    ESP_ELFSYM_EXPORT(esp_transport_tcp_set_interface_name),
    ESP_ELFSYM_EXPORT(linenoiseHistorySetMaxLen),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_password__descriptor),
    ESP_ELFSYM_EXPORT(pbuf_free_ooseq_pending),
    ESP_ELFSYM_EXPORT(gpio_isr_handler_add),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_set_calc_verify_md),
    ESP_ELFSYM_EXPORT(serial_handle),
    ESP_ELFSYM_EXPORT(gpio_isr_handler_remove),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handshake_wrapup),
    ESP_ELFSYM_EXPORT(_Bfree),
    ESP_ELFSYM_EXPORT(_isatty_r),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_get_type),
    ESP_ELFSYM_EXPORT(lwip_listen),
    ESP_ELFSYM_EXPORT(hosted_get_time_ms),
    ESP_ELFSYM_EXPORT(mbedtls_pk_sign_restartable),
    ESP_ELFSYM_EXPORT(tcp_process_refused_data),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_teardown__init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_negotiated_phymode__descriptor),
    ESP_ELFSYM_EXPORT(_sfread_r),
    ESP_ELFSYM_EXPORT(lwip_accept),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_config__init),
    ESP_ELFSYM_EXPORT(lwip_setsockopt_impl_ext),
    ESP_ELFSYM_EXPORT(vListInitialise),
    ESP_ELFSYM_EXPORT(esp_aes_setkey),
    ESP_ELFSYM_EXPORT(ip6addr_aton),
    ESP_ELFSYM_EXPORT(__tzcalc_limits),
    ESP_ELFSYM_EXPORT(sdmmc_host_init),
    ESP_ELFSYM_EXPORT(hosted_sdio_card_deinit),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_handshake_msg_ext),
    ESP_ELFSYM_EXPORT(heap_caps_malloc_default),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_certificate_and_key__init),
    ESP_ELFSYM_EXPORT(linenoiseEditInsert),
    ESP_ELFSYM_EXPORT(g_twdt_isr),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_sig_alg),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_set_mode),
    ESP_ELFSYM_EXPORT(call_start_cpu1),
    ESP_ELFSYM_EXPORT(http_parser_init),
    ESP_ELFSYM_EXPORT(raw_sendto_if_src),
    ESP_ELFSYM_EXPORT(esp_tls_conn_read),
    ESP_ELFSYM_EXPORT(bsp_input_get_queue),
    ESP_ELFSYM_EXPORT(ip6_select_source_address),
    ESP_ELFSYM_EXPORT(linenoiseHistoryAdd),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_vfs_include_dev_init),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_finish),
    ESP_ELFSYM_EXPORT(esp_cache_suspend_ext_mem_cache),
    ESP_ELFSYM_EXPORT(arg_dstr_catf),
    ESP_ELFSYM_EXPORT(__default_global_locale),
    ESP_ELFSYM_EXPORT(es8156_write_analog_system_1),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_point_read_binary),
    ESP_ELFSYM_EXPORT(_ZN3nvs11PageManager14requestNewPageEv),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_max_tx_power__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_rsassa_pss_params),
    ESP_ELFSYM_EXPORT(esp_transport_close),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_point_free),
    ESP_ELFSYM_EXPORT(hosted_queue_msg_waiting),
    ESP_ELFSYM_EXPORT(rpc__req__otawrite__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_country__descriptor),
    ESP_ELFSYM_EXPORT(linenoiseSetHintsCallback),
    ESP_ELFSYM_EXPORT(hosted_restart_host),
    ESP_ELFSYM_EXPORT(esp_intr_alloc),
    ESP_ELFSYM_EXPORT(i2s_hal_std_set_tx_slot),
    ESP_ELFSYM_EXPORT(raw_new),
    ESP_ELFSYM_EXPORT(esp_mmu_map_reserve_block_with_caps),
    ESP_ELFSYM_EXPORT(esprv_int_set_vectored),
    ESP_ELFSYM_EXPORT(pxCurrentTCBs),
    ESP_ELFSYM_EXPORT(ip4_output_if_src),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_ca_cert__init),
    ESP_ELFSYM_EXPORT(ethbroadcast),
    ESP_ELFSYM_EXPORT(rpc__event__sta_scan_done__descriptor),
    ESP_ELFSYM_EXPORT(wifi_he_ap_info__descriptor),
    ESP_ELFSYM_EXPORT(setup_transport),
    ESP_ELFSYM_EXPORT(esp_time_impl_get_time),
    ESP_ELFSYM_EXPORT(_C_time_locale),
    ESP_ELFSYM_EXPORT(hosted_unlock_mutex),
    ESP_ELFSYM_EXPORT(xRingbufferReceiveUpToFromISR),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_get_ap_records__init),
    ESP_ELFSYM_EXPORT(xTaskGetIdleTaskHandleForCore),
    ESP_ELFSYM_EXPORT(mbedtls_ctr_drbg_init),
    ESP_ELFSYM_EXPORT(esp_flash_default_chip),
    ESP_ELFSYM_EXPORT(bootloader_read_flash_id),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_select_card),
    ESP_ELFSYM_EXPORT(cmd_testgfx),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_hostname_pointer),
    ESP_ELFSYM_EXPORT(rpc_wifi_stop),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_suspend__descriptor),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_connect_peri),
    ESP_ELFSYM_EXPORT(spi_flash_enable_cache),
    ESP_ELFSYM_EXPORT(es8156_write_p2s_control),
    ESP_ELFSYM_EXPORT(gdma_del_channel),
    ESP_ELFSYM_EXPORT(rgb_display_set_vga_palette),
    ESP_ELFSYM_EXPORT(esp_md5_free),
    ESP_ELFSYM_EXPORT(esp_crypto_ds_enable_periph_clk),
    ESP_ELFSYM_EXPORT(panic_prepare_frame_from_ctx),
    ESP_ELFSYM_EXPORT(hosted_sdio_read_block),
    ESP_ELFSYM_EXPORT(esp_intr_enable),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_client_key_data),
    ESP_ELFSYM_EXPORT(rgb_gfx_hline),
    ESP_ELFSYM_EXPORT(efuse_hal_flash_encryption_enabled),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_crc_on_off),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page8readItemEhNS_8ItemTypeEPKcPvjhNS_9VerOffsetE),
    ESP_ELFSYM_EXPORT(dhcp_parse_extra_opts),
    ESP_ELFSYM_EXPORT(panic_print_hex),
    ESP_ELFSYM_EXPORT(SysTickIsrHandler),
    ESP_ELFSYM_EXPORT(strcat),
    ESP_ELFSYM_EXPORT(__lock___arc4random_mutex),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_protocols__init),
    ESP_ELFSYM_EXPORT(sdmmc_io_init_read_card_cap),
    ESP_ELFSYM_EXPORT(littlefs_esp_part_read),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_ecp_group_id_from_tls_id),
    ESP_ELFSYM_EXPORT(hosted_sdio_wait_slave_intr),
    ESP_ELFSYM_EXPORT(adler32),
    ESP_ELFSYM_EXPORT(spi_flash_op_lock),
    ESP_ELFSYM_EXPORT(memp_init),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_username__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_free),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_max_tx_power__descriptor),
    ESP_ELFSYM_EXPORT(heap_caps_get_info),
    ESP_ELFSYM_EXPORT(nd6_get_destination_mtu),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_bitstring_null),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_sta_get_ap_info),
    ESP_ELFSYM_EXPORT(__ssrefill_r),
    ESP_ELFSYM_EXPORT(spi_flash_guard_set),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_bootstrap_gen__init),
    ESP_ELFSYM_EXPORT(ecc_hal_start_calc),
    ESP_ELFSYM_EXPORT(rtc_clk_cal_internal),
    ESP_ELFSYM_EXPORT(esp_netif_netstack_buf_ref),
    ESP_ELFSYM_EXPORT(sdmmc_init_csd),
    ESP_ELFSYM_EXPORT(mbedtls_ctr_drbg_seed),
    ESP_ELFSYM_EXPORT(mmu_hal_unmap_region),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_delconn),
    ESP_ELFSYM_EXPORT(esp_http_client_init),
    ESP_ELFSYM_EXPORT(rtc_clk_freq_to_period),
    ESP_ELFSYM_EXPORT(rv_utils_dbgr_is_attached),
    ESP_ELFSYM_EXPORT(spi_flash_chip_winbond_read),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_band__init),
    ESP_ELFSYM_EXPORT(__muldf3),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_change_cipher_spec),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_free),
    ESP_ELFSYM_EXPORT(i2s_check_set_mclk),
    ESP_ELFSYM_EXPORT(_ZNK3nvs4Item26calculateCrc32WithoutValueEv),
    ESP_ELFSYM_EXPORT(lwip_read),
    ESP_ELFSYM_EXPORT(esp_create_mbedtls_handle),
    ESP_ELFSYM_EXPORT(heap_caps_malloc_prefer),
    ESP_ELFSYM_EXPORT(esp_littlefs_info),
    ESP_ELFSYM_EXPORT(mbedtls_sha1_free),
    ESP_ELFSYM_EXPORT(sdmmc_check_host_function_ptr_integrity),
    ESP_ELFSYM_EXPORT(esp_system_get_time),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_complete),
    ESP_ELFSYM_EXPORT(rpc__event__espinit__init),
    ESP_ELFSYM_EXPORT(sys_mutex_unlock),
    ESP_ELFSYM_EXPORT(udp_bind),
    ESP_ELFSYM_EXPORT(es8156_write_time_control_2),
    ESP_ELFSYM_EXPORT(esp_flash_registered_chips),
    ESP_ELFSYM_EXPORT(__wrap_readdir),
    ESP_ELFSYM_EXPORT(esp_flash_read),
    ESP_ELFSYM_EXPORT(ESP_HOSTED_EVENT),
    ESP_ELFSYM_EXPORT(http_parser_pause),
    ESP_ELFSYM_EXPORT(strtoul_l),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_bandwidths__init),
    ESP_ELFSYM_EXPORT(tcp_backlog_accepted),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_dpp_uri_ready__init),
    ESP_ELFSYM_EXPORT(compose_tlv),
    ESP_ELFSYM_EXPORT(_lock_release_recursive),
    ESP_ELFSYM_EXPORT(rpc__resp__otabegin__init),
    ESP_ELFSYM_EXPORT(_daylight),
    ESP_ELFSYM_EXPORT(multi_heap_aligned_alloc_offs),
    ESP_ELFSYM_EXPORT(breezy_p4_export_symbols),
    ESP_ELFSYM_EXPORT(rpc__req__mem_monitor__init),
    ESP_ELFSYM_EXPORT(g_wifi_default_wpa_crypto_funcs),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_okc_support__init),
    ESP_ELFSYM_EXPORT(mbedtls_md_hmac_reset),
    ESP_ELFSYM_EXPORT(esp_mspi_32bit_address_flash_feature_check),
    ESP_ELFSYM_EXPORT(optind),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_parse_server_name_ext),
    ESP_ELFSYM_EXPORT(esp_timer_init_include_func),
    ESP_ELFSYM_EXPORT(rpc__event__ap__sta_disconnected__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_check_pubkey),
    ESP_ELFSYM_EXPORT(cJSON_GetArrayItem),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_set_relative_addr),
    ESP_ELFSYM_EXPORT(rpc__resp__otabegin__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_bandwidths__init),
    ESP_ELFSYM_EXPORT(sdmmc_init_mmc_read_ext_csd),
    ESP_ELFSYM_EXPORT(esp_log_linked_list_clean),
    ESP_ELFSYM_EXPORT(httpd_req_recv),
    ESP_ELFSYM_EXPORT(mbedtls_aria_crypt_ctr),
    ESP_ELFSYM_EXPORT(__env_unlock),
    ESP_ELFSYM_EXPORT(tlsf_check_pool),
    ESP_ELFSYM_EXPORT(httpd_sess_init),
    ESP_ELFSYM_EXPORT(esp_transport_utils_ms_to_timeval),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_lset),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_suiteb192bit_certification__init),
    ESP_ELFSYM_EXPORT(esp_md5_init),
    ESP_ELFSYM_EXPORT(rpc__req__otabegin__descriptor),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_enable_etm_task),
    ESP_ELFSYM_EXPORT(rtc_clk_32k_enable),
    ESP_ELFSYM_EXPORT(i2s_alloc_dma_desc),
    ESP_ELFSYM_EXPORT(__subdf3),
    ESP_ELFSYM_EXPORT(panic_print_str),
    ESP_ELFSYM_EXPORT(esp_hosted_sdio_get_config),
    ESP_ELFSYM_EXPORT(bsp_power_initialize),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_ttls_phase2_method__init),
    ESP_ELFSYM_EXPORT(__sclose),
    ESP_ELFSYM_EXPORT(__wrap___cxa_allocate_exception),
    ESP_ELFSYM_EXPORT(tcp_free),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_mode_from_ciphersuite),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_tag),
    ESP_ELFSYM_EXPORT(vterm_input_flush),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_country__descriptor),
    ESP_ELFSYM_EXPORT(mpi_hal_disable_hardware_hw_op),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_dpi_set_horizontal_timing),
    ESP_ELFSYM_EXPORT(mempool_free),
    ESP_ELFSYM_EXPORT(mbedtls_pk_setup),
    ESP_ELFSYM_EXPORT(wifi_bss_max_idle_config__init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_stop__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_get_params),
    ESP_ELFSYM_EXPORT(esp_tls_get_error_handle),
    ESP_ELFSYM_EXPORT(protobuf_c_message_get_packed_size),
    ESP_ELFSYM_EXPORT(lfs_format),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_get_level__init),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_timing_tuning),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_get_ap_records__descriptor),
    ESP_ELFSYM_EXPORT(littlefs_esp_part_sync),
    ESP_ELFSYM_EXPORT(bsp_i2c_primary_bus_get_handle),
    ESP_ELFSYM_EXPORT(_ZdaPv),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_append),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_deinit__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_parse_pubkey),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_mode_from_transform),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_alpn_protocol),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_name),
    ESP_ELFSYM_EXPORT(i2s_hal_calc_mclk_precise_division),
    ESP_ELFSYM_EXPORT(_timezone),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_setup__init),
    ESP_ELFSYM_EXPORT(__mprec_tens),
    ESP_ELFSYM_EXPORT(netconn_err),
    ESP_ELFSYM_EXPORT(tcp_input_pcb),
    ESP_ELFSYM_EXPORT(sys_thread_sem_init),
    ESP_ELFSYM_EXPORT(esp_log_util_set_cache_enabled_cb),
    ESP_ELFSYM_EXPORT(raw_send),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_start__descriptor),
    ESP_ELFSYM_EXPORT(esp_vfs_select_triggered),
    ESP_ELFSYM_EXPORT(__truncdfsf2),
    ESP_ELFSYM_EXPORT(tcsetattr),
    ESP_ELFSYM_EXPORT(cJSON_ParseWithLengthOpts),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_finished),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_country__descriptor),
    ESP_ELFSYM_EXPORT(dhcp_fine_tmr),
    ESP_ELFSYM_EXPORT(esp_log_timestamp),
    ESP_ELFSYM_EXPORT(esp_sha_release_hardware),
    ESP_ELFSYM_EXPORT(dhcp_network_changed_link_up),
    ESP_ELFSYM_EXPORT(esp_clk_tree_rc_fast_get_freq_hz),
    ESP_ELFSYM_EXPORT(esp_efuse_startup_include_func),
    ESP_ELFSYM_EXPORT(heap_info__init),
    ESP_ELFSYM_EXPORT(netconn_join_leave_group),
    ESP_ELFSYM_EXPORT(lfs_crc),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_domain_name__init),
    ESP_ELFSYM_EXPORT(lwip_inet_ntop),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_enterprise_disable__descriptor),
    ESP_ELFSYM_EXPORT(spi_flash_enable_interrupts_caches_and_other_cpu),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_write),
    ESP_ELFSYM_EXPORT(regi2c_ctrl_write_reg),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_read),
    ESP_ELFSYM_EXPORT(i2s_platform_acquire_occupation),
    ESP_ELFSYM_EXPORT(esp_cache_resume_ext_mem_cache),
    ESP_ELFSYM_EXPORT(pbuf_cat),
    ESP_ELFSYM_EXPORT(ulTaskGenericNotifyTake),
    ESP_ELFSYM_EXPORT(multi_heap_realloc_impl),
    ESP_ELFSYM_EXPORT(mspi_timing_config_psram_read_data),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_password__init),
    ESP_ELFSYM_EXPORT(httpd_resp_set_type),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_teardown__descriptor),
    ESP_ELFSYM_EXPORT(gpio_get_level),
    ESP_ELFSYM_EXPORT(vterm_enter_graphics_mode),
    ESP_ELFSYM_EXPORT(esp_event_loop_run),
    ESP_ELFSYM_EXPORT(gpio_hold_dis),
    ESP_ELFSYM_EXPORT(httpd_sess_get_free),
    ESP_ELFSYM_EXPORT(tcp_free_ooseq),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple14get_typed_itemENS_8ItemTypeEPKcPvj),
    ESP_ELFSYM_EXPORT(dns_mquery_v6group),
    ESP_ELFSYM_EXPORT(pbuf_clen),
    ESP_ELFSYM_EXPORT(__kernel_cos),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_config__init),
    ESP_ELFSYM_EXPORT(GPIO_HOLD_MASK),
    ESP_ELFSYM_EXPORT(http_parser_settings_init),
    ESP_ELFSYM_EXPORT(gzerror),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_transform_free),
    ESP_ELFSYM_EXPORT(sdmmc_mmc_enable_hs_mode),
    ESP_ELFSYM_EXPORT(mempool_create),
    ESP_ELFSYM_EXPORT(_Znaj),
    ESP_ELFSYM_EXPORT(rpc_core_start),
    ESP_ELFSYM_EXPORT(esp_lcd_panel_reset),
    ESP_ELFSYM_EXPORT(esp_vfs_usb_serial_jtag_use_driver),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_write_be),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_parse_cn_inet_pton),
    ESP_ELFSYM_EXPORT(esp_mbedtls_conn_delete),
    ESP_ELFSYM_EXPORT(vPortTCBPreDeleteHook),
    ESP_ELFSYM_EXPORT(rpc__event__wifi_dpp_cfg_recvd__init),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_config_host_io_mode),
    ESP_ELFSYM_EXPORT(atoi),
    ESP_ELFSYM_EXPORT(gpio_intr_enable),
    ESP_ELFSYM_EXPORT(_fputs_r),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager16deinit_partitionEPKc),
    ESP_ELFSYM_EXPORT(aes_hal_gcm_init),
    ESP_ELFSYM_EXPORT(rgb_gfx_rectfill),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_point_init),
    ESP_ELFSYM_EXPORT(gdma_hal_enable_access_encrypt_mem),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_random),
    ESP_ELFSYM_EXPORT(nd6_clear_destination_cache),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_read_intr_status),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_sub_int),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_certificate_and_key__descriptor),
    ESP_ELFSYM_EXPORT(ESP_LITTLEFS_TAG),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_probe__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_tls_read_point),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_keep_alive),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_parse_key),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage26eraseMismatchedBlobIndexesER14intrusive_listINS0_13BlobIndexNodeEE),
    ESP_ELFSYM_EXPORT(vPortYieldFromISR),
    ESP_ELFSYM_EXPORT(spi_flash_munmap),
    ESP_ELFSYM_EXPORT(tanmatsu_keyboard_start),
    ESP_ELFSYM_EXPORT(__ieee754_rem_pio2f),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_driver_install),
    ESP_ELFSYM_EXPORT(soc_get_available_memory_regions),
    ESP_ELFSYM_EXPORT(esp_pthread_set_cfg),
    ESP_ELFSYM_EXPORT(rpc_id__descriptor),
    ESP_ELFSYM_EXPORT(esp_netif_get_event_id),
    ESP_ELFSYM_EXPORT(tcp_pcb_purge),
    ESP_ELFSYM_EXPORT(mbedtls_pem_init),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_cipher_alg),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_init),
    ESP_ELFSYM_EXPORT(mbedtls_aria_setkey_enc),
    ESP_ELFSYM_EXPORT(__fixunsdfsi),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_update_handshake_status),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_set_iv),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_get_flow_id_status__init),
    ESP_ELFSYM_EXPORT(esp_intr_alloc_intrstatus_bind),
    ESP_ELFSYM_EXPORT(prvTaskCreateDynamicPinnedToCoreWithCaps),
    ESP_ELFSYM_EXPORT(strftime),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_set_crc_poly),
    ESP_ELFSYM_EXPORT(i2s_hal_std_set_rx_slot),
    ESP_ELFSYM_EXPORT(httpd_unrecv),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_config__init),
    ESP_ELFSYM_EXPORT(mbedtls_pem_read_buffer),
    ESP_ELFSYM_EXPORT(spi_flash_hal_check_status),
    ESP_ELFSYM_EXPORT(igmp_report_groups),
    ESP_ELFSYM_EXPORT(__trunctfdf2),
    ESP_ELFSYM_EXPORT(__wrap_remove),
    ESP_ELFSYM_EXPORT(esp_sha_write_digest_state),
    ESP_ELFSYM_EXPORT(esp_netif_get_ifkey),
    ESP_ELFSYM_EXPORT(xQueueCreateWithCaps),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_username__init),
    ESP_ELFSYM_EXPORT(ets_isr_mask),
    ESP_ELFSYM_EXPORT(rgb_display_get_fb_width),
    ESP_ELFSYM_EXPORT(_sprintf_r),
    ESP_ELFSYM_EXPORT(esp_deregister_freertos_idle_hook_for_cpu),
    ESP_ELFSYM_EXPORT(mbedtls_md5),
    ESP_ELFSYM_EXPORT(rtos_save_fpu_coproc),
    ESP_ELFSYM_EXPORT(sdmmc_host_do_transaction),
    ESP_ELFSYM_EXPORT(esp_vfs_register_common),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_vfs_register),
    ESP_ELFSYM_EXPORT(esp_console_cmd_register),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_band__descriptor),
    ESP_ELFSYM_EXPORT(opendir),
    ESP_ELFSYM_EXPORT(port_uxCoprocOwner),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_configure_host_io_mode),
    ESP_ELFSYM_EXPORT(esp_rtc_get_time_us),
    ESP_ELFSYM_EXPORT(optopt),
    ESP_ELFSYM_EXPORT(rgb_gfx_clear),
    ESP_ELFSYM_EXPORT(sqrtf),
    ESP_ELFSYM_EXPORT(cmd_more),
    ESP_ELFSYM_EXPORT(__cxx_init_dummy),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_write_default),
    ESP_ELFSYM_EXPORT(tcp_eff_send_mss_netif),
    ESP_ELFSYM_EXPORT(tcdrain),
    ESP_ELFSYM_EXPORT(pthread_setspecific),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_get_disable_time_check__init),
    ESP_ELFSYM_EXPORT(mbedtls_pkcs5_pbes2_ext),
    ESP_ELFSYM_EXPORT(rtc_gpio_pullup_en),
    ESP_ELFSYM_EXPORT(httpd_sess_free_ctx),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_reset_in_pointers),
    ESP_ELFSYM_EXPORT(clk_hal_lp_slow_get_freq_hz),
    ESP_ELFSYM_EXPORT(__wrap__Unwind_DeleteException),
    ESP_ELFSYM_EXPORT(sdmmc_flip_byte_order),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_supports_direct_write),
    ESP_ELFSYM_EXPORT(gdma_hal_get_lfsr_mask_from_matrix),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_max_tx_power__init),
    ESP_ELFSYM_EXPORT(_freopen_r),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_driver_strength),
    ESP_ELFSYM_EXPORT(sdmmc_init_mmc_decode_cid),
    ESP_ELFSYM_EXPORT(regdma_link_new_addr_map_default),
    ESP_ELFSYM_EXPORT(wifi_bss_max_idle_config__descriptor),
    ESP_ELFSYM_EXPORT(ecc_hal_read_mul_result),
    ESP_ELFSYM_EXPORT(realpath),
    ESP_ELFSYM_EXPORT(spi_flash_hal_device_config),
    ESP_ELFSYM_EXPORT(vTaskSuspend),
    ESP_ELFSYM_EXPORT(esp_tls_get_and_clear_error_type),
    ESP_ELFSYM_EXPORT(rpc__event__supp_dpp_uri_ready__init),
    ESP_ELFSYM_EXPORT(esp_ds_get_keylen),
    ESP_ELFSYM_EXPORT(fwrite),
    ESP_ELFSYM_EXPORT(strspn),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_connect__descriptor),
    ESP_ELFSYM_EXPORT(rtc_gpio_pullup_dis),
    ESP_ELFSYM_EXPORT(es8156_write_volume_control),
    ESP_ELFSYM_EXPORT(sdmmc_init_card_hs_mode),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager11init_customEPNS_9PartitionEmm),
    ESP_ELFSYM_EXPORT(esp_cache_err_get_cpuid),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page14alterPageStateENS0_9PageStateE),
    ESP_ELFSYM_EXPORT(regdma_link_new_addr_map),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_identity__init),
    ESP_ELFSYM_EXPORT(esp_libc_include_reent_syscalls_impl),
    ESP_ELFSYM_EXPORT(wdt_hal_deinit),
    ESP_ELFSYM_EXPORT(_svfprintf_r),
    ESP_ELFSYM_EXPORT(lcd_periph_rgb_signals),
    ESP_ELFSYM_EXPORT(xIsrStackTop),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page6Header14calculateCrc32Ev),
    ESP_ELFSYM_EXPORT(spi_flash_hal_configure_host_io_mode),
    ESP_ELFSYM_EXPORT(hosted_timer_stop),
    ESP_ELFSYM_EXPORT(sdmmc_host_set_bus_width),
    ESP_ELFSYM_EXPORT(linenoiseAddCompletion),
    ESP_ELFSYM_EXPORT(heap_caps_init),
    ESP_ELFSYM_EXPORT(pbuf_take_at),
    ESP_ELFSYM_EXPORT(gzclose_w),
    ESP_ELFSYM_EXPORT(raw_new_ip_type),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_set_pull_mode__init),
    ESP_ELFSYM_EXPORT(tlsf_get_pool),
    ESP_ELFSYM_EXPORT(puts),
    ESP_ELFSYM_EXPORT(pbuf_clone),
    ESP_ELFSYM_EXPORT(_i2s_hal_set_rx_clock),
    ESP_ELFSYM_EXPORT(tlsf_pool_overhead),
    ESP_ELFSYM_EXPORT(udp_new_ip_type),
    ESP_ELFSYM_EXPORT(vsnprintf),
    ESP_ELFSYM_EXPORT(bmi270_feat_out),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_ca_cert__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_disconnect__init),
    ESP_ELFSYM_EXPORT(linenoiseEditMoveHome),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_exp_mod),
    ESP_ELFSYM_EXPORT(esp_tls_get_bytes_avail),
    ESP_ELFSYM_EXPORT(lfs_fs_grow),
    ESP_ELFSYM_EXPORT(__retarget_lock_acquire_recursive),
    ESP_ELFSYM_EXPORT(_ZNSt9type_infoD1Ev),
    ESP_ELFSYM_EXPORT(esp_log_linked_list_set_level),
    ESP_ELFSYM_EXPORT(_mtvt_table),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage17readMultiPageBlobEhPKcPvj),
    ESP_ELFSYM_EXPORT(strlcpy),
    ESP_ELFSYM_EXPORT(getopt_long),
    ESP_ELFSYM_EXPORT(fopen),
    ESP_ELFSYM_EXPORT(port_xSchedulerRunning),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_set_direction__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__custom_rpc__descriptor),
    ESP_ELFSYM_EXPORT(_fread_r),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_params__init),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_suiteb192bit_certification__init),
    ESP_ELFSYM_EXPORT(__errno),
    ESP_ELFSYM_EXPORT(multi_heap_get_allocated_size),
    ESP_ELFSYM_EXPORT(esp_tls_conn_destroy),
    ESP_ELFSYM_EXPORT(bmi2_sec_init),
    ESP_ELFSYM_EXPORT(hci_drv_show_configuration),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_erase_block),
    ESP_ELFSYM_EXPORT(tcp_rst_netif),
    ESP_ELFSYM_EXPORT(bmi2_get_feat_config),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage8findItemEhNS_8ItemTypeEPKcRPNS_4PageERNS_4ItemEhNS_9VerOffsetE),
    ESP_ELFSYM_EXPORT(dw_gdma_del_link_list),
    ESP_ELFSYM_EXPORT(_strtoul_r),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_bus_width),
    ESP_ELFSYM_EXPORT(_sscanf_r),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_mla),
    ESP_ELFSYM_EXPORT(mbedtls_sha512_clone),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_band_mode__init),
    ESP_ELFSYM_EXPORT(rpc__resp__config_heartbeat__init),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_enable_intr),
    ESP_ELFSYM_EXPORT(igmp_start),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_get_bit),
    ESP_ELFSYM_EXPORT(spi_flash_timing_is_tuned),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_protocol__descriptor),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_send),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_config_init),
    ESP_ELFSYM_EXPORT(periph_rcc_release_exit),
    ESP_ELFSYM_EXPORT(_i2c_hal_init),
    ESP_ELFSYM_EXPORT(getc),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_scr),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_bytes_avail),
    ESP_ELFSYM_EXPORT(esp_ipc_call_nonblocking),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_okc_support__descriptor),
    ESP_ELFSYM_EXPORT(esp_netif_transmit_wrap),
    ESP_ELFSYM_EXPORT(http_header_get_item),
    ESP_ELFSYM_EXPORT(deflateEnd),
    ESP_ELFSYM_EXPORT(httpd_sess_trigger_close_),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_auth_encrypt_ext),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_inactive_time__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_stop_listen__init),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_int),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsassa_pkcs1_v15_verify),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_get_pmic_faults),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_ttls_phase2_method__descriptor),
    ESP_ELFSYM_EXPORT(strtoull_l),
    ESP_ELFSYM_EXPORT(multi_heap_get_allocated_size_impl),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page5eraseEv),
    ESP_ELFSYM_EXPORT(tcp_segs_free),
    ESP_ELFSYM_EXPORT(esp_crypto_base64_encode),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_read),
    ESP_ELFSYM_EXPORT(esp_partition_is_flash_region_writable),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_init),
    ESP_ELFSYM_EXPORT(xRingbufferReceiveUpTo),
    ESP_ELFSYM_EXPORT(esp_mbedtls_cleanup),
    ESP_ELFSYM_EXPORT(rpc__resp__iface_mac_addr_len_get__init),
    ESP_ELFSYM_EXPORT(esp_lcd_panel_draw_bitmap),
    ESP_ELFSYM_EXPORT(mkdir),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_init__init),
    ESP_ELFSYM_EXPORT(io_mux_force_disable_lp_io_clock),
    ESP_ELFSYM_EXPORT(sdmmc_mmc_decode_csd),
    ESP_ELFSYM_EXPORT(gdma_hal_set_burst_size),
    ESP_ELFSYM_EXPORT(mbedtls_net_free),
    ESP_ELFSYM_EXPORT(esp_sha_dma_start),
    ESP_ELFSYM_EXPORT(esp_netif_new),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashListC1Ev),
    ESP_ELFSYM_EXPORT(__divdf3),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashList4findEjRKNS_4ItemE),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_uint_le_mpi),
    ESP_ELFSYM_EXPORT(getopt_long_only),
    ESP_ELFSYM_EXPORT(netif_ip6_addr_set_state),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition18get_partition_nameEv),
    ESP_ELFSYM_EXPORT(igmp_joingroup_netif),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_input_enable__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_info_from_type),
    ESP_ELFSYM_EXPORT(esp_netif_remove_from_list_unsafe),
    ESP_ELFSYM_EXPORT(pbuf_put_at),
    ESP_ELFSYM_EXPORT(esp_netif_dhcpc_get_status),
    ESP_ELFSYM_EXPORT(tcp_send_fin),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_check_extended_key_usage),
    ESP_ELFSYM_EXPORT(siscanf),
    ESP_ELFSYM_EXPORT(esp_security_init_include_impl),
    ESP_ELFSYM_EXPORT(tcp_rexmit_rto_prepare),
    ESP_ELFSYM_EXPORT(pmu_lp_system_power_param_default),
    ESP_ELFSYM_EXPORT(putc),
    ESP_ELFSYM_EXPORT(esp_log),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_write_le),
    ESP_ELFSYM_EXPORT(gzwrite),
    ESP_ELFSYM_EXPORT(s_microseconds_offset),
    ESP_ELFSYM_EXPORT(rpc_slaveif_start),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_start_renegotiation),
    ESP_ELFSYM_EXPORT(_strtoull_r),
    ESP_ELFSYM_EXPORT(tcp_bound_pcbs),
    ESP_ELFSYM_EXPORT(rpc__resp__set_mac_address__descriptor),
    ESP_ELFSYM_EXPORT(esp_clk_tree_lp_fast_get_freq_hz),
    ESP_ELFSYM_EXPORT(rgb_gfx_pixel),
    ESP_ELFSYM_EXPORT(esp_pm_lock_acquire),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_grp_id_list),
    ESP_ELFSYM_EXPORT(memp_IGMP_GROUP),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_stop),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_get_intr_status_reg),
    ESP_ELFSYM_EXPORT(sdmmc_init_rca),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple9erase_allEv),
    ESP_ELFSYM_EXPORT(esp_transport_tcp_set_keep_alive),
    ESP_ELFSYM_EXPORT(httpd_uri_match_wildcard),
    ESP_ELFSYM_EXPORT(ecc_hal_read_verify_result),
    ESP_ELFSYM_EXPORT(tcp_ticks),
    ESP_ELFSYM_EXPORT(esp_aes_xts_setkey_dec),
    ESP_ELFSYM_EXPORT(mbedtls_pk_can_do),
    ESP_ELFSYM_EXPORT(regdma_find_next_module_link_head),
    ESP_ELFSYM_EXPORT(ferror),
    ESP_ELFSYM_EXPORT(tcp_trigger_input_pcb_close),
    ESP_ELFSYM_EXPORT(__getopt_long_r),
    ESP_ELFSYM_EXPORT(soc_mipi_dsi_phy_pll_ranges),
    ESP_ELFSYM_EXPORT(snprintf),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_client_hello),
    ESP_ELFSYM_EXPORT(etharp_input),
    ESP_ELFSYM_EXPORT(spi_flash_guard_get),
    ESP_ELFSYM_EXPORT(tcp_close_ext),
    ESP_ELFSYM_EXPORT(_ZN3nvs11PageManager4loadEPNS_9PartitionEmm),
    ESP_ELFSYM_EXPORT(rpc_slaveif_init),
    ESP_ELFSYM_EXPORT(raw_connect),
    ESP_ELFSYM_EXPORT(tcp_recv),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_start_with_desc),
    ESP_ELFSYM_EXPORT(rpc_start),
    ESP_ELFSYM_EXPORT(__month_lengths),
    ESP_ELFSYM_EXPORT(eTaskGetState),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_hash_from_md_alg),
    ESP_ELFSYM_EXPORT(eap_fast_config__descriptor),
    ESP_ELFSYM_EXPORT(lwip_getaddrinfo),
    ESP_ELFSYM_EXPORT(lwip_getpeername),
    ESP_ELFSYM_EXPORT(__lock___atexit_recursive_mutex),
    ESP_ELFSYM_EXPORT(esp_log_cache_add),
    ESP_ELFSYM_EXPORT(rpc__gpio_config__descriptor),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv120__si_class_type_info12__do_dyncastEiNS_17__class_type_info10__sub_kindEPKS1_PKvS4_S6_RNS1_16__dyncast_resultE),
    ESP_ELFSYM_EXPORT(esp_timer_impl_early_init),
    ESP_ELFSYM_EXPORT(es8156_write_clock_off),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_clear_ap_list__init),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_identity__descriptor),
    ESP_ELFSYM_EXPORT(xPortSwitchFlag),
    ESP_ELFSYM_EXPORT(fcntl),
    ESP_ELFSYM_EXPORT(__cxa_begin_catch),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_band_mode__descriptor),
    ESP_ELFSYM_EXPORT(multi_heap_internal_unlock),
    ESP_ELFSYM_EXPORT(_lseek_r),
    ESP_ELFSYM_EXPORT(gpio_pullup_en),
    ESP_ELFSYM_EXPORT(rpc__req__config_heartbeat__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_ca_cert__init),
    ESP_ELFSYM_EXPORT(_strtoll_r),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage21createOrOpenNamespaceEPKcbRh),
    ESP_ELFSYM_EXPORT(spi_flash_chip_list_check),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_bandwidths__init),
    ESP_ELFSYM_EXPORT(memp_ND6_QUEUE),
    ESP_ELFSYM_EXPORT(access),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_read_unique_id),
    ESP_ELFSYM_EXPORT(mbedtls_pk_init),
    ESP_ELFSYM_EXPORT(gdma_hal_set_strategy),
    ESP_ELFSYM_EXPORT(_vector_table),
    ESP_ELFSYM_EXPORT(heap_caps_get_allocated_size),
    ESP_ELFSYM_EXPORT(esp_panic_handler_increment_entry_count),
    ESP_ELFSYM_EXPORT(_findenv_r),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_parse_change_cipher_spec),
    ESP_ELFSYM_EXPORT(xTaskCheckForTimeOut),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_protocol__init),
    ESP_ELFSYM_EXPORT(__retarget_lock_try_acquire),
    ESP_ELFSYM_EXPORT(esp_cpu_set_breakpoint),
    ESP_ELFSYM_EXPORT(dma2d_rx_channel_reserved_mask),
    ESP_ELFSYM_EXPORT(hosted_get_host_wakeup_or_reboot_reason),
    ESP_ELFSYM_EXPORT(gdma_register_tx_event_callbacks),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_pkcs1_encrypt),
    ESP_ELFSYM_EXPORT(pthread_attr_init),
    ESP_ELFSYM_EXPORT(vTaskGenericNotifyGiveFromISR),
    ESP_ELFSYM_EXPORT(esp_mbedtls_write),
    ESP_ELFSYM_EXPORT(i2c_periph_signal),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_connection_monitor_include),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_pac_file__descriptor),
    ESP_ELFSYM_EXPORT(sdmmc_mmc_switch),
    ESP_ELFSYM_EXPORT(tcpip_api_call),
    ESP_ELFSYM_EXPORT(ds_hal_busy),
    ESP_ELFSYM_EXPORT(rgb_gfx_vline),
    ESP_ELFSYM_EXPORT(vRingbufferReturnItemFromISR),
    ESP_ELFSYM_EXPORT(xTaskIncrementTick),
    ESP_ELFSYM_EXPORT(cache_hal_suspend),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_twt_config__init),
    ESP_ELFSYM_EXPORT(sleep_retention_entries_create),
    ESP_ELFSYM_EXPORT(hosted_write_gpio),
    ESP_ELFSYM_EXPORT(tcp_enqueue_flags),
    ESP_ELFSYM_EXPORT(lwip_fcntl),
    ESP_ELFSYM_EXPORT(http_header_delete),
    ESP_ELFSYM_EXPORT(_raise_r),
    ESP_ELFSYM_EXPORT(rpc__event__dhcp_dns_status__descriptor),
    ESP_ELFSYM_EXPORT(hosted_post_semaphore_from_isr),
    ESP_ELFSYM_EXPORT(dhcp_release),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsassa_pkcs1_v15_sign),
    ESP_ELFSYM_EXPORT(lfs_file_truncate),
    ESP_ELFSYM_EXPORT(vSemaphoreDeleteWithCaps),
    ESP_ELFSYM_EXPORT(sdmmc_host_deinit_slot),
    ESP_ELFSYM_EXPORT(vterm_get_palette),
    ESP_ELFSYM_EXPORT(__kernel_sinf),
    ESP_ELFSYM_EXPORT(_ZN3nvs4LockC1Ev),
    ESP_ELFSYM_EXPORT(__ledf2),
    ESP_ELFSYM_EXPORT(serial_drv_close),
    ESP_ELFSYM_EXPORT(gpio_set_level),
    ESP_ELFSYM_EXPORT(esp_heap_adjust_alignment_to_hw),
    ESP_ELFSYM_EXPORT(esp_gpio_reserve),
    ESP_ELFSYM_EXPORT(rpc_type__descriptor),
    ESP_ELFSYM_EXPORT(pmu_hp_system_init),
    ESP_ELFSYM_EXPORT(esp_event_handler_unregister),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_is_driver_installed),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_use_default_cert_bundle__init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_protocol__descriptor),
    ESP_ELFSYM_EXPORT(_getenv_r),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_grow),
    ESP_ELFSYM_EXPORT(lp_gpio_connect_out_signal),
    ESP_ELFSYM_EXPORT(i2s_gpio_check_and_set),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_mul_restartable),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_supports_direct_read),
    ESP_ELFSYM_EXPORT(rpc__resp__app_get_desc__descriptor),
    ESP_ELFSYM_EXPORT(rgb_display_set_callbacks),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_new_password__init),
    ESP_ELFSYM_EXPORT(mspi_timing_config_psram_set_tuning_phase),
    ESP_ELFSYM_EXPORT(__floatsidf),
    ESP_ELFSYM_EXPORT(_fopen_r),
    ESP_ELFSYM_EXPORT(esp_timer_stop),
    ESP_ELFSYM_EXPORT(ecc_hal_write_mul_param),
    ESP_ELFSYM_EXPORT(rpc__resp__otaend__init),
    ESP_ELFSYM_EXPORT(hosted_destroy_queue),
    ESP_ELFSYM_EXPORT(esp_system_reset_modules_on_exit),
    ESP_ELFSYM_EXPORT(__lshrdi3),
    ESP_ELFSYM_EXPORT(mpi_hal_write_to_mem_block),
    ESP_ELFSYM_EXPORT(mbedtls_ct_memcpy_offset),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_suspend__init),
    ESP_ELFSYM_EXPORT(rpc__req__ext_coex__init),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_identity__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_get_flow_id_status__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage18eraseMultiPageBlobEhPKcNS_9VerOffsetE),
    ESP_ELFSYM_EXPORT(wifi_itwt_setup_config__descriptor),
    ESP_ELFSYM_EXPORT(esp_mmu_map),
    ESP_ELFSYM_EXPORT(heap_caps_aligned_alloc_base),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_oid_by_md),
    ESP_ELFSYM_EXPORT(__submore),
    ESP_ELFSYM_EXPORT(hosted_dequeue_item),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_tls_id_from_ecp_group_id),
    ESP_ELFSYM_EXPORT(panic_arch_fill_info),
    ESP_ELFSYM_EXPORT(int_wdt_cpu1_ticked),
    ESP_ELFSYM_EXPORT(heap_caps_aligned_alloc),
    ESP_ELFSYM_EXPORT(rpc_wifi_scan_get_ap_num),
    ESP_ELFSYM_EXPORT(dma2d_release_pool),
    ESP_ELFSYM_EXPORT(gpio_iomux_output),
    ESP_ELFSYM_EXPORT(bus_handle),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_set_strategy),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_read_be),
    ESP_ELFSYM_EXPORT(mbedtls_eckey_info),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv120__si_class_type_infoD1Ev),
    ESP_ELFSYM_EXPORT(esp_event_post),
    ESP_ELFSYM_EXPORT(rpc__req__eap_get_disable_time_check__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_mul_mpi),
    ESP_ELFSYM_EXPORT(vPortExitCriticalMultiCore),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_parse_der),
    ESP_ELFSYM_EXPORT(hosted_thread_cancel),
    ESP_ELFSYM_EXPORT(mbedtls_base64_decode),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_stop__init),
    ESP_ELFSYM_EXPORT(rpc__req__otabegin__init),
    ESP_ELFSYM_EXPORT(bsearch),
    ESP_ELFSYM_EXPORT(rtc_clk_slow_freq_get_hz),
    ESP_ELFSYM_EXPORT(netbuf_delete),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_enable_access_encrypt_mem),
    ESP_ELFSYM_EXPORT(esp_vfs_select),
    ESP_ELFSYM_EXPORT(s_get_cache_state),
    ESP_ELFSYM_EXPORT(mpi_hal_read_result_hw_op),
    ESP_ELFSYM_EXPORT(_ZN14NVSHandleEntry17s_nvs_next_handleE),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_clear_ap_list__init),
    ESP_ELFSYM_EXPORT(gdma_connect),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_config_free),
    ESP_ELFSYM_EXPORT(nd6_restart_netif),
    ESP_ELFSYM_EXPORT(esp_lcd_new_panel_st7701_mipi),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_negotiated_phymode__init),
    ESP_ELFSYM_EXPORT(etharp_remove_static_entry),
    ESP_ELFSYM_EXPORT(__gethex),
    ESP_ELFSYM_EXPORT(mld6_tmr),
    ESP_ELFSYM_EXPORT(esp_hw_stack_guard_get_fired_cpu),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_fetch_input),
    ESP_ELFSYM_EXPORT(lwip_ioctl),
    ESP_ELFSYM_EXPORT(memchr),
    ESP_ELFSYM_EXPORT(sys_thread_tcpip),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv111__terminateEPFvvE),
    ESP_ELFSYM_EXPORT(netif_set_default),
    ESP_ELFSYM_EXPORT(gdma_hal_get_intr_status_reg),
    ESP_ELFSYM_EXPORT(xQueueGenericSend),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_group_free),
    ESP_ELFSYM_EXPORT(__b2d),
    ESP_ELFSYM_EXPORT(rtc_gpio_is_valid_gpio),
    ESP_ELFSYM_EXPORT(_ungetc_r),
    ESP_ELFSYM_EXPORT(cmd_eget),
    ESP_ELFSYM_EXPORT(rpc__req__ext_coex__descriptor),
    ESP_ELFSYM_EXPORT(vterm_input_feed),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_ca_cert__descriptor),
    ESP_ELFSYM_EXPORT(port_uxOldInterruptState),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_import_raw),
    ESP_ELFSYM_EXPORT(wlanif_input),
    ESP_ELFSYM_EXPORT(_fflush_r),
    ESP_ELFSYM_EXPORT(esp_transport_connect),
    ESP_ELFSYM_EXPORT(sys_timeout),
    ESP_ELFSYM_EXPORT(esp_vfs_lseek),
    ESP_ELFSYM_EXPORT(panic_print_backtrace),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_clear_ap_list__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_bandwidths__descriptor),
    ESP_ELFSYM_EXPORT(hosted_queue_item),
    ESP_ELFSYM_EXPORT(write),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_certificate),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_gen_public),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_md_hmac),
    ESP_ELFSYM_EXPORT(strcasecmp),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_twt_config__init),
    ESP_ELFSYM_EXPORT(__ascii_mbtowc),
    ESP_ELFSYM_EXPORT(__ffsdi2),
    ESP_ELFSYM_EXPORT(vfprintf),
    ESP_ELFSYM_EXPORT(rtc_gpio_set_direction),
    ESP_ELFSYM_EXPORT(__swbuf_r),
    ESP_ELFSYM_EXPORT(httpd_sess_process),
    ESP_ELFSYM_EXPORT(vPortYield),
    ESP_ELFSYM_EXPORT(tcpip_init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_bandwidth__init),
    ESP_ELFSYM_EXPORT(mbedtls_sha1_finish),
    ESP_ELFSYM_EXPORT(esp_aes_acquire_hardware),
    ESP_ELFSYM_EXPORT(netconn_write_vectors_partly),
    ESP_ELFSYM_EXPORT(mbedtls_md_setup),
    ESP_ELFSYM_EXPORT(gpio_pulldown_en),
    ESP_ELFSYM_EXPORT(mbedtls_x509_parse_subject_alt_name),
    ESP_ELFSYM_EXPORT(esp_ipc_func),
    ESP_ELFSYM_EXPORT(wifi_country__init),
    ESP_ELFSYM_EXPORT(etharp_cleanup_netif),
    ESP_ELFSYM_EXPORT(inflate_table),
    ESP_ELFSYM_EXPORT(esp_vfs_link),
    ESP_ELFSYM_EXPORT(lcd_com_register_device),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_init),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_config__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_lsb),
    ESP_ELFSYM_EXPORT(pthread_join),
    ESP_ELFSYM_EXPORT(rpc__event__ap__sta_connected__descriptor),
    ESP_ELFSYM_EXPORT(esp_async_fbcpy_uninstall),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_update_in_pointers),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_vfs_use_driver),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_parse_finished),
    ESP_ELFSYM_EXPORT(__env_lock),
    ESP_ELFSYM_EXPORT(hosted_get_semaphore),
    ESP_ELFSYM_EXPORT(hosted_memcpy),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_driver_uninstall),
    ESP_ELFSYM_EXPORT(__hexdig_fun),
    ESP_ELFSYM_EXPORT(esp_vfs_closedir),
    ESP_ELFSYM_EXPORT(wifi_sta_config__init),
    ESP_ELFSYM_EXPORT(wifi_scan_time__descriptor),
    ESP_ELFSYM_EXPORT(esp_log_is_tag_loggable),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_rng),
    ESP_ELFSYM_EXPORT(esp_cpu_compare_and_set),
    ESP_ELFSYM_EXPORT(esp_timer_start_periodic),
    ESP_ELFSYM_EXPORT(sdmmc_host_dma_prepare),
    ESP_ELFSYM_EXPORT(esp_aes_xts_setkey_enc),
    ESP_ELFSYM_EXPORT(dns_setserver),
    ESP_ELFSYM_EXPORT(lwip_write),
    ESP_ELFSYM_EXPORT(rtc_clk_apb_freq_get),
    ESP_ELFSYM_EXPORT(ungetc),
    ESP_ELFSYM_EXPORT(esp_mbedtls_verify_certificate),
    ESP_ELFSYM_EXPORT(MPI_OPERATIONS_REG),
    ESP_ELFSYM_EXPORT(nvs_get_str),
    ESP_ELFSYM_EXPORT(cos),
    ESP_ELFSYM_EXPORT(pmu_hp_system_digital_param_default),
    ESP_ELFSYM_EXPORT(xQueueReceive),
    ESP_ELFSYM_EXPORT(mbedtls_oid_get_md_alg),
    ESP_ELFSYM_EXPORT(esp_http_client_get_status_code),
    ESP_ELFSYM_EXPORT(__nedf2),
    ESP_ELFSYM_EXPORT(mbedtls_sha1_update),
    ESP_ELFSYM_EXPORT(__ssvfscanf_r),
    ESP_ELFSYM_EXPORT(mbedtls_md_info_from_type),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_output_max_frag_len),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_ap_get_sta_list__descriptor),
    ESP_ELFSYM_EXPORT(__swsetup_r),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_recv),
    ESP_ELFSYM_EXPORT(linenoiseEditDelete),
    ESP_ELFSYM_EXPORT(ip6_output_if),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_ap_get_sta_list__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_cipher_reset),
    ESP_ELFSYM_EXPORT(mbedtls_pk_free),
    ESP_ELFSYM_EXPORT(wifi_itwt_setup_config__init),
    ESP_ELFSYM_EXPORT(udp_recv),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_new_password__descriptor),
    ESP_ELFSYM_EXPORT(ip6_route),
    ESP_ELFSYM_EXPORT(i2s_platform_release_occupation),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage9eraseItemEhNS_8ItemTypeEPKc),
    ESP_ELFSYM_EXPORT(_fseeko_r),
    ESP_ELFSYM_EXPORT(gzopen),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_read_signature_restartable),
    ESP_ELFSYM_EXPORT(memspi_host_read_data_slicer),
    ESP_ELFSYM_EXPORT(mspi_timing_flash_tuning),
    ESP_ELFSYM_EXPORT(es8156_write_register),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_set_timer),
    ESP_ELFSYM_EXPORT(cache_hal_vaddr_to_cache_level_id),
    ESP_ELFSYM_EXPORT(esp_intr_noniram_disable),
    ESP_ELFSYM_EXPORT(tlsf_free),
    ESP_ELFSYM_EXPORT(spi_flash_hal_common_command),
    ESP_ELFSYM_EXPORT(esp_console_rm_item_free_hint),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple13get_item_sizeENS_8ItemTypeEPKcRj),
    ESP_ELFSYM_EXPORT(wifi_sta_list__init),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_wait_tx_done),
    ESP_ELFSYM_EXPORT(_impure_ptr),
    ESP_ELFSYM_EXPORT(esp_app_desc__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__get_mac_address__init),
    ESP_ELFSYM_EXPORT(power_supply_periph_signal),
    ESP_ELFSYM_EXPORT(httpd_sess_enum),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_send_csd),
    ESP_ELFSYM_EXPORT(rpc__event__sta_itwt_teardown__init),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_deduce_private_exponent),
    ESP_ELFSYM_EXPORT(__sfp_lock_acquire),
    ESP_ELFSYM_EXPORT(esp_ipc_isr_handler),
    ESP_ELFSYM_EXPORT(esp_lcd_panel_io_rx_param),
    ESP_ELFSYM_EXPORT(heap_caps_malloc_base),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_safe_cond_assign),
    ESP_ELFSYM_EXPORT(lwip_getsockopt_impl_ext),
    ESP_ELFSYM_EXPORT(tcpip_callback),
    ESP_ELFSYM_EXPORT(cmd_df),
    ESP_ELFSYM_EXPORT(_fgetc_r),
    ESP_ELFSYM_EXPORT(ip_addr_any),
    ESP_ELFSYM_EXPORT(_mbrtowc_r),
    ESP_ELFSYM_EXPORT(arg_print_formatted),
    ESP_ELFSYM_EXPORT(pthread_create),
    ESP_ELFSYM_EXPORT(_setlocale_r),
    ESP_ELFSYM_EXPORT(pbuf_get_at),
    ESP_ELFSYM_EXPORT(pthread_include_pthread_semaphore_impl),
    ESP_ELFSYM_EXPORT(chan_arr),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_config__descriptor),
    ESP_ELFSYM_EXPORT(pvTaskIncrementMutexHeldCount),
    ESP_ELFSYM_EXPORT(lwip_netconn_do_newconn),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_point_write_binary),
    ESP_ELFSYM_EXPORT(gettimeofday),
    ESP_ELFSYM_EXPORT(sdmmc_io_read_bytes),
    ESP_ELFSYM_EXPORT(mbedtls_pk_get_type),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_channel__init),
    ESP_ELFSYM_EXPORT(st7701_get_panel),
    ESP_ELFSYM_EXPORT(esp_transport_destroy),
    ESP_ELFSYM_EXPORT(bsp_orientation_initialize),
    ESP_ELFSYM_EXPORT(esp_ptr_executable),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_country_code__descriptor),
    ESP_ELFSYM_EXPORT(esp_hosted_transport_is_config_valid),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashList5eraseEj),
    ESP_ELFSYM_EXPORT(tcp_timer_needed),
    ESP_ELFSYM_EXPORT(rtc_clk_8m_enable),
    ESP_ELFSYM_EXPORT(lwip_htonl),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_get_ap_num__init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_clz),
    ESP_ELFSYM_EXPORT(time),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_country_code__descriptor),
    ESP_ELFSYM_EXPORT(mspi_timing_config_psram_prepare_reference_data),
    ESP_ELFSYM_EXPORT(rpc__req__config_heartbeat__init),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_wait_default),
    ESP_ELFSYM_EXPORT(cache_hal_init),
    ESP_ELFSYM_EXPORT(fseek),
    ESP_ELFSYM_EXPORT(rpc__resp__feature_control__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs8HashList6insertERKNS_4ItemEj),
    ESP_ELFSYM_EXPORT(__wrap_stat),
    ESP_ELFSYM_EXPORT(__srget_r),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_clear_intr),
    ESP_ELFSYM_EXPORT(vTaskDelay),
    ESP_ELFSYM_EXPORT(__wrap_rmdir),
    ESP_ELFSYM_EXPORT(__atexit0),
    ESP_ELFSYM_EXPORT(rpc__event__supp_dpp_fail__init),
    ESP_ELFSYM_EXPORT(_ZNK3nvs4Item14calculateCrc32Ev),
    ESP_ELFSYM_EXPORT(esp_aes_gcm_crypt_and_tag),
    ESP_ELFSYM_EXPORT(spi_flash_hal_read),
    ESP_ELFSYM_EXPORT(esp_netif_get_flags),
    ESP_ELFSYM_EXPORT(mbedtls_hardware_poll),
    ESP_ELFSYM_EXPORT(esp_transport_ssl_set_cert_data_der),
    ESP_ELFSYM_EXPORT(remove),
    ESP_ELFSYM_EXPORT(IP_EVENT),
    ESP_ELFSYM_EXPORT(httpd_sess_delete_invalid),
    ESP_ELFSYM_EXPORT(gdma_start),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_gcd),
    ESP_ELFSYM_EXPORT(wifi_bandwidths__descriptor),
    ESP_ELFSYM_EXPORT(i2s_get_buf_size),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handshake_server_step),
    ESP_ELFSYM_EXPORT(strncpy),
    ESP_ELFSYM_EXPORT(_ZNSt9exceptionD2Ev),
    ESP_ELFSYM_EXPORT(mbedtls_aria_crypt_cfb128),
    ESP_ELFSYM_EXPORT(memcmp),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_country__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs4LockD2Ev),
    ESP_ELFSYM_EXPORT(__floatundidf),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_aid__descriptor),
    ESP_ELFSYM_EXPORT(fclose),
    ESP_ELFSYM_EXPORT(arg_dstr_reset),
    ESP_ELFSYM_EXPORT(httpd_unregister_all_uri_handlers),
    ESP_ELFSYM_EXPORT(memp_NETCONN),
    ESP_ELFSYM_EXPORT(esp_flash_init_main),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_get_inputs),
    ESP_ELFSYM_EXPORT(__getreent),
    ESP_ELFSYM_EXPORT(s_cache_hal_init_ctx),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page10writeEntryERKNS_4ItemE),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_enable_burst),
    ESP_ELFSYM_EXPORT(mem_info__init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_renegotiate),
    ESP_ELFSYM_EXPORT(mem_info__descriptor),
    ESP_ELFSYM_EXPORT(acd_add),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handshake_client_step),
    ESP_ELFSYM_EXPORT(gdma_hal_enable_burst),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_setup__descriptor),
    ESP_ELFSYM_EXPORT(netconn_getaddr),
    ESP_ELFSYM_EXPORT(esp_aes_crypt_ctr),
    ESP_ELFSYM_EXPORT(esp_sha_read_digest_state),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_current_limit),
    ESP_ELFSYM_EXPORT(nvs_flash_init),
    ESP_ELFSYM_EXPORT(rpc_wifi_scan_get_ap_records),
    ESP_ELFSYM_EXPORT(esp_rtc_init),
    ESP_ELFSYM_EXPORT(g_wifi_osi_funcs),
    ESP_ELFSYM_EXPORT(mspi_timing_enter_low_speed_mode),
    ESP_ELFSYM_EXPORT(spi_flash_brownout_need_reset),
    ESP_ELFSYM_EXPORT(heap_caps_realloc_base),
    ESP_ELFSYM_EXPORT(_Balloc),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_protocol__init),
    ESP_ELFSYM_EXPORT(esp_clk_tree_enable_src),
    ESP_ELFSYM_EXPORT(esp_crypto_ds_lock_acquire),
    ESP_ELFSYM_EXPORT(rpc__event__custom_rpc__init),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_certificate_and_key__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_hmac_drbg_init),
    ESP_ELFSYM_EXPORT(esp_brownout_init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_set_target_wake_time_offset__descriptor),
    ESP_ELFSYM_EXPORT(esp_ds_rsa_sign),
    ESP_ELFSYM_EXPORT(esp_app_get_elf_sha256),
    ESP_ELFSYM_EXPORT(http_header_destroy),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_channel__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_alg),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_domain_name__descriptor),
    ESP_ELFSYM_EXPORT(esp_aes_xts_init),
    ESP_ELFSYM_EXPORT(release_slave_reset_gpio_post_wakeup),
    ESP_ELFSYM_EXPORT(strdup),
    ESP_ELFSYM_EXPORT(aes_hal_setkey),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_start_listen__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_band__init),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_check_privkey),
    ESP_ELFSYM_EXPORT(uxQueueMessagesWaiting),
    ESP_ELFSYM_EXPORT(node_remove_from_list),
    ESP_ELFSYM_EXPORT(mbedtls_sha512),
    ESP_ELFSYM_EXPORT(xQueueSemaphoreTake),
    ESP_ELFSYM_EXPORT(wifi_event_sta_connected__init),
    ESP_ELFSYM_EXPORT(hosted_malloc),
    ESP_ELFSYM_EXPORT(tlsf_fit_size),
    ESP_ELFSYM_EXPORT(sdmmc_enable_hs_mode_and_check),
    ESP_ELFSYM_EXPORT(pbuf_skip),
    ESP_ELFSYM_EXPORT(ip6_chksum_pseudo),
    ESP_ELFSYM_EXPORT(__wrap_realpath),
    ESP_ELFSYM_EXPORT(sdmmc_io_write_byte),
    ESP_ELFSYM_EXPORT(vterm_init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_tls12_write_client_hello_exts),
    ESP_ELFSYM_EXPORT(protobuf_c_message_free_unpacked),
    ESP_ELFSYM_EXPORT(mbedtls_gcm_free_soft),
    ESP_ELFSYM_EXPORT(i2c_master_probe),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_disable_time_check__init),
    ESP_ELFSYM_EXPORT(lwip_freeaddrinfo),
    ESP_ELFSYM_EXPORT(inflateInit2_),
    ESP_ELFSYM_EXPORT(xRingbufferSend),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_traverse_sequence_of),
    ESP_ELFSYM_EXPORT(sdmmc_host_dma_stop),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_stop__init),
    ESP_ELFSYM_EXPORT(esp_time_impl_get_time_since_boot),
    ESP_ELFSYM_EXPORT(_strtod_l),
    ESP_ELFSYM_EXPORT(__lock___dd_hash_mutex),
    ESP_ELFSYM_EXPORT(tlsf_add_pool),
    ESP_ELFSYM_EXPORT(esp_vfs_unlink),
    ESP_ELFSYM_EXPORT(wifi_sta_info__init),
    ESP_ELFSYM_EXPORT(rtc_clk_cpu_set_to_default_config),
    ESP_ELFSYM_EXPORT(mbedtls_md_clone),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_verify),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_init__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_identity__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__mem_monitor__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ecdsa_verify_restartable),
    ESP_ELFSYM_EXPORT(heap_caps_add_region_with_caps),
    ESP_ELFSYM_EXPORT(__sflush_r),
    ESP_ELFSYM_EXPORT(_fseek_r),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_ap_info__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_bandwidth__descriptor),
    ESP_ELFSYM_EXPORT(nvs_flash_erase_partition),
    ESP_ELFSYM_EXPORT(memp_malloc),
    ESP_ELFSYM_EXPORT(ip4_output_if),
    ESP_ELFSYM_EXPORT(sdmmc_io_write_blocks),
    ESP_ELFSYM_EXPORT(__retarget_lock_release_recursive),
    ESP_ELFSYM_EXPORT(esp_intr_enable_source),
    ESP_ELFSYM_EXPORT(__fp_lock_all),
    ESP_ELFSYM_EXPORT(zcalloc),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_storage__descriptor),
    ESP_ELFSYM_EXPORT(ip4_input),
    ESP_ELFSYM_EXPORT(bmi2_write_config_file),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsaes_pkcs1_v15_encrypt),
    ESP_ELFSYM_EXPORT(ip6_options_add_hbh_ra),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_use_default_cert_bundle__descriptor),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_disconnect),
    ESP_ELFSYM_EXPORT(__srget),
    ESP_ELFSYM_EXPORT(http_header_set),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_addr_map),
    ESP_ELFSYM_EXPORT(memp_free),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_scan_get_ap_records),
    ESP_ELFSYM_EXPORT(memp_TCP_SEG),
    ESP_ELFSYM_EXPORT(esp_netif_get_handle_from_ifkey),
    ESP_ELFSYM_EXPORT(__wrap_closedir),
    ESP_ELFSYM_EXPORT(bmi2_set_adv_power_save),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_reset_out_pointers),
    ESP_ELFSYM_EXPORT(acd_arp_reply),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_twt_config__descriptor),
    ESP_ELFSYM_EXPORT(rpc_wifi_connect),
    ESP_ELFSYM_EXPORT(lwip_recv),
    ESP_ELFSYM_EXPORT(_strtol_r),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_username__init),
    ESP_ELFSYM_EXPORT(s_keys),
    ESP_ELFSYM_EXPORT(memp_MLD6_GROUP),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_enable_intr),
    ESP_ELFSYM_EXPORT(es8156_initialize),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_write),
    ESP_ELFSYM_EXPORT(_mbtowc_r),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_read_record),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_init__init),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE),
    ESP_ELFSYM_EXPORT(tcpip_try_callback),
    ESP_ELFSYM_EXPORT(panic_abort),
    ESP_ELFSYM_EXPORT(esp_partition_get_main_flash_sector_size),
    ESP_ELFSYM_EXPORT(tcp_slowtmr),
    ESP_ELFSYM_EXPORT(http_header_init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_config__init),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_suspend__descriptor),
    ESP_ELFSYM_EXPORT(efuse_hal_get_minor_chip_version),
    ESP_ELFSYM_EXPORT(hosted_sdio_init),
    ESP_ELFSYM_EXPORT(multi_heap_malloc),
    ESP_ELFSYM_EXPORT(esp_tls_internal_event_tracker_capture),
    ESP_ELFSYM_EXPORT(gpio_hold_en),
    ESP_ELFSYM_EXPORT(ethip6_output),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_get_keyboard_keys),
    ESP_ELFSYM_EXPORT(rtc_clk_mpll_enable),
    ESP_ELFSYM_EXPORT(_vasprintf_r),
    ESP_ELFSYM_EXPORT(_tr_align),
    ESP_ELFSYM_EXPORT(ets_isr_unmask),
    ESP_ELFSYM_EXPORT(rpc__resp__set_mode__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_hmac_drbg_update),
    ESP_ELFSYM_EXPORT(console_tcflush),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_protocol__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_get_ap_record__init),
    ESP_ELFSYM_EXPORT(rpc__req__set_mode__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_send_probe_req__init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_sub_mpi),
    ESP_ELFSYM_EXPORT(esp_cpu_reset),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_get_intr_status_reg),
    ESP_ELFSYM_EXPORT(gpio_hal_iomux_out),
    ESP_ELFSYM_EXPORT(wifi_ap_config__init),
    ESP_ELFSYM_EXPORT(sys_arch_unprotect),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_go_idle_state),
    ESP_ELFSYM_EXPORT(udp_send),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage7findKeyEhPKcPNS_8ItemTypeE),
    ESP_ELFSYM_EXPORT(vTaskSuspendAll),
    ESP_ELFSYM_EXPORT(esp_elf_relocate),
    ESP_ELFSYM_EXPORT(esp_register_freertos_tick_hook),
    ESP_ELFSYM_EXPORT(sys_mbox_post),
    ESP_ELFSYM_EXPORT(xPortCheckValidTCBMem),
    ESP_ELFSYM_EXPORT(rgb_display_get_vga_palette_entry),
    ESP_ELFSYM_EXPORT(rpc_platform_deinit),
    ESP_ELFSYM_EXPORT(nd6_cleanup_netif),
    ESP_ELFSYM_EXPORT(sdmmc_host_get_real_freq),
    ESP_ELFSYM_EXPORT(spi_flash_chip_winbond_get_caps),
    ESP_ELFSYM_EXPORT(gpio_intr_disable),
    ESP_ELFSYM_EXPORT(sdmmc_host_set_input_delay),
    ESP_ELFSYM_EXPORT(sdmmc_allocate_aligned_buf),
    ESP_ELFSYM_EXPORT(regdma_link_stats),
    ESP_ELFSYM_EXPORT(tcp_tw_pcbs),
    ESP_ELFSYM_EXPORT(_lock_close_recursive),
    ESP_ELFSYM_EXPORT(_vsnprintf_r),
    ESP_ELFSYM_EXPORT(esp_mpi_enable_hardware_hw_op),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_sig_from_pk),
    ESP_ELFSYM_EXPORT(esp_netif_start),
    ESP_ELFSYM_EXPORT(_realloc_r),
    ESP_ELFSYM_EXPORT(esp_task_wdt_impl_timer_restart),
    ESP_ELFSYM_EXPORT(vTaskSetThreadLocalStoragePointerAndDelCallback),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_suspend_cmd_conf),
    ESP_ELFSYM_EXPORT(esp_wifi_create_if_driver),
    ESP_ELFSYM_EXPORT(esp_wifi_register_if_rxcb),
    ESP_ELFSYM_EXPORT(vTaskDelayUntil),
    ESP_ELFSYM_EXPORT(uxTopUsedPriority),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_channel__init),
    ESP_ELFSYM_EXPORT(acd_netif_ip_addr_changed),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_phy_write_register),
    ESP_ELFSYM_EXPORT(esp_libc_include_syscalls_impl),
    ESP_ELFSYM_EXPORT(rgb_gfx_blit),
    ESP_ELFSYM_EXPORT(st7701_initialize),
    ESP_ELFSYM_EXPORT(tcp_seg_copy),
    ESP_ELFSYM_EXPORT(mbedtls_md_starts),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition8get_sizeEv),
    ESP_ELFSYM_EXPORT(netif_ip6_addr_set),
    ESP_ELFSYM_EXPORT(esp_int_wdt_cpu_init),
    ESP_ELFSYM_EXPORT(_lock_acquire_recursive),
    ESP_ELFSYM_EXPORT(rpc__resp__supp_dpp_deinit__init),
    ESP_ELFSYM_EXPORT(__strtok_r),
    ESP_ELFSYM_EXPORT(httpd_req_new),
    ESP_ELFSYM_EXPORT(spi_flash_encryption_hal_enable),
    ESP_ELFSYM_EXPORT(dw_gdma_hal_deinit),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_pkcs1_decrypt),
    ESP_ELFSYM_EXPORT(console_write),
    ESP_ELFSYM_EXPORT(is_transport_tx_ready),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_key_exchange_md_tls1_2),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_scan_params__descriptor),
    ESP_ELFSYM_EXPORT(cmd_httpd),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_ca_chain),
    ESP_ELFSYM_EXPORT(tlsf_create_with_pool),
    ESP_ELFSYM_EXPORT(bmi270_feat_in),
    ESP_ELFSYM_EXPORT(esp_netif_is_netif_up),
    ESP_ELFSYM_EXPORT(dhcp_start),
    ESP_ELFSYM_EXPORT(argtable3_xmalloc),
    ESP_ELFSYM_EXPORT(__smakebuf_r),
    ESP_ELFSYM_EXPORT(pmu_hal_hp_set_sleep_active_backup_enable),
    ESP_ELFSYM_EXPORT(esp_netif_get_default_netif),
    ESP_ELFSYM_EXPORT(http_message_needs_eof),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_pend_fatal_alert),
    ESP_ELFSYM_EXPORT(esp_flash_write_encrypted),
    ESP_ELFSYM_EXPORT(_g_esp_netif_inherent_sta_config),
    ESP_ELFSYM_EXPORT(mem_calloc),
    ESP_ELFSYM_EXPORT(esp_log_impl_unlock),
    ESP_ELFSYM_EXPORT(rpc__event__sta_scan_done__init),
    ESP_ELFSYM_EXPORT(_putc_r),
    ESP_ELFSYM_EXPORT(__stdio_exit_handler),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_device_config),
    ESP_ELFSYM_EXPORT(rpc_send_req),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_derive_keys),
    ESP_ELFSYM_EXPORT(gdma_stop),
    ESP_ELFSYM_EXPORT(udp_init),
    ESP_ELFSYM_EXPORT(g_mmu_mem_regions),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage4initEmm),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_disconnect_peri),
    ESP_ELFSYM_EXPORT(sdmmc_hal_init),
    ESP_ELFSYM_EXPORT(sdmmc_io_reset),
    ESP_ELFSYM_EXPORT(memp_ARP_QUEUE),
    ESP_ELFSYM_EXPORT(sys_arch_mbox_tryfetch),
    ESP_ELFSYM_EXPORT(lfs_file_write),
    ESP_ELFSYM_EXPORT(regdma_find_prev_module_link_tail),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_set_pull_mode__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ctr_drbg_random_with_add),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_check_curve),
    ESP_ELFSYM_EXPORT(reachable_time),
    ESP_ELFSYM_EXPORT(xt_unhandled_exception),
    ESP_ELFSYM_EXPORT(netconn_bind),
    ESP_ELFSYM_EXPORT(rpc__resp__get_coprocessor_fw_version__descriptor),
    ESP_ELFSYM_EXPORT(tcp_write),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_get_io_mode),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_check_privkey),
    ESP_ELFSYM_EXPORT(raw_sendto),
    ESP_ELFSYM_EXPORT(lcd_hal_init),
    ESP_ELFSYM_EXPORT(tcp_listen_pcbs),
    ESP_ELFSYM_EXPORT(esp_vfs_include_nullfs_register),
    ESP_ELFSYM_EXPORT(wifi_init_config__init),
    ESP_ELFSYM_EXPORT(netif_set_up),
    ESP_ELFSYM_EXPORT(strcasestr),
    ESP_ELFSYM_EXPORT(esp_vfs_null_register),
    ESP_ELFSYM_EXPORT(ecp_mul_restartable_internal_soft),
    ESP_ELFSYM_EXPORT(udp_sendto_if_src),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_band__init),
    ESP_ELFSYM_EXPORT(cfree),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_band__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_ttls_phase2_method__descriptor),
    ESP_ELFSYM_EXPORT(_strtod_r),
    ESP_ELFSYM_EXPORT(esp_aes_free),
    ESP_ELFSYM_EXPORT(sys_mbox_trypost),
    ESP_ELFSYM_EXPORT(mbedtls_sha256_starts),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_tls12_get_preferred_hash_for_sig_alg),
    ESP_ELFSYM_EXPORT(regdma_link_new_branch_continuous),
    ESP_ELFSYM_EXPORT(pthread_include_pthread_local_storage_impl),
    ESP_ELFSYM_EXPORT(tcp_next_iss),
    ESP_ELFSYM_EXPORT(arg_dstr_cat),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_username__init),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_set_direction__descriptor),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_read_reg),
    ESP_ELFSYM_EXPORT(ip_chksum_pseudo),
    ESP_ELFSYM_EXPORT(esp_log_writev),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition11erase_rangeEjj),
    ESP_ELFSYM_EXPORT(sdmmc_io_print_cis_info),
    ESP_ELFSYM_EXPORT(mbedtls_md_hmac_finish),
    ESP_ELFSYM_EXPORT(vPortClearInterruptMaskFromISR),
    ESP_ELFSYM_EXPORT(hosted_thread_create),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_ciphersuite_sig_alg),
    ESP_ELFSYM_EXPORT(igmp_stop),
    ESP_ELFSYM_EXPORT(sqrt),
    ESP_ELFSYM_EXPORT(breezybox_exec),
    ESP_ELFSYM_EXPORT(xQueueTakeMutexRecursive),
    ESP_ELFSYM_EXPORT(vTaskSetTimeOutState),
    ESP_ELFSYM_EXPORT(tlsf_walk_pool),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_transform_init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_inv_mod),
    ESP_ELFSYM_EXPORT(bsp_input_hooks_init),
    ESP_ELFSYM_EXPORT(sdmmc_host_is_slot_set_to_uhs1),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_encrypt_buf),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage9writeItemEhNS_8ItemTypeEPKcPKvj),
    ESP_ELFSYM_EXPORT(bootloader_execute_flash_command),
    ESP_ELFSYM_EXPORT(sem_to_slave_queue),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_dpi_set_vertical_timing),
    ESP_ELFSYM_EXPORT(rom_flash_chip_dummy),
    ESP_ELFSYM_EXPORT(pcTaskGetName),
    ESP_ELFSYM_EXPORT(_ZNSt9exceptionD1Ev),
    ESP_ELFSYM_EXPORT(xQueueReceiveFromISR),
    ESP_ELFSYM_EXPORT(lseek),
    ESP_ELFSYM_EXPORT(udp_sendto_if),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple10erase_itemEPKc),
    ESP_ELFSYM_EXPORT(gpio_uninstall_isr_service),
    ESP_ELFSYM_EXPORT(mld6_joingroup_netif),
    ESP_ELFSYM_EXPORT(__fixdfdi),
    ESP_ELFSYM_EXPORT(httpd_uri),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_clear_fast_connect__init),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_disable_time_check__descriptor),
    ESP_ELFSYM_EXPORT(_times_r),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_erase_sector),
    ESP_ELFSYM_EXPORT(hosted_hold_gpio),
    ESP_ELFSYM_EXPORT(sys_mbox_free),
    ESP_ELFSYM_EXPORT(esp_sha_set_mode),
    ESP_ELFSYM_EXPORT(rgb_display_wait_vsync),
    ESP_ELFSYM_EXPORT(fsync),
    ESP_ELFSYM_EXPORT(acd_network_changed_link_down),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_ca_cert__descriptor),
    ESP_ELFSYM_EXPORT(tcp_backlog_delayed),
    ESP_ELFSYM_EXPORT(strtof),
    ESP_ELFSYM_EXPORT(esp_deep_sleep_register_hook),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_protocols__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_set_target_wake_time_offset__init),
    ESP_ELFSYM_EXPORT(cmd_cd),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_deduce_primes),
    ESP_ELFSYM_EXPORT(rpc__req__get_coprocessor_fw_version__init),
    ESP_ELFSYM_EXPORT(memp_PBUF),
    ESP_ELFSYM_EXPORT(inflateReset),
    ESP_ELFSYM_EXPORT(tlsf_memalign_offs),
    ESP_ELFSYM_EXPORT(hmac_hal_start),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsaes_pkcs1_v15_decrypt),
    ESP_ELFSYM_EXPORT(_ctype_),
    ESP_ELFSYM_EXPORT(memspi_host_erase_sector),
    ESP_ELFSYM_EXPORT(mbedtls_ct_zeroize_if),
    ESP_ELFSYM_EXPORT(lwip_init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_storage__init),
    ESP_ELFSYM_EXPORT(rpc_feature_option__descriptor),
    ESP_ELFSYM_EXPORT(multi_heap_register),
    ESP_ELFSYM_EXPORT(__retarget_lock_init),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_set_level__descriptor),
    ESP_ELFSYM_EXPORT(esp_ipc_func_arg),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page14writeEntryDataEPKhj),
    ESP_ELFSYM_EXPORT(esp_event_post_to),
    ESP_ELFSYM_EXPORT(spi_flash_hal_setup_auto_suspend_mode),
    ESP_ELFSYM_EXPORT(rpc__resp__get_ps__init),
    ESP_ELFSYM_EXPORT(getopt),
    ESP_ELFSYM_EXPORT(strtoul),
    ESP_ELFSYM_EXPORT(esp_lcd_new_rgb_panel),
    ESP_ELFSYM_EXPORT(esp_log_cache_get_level),
    ESP_ELFSYM_EXPORT(memp_pools),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_write_sig_alg_ext),
    ESP_ELFSYM_EXPORT(console_read),
    ESP_ELFSYM_EXPORT(mpi_hal_set_search_position),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_scan_start__init),
    ESP_ELFSYM_EXPORT(spi_flash_hal_init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_suspend__descriptor),
    ESP_ELFSYM_EXPORT(esp_netif_set_old_ip_info),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_get_aid__init),
    ESP_ELFSYM_EXPORT(rpc_wifi_start),
    ESP_ELFSYM_EXPORT(_ZN3nvs7StorageD1Ev),
    ESP_ELFSYM_EXPORT(memspi_host_read_status_hs),
    ESP_ELFSYM_EXPORT(sdmmc_host_get_slot_width),
    ESP_ELFSYM_EXPORT(cJSON_IsArray),
    ESP_ELFSYM_EXPORT(pbuf_free_header),
    ESP_ELFSYM_EXPORT(iswspace),
    ESP_ELFSYM_EXPORT(sdmmc_host_enable_clk_cmd11),
    ESP_ELFSYM_EXPORT(esp_hosted_woke_from_power_save),
    ESP_ELFSYM_EXPORT(transport_pserial_send),
    ESP_ELFSYM_EXPORT(rpc_wifi_set_mode),
    ESP_ELFSYM_EXPORT(rtc_clk_apll_coeff_set),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_bandwidth__init),
    ESP_ELFSYM_EXPORT(esp_transport_poll_read),
    ESP_ELFSYM_EXPORT(parse_tlv),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Item14calculateCrc32EPKhj),
    ESP_ELFSYM_EXPORT(heap_caps_check_integrity_all),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_import),
    ESP_ELFSYM_EXPORT(wifi_scan_default_params__descriptor),
    ESP_ELFSYM_EXPORT(aes_hal_gcm_calc_hash),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_init),
    ESP_ELFSYM_EXPORT(open),
    ESP_ELFSYM_EXPORT(esp_crypto_ecc_enable_periph_clk),
    ESP_ELFSYM_EXPORT(rgb_gfx_rect),
    ESP_ELFSYM_EXPORT(spi_flash_chip_winbond_suspend_cmd_conf),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_read),
    ESP_ELFSYM_EXPORT(rpc_wifi_scan_start),
    ESP_ELFSYM_EXPORT(netif_ip6_addr_set_parts),
    ESP_ELFSYM_EXPORT(gdma_hal_clear_intr),
    ESP_ELFSYM_EXPORT(serial_drv_read),
    ESP_ELFSYM_EXPORT(esp_ds_init_data_ctx),
    ESP_ELFSYM_EXPORT(esp_flash_get_physical_size),
    ESP_ELFSYM_EXPORT(esp_timer_early_init),
    ESP_ELFSYM_EXPORT(spi_flash_init_lock),
    ESP_ELFSYM_EXPORT(sprintf),
    ESP_ELFSYM_EXPORT(pxPortUpdateCoprocOwner),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_password__init),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_get_level__descriptor),
    ESP_ELFSYM_EXPORT(spi_flash_set_erasing_flag),
    ESP_ELFSYM_EXPORT(hosted_event_post),
    ESP_ELFSYM_EXPORT(__localeconv_l),
    ESP_ELFSYM_EXPORT(ip6_input),
    ESP_ELFSYM_EXPORT(sdmmc_io_read_byte),
    ESP_ELFSYM_EXPORT(dhcp_supplied_address),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_disconnect__descriptor),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_set_direction__init),
    ESP_ELFSYM_EXPORT(linenoiseClearScreen),
    ESP_ELFSYM_EXPORT(iswspace_l),
    ESP_ELFSYM_EXPORT(ds_hal_configure_iv),
    ESP_ELFSYM_EXPORT(wifi_event_sta_disconnected__init),
    ESP_ELFSYM_EXPORT(esp_mspi_get_io),
    ESP_ELFSYM_EXPORT(__lock___malloc_recursive_mutex),
    ESP_ELFSYM_EXPORT(z_errmsg),
    ESP_ELFSYM_EXPORT(memp_UDP_PCB),
    ESP_ELFSYM_EXPORT(http_parser_url_init),
    ESP_ELFSYM_EXPORT(mbedtls_sha1_starts),
    ESP_ELFSYM_EXPORT(sdmmc_host_start_command),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_bandwidth__init),
    ESP_ELFSYM_EXPORT(tcp_keepalive),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_read_le),
    ESP_ELFSYM_EXPORT(__kernel_rem_pio2),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handle_message_type),
    ESP_ELFSYM_EXPORT(pmu_lp_system_analog_param_default),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_decrypt_buf),
    ESP_ELFSYM_EXPORT(esp_mbedtls_mem_calloc),
    ESP_ELFSYM_EXPORT(sleep),
    ESP_ELFSYM_EXPORT(xPortSysTickHandler),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_teardown__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition4readEjPvj),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_private),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_inactive_time__descriptor),
    ESP_ELFSYM_EXPORT(sys_sem_free),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_curve_info_from_tls_id),
    ESP_ELFSYM_EXPORT(mspi_timing_config_set_flash_clock),
    ESP_ELFSYM_EXPORT(gpio_hal_intr_enable_on_core),
    ESP_ELFSYM_EXPORT(pxPortGetCoprocArea),
    ESP_ELFSYM_EXPORT(esp_intr_noniram_enable),
    ESP_ELFSYM_EXPORT(gpio_set_direction),
    ESP_ELFSYM_EXPORT(sys_arch_protect),
    ESP_ELFSYM_EXPORT(_dtoa_r),
    ESP_ELFSYM_EXPORT(esp_libc_time_init),
    ESP_ELFSYM_EXPORT(__sseek),
    ESP_ELFSYM_EXPORT(esp_tls_conn_write),
    ESP_ELFSYM_EXPORT(dns_tmr),
    ESP_ELFSYM_EXPORT(rpc__req__app_get_desc__init),
    ESP_ELFSYM_EXPORT(__any_on),
    ESP_ELFSYM_EXPORT(fseeko),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_config__descriptor),
    ESP_ELFSYM_EXPORT(bsp_internal_coprocessor_keyboard_callback),
    ESP_ELFSYM_EXPORT(xTaskGetSchedulerState),
    ESP_ELFSYM_EXPORT(cmd_cp),
    ESP_ELFSYM_EXPORT(spi_flash_cache2phys),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_get_interrupt),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_finish_handshake_msg),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_set_pull_mode__init),
    ESP_ELFSYM_EXPORT(sdmmc_fix_host_flags),
    ESP_ELFSYM_EXPORT(__state_table),
    ESP_ELFSYM_EXPORT(esp_int_wdt_init),
    ESP_ELFSYM_EXPORT(esp_sha_dma),
    ESP_ELFSYM_EXPORT(hosted_lock_mempool),
    ESP_ELFSYM_EXPORT(_stat_r),
    ESP_ELFSYM_EXPORT(wlanif_init),
    ESP_ELFSYM_EXPORT(esp_timer_delete),
    ESP_ELFSYM_EXPORT(pbuf_alloc_reference),
    ESP_ELFSYM_EXPORT(esp_elf_map_sym),
    ESP_ELFSYM_EXPORT(dma2d_periph_signals),
    ESP_ELFSYM_EXPORT(rpc__req__otaactivate__descriptor),
    ESP_ELFSYM_EXPORT(_ZNK3nvs4Page9readEntryEjRNS_4ItemE),
    ESP_ELFSYM_EXPORT(__retarget_lock_close_recursive),
    ESP_ELFSYM_EXPORT(breezybox_export_symbols),
    ESP_ELFSYM_EXPORT(deflateResetKeep),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_set_level__init),
    ESP_ELFSYM_EXPORT(rpc__req__eap_use_default_cert_bundle__descriptor),
    ESP_ELFSYM_EXPORT(__wrap_rename),
    ESP_ELFSYM_EXPORT(rpc__req__feature_control__init),
    ESP_ELFSYM_EXPORT(regdma_link_get_config_mode),
    ESP_ELFSYM_EXPORT(roundf),
    ESP_ELFSYM_EXPORT(gdma_axi_hal_clear_crc),
    ESP_ELFSYM_EXPORT(rom_spiflash_api_funcs),
    ESP_ELFSYM_EXPORT(__wrap_open),
    ESP_ELFSYM_EXPORT(esp_err_to_name),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_password__descriptor),
    ESP_ELFSYM_EXPORT(_ZN3nvs4PageC2Ev),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_max_tx_power__init),
    ESP_ELFSYM_EXPORT(esp_wifi_is_if_ready_when_started),
    ESP_ELFSYM_EXPORT(dma2d_tx_channel_reserved_mask),
    ESP_ELFSYM_EXPORT(tcp_update_rcv_ann_wnd),
    ESP_ELFSYM_EXPORT(tcpip_input),
    ESP_ELFSYM_EXPORT(esp_http_client_write),
    ESP_ELFSYM_EXPORT(bmi2_error_codes_print_result),
    ESP_ELFSYM_EXPORT(select),
    ESP_ELFSYM_EXPORT(__gtdf2),
    ESP_ELFSYM_EXPORT(inflateReset2),
    ESP_ELFSYM_EXPORT(soc_memory_region_count),
    ESP_ELFSYM_EXPORT(mbedtls_hmac_drbg_random),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_len),
    ESP_ELFSYM_EXPORT(gdma_ahb_hal_append),
    ESP_ELFSYM_EXPORT(_impure_data),
    ESP_ELFSYM_EXPORT(sscanf),
    ESP_ELFSYM_EXPORT(esp_panic_handler_feed_wdts),
    ESP_ELFSYM_EXPORT(mbedtls_ccm_auth_decrypt),
    ESP_ELFSYM_EXPORT(lfs_dir_open),
    ESP_ELFSYM_EXPORT(mbedtls_hmac_drbg_free),
    ESP_ELFSYM_EXPORT(pbuf_header_force),
    ESP_ELFSYM_EXPORT(linenoiseEditHistoryNext),
    ESP_ELFSYM_EXPORT(strlen),
    ESP_ELFSYM_EXPORT(esp_event_handler_register_with_internal),
    ESP_ELFSYM_EXPORT(memspi_host_program_page),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager24lookup_storage_from_nameEPKc),
    ESP_ELFSYM_EXPORT(rpc__resp__set_mode__init),
    ESP_ELFSYM_EXPORT(strtod),
    ESP_ELFSYM_EXPORT(esp_ptr_dma_ext_capable),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsassa_pss_verify_ext),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_free_named_data_list_shallow),
    ESP_ELFSYM_EXPORT(panic_soc_fill_info),
    ESP_ELFSYM_EXPORT(esp_timer_init),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_send_op_cond),
    ESP_ELFSYM_EXPORT(breezy_net_up),
    ESP_ELFSYM_EXPORT(mbedtls_pk_ecc_set_key),
    ESP_ELFSYM_EXPORT(cmd_head),
    ESP_ELFSYM_EXPORT(cJSON_IsString),
    ESP_ELFSYM_EXPORT(mbedtls_platform_zeroize),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_clear_new_password__descriptor),
    ESP_ELFSYM_EXPORT(__popcountsi2),
    ESP_ELFSYM_EXPORT(httpd_sess_delete),
    ESP_ELFSYM_EXPORT(tcp_split_unsent_seg),
    ESP_ELFSYM_EXPORT(http_parser_parse_url),
    ESP_ELFSYM_EXPORT(__tz_unlock),
    ESP_ELFSYM_EXPORT(bsp_device_initialize),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_free),
    ESP_ELFSYM_EXPORT(hosted_init_hook),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_connect__descriptor),
    ESP_ELFSYM_EXPORT(__seofread),
    ESP_ELFSYM_EXPORT(strtol),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_sta_itwt_send_probe_req__descriptor),
    ESP_ELFSYM_EXPORT(heap_size_threshold__init),
    ESP_ELFSYM_EXPORT(esp_netif_get_old_ip_info),
    ESP_ELFSYM_EXPORT(dhcps_set_new_lease_cb),
    ESP_ELFSYM_EXPORT(bmi2_interface_init),
    ESP_ELFSYM_EXPORT(_dist_code),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_reset),
    ESP_ELFSYM_EXPORT(esp_log_va),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_channel__descriptor),
    ESP_ELFSYM_EXPORT(spi_flash_encryption_hal_check),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_config_set_tuning_regs),
    ESP_ELFSYM_EXPORT(strchrnul),
    ESP_ELFSYM_EXPORT(gdma_hal_reset),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_start__descriptor),
    ESP_ELFSYM_EXPORT(esp_vfs_read),
    ESP_ELFSYM_EXPORT(mbedtls_base64_encode),
    ESP_ELFSYM_EXPORT(i2c_hal_master_init),
    ESP_ELFSYM_EXPORT(esp_http_client_set_redirection),
    ESP_ELFSYM_EXPORT(linenoiseEditMoveEnd),
    ESP_ELFSYM_EXPORT(rtc_gpio_deinit),
    ESP_ELFSYM_EXPORT(esp_partition_erase_range),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_read_binary),
    ESP_ELFSYM_EXPORT(vTaskPlaceOnEventList),
    ESP_ELFSYM_EXPORT(wifi_tx_throttling),
    ESP_ELFSYM_EXPORT(_ZNSt9type_infoD2Ev),
    ESP_ELFSYM_EXPORT(pau_hal_lp_sys_initialize),
    ESP_ELFSYM_EXPORT(hci_drv_init),
    ESP_ELFSYM_EXPORT(bsp_internal_coprocessor_input_callback),
    ESP_ELFSYM_EXPORT(strncat),
    ESP_ELFSYM_EXPORT(wifi_scan_default_params__init),
    ESP_ELFSYM_EXPORT(hosted_realloc),
    ESP_ELFSYM_EXPORT(memp_TCPIP_MSG_API),
    ESP_ELFSYM_EXPORT(heap_caps_get_total_size),
    ESP_ELFSYM_EXPORT(httpd_req_delete),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_host_gen_read_dcs_command),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_read_bytes),
    ESP_ELFSYM_EXPORT(memp_RAW_PCB),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_username__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__custom_rpc__init),
    ESP_ELFSYM_EXPORT(esp_md5_finish),
    ESP_ELFSYM_EXPORT(esp_netif_attach_wifi_station),
    ESP_ELFSYM_EXPORT(vTaskSwitchContext),
    ESP_ELFSYM_EXPORT(xTaskGetCurrentTaskHandleForCore),
    ESP_ELFSYM_EXPORT(itoa),
    ESP_ELFSYM_EXPORT(tcp_alloc),
    ESP_ELFSYM_EXPORT(mbedtls_x509_crt_profile_suiteb),
    ESP_ELFSYM_EXPORT(rpc_set_wifi_mode),
    ESP_ELFSYM_EXPORT(tcp_sent),
    ESP_ELFSYM_EXPORT(mbedtls_ct_memcmp),
    ESP_ELFSYM_EXPORT(__ulp),
    ESP_ELFSYM_EXPORT(mbedtls_hmac_drbg_seed_buf),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_ap_get_sta_aid__init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_mul_int),
    ESP_ELFSYM_EXPORT(_fputc_r),
    ESP_ELFSYM_EXPORT(_read_r),
    ESP_ELFSYM_EXPORT(mbedtls_pk_parse_key),
    ESP_ELFSYM_EXPORT(spi_flash_init_chip_state),
    ESP_ELFSYM_EXPORT(lp_gpio_connect_in_signal),
    ESP_ELFSYM_EXPORT(__srefill_r),
    ESP_ELFSYM_EXPORT(mbedtls_calloc),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_clear_fast_connect__descriptor),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_erase_chip),
    ESP_ELFSYM_EXPORT(esp_crypto_sha_enable_periph_clk),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_protocol__init),
    ESP_ELFSYM_EXPORT(spi_flash_cache_enabled),
    ESP_ELFSYM_EXPORT(rpc_slaveif_wifi_connect),
    ESP_ELFSYM_EXPORT(_ZNK3nvs4Page18getVarDataTailroomEv),
    ESP_ELFSYM_EXPORT(esp_http_client_cleanup),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_config__descriptor),
    ESP_ELFSYM_EXPORT(esp_libc_include_assert_impl),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_channel__descriptor),
    ESP_ELFSYM_EXPORT(dw_gdma_del_channel),
    ESP_ELFSYM_EXPORT(esp_aes_process_dma_gcm),
    ESP_ELFSYM_EXPORT(__ubsan_include),
    ESP_ELFSYM_EXPORT(dhcp_release_and_stop),
    ESP_ELFSYM_EXPORT(dhcps_new),
    ESP_ELFSYM_EXPORT(hal_utils_calc_clk_div_frac_accurate),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv120__si_class_type_infoD2Ev),
    ESP_ELFSYM_EXPORT(serial_ll_init),
    ESP_ELFSYM_EXPORT(netconn_tcp_recvd),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Lock10mSemaphoreE),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_deauth_sta__init),
    ESP_ELFSYM_EXPORT(rpc__req__otaend__init),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_check_pubkey),
    ESP_ELFSYM_EXPORT(xTaskPriorityDisinherit),
    ESP_ELFSYM_EXPORT(rpc__resp__iface_mac_addr_set_get__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_protocol__descriptor),
    ESP_ELFSYM_EXPORT(rpc__event__supp_dpp_uri_ready__descriptor),
    ESP_ELFSYM_EXPORT(dma2d_register_rx_event_callbacks),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_handshake),
    ESP_ELFSYM_EXPORT(esp_transport_set_async_connect_func),
    ESP_ELFSYM_EXPORT(hosted_sdio_deinit),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_free),
    ESP_ELFSYM_EXPORT(udp_sendto),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_sequence_of),
    ESP_ELFSYM_EXPORT(rpc__gpio_pull_mode__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_conf_alpn_protocols),
    ESP_ELFSYM_EXPORT(esp_clk_apb_freq),
    ESP_ELFSYM_EXPORT(sniprintf),
    ESP_ELFSYM_EXPORT(sys_untimeout),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_validate_params),
    ESP_ELFSYM_EXPORT(icmp_input),
    ESP_ELFSYM_EXPORT(vfiprintf),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page9eraseItemEhNS_8ItemTypeEPKchNS_9VerOffsetE),
    ESP_ELFSYM_EXPORT(esp_cpu_unstall),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_get_level__init),
    ESP_ELFSYM_EXPORT(sdmmc_init_io_bus_width),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_enterprise_disable__init),
    ESP_ELFSYM_EXPORT(hosted_free),
    ESP_ELFSYM_EXPORT(spi_flash_chip_winbond_page_program),
    ESP_ELFSYM_EXPORT(netif_add_ext_callback),
    ESP_ELFSYM_EXPORT(_fwalk_sglue),
    ESP_ELFSYM_EXPORT(timestamp_id),
    ESP_ELFSYM_EXPORT(FreeRTOS_openocd_params),
    ESP_ELFSYM_EXPORT(regdma_link_update_next),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_add_abs),
    ESP_ELFSYM_EXPORT(gdma_new_link_list),
    ESP_ELFSYM_EXPORT(usb_serial_jtag_read_ready),
    ESP_ELFSYM_EXPORT(setjmp),
    ESP_ELFSYM_EXPORT(esp_rom_regi2c_read),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_session_init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_bitlen),
    ESP_ELFSYM_EXPORT(mbedtls_pkcs5_pbkdf2_hmac_ext),
    ESP_ELFSYM_EXPORT(ip4addr_aton),
    ESP_ELFSYM_EXPORT(sdmmc_host_card_busy),
    ESP_ELFSYM_EXPORT(esp_crosscore_int_init),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_sequence_free),
    ESP_ELFSYM_EXPORT(mem_trim),
    ESP_ELFSYM_EXPORT(soc_memory_regions),
    ESP_ELFSYM_EXPORT(bsp_i2c_primary_bus_initialize),
    ESP_ELFSYM_EXPORT(rtc_clk_cpu_freq_get_config),
    ESP_ELFSYM_EXPORT(clearerr),
    ESP_ELFSYM_EXPORT(spi_flash_hal_gpspi_poll_cmd_done),
    ESP_ELFSYM_EXPORT(rpc__req__set_dhcp_dns_status__descriptor),
    ESP_ELFSYM_EXPORT(serial_drv_open),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager11open_handleEPKcS2_15nvs_open_mode_tPPNS_15NVSHandleSimpleE),
    ESP_ELFSYM_EXPORT(__ctzdi2),
    ESP_ELFSYM_EXPORT(periph_rtc_dig_clk8m_enable),
    ESP_ELFSYM_EXPORT(esp_log_linked_list_get_level),
    ESP_ELFSYM_EXPORT(transport_drv_add_channel),
    ESP_ELFSYM_EXPORT(rename),
    ESP_ELFSYM_EXPORT(_ZN3nvs19NVSPartitionManager14init_partitionEPKc),
    ESP_ELFSYM_EXPORT(sdmmc_io_write_bytes),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_protocols__init),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_md_alg_from_hash),
    ESP_ELFSYM_EXPORT(mbedtls_sha256_update),
    ESP_ELFSYM_EXPORT(_lock_try_acquire),
    ESP_ELFSYM_EXPORT(esp_get_free_heap_size),
    ESP_ELFSYM_EXPORT(i2s_periph_signal),
    ESP_ELFSYM_EXPORT(adler32_z),
    ESP_ELFSYM_EXPORT(seekdir),
    ESP_ELFSYM_EXPORT(netif_find),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_twt_config__descriptor),
    ESP_ELFSYM_EXPORT(cmd_pwd),
    ESP_ELFSYM_EXPORT(esp_littlefs_format_partition),
    ESP_ELFSYM_EXPORT(mpi_hal_write_m_prime),
    ESP_ELFSYM_EXPORT(heap_caps_realloc_default),
    ESP_ELFSYM_EXPORT(fdopen),
    ESP_ELFSYM_EXPORT(mbedtls_aria_free),
    ESP_ELFSYM_EXPORT(esp_partition_iterator_release),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_get_max_tx_power__init),
    ESP_ELFSYM_EXPORT(_ZSt9terminatev),
    ESP_ELFSYM_EXPORT(esp_wifi_remote_get_mac),
    ESP_ELFSYM_EXPORT(multi_heap_realloc),
    ESP_ELFSYM_EXPORT(ecc_hal_is_calc_finished),
    ESP_ELFSYM_EXPORT(inet_chksum),
    ESP_ELFSYM_EXPORT(rtc_clk_freq_cal),
    ESP_ELFSYM_EXPORT(cmd_cat),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition12get_readonlyEv),
    ESP_ELFSYM_EXPORT(rpc__resp__set_ps__init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_inactive_time__init),
    ESP_ELFSYM_EXPORT(xPortInIsrContext),
    ESP_ELFSYM_EXPORT(__floatunsidf),
    ESP_ELFSYM_EXPORT(tcgetattr),
    ESP_ELFSYM_EXPORT(esp_console_get_hint),
    ESP_ELFSYM_EXPORT(_reclaim_reent),
    ESP_ELFSYM_EXPORT(_tr_flush_bits),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_certificate_and_key__init),
    ESP_ELFSYM_EXPORT(mspi_timing_psram_set_best_tuning_delayline),
    ESP_ELFSYM_EXPORT(_tzset_unlocked_r),
    ESP_ELFSYM_EXPORT(arg_dstr_cstr),
    ESP_ELFSYM_EXPORT(ds_hal_finish),
    ESP_ELFSYM_EXPORT(inflate_fixed),
    ESP_ELFSYM_EXPORT(netbuf_alloc),
    ESP_ELFSYM_EXPORT(__swrite),
    ESP_ELFSYM_EXPORT(etharp_request),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_write_len),
    ESP_ELFSYM_EXPORT(esp_transport_set_default_port),
    ESP_ELFSYM_EXPORT(tanmatsu_coprocessor_initialize),
    ESP_ELFSYM_EXPORT(vTaskPlaceOnEventListRestricted),
    ESP_ELFSYM_EXPORT(vListInsertEnd),
    ESP_ELFSYM_EXPORT(esp_register_freertos_idle_hook_for_cpu),
    ESP_ELFSYM_EXPORT(dw_gdma_new_link_list),
    ESP_ELFSYM_EXPORT(tlsf_check),
    ESP_ELFSYM_EXPORT(tcflush),
    ESP_ELFSYM_EXPORT(esp_lcd_panel_init),
    ESP_ELFSYM_EXPORT(localtime_r),
    ESP_ELFSYM_EXPORT(esp_psram_extram_test),
    ESP_ELFSYM_EXPORT(aes_hal_transform_dma_start),
    ESP_ELFSYM_EXPORT(gpio_pulldown_dis),
    ESP_ELFSYM_EXPORT(udp_remove),
    ESP_ELFSYM_EXPORT(bootloader_init_mem),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage19populateBlobIndicesER14intrusive_listINS0_13BlobIndexNodeEE),
    ESP_ELFSYM_EXPORT(esp_log_vprint_func),
    ESP_ELFSYM_EXPORT(esp_crosscore_int_send_twdt_abort),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_get_ap_info__init),
    ESP_ELFSYM_EXPORT(esp_timer_impl_init),
    ESP_ELFSYM_EXPORT(strftime_l),
    ESP_ELFSYM_EXPORT(xTaskPriorityInherit),
    ESP_ELFSYM_EXPORT(httpd_sess_set_descriptors),
    ESP_ELFSYM_EXPORT(hosted_wifi_event_post),
    ESP_ELFSYM_EXPORT(rpc__event__mem_monitor__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__get_mode__init),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_input_enable__descriptor),
    ESP_ELFSYM_EXPORT(ecp_mul_restartable_internal),
    ESP_ELFSYM_EXPORT(console_tcsetattr),
    ESP_ELFSYM_EXPORT(esp_panic_handler_enable_rtc_wdt),
    ESP_ELFSYM_EXPORT(httpd_resp_send),
    ESP_ELFSYM_EXPORT(ftello),
    ESP_ELFSYM_EXPORT(spi_flash_encryption_hal_prepare),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv117__class_type_infoD1Ev),
    ESP_ELFSYM_EXPORT(__wrap___gxx_personality_v0),
    ESP_ELFSYM_EXPORT(rtos_save_pie_coproc),
    ESP_ELFSYM_EXPORT(rpc__req__eap_clear_username__descriptor),
    ESP_ELFSYM_EXPORT(rpc_feature_command__descriptor),
    ESP_ELFSYM_EXPORT(__lock___at_quick_exit_mutex),
    ESP_ELFSYM_EXPORT(memp_PBUF_POOL),
    ESP_ELFSYM_EXPORT(finite),
    ESP_ELFSYM_EXPORT(console_end_select),
    ESP_ELFSYM_EXPORT(rgb_display_set_mode),
    ESP_ELFSYM_EXPORT(_fwrite_r),
    ESP_ELFSYM_EXPORT(lfs_unmount),
    ESP_ELFSYM_EXPORT(vTaskDelete),
    ESP_ELFSYM_EXPORT(vPortAssertIfInISR),
    ESP_ELFSYM_EXPORT(esp_aes_xts_free),
    ESP_ELFSYM_EXPORT(wifi_event_sta_scan_done__descriptor),
    ESP_ELFSYM_EXPORT(i2c_master_transmit_receive),
    ESP_ELFSYM_EXPORT(ds_hal_start),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_rsaes_oaep_encrypt),
    ESP_ELFSYM_EXPORT(wifi_scan_channel_bitmap__init),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_bandwidths__init),
    ESP_ELFSYM_EXPORT(gmtime_r),
    ESP_ELFSYM_EXPORT(_fcntl_r),
    ESP_ELFSYM_EXPORT(__unorddf2),
    ESP_ELFSYM_EXPORT(httpd_sess_clear_ctx),
    ESP_ELFSYM_EXPORT(mbedtls_ct_memmove_left),
    ESP_ELFSYM_EXPORT(vterm_get_direct_buffer),
    ESP_ELFSYM_EXPORT(rpc__req__gpio_reset_pin__descriptor),
    ESP_ELFSYM_EXPORT(mbedtls_x509_get_ns_cert_type),
    ESP_ELFSYM_EXPORT(esp_ds_start_sign),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_band__init),
    ESP_ELFSYM_EXPORT(rpc__resp__eap_set_ca_cert__init),
    ESP_ELFSYM_EXPORT(regdma_link_new_write_default),
    ESP_ELFSYM_EXPORT(periph_rcc_acquire_enter),
    ESP_ELFSYM_EXPORT(heap_size_threshold__descriptor),
    ESP_ELFSYM_EXPORT(tcp_rexmit),
    ESP_ELFSYM_EXPORT(tcp_rexmit_rto),
    ESP_ELFSYM_EXPORT(lwip_netconn_is_deallocated_msg),
    ESP_ELFSYM_EXPORT(mbrtowc),
    ESP_ELFSYM_EXPORT(esp_elf_free),
    ESP_ELFSYM_EXPORT(__sf),
    ESP_ELFSYM_EXPORT(tanmatsu_lcd_init),
    ESP_ELFSYM_EXPORT(rpc__event__sta_connected__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__get_mode__descriptor),
    ESP_ELFSYM_EXPORT(cmd_mkdir),
    ESP_ELFSYM_EXPORT(httpd_default_send),
    ESP_ELFSYM_EXPORT(wifi_pmf_config__descriptor),
    ESP_ELFSYM_EXPORT(breezybox_start_stdio),
    ESP_ELFSYM_EXPORT(rpc_platform_init),
    ESP_ELFSYM_EXPORT(floor),
    ESP_ELFSYM_EXPORT(lfs_dir_rewind),
    ESP_ELFSYM_EXPORT(__tz_lock),
    ESP_ELFSYM_EXPORT(_strerror_r),
    ESP_ELFSYM_EXPORT(rpc__event__sta_disconnected__init),
    ESP_ELFSYM_EXPORT(_ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PPv),
    ESP_ELFSYM_EXPORT(__extendsfdf2),
    ESP_ELFSYM_EXPORT(lfs_stat),
    ESP_ELFSYM_EXPORT(esp_psram_extram_reserve_dma_pool),
    ESP_ELFSYM_EXPORT(pmu_hp_system_clock_param_default),
    ESP_ELFSYM_EXPORT(periph_rtc_dig_clk8m_disable),
    ESP_ELFSYM_EXPORT(__call_exitprocs),
    ESP_ELFSYM_EXPORT(http_header_set_format),
    ESP_ELFSYM_EXPORT(ip6_addr_any),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimpleD0Ev),
    ESP_ELFSYM_EXPORT(esp_vfs_lwip_sockets_register),
    ESP_ELFSYM_EXPORT(esp_log_set_default_level),
    ESP_ELFSYM_EXPORT(gdma_link_get_head_addr),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_check_timer),
    ESP_ELFSYM_EXPORT(_ZN3nvs4LockD1Ev),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_pk_alg_from_sig),
    ESP_ELFSYM_EXPORT(spi_flash_encryption_hal_disable),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartitionC1EPK15esp_partition_t),
    ESP_ELFSYM_EXPORT(esp_async_fbcpy_install),
    ESP_ELFSYM_EXPORT(dw_gdma_hal_init),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_core_cond_assign),
    ESP_ELFSYM_EXPORT(pbuf_try_get_at),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_band_mode__init),
    ESP_ELFSYM_EXPORT(periph_rcc_release_enter),
    ESP_ELFSYM_EXPORT(raw_input),
    ESP_ELFSYM_EXPORT(console_fstat),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage16cmpMultiPageBlobEhPKcPKvj),
    ESP_ELFSYM_EXPORT(_ZN3nvs4Page10initializeEv),
    ESP_ELFSYM_EXPORT(hosted_create_mutex),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_okc_support__descriptor),
    ESP_ELFSYM_EXPORT(arg_print_errors),
    ESP_ELFSYM_EXPORT(esp_netif_set_mac_api),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_mul),
    ESP_ELFSYM_EXPORT(esp_ptr_byte_accessible),
    ESP_ELFSYM_EXPORT(gdma_register_rx_event_callbacks),
    ESP_ELFSYM_EXPORT(lwip_netconn_is_err_msg),
    ESP_ELFSYM_EXPORT(rtc_clk_xtal_freq_get),
    ESP_ELFSYM_EXPORT(s_lcd_platform),
    ESP_ELFSYM_EXPORT(gdma_hal_set_priority),
    ESP_ELFSYM_EXPORT(rpc__req__eap_set_certificate_and_key__descriptor),
    ESP_ELFSYM_EXPORT(raw_remove),
    ESP_ELFSYM_EXPORT(mbedtls_ssl_get_ciphersuite_sig_pk_alg),
    ESP_ELFSYM_EXPORT(wifi_init_config__descriptor),
    ESP_ELFSYM_EXPORT(memspi_host_erase_block),
    ESP_ELFSYM_EXPORT(wifi_scan_threshold__init),
    ESP_ELFSYM_EXPORT(mbedtls_ecdh_read_params),
    ESP_ELFSYM_EXPORT(bsp_input_hooks_process),
    ESP_ELFSYM_EXPORT(color_hal_pixel_format_get_bit_depth),
    ESP_ELFSYM_EXPORT(optarg),
    ESP_ELFSYM_EXPORT(esp_random),
    ESP_ELFSYM_EXPORT(esp_efuse_utility_check_errors),
    ESP_ELFSYM_EXPORT(esp_flash_read_chip_id),
    ESP_ELFSYM_EXPORT(es8156_write_page_select),
    ESP_ELFSYM_EXPORT(__clzsi2),
    ESP_ELFSYM_EXPORT(spi_flash_hal_disable_auto_resume_mode),
    ESP_ELFSYM_EXPORT(etharp_tmr),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_tls_write_group),
    ESP_ELFSYM_EXPORT(esp_netif_up),
    ESP_ELFSYM_EXPORT(esp_flash_chip_driver_initialized),
    ESP_ELFSYM_EXPORT(rpc_register_event_callbacks),
    ESP_ELFSYM_EXPORT(esp_transport_list_init),
    ESP_ELFSYM_EXPORT(memp_TCPIP_MSG_INPKT),
    ESP_ELFSYM_EXPORT(rpc__resp__otaactivate__init),
    ESP_ELFSYM_EXPORT(esp_clk_tree_xtal32k_get_freq_hz),
    ESP_ELFSYM_EXPORT(gdma_disconnect),
    ESP_ELFSYM_EXPORT(mbedtls_eckeydh_info),
    ESP_ELFSYM_EXPORT(__sccl),
    ESP_ELFSYM_EXPORT(mbedtls_mpi_mod_int),
    ESP_ELFSYM_EXPORT(malloc),
    ESP_ELFSYM_EXPORT(nd6_adjust_mld_membership),
    ESP_ELFSYM_EXPORT(cache_hal_is_cache_enabled),
    ESP_ELFSYM_EXPORT(rpc__resp__gpio_config__init),
    ESP_ELFSYM_EXPORT(periph_rtc_mpll_freq_set),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_set_bandwidth__init),
    ESP_ELFSYM_EXPORT(mld6_report_groups),
    ESP_ELFSYM_EXPORT(lwip_hook_tcp_isn),
    ESP_ELFSYM_EXPORT(mbedtls_pk_ecc_set_group),
    ESP_ELFSYM_EXPORT(mbedtls_ecp_curve_list),
    ESP_ELFSYM_EXPORT(mld6_joingroup),
    ESP_ELFSYM_EXPORT(mbedtls_md_init),
    ESP_ELFSYM_EXPORT(task_wdt_timeout_abort),
    ESP_ELFSYM_EXPORT(rpc__resp__get_mode__init),
    ESP_ELFSYM_EXPORT(strcmp),
    ESP_ELFSYM_EXPORT(xQueueGiveMutexRecursive),
    ESP_ELFSYM_EXPORT(esp_aes_init),
    ESP_ELFSYM_EXPORT(spi_flash_chip_generic_write_encrypted),
    ESP_ELFSYM_EXPORT(es8156_read_page_select),
    ESP_ELFSYM_EXPORT(esp_lcd_new_panel_io_dbi),
    ESP_ELFSYM_EXPORT(spi_flash_check_and_flush_cache),
    ESP_ELFSYM_EXPORT(ftell),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_sta_itwt_set_target_wake_time_offset__init),
    ESP_ELFSYM_EXPORT(sdmmc_init_sd_ssr),
    ESP_ELFSYM_EXPORT(spi_flash_disable_cache),
    ESP_ELFSYM_EXPORT(bsp_i2c_primary_bus_get_semaphore),
    ESP_ELFSYM_EXPORT(intr_handler_get),
    ESP_ELFSYM_EXPORT(esp_app_desc__init),
    ESP_ELFSYM_EXPORT(mipi_dsi_hal_configure_phy_pll),
    ESP_ELFSYM_EXPORT(app_elf_sha256_str),
    ESP_ELFSYM_EXPORT(cmd_wc),
    ESP_ELFSYM_EXPORT(_ZN3nvs12NVSPartition11get_addressEv),
    ESP_ELFSYM_EXPORT(sha_hal_hash_dma),
    ESP_ELFSYM_EXPORT(settimeofday),
    ESP_ELFSYM_EXPORT(esp_backtrace_print),
    ESP_ELFSYM_EXPORT(_ZN10__cxxabiv120__si_class_type_infoD0Ev),
    ESP_ELFSYM_EXPORT(http_utils_assign_string),
    ESP_ELFSYM_EXPORT(esp_ldo_acquire_channel),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_country_code__init),
    ESP_ELFSYM_EXPORT(_ZN3nvs7Storage8readItemEhNS_8ItemTypeEPKcPvj),
    ESP_ELFSYM_EXPORT(httpd_resp_send_chunk),
    ESP_ELFSYM_EXPORT(gdma_get_alignment_constraints),
    ESP_ELFSYM_EXPORT(mbedtls_asn1_get_mpi),
    ESP_ELFSYM_EXPORT(dma2d_hal_rx_reset_channel),
    ESP_ELFSYM_EXPORT(mbedtls_pk_parse_subpubkey),
    ESP_ELFSYM_EXPORT(es8156_read_register),
    ESP_ELFSYM_EXPORT(esp_lcd_panel_io_tx_param),
    ESP_ELFSYM_EXPORT(mpi_hal_write_rinv),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_get_bandwidth__descriptor),
    ESP_ELFSYM_EXPORT(rpc__req__wifi_ap_get_sta_aid__init),
    ESP_ELFSYM_EXPORT(igmp_init),
    ESP_ELFSYM_EXPORT(sem_from_slave_queue),
    ESP_ELFSYM_EXPORT(ds_hal_read_result),
    ESP_ELFSYM_EXPORT(esp_flash_erase_region),
    ESP_ELFSYM_EXPORT(esp_vfs_usb_serial_jtag_get_vfs),
    ESP_ELFSYM_EXPORT(hosted_destroy_semaphore),
    ESP_ELFSYM_EXPORT(periph_rcc_enter),
    ESP_ELFSYM_EXPORT(nvs_erase_key),
    ESP_ELFSYM_EXPORT(sdmmc_send_cmd_send_if_cond),
    ESP_ELFSYM_EXPORT(err_to_errno),
    ESP_ELFSYM_EXPORT(rpc__resp__wifi_set_storage__init),
    ESP_ELFSYM_EXPORT(_ZNKSt9bad_alloc4whatEv),
    ESP_ELFSYM_EXPORT(tcp_abandon),
    ESP_ELFSYM_EXPORT(readdir),
    ESP_ELFSYM_EXPORT(_ZN3nvs15NVSHandleSimple8get_blobEPKcPvj),
    ESP_ELFSYM_EXPORT(mbedtls_rsa_pkcs1_sign),
    ESP_ELFSYM_END
};
