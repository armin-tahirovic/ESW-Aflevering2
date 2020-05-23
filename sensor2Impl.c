#include <stdio.h>
#include "FreeRTOS.h"
#include "sensor2.h"

typedef struct Sensor2 {
  int8_t meassurement;
} Sensor2_t;

pSensor2 create_sensor2() {
  pSensor2 new_sensor = (pSensor2)pvPortMalloc(sizeof(Sensor2_t));

  if (new_sensor == NULL)
    return NULL;

  return new_sensor;
}

void destroy_sensor2(pSensor2 self) {
  vPortFree(self);
}

void meassure_sensor2(pSensor2 self) {
  int8_t _latestMeassure = 5;

  self->meassurement = _latestMeassure;
}

int lastMeassure_sensor2(pSensor2 self) {
  return self->meassurement;
}

void taskSensor2(void* pvParameters) {

  (void)pvParameters;

  for (;;) {
    vTaskDelay(pdMS_TO_TICKS(200));
    meassure_sensor2(s2_meassurement);

    xEventGroupSetBits(xEventGroupSensor, BIT_1);
  }
}
