// Secret Abstract base class

#include<iostream>

using std::string;


class Matrix {
  public:
	int rows;
	int cols;
	  
    Matrix(int r, int c)
    {
      rows = r;
	  cols = c;
	  int matrix[rows * cols];
    }
	
	
	~Matrix() {
		delete &rows;
		delete &cols;
		delete[] &matrix;
	}
	
	int getValue(int r, int c);
	void setValue(int r, int c);
	void display(); 
	
};
