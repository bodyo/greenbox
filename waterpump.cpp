#include "waterpump.h"

WaterPump::WaterPump(int controllPin, int moistureControllPin, int wetValue, int dryValue)
	: _mosController(controllPin),
	  _moisture(moistureControllPin, wetValue, dryValue)
{
}

void WaterPump::exec()
{
	if (_moisture.sensorData() < _minMoistureValue)
		turnOnFor(_wateringTime);
}

void WaterPump::turnOnFor(int miliSeconds)
{
	_mosController.turnOn();
	delay(miliSeconds);
	_mosController.turnOff();
}

void WaterPump::turnOff()
{
	_mosController.turnOff();
}

void WaterPump::setWateringValue(int value)
{
	_minMoistureValue = value;
}

String WaterPump::dataToJson() const
{
    String waterPumpJson("\"WaterPump\":{");
    waterPumpJson += "\"Moisture\":";
    waterPumpJson += _moisture.sensorData();
    waterPumpJson += ",\"MinMoisture\":";
    waterPumpJson += _minMoistureValue;
    waterPumpJson += ",\"WateringTime\":";
    waterPumpJson += _wateringTime;
    waterPumpJson += '}';
    
    return waterPumpJson;
}
