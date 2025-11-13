#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN GPIO_NUM_7

static TaskHandle_t blink_task_handle = NULL; //TaskHandle_t is a function that allows us to create a new function

//creating the FreeRTOS task function
static void blink_task(void *arg)
{
    while(1) {
        gpio_set_level(LED_PIN, 1);
        ESP_LOGI("Blink Task", "LED ON (core %d)", xPortGetCoreID);
        vTaskDelay(pdMS_TO_TICKS(1000));

        gpio_set_level(LED_PIN, 0);
        ESP_LOGI("BlinkTask", "LED OFF (core %d)",xPortGetCoreID);
        vTaskDelay(pdMS_TO_TICKS(1000)); //wait 1000ms
    }
}

void app_main(void)
{
    gpio_config_t io = {
        .pin_bit_mask = 1ULL << LED_PIN, // 1ULL is used because its a 64-bit 1, that means its has 64 bits to go, since esp has so many pins 1ULL has enough to move around. so after this code pin 7 has set to high meaning it has given 1.
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE // disable GPIO interrupts since this is a LED no need of interrupts but if this was a button interrupts should be enabled.
    };
    gpio_config(&io); //applies the configuration to the hardware for all pins in pin_bit_mask at once.
}