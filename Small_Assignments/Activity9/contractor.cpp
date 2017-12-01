
#include "contractor.hpp"

int Contractor::pay() {
  int pay = 0;
  
  if (hours > maxHours) {
	  std::cout << "Exceeded max hours. Only max hours will be recorded\n";
	  hours = maxHours;
  }
  
  if ( hours > 40 ) {
	  pay = payrate * 40;
	  pay += (payrate * 1.5) * (hours - 40);
  }
  else {
	  pay = payrate * hours;
  }
  
  return (pay);
}


void Contractor::setMaxHours(int m) {
	maxHours = m;
}

