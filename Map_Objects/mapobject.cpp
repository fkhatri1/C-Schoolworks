//Faysal Khatri
#include <iostream>
#include "mapobject.hpp"

using namespace std;

MapObject::MapObject(string l, int x, int y, float s, int d, object_type_t t) {
	label = l;
	xloc = x;
	yloc = y;
	speed = s;
	direction = d;
	type = t;
}

MapObject::MapObject() {
	label = "";
	xloc = -1;
	yloc = -1;
	speed = -1;
	direction = -1;
	type = EMPTY;
}

void MapObject::get() {
	string label, xloc, yloc, speed, direction, type;

	printf("Enter name of object: ");  	getline(cin, label);
	printf("Enter x location: "); 	 	getline(cin, xloc);
	printf("Enter y location: "); 	 	getline(cin, yloc);
	printf("Enter speed: ");  			getline(cin, speed);
	printf("Enter direction: "); 		getline(cin, direction);
	printf("Enter type: ");  			getline(cin, type);
    
	(*this).label = label;
	(*this).xloc=stoi(xloc);
	(*this).yloc=stoi(yloc);
	(*this).speed=stof(speed);
	(*this).direction=stoi(direction);
	(*this).type=string_to_type(type); 
    
}

void MapObject::print() {
	cout << (*this).label << endl;
	cout << "  Location: (" << (*this).xloc << ", " << (*this).xloc << ")";
	cout << "  Speed: " << (*this).speed;
	cout << "  Direction: " << (*this).direction;
	cout << "  Type: " << string_from_type((*this).type) << endl;
}

object_type_t MapObject::getType() const {
	return (*this).type;
}

string MapObject::getLabel() const {
	return (*this).label;
}

int MapObject::getX() const {
	return (*this).xloc;
}

int MapObject::getY() const {
	return (*this).yloc;
}

object_type_t string_to_type(string string_type) {
	object_type_t ret;
	
	if ( string_type.compare("car\n") == 0 )
		ret = CAR;
	else if ( string_type.compare("tree\n") == 0 )
		ret = TREE;
	else if ( string_type.compare("police\n") == 0 )
		ret = POLICE;
	else if ( string_type.compare("obstacle\n") == 0 )
		ret = OBSTACLE;
	else {
		ret = EMPTY;
	}
	return ret;
}

char get_map_representation(object_type_t type) {
	char ret;
	if (type == CAR)
		ret = 'O';
	else if (type == TREE)
		ret = '*';
	else if (type == POLICE)
		ret = '#';
	else if (type == OBSTACLE)
		ret = 'X';
	else
		ret = ' ';
	
	return ret;
}

bool MapObject::collision(const MapObject &that) {
	if ((*this).getX() == that.getX()) {
		if ((*this).getY() == that.getY()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

string string_from_type(object_type_t type) {
	string ret;
	
	if (type == CAR)
		ret = "CAR";
	else if (type == TREE)
		ret = "TREE";
	else if (type == POLICE)
		ret = "POLICE";
	else if (type == OBSTACLE)
		ret = "OBSTACLE";
	else
		ret = "EMPTY";
	
	return ret;
}