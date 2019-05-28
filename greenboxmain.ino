#include "greenbox.h"

GreenBox greenBox;

void setup() {
  Serial.begin(9600);
  greenBox.waterPump().setWateringValue(60);
}

void loop() {
  greenBox.exec();
}
