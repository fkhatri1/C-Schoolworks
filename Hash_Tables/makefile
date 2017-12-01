CC=g++ 
CPPFLAGS=--std=c++11 -Wall -pedantic

all: rbnode.o rbtree.o main.cpp
	$(CC) $(CPPFLAGS) main.cpp rbnode.o rbtree.o -o RBtree

rbnode.o: chainedhash.cpp
	$(CC) $(CPPFLAGS) -c rbnode.cpp

rbtree.o: rbtree.cpp
	$(CC) $(CPPFLAGS) -c rbtree.cpp


clean:
	rm -f *.o *.exe
