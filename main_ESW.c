#include <stdio.h>
#include "FreeRTOS.h"
#include "sensor1.h"
#include "sensor2.h"

#define TASK_MY_FIRST_PRIORITY (tskIDLE_PRIORITY + 1)
#define TASK_MY_SECOND_PRIORITY (tskIDLE_PRIORITY + 5)
#define TASK_LORA_DRIVER (tskIDLE_PRIORITY + 10)

#define TASK_MY_FIRST_STACK (configMINIMAL_STACK_SIZE)
#define TASK_MY_SECOND_STACK (configMINIMAL_STACK_SIZE)

int main_ESW() {
  s1_meassurement = create_sensor1();
  s2_meassurement = create_sensor2();
  xEventGroupSensor = xEventGroupCreate();
  xSemaphoreMutex = xSemaphoreCreateMutex();

  xTaskCreate(
    taskLoraDriver,
    "LoraDriver",
    TASK_MY_FIRST_STACK,
    NULL,
    TASK_LORA_DRIVER,
    NULL);

  xTaskCreate(
    taskSensor1,
    "Sensor1",
    TASK_MY_SECOND_STACK,
    NULL,
    TASK_MY_SECOND_PRIORITY,
    NULL);

  xTaskCreate(
    taskSensor2,
    "Sensor2",
    TASK_MY_SECOND_STACK,
    NULL,
    TASK_MY_SECOND_PRIORITY,
    NULL);

  xTaskCreate(
    taskAppController,
    "AppController",
    TASK_MY_FIRST_STACK,
    NULL,
    TASK_MY_FIRST_PRIORITY,
    NULL);

  vTaskStartScheduler();
  for (;;);
}
