#include <iostream>

class Singleton {

private:
  static Singleton* single;

  Singleton()
  {
    std::cout << "creating a new instance of Singleton" << std::endl;
  }

  ~Singleton()
  {
    std::cout << "destroyed the instance" << std::endl;
  }

public:
  static Singleton* getinstance()
  {
    if(!single)
    {
      single = new Singleton();
    }
    return single;
  }

  static void destroyinstance()
  {
    delete single;
    single = nullptr; //reset the pointer
  }

  void print()
  {
    std::cout << "printing singleton" << std::endl;
  }
};

Singleton* Singleton::single = nullptr;

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
