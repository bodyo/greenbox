#include "greenbox.h"

GreenBox::GreenBox()
  : _waterPump(40, A2, 425, 791), // temp
    _tempHumiditySensor(A1)
{
  
}

WaterPump& GreenBox::waterPump()
{
    return _waterPump;
}

TempHumiditySensor& GreenBox::tempHumiditySensor()
{
    return _tempHumiditySensor;
}

void GreenBox::setGreenBoxId(int id)
{
    _greenBoxId = id;
}

String GreenBox::getJson() const
{
    String json("{");
    json += "\"greenBoxId\":";
    json += _greenBoxId;
    json += ',';
    json += _tempHumiditySensor.getJson();
    json += ',';
    json += _waterPump.dataToJson();
    json += '}';

    return json;
}

void GreenBox::exec()
{
    _waterPump.exec();

    float temp = _tempHumiditySensor.temperature();
    float hum = _tempHumiditySensor.humidity();
    
    Serial.println(getJson());
}
