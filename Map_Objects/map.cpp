#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include"map.hpp"



using namespace std;

void Map::add(int x, int y, char value) {
   map[(y * width) + x] = value;
}

void Map::load(MapObjectList &list)
{
    for (MapObject object : list.getObjects()) 
    {
      add(object.getX(), object.getY(), object.getType());
    }
}

Map::Map(MapObjectList objects, int x, int y) {
    int rr, cc;

    width = x;
    height = y;
    map = (int *) malloc(sizeof(int) * width * height);
    for (rr=0;rr<height;rr++) 
        for (cc=0;cc<width;cc++) 
            map[(rr * width) + cc] = EMPTY;
    load(objects);
}

void Map::print() {
    int rr, cc;
    char output = ' ';
    object_type_t output_type = EMPTY;

    for (rr=0;rr<height;rr++)  {
        for (cc=0;cc<width;cc++)  {
            output_type = (object_type_t) map[(rr * width) + cc];
            output = get_map_representation((object_type_t) map[(rr * width) + cc]);
            if (output_type != EMPTY) {
                cout << get_map_representation((object_type_t) map[(rr * width) + cc]);
            }
            // If an empty space, check if we should print a road character
            else {
                if ( (cc % 5 == 0) && (rr % 5 == 0)) {
                    cout << '+';
                }
                else if (cc % 5 == 0) {
                    cout << '|';
                }
                else if (rr % 5 == 0) {
                    cout << '-';
                }
                else {
                    cout << ' ';
                }
            }
        }
        if (rr % 5 == 0) {
            cout << '+' << endl;
        }
        else {
            cout << '|' << endl;
        }
    }
}
MapObject object_from_string(char * buff) {
    char label[50];
    char * tok = strtok(buff, ",");
    int xloc;
    int yloc;
    float speed;
    int direction;
    object_type_t type;
    if(tok != NULL) {
        strncpy(label, tok, 50);
        xloc=atoi(strtok(NULL, ","));
        yloc=atoi(strtok(NULL, ","));
        speed=atof(strtok(NULL, ","));
        direction=atof(strtok(NULL, ","));
        type=string_to_type(strtok(NULL, ","));
    }

    MapObject ret(label, xloc, yloc, speed, direction, type);
    return MapObject(label, xloc, yloc, speed, direction, type);
}

void get_objects(MapObjectList &list, string filename) {

    FILE *fp;
    char buffer[50];
    fp = fopen(filename.c_str(), "r");

    while (fgets(buffer, 50,fp)) {
        list.add(object_from_string(buffer));
    }
}

