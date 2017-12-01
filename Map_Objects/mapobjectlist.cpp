//Faysal Khatri
#include <string>
#include <iostream>
#include "mapobjectlist.hpp"



MapObjectList::MapObjectList() {
}

void MapObjectList::add(MapObject obj) {
	objects.push_back(obj);
}

void MapObjectList::print()  {
	for (int i=0; i<objects.size(); i++) {
		objects.at(i).print();
	}
}

void MapObjectList::get_all_of_type(object_type_t target_type) {
	for (int i=0; i<objects.size(); i++) {
		if (objects.at(i).getType() == target_type)
			objects.at(i).print();
	}
}

void MapObjectList::find(string target) {
	for (int i=0; i<objects.size(); i++) {
		if (objects.at(i).getLabel() == target)
			objects.at(i).print();
	}
}
	
	