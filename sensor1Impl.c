#include "sensor1.h"

typedef struct Sensor1 {
  int8_t meassurement;
} Sensor1_t;

pSensor1 create_sensor1() {
  pSensor1 new_sensor = (pSensor1)pvPortMalloc(sizeof(Sensor1_t));

  if (new_sensor == NULL)
    return NULL;

  return new_sensor;
}

void destroy_sensor1(pSensor1 self) {
  vPortFree(self);
}

void meassure_sensor1(pSensor1 self) {
  self->meassurement = rand() % 16;
}

int lastMeassure_sensor1(pSensor1 self) {
  return self->meassurement;
}

void taskSensor1(void* pvParameters) {
  (void)pvParameters;

  for (;;) {
    vTaskDelay(pdMS_TO_TICKS(200));
    meassure_sensor1(s1_meassurement);

    xEventGroupSetBits(xEventGroupSensor, BIT_0);
  }
}
