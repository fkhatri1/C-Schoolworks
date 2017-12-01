#include<iostream>

using namespace std;

class MyClass {
  private:
    int num;
    string str;

  public:
    // constructor
    MyClass(int num, string str);
	MyClass();
    void print ();
};

// Constructor
MyClass::MyClass(int a, string b) {
   num = a;
   str = b;
}

MyClass::MyClass() {
   num = 0;  //default values
   str = "default";
}

void MyClass::print() {
  cout << "  Num: " << num << endl;
  cout << "  Str: " << str << endl;
}


int main() {
  MyClass faysal(18, "faysal khatri"); 
  MyClass *faysal2 = new MyClass();

  cout << "My Class 1: " << endl;
  faysal.print();
  
  cout << "My Class 2: " << endl;
  faysal2->print();
  return 0;
}