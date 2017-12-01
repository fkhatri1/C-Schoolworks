//Caesar object derived from Secret

#ifndef SECRET
#define SECRET
#include"secret.hpp"
#endif

using std::string;


class Autokey : public Secret {
  public:
    Autokey(string m) : Secret(m)
    {
       //using base class constructor.
    }
		
	Autokey() : Secret()
	{
		//using base class constructor.
	}
	
	// base class destructor will be called by default
	
	void encrypt(string key);
	void decrypt(string key);  
};

