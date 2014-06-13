

// TODO add real comment with header for this file

//#include "Arduino.h"
//#include <EEPROM.h>
#include "sensor.h"

void incProbeIndex(Sensor_t* sensor);

void setProbe(Sensor_t* sensor, unsigned index, unsigned value);

unsigned readCurrentValue(struct Sensor_t* sensor) {
  return 0;//analogRead(sensor->sensorPIN);
}

unsigned getProbe(Sensor_t* sensor, unsigned index) {
  return 0;//EEPROM.read(sensor->startEEPROMAdress + index);
}

void setProbe(struct Sensor_t* sensor, unsigned index, unsigned value) {
  //EEPROM.write(sensor->startEEPROMAdress + index, value);
}

float normalizeTemperature(unsigned temperature) {
  temperature -= 102; // calibrate: 0C -> 0V
  float outputValue = (temperature / 20.5) * 10 ;// normalize
  
  return outputValue;
}

void incProbeIndex(Sensor_t* sensor) {
  if (sensor->probeIndex == sensor->probeTotalAmout) {
    sensor->probeIndex = 0;
  }
  sensor->probeIndex++;
}

void updateStats(Sensor_t* sensor) {
  unsigned value = readCurrentValue(sensor);
  setProbe(sensor, sensor->probeIndex, value);
  incProbeIndex(sensor);
}

