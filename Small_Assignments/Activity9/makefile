CC=g++ 
CPPFLAGS=--std=c++11 -Wall -pedantic

all: staff.cpp staffmember.o employee.o salaried.o hourly.o contractor.o
	$(CC) $(CPPFLAGS) staff.cpp staffmember.o employee.o salaried.o hourly.o contractor.o -o staff

staffmember.o: staffmember.cpp
	$(CC) $(CPPFLAGS) -c staffmember.cpp

employee.o: employee.cpp
	$(CC) $(CPPFLAGS) -c employee.cpp

salaried.o: salaried.cpp
	$(CC) $(CPPFLAGS) -c salaried.cpp

hourly.o: hourly.cpp
	$(CC) $(CPPFLAGS) -c hourly.cpp
	
contractor.o: contractor.cpp
	$(CC) $(CPPFLAGS) -c contractor.cpp

clean:
	rm -f *.o *.exe
