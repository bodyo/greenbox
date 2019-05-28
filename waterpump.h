#include "moscontroller.h"
#include "moisture.h"

class WaterPump
{
public:
	WaterPump(int mosControllPin, int moistureControllPin, int wetValue, int dryValue);
	
	void exec();
	
	void turnOnFor(int miliSeconds);
	void turnOff();
	
	void setControllPin(int pin);
  void setWateringValue(int value);

  String dataToJson() const;
	
private:
	MosController _mosController;
	Moisture _moisture;
	
	int _minMoistureValue{ 70 };
  long int _wateringTime{200000};
};
