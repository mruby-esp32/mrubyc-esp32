#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "mrubyc.h"

#include "mrb_code.h"

#define TAG "mrubyc_task"

#define MEMORY_SIZE (1024*30)
static uint8_t memory_pool[MEMORY_SIZE];

static void
mruby_task(void *arg) {
    struct VM *vm;

    mrbc_init_alloc(memory_pool, MEMORY_SIZE);
    init_static();
    vm = mrbc_vm_open(NULL);
    if (!vm) {
        ESP_LOGE(TAG, "%s", "Error: VM open failed");
        goto ERROR;
    }
    ESP_LOGI(TAG, "%s", "Loading binary...");
    if (mrbc_load_mrb(vm, mrb_code) != 0) {
        ESP_LOGE(TAG, "%s", "Error: Illegal bytecode");
        goto ERROR;
    }
    mrbc_vm_begin(vm);
    mrbc_vm_run(vm);
    mrbc_vm_end(vm);
    mrbc_vm_close(vm);
    ESP_LOGI(TAG, "%s", "Success");

ERROR:
    while (1) {
        // This task should never end, even if the
        // script ends.
    }
}

void
app_main(void) {
    nvs_flash_init();
    xTaskCreate(&mruby_task, TAG, 8192, NULL, 5, NULL);
}
