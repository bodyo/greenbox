#include "temphumiditysensor.h"

TempHumiditySensor::TempHumiditySensor(int dataPin, int dhtType)
    :_dhtSensor(dataPin, dhtType)
{

}

void TempHumiditySensor::setPreferedTemerature(int temp)
{
    _preferedTemp = temp;
}

void TempHumiditySensor::setPreferedHumidity(int humidity)
{
    _preferedHumidity = humidity;
}

double TempHumiditySensor::temperature() const
{
    return _dhtSensor.readTemperature();
}

double TempHumiditySensor::humidity() const
{
    return _dhtSensor.readHumidity();
}

String TempHumiditySensor::getJson() const
{
    return dataToJson(temperature(), humidity());
}

String TempHumiditySensor::dataToJson(float temp, float humid)
{
    String tempHumJson("\"TempHumiditySensor\":{");
    tempHumJson += "\"temperature\":";
    tempHumJson += temp;
    tempHumJson += ",\"humidity\":";
    tempHumJson += humid;
    tempHumJson += "}";
    return tempHumJson;
}
