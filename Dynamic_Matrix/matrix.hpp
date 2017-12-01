
#include<iostream>

using std::ostream;

class Matrix {
  public:
	int rows;
	int cols;
	int* matrix;
	  
    Matrix(int r, int c)
    {
      rows = r;
	  cols = c;
	  matrix = new int[rows * cols];
    }
	
	//Copy Constructor
	Matrix(const Matrix * m1) {
	  rows = m1->rows;
	  cols = m1->cols;
	  matrix = m1->matrix;
    }
	
	//Destructor
	~Matrix() {
		delete[] matrix;
	}
	
	
	int getValue(int r, int c) const;
	void setValue(int r, int c, int v);
	void print(); 
	Matrix * transpose();
	
	Matrix * operator+ (const Matrix * m2);
	Matrix * operator* (int i);
	friend ostream& operator<< (ostream& strm, const Matrix * m);
	
};
