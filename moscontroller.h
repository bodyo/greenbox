class MosController
{
public:
  MosController(int controllPin);

  void turnOn();
  void turnOff();
  
private:
  int _controllPin{ -1 };
};
