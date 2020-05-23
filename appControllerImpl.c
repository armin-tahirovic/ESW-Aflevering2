#include "appController.h"

void taskAppController(void* pvParameters) {

  (void)pvParameters;
  
  for (;;)
  {
    EventBits_t uxBits = xEventGroupWaitBits(
      xEventGroupSensor,
      BIT_0 | BIT_1,
      pdTRUE,
      pdTRUE,
      pdMS_TO_TICKS(1000));

    if ((uxBits & (BIT_0 | BIT_1)) == (BIT_0 | BIT_1))
    {
      pLora message = (pLora)pvPortMalloc(sizeof(LoraDriver_t));
      int8_t meassure1 = lastMeassure_sensor1(s1_meassurement);
      int8_t meassure2 = lastMeassure_sensor2(s2_meassurement);

      message->len = sizeof(int8_t) * 2;
      message->bytes = pvPortMalloc(sizeof(int8_t) * 2);
      message->bytes[0] = meassure1;
      message->bytes[1] = meassure2;


      message_lora(message);
      xEventGroupClearBits(xEventGroupSensor, BIT_0 | BIT_1);
    }
    else
    {
      xSemaphoreTake(xSemaphoreMutex, portMAX_DELAY);
      printf("Fejl ved taskAppController \n");
      xSemaphoreGive(xSemaphoreMutex);
    }
  }

  vTaskDelete(NULL);
}

