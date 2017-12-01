#include<iostream>
#include "matrix.hpp"

using std::cout;
using std::endl;

int main() {
  Matrix * mat1 = new Matrix(4, 4);
  mat1->setValue(3, 3, 33);
  mat1->setValue(2, 3, 23);
  mat1->setValue(2, 1, 21);
  mat1->setValue(4, 1, 41);
  cout << "Matrix 1:" << endl;
  mat1->print();
  
  Matrix * mat2 = mat1->transpose();
  cout << "Matrix 2 is the transpose of Matrix 1:" << endl;
  mat2->print();
  
  Matrix * mat3 = *mat1 + mat2;
  cout << "Matrix 3 is Matrix 1 + Matrix 2:" << endl;
  mat3->print();
  
  Matrix * mat4 = *mat3 * 2;
  cout << "Matrix 4 is Matrix 3 * 2:" << endl;
  mat4->print();
  
  
  cout << "Stream injection of Matrix 4:" << mat4;
  return 0;
}

ostream& operator<< (ostream& strm, const Matrix * m) {
  strm << endl;
  for (int r=1; r<=m->rows; r++) {
	for (int c=1; c<=m->cols; c++) {
		strm << "\t" << m->getValue(r,c);
	}
	strm << endl;
  }
  strm << endl << endl;
  return strm;
}