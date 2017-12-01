#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;


class Review {
    private:
        string str;
        int len;
        int * num;

    public:
        Review(int, string s); 
        ~Review(); 
        void print ();
};

Review::Review(int x, string s) {
    len = x;
    num = new int[len];
    for(int ii=0;ii<len;ii++) {
        num[ii] = ii;
    }
    str = s;
}

void Review::print () {
    cout << "Review " << str << endl;
    for(int ii=0;ii<len;ii++) {
        cout << num[ii] << " ";
    }
    cout << endl;
}

Review::~Review() {

}

int main() {
    Review m(5, "Faysal Khatri");
    m.print();

    Review n(10, "Testing");
    n.print();
}

