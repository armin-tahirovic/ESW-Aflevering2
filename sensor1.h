#pragma once
#include <stdio.h>
#include "FreeRTOS.h"
#include "appController.h"

typedef struct Sensor1* pSensor1;

pSensor1 create_sensor1();
void destroy_sensor1(pSensor1 self);
void meassure_sensor1(pSensor1 self);
int lastMeassure_sensor1(pSensor1 self);

void taskSensor1(void* pvParameters);
