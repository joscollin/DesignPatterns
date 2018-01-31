#include<iostream>

enum genre {ROCK, POP, COUNTRY, INVALID};

class MusicRecord {
 public:
  virtual void playsong() = 0;
};

class RockRecord: public MusicRecord {
 public:
  void playsong()
  {
    std::cout << "Playing: Eagles - Desperado" << std::endl;
  }
};

class PopRecord: public MusicRecord {
 public:
  void playsong()
  {
    std::cout << "Playing: Michael Jackson - Thriller" << std::endl;
  }
};

class CountryRecord: public MusicRecord {
 public:
  void playsong()
  {
    std::cout << "Playing: John Denver - Country Roads" << std::endl;
  }
};

class MusicFactory {
 public:
  MusicRecord* getrecord(genre gen)
  {
    MusicRecord *musicrecord = nullptr;
    switch(gen)
    {
      case ROCK:
        musicrecord = new RockRecord();
        break;
      case POP:
        musicrecord = new PopRecord();
        break;
      case COUNTRY:
        musicrecord = new CountryRecord();
        break;
      default:
        musicrecord = nullptr;
        break;
    }
    return musicrecord;
  }
};

int main()
{
  MusicFactory *musicfactory = new MusicFactory();

  int option;
  std::cout << "Enter 1 for Rock, 2 for Pop, 3 for Country" << std::endl;
  std::cin >> option;

  genre gen;
  switch(option)
  {
    case 1:
      gen = ROCK;
      break;
    case 2:
      gen = POP;
      break;
    case 3:
      gen = COUNTRY;
      break;
    default:
      gen = INVALID;
      break;
  }
  
  MusicRecord *musicrecord = musicfactory->getrecord(gen);
  if(musicrecord)
  {
    musicrecord->playsong();
  }
  else
  {
    std::cout << "Wrong genre selected" << std::endl;
  }

  return 0;
}
