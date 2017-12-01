#include<iostream>
#include "matrix.hpp"

using std::cout;
using std::endl;
using std::ostream;

void Matrix::print() {
  for (int r=1; r<=rows; r++) {
	for (int c=1; c<=cols; c++) {
		int target = ( ((r-1) * cols) + c - 1 );
		cout << "\t" << matrix[target];
	}
	cout << endl;
  }
  cout << endl << endl;
}


int Matrix::getValue(int r, int c) const {
  int target = ( ((r-1) * cols) + c - 1 );
  return matrix[target];
}

void Matrix::setValue(int r, int c, int v) {
  if ( (r>=1) && (r<=rows) ) {
	  if ( (c>=1) && (c<=cols) ) {
		  int target = ( ((r-1) * cols) + c - 1 );
		  matrix[target] = v;
	  }
  }
}


Matrix* Matrix::transpose() {
	Matrix * temp = new Matrix(this->cols, this->rows);
	
	for (int r=1; r<=rows; r++) {
		for (int c=1; c<=cols; c++) {
			temp->setValue(r, c, this->getValue(c, r));
		}
    }
	
	return temp;
}

Matrix* Matrix::operator+ (const Matrix * m2) {
	if ( (this->rows == m2->rows) && (this->cols == m2->cols) ) {
		
		Matrix * temp = new Matrix(this->rows, this->cols);
		for (int r=1; r<=rows; r++) {
			for (int c=1; c<=cols; c++) {
				temp->setValue(r, c, (this->getValue(r,c) + m2->getValue(r,c)) );
			}
		}
		return temp;
	}
	else {
		return nullptr;
	}
}

Matrix* Matrix::operator* (int i) {
	Matrix * temp = new Matrix(this->rows, this->cols);
		for (int r=1; r<=rows; r++) {
			for (int c=1; c<=cols; c++) {
				temp->setValue(r, c, (this->getValue(r,c) * i) );
			}
		}
		return temp;
}


