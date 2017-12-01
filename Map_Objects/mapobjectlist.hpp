//Faysal Khatri
#ifndef MAP_OBJECT_LIST
#define MAP_OBJECT_LIST
#include <vector>
#include "mapobject.hpp"


class MapObjectList {
	private:
		std::vector<MapObject> objects;
	public:
		MapObjectList();
		void add(MapObject);
		void print();
		void get_all_of_type(object_type_t);
		void find(string);
		std::vector<MapObject>& getObjects() {return objects; }
};

#endif