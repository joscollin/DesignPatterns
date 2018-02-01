#include <iostream>

class Singleton {
private:
  Singleton()
  {
    std::cout << "creating a new instance of Singleton" << std::endl;
  }
public:
  static Singleton* single;
  static bool instanceflag;
  ~Singleton()
  {
    instanceflag = false;
    std::cout << "destroyed the instance" << std::endl;
  }

  static Singleton* getinstance()
  {
    if(!instanceflag)
    {
      single = new Singleton();
      instanceflag = true;
    }
    return single;
  }

  static void destroyinstance()
  {
    delete single;
  }
  
  void print()
  {
    std::cout << "printing singleton" << std::endl;
  }
};

Singleton* Singleton::single = nullptr;
bool Singleton::instanceflag = false;

int main()
{
  Singleton *s1 = Singleton::getinstance();
  s1->print();
  Singleton *s2 = Singleton::getinstance();
  s2->print();

  Singleton::destroyinstance();

  Singleton *s3 = Singleton::getinstance();
  s3->print();
  
  return 0;
}
