#include<iostream>
#include "mapobjectlist.hpp"
#include "mapobject.hpp"
#include "map.hpp"


using namespace std;

int main ()
{
	cout << "FAYSAL KHATRI" << endl;
    int ii;
    MapObjectList mapList;
    MapObject new_object;

    // mapList.add(new_object);

    // Read objects from a file then create & print map
    get_objects(mapList, "objects.txt");
    Map map(mapList, 30, 16);
    map.print();


    cout << endl << "print():" << endl;
    mapList.print();
    cout << "\nget_all_of_type(CAR):" << endl;
    mapList.get_all_of_type(CAR);
    cout << "\nfind(\"RedCar\")" << endl;
    mapList.find("RedCar");

    cout << "\ncollision() test:" << endl;
    MapObject test1("Test1", 14, 5, 90, 55);
    MapObject test2("Test2", 14, 5, 90, 55);
    MapObject test3("Test3", 20, 5, 90, 55);
    if (test1.collision(test2)) 
        cout << "TEST1: SUCCESS!" << endl;
    else
        cout << "TEST2: FAIL!" << endl;
    if (test1.collision(test3)) 
        cout << "TEST2: FAIL!" << endl;
    else
        cout << "TEST2: SUCCESS!" << endl;

	cout << "FAYSAL KHATRI" << endl;
    return 0;
}

