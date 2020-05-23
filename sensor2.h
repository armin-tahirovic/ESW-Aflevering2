#pragma once
#include "appController.h"

typedef struct Sensor2* pSensor2;

pSensor2 create_sensor2();
void destroy_sensor2(pSensor2 self);
void meassure_sensor2(pSensor2 self);
int lastMeassure_sensor2(pSensor2 self);

void taskSensor2(void* pvParameters);
