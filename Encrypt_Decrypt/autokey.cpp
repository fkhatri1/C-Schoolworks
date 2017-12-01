#include<iostream>
#include <stdlib.h>

#include"autokey.hpp"


using std::string;

void Autokey::encrypt(string key) {
  //Autokey cipher key is a string. 
  if (!encrypted) {
	  unsigned int i;
	  char k;
	  string output = "";
	  
	  for (i=0; i<message.length(); i++) {
		 k = key[ i % key.length()  ];
		 key[ i % key.length() ] = (message[i]);
		 output += (message[i] + k);
		 
	  }
	  
	  message = output;
	  encrypted = true;
  }
}

void Autokey::decrypt(string key) {
  if (encrypted) {
	  unsigned int i;
	  char k;
	  string output = "";
	  
	  for (i=0; i<message.length(); i++) {
		 k = key[ i % key.length() ];
		 output += (message[i] - k);
		 key[ i % key.length() ] = (output[i]);
	  }
	  
	  message = output;
	  encrypted = false;
  }
}
