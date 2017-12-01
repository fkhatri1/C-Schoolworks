CC=g++ 
CPPFLAGS=--std=c++11

all: project3.cpp mapobject.o map.o mapobjectlist.o
	$(CC) $(CPPFLAGS) project3.cpp mapobject.o map.o mapobjectlist.o -o project3

mapobject.o: mapobject.cpp
	$(CC) $(CPPFLAGS) -c mapobject.cpp

mapobjectlist.o: mapobjectlist.cpp
	$(CC) $(CPPFLAGS) -c mapobjectlist.cpp

map.o: map.cpp
	$(CC) $(CPPFLAGS) -c map.cpp

clean:
	rm -f *.o *.exe *~
