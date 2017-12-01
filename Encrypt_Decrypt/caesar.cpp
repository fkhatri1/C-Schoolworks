#include<iostream>
#include <stdlib.h>

#include"caesar.hpp"

using std::string;

void Caesar::encrypt(string key) {
  //Caesar cipher key is only one character. 
  if (!encrypted) {
	  unsigned int i;
	  char k = key[0];
	  string output = "";
	  
	  for (i=0; i<message.length(); i++) {
		 output += (message[i] + k);
	  }
	  
	  message = output;
	  encrypted = true;
  }
}

void Caesar::decrypt(string key) {
  if (encrypted) {
	  unsigned int i;
	  char k = key[0];
	  string output = "";
	  
	  for (i=0; i<message.length(); i++) {
		 output += (message[i] - k);
	  }
	  
	  message = output;
	  encrypted = false;
  }
}
