#include<iostream>
#include<vector>

using namespace std;

template<class T>
class Bag {
    private:
        vector<T> bag;

    public:
        Bag(int size);
        void add(T item) {
			bag.push_back(item);
		}
        void print() {
			cout << "bag contents: " << endl;
			for (unsigned int ii=0; ii<bag.size(); ii++) {
			cout <<  bag[ii] << " ";
			}
			cout << endl;
		}

};

template<class T>
Bag<T>::Bag(int size) {
	vector<T> bag(size);
}


int main() {
  Bag<string> myBag(10);
  myBag.add("hello");
  myBag.add("goodbye");
  myBag.print();

  Bag<int> myIntBag(1);
  myIntBag.add(1);
  myIntBag.add(2);
  myIntBag.add(3);
  myIntBag.print();
  
  
  return 0;
}