#include<iostream>

class Button {
 public:
  virtual void draw() = 0;
};

class OSXButton: public Button {
 public:
  void draw ()
  {
    std::cout << "drawing osx button" << "\n";
  }
};

class WinButton: public Button {

 public:
  void draw()
  {
    std::cout << "drawing win button" << "\n";
  }
};

class GUIFactory {
 public:
  virtual Button* createbutton() = 0;
};

class OSXFactory: public GUIFactory {

 public:
  Button* createbutton()
  {
    return new OSXButton();
  }
};

class WinFactory: public GUIFactory {

 public:
  Button* createbutton()
  {
    return new WinButton();
  }
};

//The application never knows what factory it is dealing with
//and what button it is creating and drawing. This is due to
//the abstract factory.
class Application {

 public:
  Application(GUIFactory* factory)
  {
    Button* button = factory->createbutton();
    button->draw();
  }
};

int main()
{

  int input;
  std::cout << "Enter 1 or 2: ";
  std::cin >> input;

  GUIFactory* factory;
  if (input == 1)
  {
    factory = new OSXFactory();
  }
  else if (input == 2)
  {
    factory = new WinFactory();
  }
  else
  {
    std::cout << "wrong input";
    return 1;
  }
  
  Application *application = new Application(factory);
  return 0;
}
