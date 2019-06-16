

#include "environmentMonitor.h"

void init(EnvironmentMonitor_t* monitor) {
  monitor->pluggedSensorsAmount = 0;
}

boolean registerSensor(EnvironmentMonitor_t* monitor,  struct Sensor_t* newSensor) {
  if (monitor->pluggedSensorsAmount < monitor->sensorsMaxAmount) {
    return false;
  }
  monitor->sensor[ monitor->pluggedSensorsAmount++ ] = newSensor;  
  return true;
}

// sends stats in CSV format over USB link
void sendStatsToUser(EnvironmentMonitor_t* monitor) {
  //Serial.print("SensorID, SensorType, ProbeNumber, Value;\n");
  
  for (unsigned i = 0; i < monitor->pluggedSensorsAmount; i++) {
    for (unsigned j = 0; (j < monitor->sensor[i]->probeIndex) && (j < monitor->sensor[i]->probeTotalAmout); j++) {
      //Serial.print(i);
      //Serial.print(",");
      
      //Serial.print(monitor->sensor[i]->type);
      //Serial.print(",");
      
      //Serial.print(j);
      //Serial.print(",");                       
      
      //Serial.print(normalizeTemperature(getProbe(monitor->sensor[i], j)));
      //Serial.print(";\n");  
    }
  }
}

