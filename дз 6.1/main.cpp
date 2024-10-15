//
//  main.cpp
//  дз 6.1
//
//  Created by Егор Джемлиханов on 14.10.2024.
//

#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main()
{
    Matrix<Point> mat1(2, 2);
    mat1.Input();
    mat1.Print();

    Matrix<Point> mat2(2, 2);
    mat2.Input();
    mat2.Print();

    Matrix<Point> sumMatrix = mat1.SumMatrix(mat2);
    sumMatrix.Print();

    Matrix<Point> multiMatrix = mat1.MultiMatrix(mat2);
    multiMatrix.Print();

    Matrix<Point> transposedMatrix = mat1.TransposeMatrix();
    transposedMatrix.Print();

    return 0;
}
