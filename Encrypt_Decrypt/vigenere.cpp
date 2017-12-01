#include<iostream>
#include <stdlib.h>

#include"vigenere.hpp"


using std::string;

void Vigenere::encrypt(string key) {
  //Vigenere cipher key is a string. 
  if (!encrypted) {
	  unsigned int i;
	  char k;
	  string output = "";
	  
	  for (i=0; i<message.length(); i++) {
		 k = key[ i % key.length() ];
		 output += (message[i] + k);
	  }
	  
	  message = output;
	  encrypted = true;
  }
}

void Vigenere::decrypt(string key) {
  if (encrypted) {
	  unsigned int i;
	  char k;
	  string output = "";
	  
	  for (i=0; i<message.length(); i++) {
		 k = key[ i % key.length() ];
		 output += (message[i] - k);
	  }
	  
	  message = output;
	  encrypted = false;
  }
}
