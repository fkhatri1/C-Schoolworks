//Caesar object derived from Secret

#ifndef SECRET
#define SECRET
#include"secret.hpp"
#endif

using std::string;


class Caesar : public Secret {
  public:
    Caesar(string m) : Secret(m)
    {
       //using base class constructor.
    }
		
	Caesar() : Secret()
	{
		//using base class constructor.
	}
	
	// base class destructor will be called by default
	
	void encrypt(string key);
	void decrypt(string key);  
};

