#ifndef ENVIRONMENTC_MONITOR_H
#define ENVIRONMENTC_MONITOR_H

#include "Arduino.h"
#include "sensor.h"

typedef struct environmentMonitorStruct {
  const unsigned static sensorsMaxAmount = 5;
  unsigned pluggedSensorsAmount;
  Sensor_t* sensor[sensorsMaxAmount];
} EnvironmentMonitor_t ;

void init(EnvironmentMonitor_t* monitor);

boolean registerSensor(EnvironmentMonitor_t* monitor, struct Sensor_t* newSensor);

void sendStatsToUser(EnvironmentMonitor_t* monitor);

#endif
