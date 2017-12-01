CC=g++ 
CPPFLAGS=--std=c++11 -Wall -pedantic

all: proj3.cpp autokey.o vigenere.o caesar.o secret.o
	$(CC) $(CPPFLAGS) proj3.cpp autokey.o vigenere.o caesar.o secret.o -o encrypt

secret.o: secret.cpp
	$(CC) $(CPPFLAGS) -c secret.cpp

caesar.o: caesar.cpp
	$(CC) $(CPPFLAGS) -c caesar.cpp

vigenere.o: vigenere.cpp
	$(CC) $(CPPFLAGS) -c vigenere.cpp

autokey.o: autokey.cpp
	$(CC) $(CPPFLAGS) -c autokey.cpp
	
clean:
	rm -f *.o *.exe
