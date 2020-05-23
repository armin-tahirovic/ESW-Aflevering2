#pragma once
#include <stdint.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "appController.h"

QueueHandle_t xQueue;

typedef struct LoraDriver* pLora;
typedef struct LoraDriver {
  uint8_t len;
  uint8_t* bytes;
} LoraDriver_t;

void queueCreate();
void message_lora(pLora mes);
void taskLoraDriver(void* pvParameters);
