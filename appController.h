#pragma once
#include "FreeRTOS.h"
#include "semphr.h"
#include "event_groups.h"
#include "loraDriver.h"
#include "sensor1.h"
#include "sensor2.h"

#define BIT_0 ( 1 << 0 )
#define BIT_1 ( 1 << 4 )

EventGroupHandle_t xEventGroupSensor;
xSemaphoreHandle xSemaphoreMutex;
void* s1_meassurement;
void* s2_meassurement;

void taskAppController(void* pvParameters);

