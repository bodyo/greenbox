#include "DHT.h"

#ifndef TEMPHUMIDITYSENSOR
#define TEMPHUMIDITYSENSOR

class TempHumiditySensor
{
public:
    TempHumiditySensor(int dataPin, int dhtType = DHT11);

    void setPreferedTemerature(int temp);
    void setPreferedHumidity(int humidity);

    double temperature() const;
    double humidity() const;

    String getJson() const;
    static String dataToJson(float temp, float humid);

private:
    DHT _dhtSensor;

    double _preferedTemp{22};
    double _preferedHumidity{60};
};

#endif
