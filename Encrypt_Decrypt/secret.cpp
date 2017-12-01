#include "secret.hpp"

using std::cout;
using std::endl;

void Secret::display() {
  cout << message << endl;
}


void Secret::setMessage(string m) {
	for(int i=0;m[i]=='\0';i++)
	{
		m[i]=toupper(m[i]);
	}
	message = m;
	encrypted = false;
}

