// TODO add real comment with header for this file

#ifndef SENSOR_H
#define SENSOR_H

enum SensorType { temperature = 0, humidity = 1 };

// TODO add typedef
typedef struct  Sensor_t {
  enum SensorType type;
  unsigned sensorPIN;
  unsigned probeTotalAmout;
  unsigned probeIndex;
  unsigned startEEPROMAdress;
} Sensor_t;

unsigned readCurrentValue(struct Sensor_t* sensor);

unsigned getProbe(Sensor_t* sensor, unsigned index);

float normalizeTemperature(unsigned temperature);

void updateStats(Sensor_t* sensor);

#endif
