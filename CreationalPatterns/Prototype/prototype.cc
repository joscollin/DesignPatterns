#include<iostream>
#include<map>

class ColorPrototype {
public:
  virtual ColorPrototype* clone() = 0;
};

class Color: public ColorPrototype {
private:
  int red, green, blue;
public:
  //revoke default ctor
  Color() = delete;
  Color(int _red, int _green, int _blue): red{_red}, green{_green}, blue{_blue} {}
  ColorPrototype* clone()
  {
    std::cout << "cloning Color (R,G,B): (" << red << "," << green << "," << blue << ")" << std::endl;
    return new Color(red, green, blue);
  }

  //Setters
  void SetRed(int _red)
  {
    red = _red;
  }
  void SetGreen(int _green)
  {
    green = _green;
  }
  void SetBlue(int _blue)
  {
    blue = _blue;
  }

  int GetRed() {return red;}
  int GetGreen() {return green;}
  int GetBlue() {return blue;}
};

class ColorManager {
private:
  std::map<std::string, ColorPrototype*> colors; //hetrogeneous
public:
  void AddColor(const std::string& colorname, ColorPrototype* colorprot)
  {
    colors[colorname] = colorprot;
  }

  ColorPrototype* GetColor(const std::string& colorname)
  {
    const auto& iterator = colors.find(colorname);
    if (iterator != colors.end())
	return iterator->second;
    return nullptr;
  }

  void printcolors()
  {
    for(const auto& it: colors)
      {
	Color* color = (Color*)it.second;
	std::cout << it.first << " " << color->GetRed() << "," << color->GetGreen() << "," << color->GetBlue() << std::endl;
      }
  }
  
  ~ColorManager()
  {
    while(!colors.empty())
      {
	const auto& iterator = colors.begin();
	delete iterator->second;
	colors.erase(iterator);
      }
  }
};

int main()
{
  ColorManager* colormanager = new ColorManager();
  //Add your colors first
  colormanager->AddColor("Red", new Color(255, 0, 0));
  colormanager->AddColor("Green", new Color(0, 255, 0));
  colormanager->AddColor("Blue", new Color(0, 0, 255));

  //Get some colors, modify them and add it to colors.
  ColorPrototype *newgreen = colormanager->GetColor("Green")->clone();
  static_cast<Color*>(newgreen)->SetGreen(100);
  colormanager->AddColor("DarkGreen", newgreen);
  
  ColorPrototype *newblue = colormanager->GetColor("Blue")->clone();
  static_cast<Color*>(newblue)->SetRed(127);
  colormanager->AddColor("Violet", newblue);

  //print the colors
  colormanager->printcolors();
  
  delete colormanager;
  return 0;
}
