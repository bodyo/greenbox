#include <Arduino.h>

/*!
 * \breaf class that represent the Moisture sensor they basic settings and calibration
 * \note Moisture::dataPin should be analog pin
 */
class Moisture
{
public:
    Moisture(int dataPin, int wetValue, int dryValue);

    int sensorData();

private:
    int _dataPin;
    int _wetValue;
    int _dryValue;
};
