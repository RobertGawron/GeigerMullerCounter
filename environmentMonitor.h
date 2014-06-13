#ifndef ENVIRONMENTC_MONITOR_H
#define ENVIRONMENTC_MONITOR_H

//#include "Arduino.h"
#include "sensor.h"
#define boolean char

#define false 0U;
#define true 1U;
//#define sensorsMaxAmount 5U;

typedef struct environmentMonitorStruct {
  char sensorsMaxAmount/* = 5 */;
  unsigned pluggedSensorsAmount;
  Sensor_t* sensor[5];
} EnvironmentMonitor_t ;

void init(EnvironmentMonitor_t* monitor);

boolean registerSensor(EnvironmentMonitor_t* monitor, struct Sensor_t* newSensor);

void sendStatsToUser(EnvironmentMonitor_t* monitor);

#endif
