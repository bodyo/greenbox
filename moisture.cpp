#include "moisture.h"

Moisture::Moisture(int dataPin, int wetValue, int dryValue)
    :_dataPin(dataPin), _wetValue(wetValue), _dryValue(dryValue)
{
}

int Moisture::sensorData()
{
    int val = _dryValue - _wetValue;
    return 100 - ((analogRead(_dataPin)-_wetValue)*100.0/val);
}
