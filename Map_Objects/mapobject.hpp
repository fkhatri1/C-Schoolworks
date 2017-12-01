//Faysal Khatri
#ifndef MAP_OBJECT
#define MAP_OBJECT
#include <string>

using namespace std;

typedef enum {CAR, TREE, POLICE, OBSTACLE, EMPTY} object_type_t;

class MapObject {
	private:
	string label;
	int xloc, yloc;
	float speed;
	int direction;
	object_type_t type;

	public:
	MapObject(string l, int x, int y, float s, int d, object_type_t t=EMPTY);
	MapObject();
	void get();
	void print();
	bool collision(const MapObject&);
	string getLabel() const;
	object_type_t getType() const;
	int getX() const;
	int getY() const;
	

};

object_type_t string_to_type(string type_string);
char get_map_representation(object_type_t type);
string string_from_type(object_type_t);
#endif