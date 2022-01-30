#ifndef CONFIG_H_
#define CONFIG_H_
#define FLASH_BASE_ADDR               0x08000000
#define FLASH_SIZE_KB                 128
#define FLASH_BOOTLDR_SIZE_KB         16
#define FLASH_BOOTLDR_PAYLOAD_SIZE_KB 112

#define ENABLE_DFU_UPLOAD
#define ENABLE_WATCHDOG 26 /* 26 second watchdog*/

#if VECTOR_TABLE_OFFSET != 0
#define SHOW_HASH
#define HASH_REGION_START     FLASH_BASE_ADDR
#define HASH_REGION_END       (FLASH_BASE_ADDR + (1024 * FLASH_BOOTLDR_SIZE_KB))
#define DFU_VALID_FLASH_START (FLASH_BASE_ADDR)
#define DFU_VALID_FLASH_END   (FLASH_BASE_ADDR + (FLASH_BOOTLDR_SIZE_KB * 1024))
#define RUNTIME_MODE
#else
#define BOOTLOADER_MODE
#define DFU_VALID_FLASH_START (FLASH_BASE_ADDR + (FLASH_BOOTLDR_SIZE_KB * 1024))
#define DFU_VALID_FLASH_END   (FLASH_BASE_ADDR + (FLASH_BOOTLDR_PAYLOAD_SIZE_KB * 1024))
// In DFU mode, we use button to enter

#define ENABLE_GPIO_DFU_BOOT
#define GPIO_DFU_BOOT_PORT GPIOA
#define GPIO_DFU_BOOT_PIN  9

#endif

/* Commands sent with wBlockNum == 0 as per ST implementation. */
#define CMD_SETADDR 0x21
#define CMD_ERASE   0x41
#endif