#include<iostream>

using namespace std;

class MyClass {
  private:
    int a;
    string str;

  public:
    // constructor
    MyClass(int a, string str);
	MyClass();
    void print ();
	friend bool operator< (const MyClass &c1, const MyClass &c2);
	friend bool operator> (const MyClass &c1, const MyClass &c2);
	friend bool operator== (const MyClass &c1, const MyClass &c2);
	friend ostream& operator<< (ostream& strm, const MyClass& m);
};

// Constructor
MyClass::MyClass(int n, string b) {
   a = n;
   str = b;
}

MyClass::MyClass() {
   a = 0;  //default values
   str = "default";
}

void MyClass::print() {
  cout << "  Num: " << a << endl;
  cout << "  Str: " << str << endl;
}

bool operator< (const MyClass &c1, const MyClass &c2) {
	if (c1.a < c2.a) {
		return true;
	}
	else {
		return false;
	}
}

bool operator> (const MyClass &c1, const MyClass &c2) {
	if (c1.a > c2.a) {
		return true;
	}
	else {
		return false;
	}
}

bool operator== (const MyClass &c1, const MyClass &c2) {
	if (c1.a == c2.a) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<< (ostream& strm, const MyClass &m) {
  strm << "[" << m.a << "]";
  return strm;
}


int main() {
  MyClass class1(18, "faysal khatri"); 
  MyClass class2(12, "smaller");

  cout << "class1: " << class1 << "   class2: " << class2 << endl;
  cout << "class1 < class2: " << (class1 < class2) << endl;
  cout << "class1 > class2: " << (class1 > class2) << endl;
  cout << "class1 == class2: " << (class1 == class2) << endl;

  return 0;
}