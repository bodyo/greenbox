#include "waterpump.h"
#include "temphumiditysensor.h"

class GreenBox
{
public:
    GreenBox();
    
    WaterPump &waterPump();
    TempHumiditySensor& tempHumiditySensor();
    void setGreenBoxId(int id);
    void exec();

    String getJson() const;

private:
    int _greenBoxId{ -1 };
    WaterPump _waterPump;
    TempHumiditySensor _tempHumiditySensor;
};
