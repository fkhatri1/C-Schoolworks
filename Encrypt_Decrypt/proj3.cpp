#include<iostream>
#include"caesar.hpp"
#include"vigenere.hpp"
#include"autokey.hpp"

using std::cout;
using std::endl;

const int SECRETS = 6;

int main() {
	Secret * secrets[SECRETS];
	
	secrets[0] = new Autokey("Faysal Autokey");
	secrets[1] = new Autokey("Faysal Autokey the Second");
	secrets[2] = new Vigenere("Faysal Vigenere");
	secrets[3] = new Vigenere("Faysal Vigenere the Second");
	secrets[4] = new Caesar("Faysal Caesar");
	secrets[5] = new Caesar("Faysal Caesar the Second");
	
	
	cout << endl << "Printing Secret Messages" <<  endl;
	for (int i=0; i<SECRETS; i++) {
		secrets[i]->display();
	}
	
	cout << endl << "Printing Encrypted Messages" <<  endl;
	for (int i=0; i<SECRETS; i++) {
	
		secrets[i]->encrypt("ABC");
		secrets[i]->display();	
	}

	cout << endl << "Printing Decrypted Messages" <<  endl;
	for (int i=0; i<SECRETS; i++) {
		secrets[i]->decrypt("ABC");
		secrets[i]->display();	
	}	
}