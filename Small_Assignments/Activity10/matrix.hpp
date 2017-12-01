
#include<iostream>


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
	
	
	~Matrix() {
		delete &rows;
		delete &cols;
		delete[] matrix;
		delete matrix;
	}
	
	int getValue(int r, int c);
	void setValue(int r, int c, int v);
	void display(); 
	
};
