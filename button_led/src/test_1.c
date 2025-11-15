// main.c — ESP-IDF: FreeRTOS task that blinks GPIO2 once per second

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

// 1) Choose the LED pin (GPIO2 is common on many ESP32 dev boards)
#define LED_PIN GPIO_NUM_2

// 2) Optional: keep a handle if you ever want to suspend/delete the task
static TaskHandle_t blink_task_handle = NULL;

// 3) This is the FreeRTOS task function
static void blink_task(void *arg)
{
    while (1) { // run forever
        gpio_set_level(LED_PIN, 1);                       // LED ON
        ESP_LOGI("BlinkTask", "LED ON (core %d)", xPortGetCoreID());
        vTaskDelay(pdMS_TO_TICKS(1000));                  // wait 1000 ms

        gpio_set_level(LED_PIN, 0);                       // LED OFF
        ESP_LOGI("BlinkTask", "LED OFF (core %d)", xPortGetCoreID());
        vTaskDelay(pdMS_TO_TICKS(1000));                  // wait 1000 ms
    }
    // never returns; if it did, delete self:
    // vTaskDelete(NULL);
}

// 4) app_main() is the entry point in ESP-IDF (not loop()/setup())
void app_main(void)
{
    // 4a) Configure the GPIO as OUTPUT
    gpio_config_t io = {
        .pin_bit_mask = 1ULL << LED_PIN,   // which pin(s)
        .mode = GPIO_MODE_OUTPUT,          // output mode
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io);

    // 4b) Create a FreeRTOS task and (optionally) pin it to a core
    // NOTE: In ESP-IDF the stack size is in *words* (4 bytes each), not bytes.
    // 2048 words ≈ 8192 bytes of stack.
    BaseType_t ok = xTaskCreatePinnedToCore(
        blink_task,                // task function
        "BlinkTask",               // name (for debugging)
        2048,                      // stack size (WORDS, not bytes)
        NULL,                      // parameter to pass (unused)
        tskIDLE_PRIORITY + 1,      // priority (higher number = higher priority)
        &blink_task_handle,        // out: task handle (optional)
        1                          // run on core 1 (ESP32 has cores 0 and 1)
    );

    if (ok != pdPASS) {
        ESP_LOGE("app_main", "Failed to create BlinkTask");
    }
}
