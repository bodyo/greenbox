#include "moscontroller.h"

#include "Arduino.h"

MosController::MosController(int controllPin)
  :_controllPin(controllPin)
{
    pinMode(_controllPin, OUTPUT);
}

void MosController::turnOn()
{
    digitalWrite(_controllPin, HIGH);
}

void MosController::turnOff()
{
    digitalWrite(_controllPin, LOW);
}
