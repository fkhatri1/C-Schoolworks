// Staff member - base class

#include<iostream>
#include "hourly.hpp"

class Contractor : public Hourly {
  private:
	int maxHours = 40;
	
  public:
    Contractor(std::string n, std::string a, std::string p, std::string s, int r, int h, int m) : Hourly(n, a, p, s, r, h)
    {
      maxHours = m;
    }
	
	Contractor(std::string n, std::string a, std::string p, std::string s, int r, int h) : Hourly(n, a, p, s, r, h)
    {
      maxHours = 40;
    }

  int pay();
 void setMaxHours(int m);
};
