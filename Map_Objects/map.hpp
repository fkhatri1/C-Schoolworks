#ifndef MAP
#define MAP

#include<vector>
#include "mapobjectlist.hpp"
#include "mapobject.hpp"


class Map {
    private:
        int * map;
        int width;
        int height;
    public:        
        Map(MapObjectList list, int x, int y);
        void print();
        void add(int x, int y, char value);
        void load(MapObjectList &list);
};

void get_objects(MapObjectList &list, std::string filename);

#endif