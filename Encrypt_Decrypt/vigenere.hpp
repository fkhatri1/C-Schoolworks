//Caesar object derived from Secret

#ifndef SECRET
#define SECRET
#include"secret.hpp"
#endif

using std::string;


class Vigenere : public Secret {
  public:
    Vigenere(string m) : Secret(m)
    {
       //using base class constructor.
    }
		
	Vigenere() : Secret()
	{
		//using base class constructor.
	}
	
	// base class destructor will be called by default
	
	void encrypt(string key);
	void decrypt(string key);  
};

