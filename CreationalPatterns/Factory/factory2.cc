#include<iostream>
#include<vector>

enum genre {ROCK, POP, COUNTRY, INVALID};

class MusicRecord {
 public:
  virtual void playsong() = 0;

  //factory method
  static MusicRecord* getrecord(genre);
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

MusicRecord* MusicRecord::getrecord(genre gen)
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

int main()
{
  std::vector<MusicRecord*> musicrecords;

  int option;
  while (true) {
    std::cout << "Enter Rock(1), Pop(2), Country(3), Exit(0)," << std::endl;
    std::cin >> option;

    genre gen;
    switch(option)
      {
      case 0:
	exit(0);
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

    MusicRecord* musicrecord = MusicRecord::getrecord(gen);

    if (musicrecord)
      musicrecords.push_back(musicrecord);
    else
      std::cout << "wrong genre selected" << std::endl;
  }

  for (const auto &musicrecord: musicrecords) {
    musicrecord->playsong();
  }

  return 0;
}
