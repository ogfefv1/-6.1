//
//  Matrix.hpp
//  дз 6.1
//
//  Created by Егор Джемлиханов on 14.10.2024.
//

#pragma once
#include <iostream>

using namespace std;

class Point
{
public:
    int x, y;

    Point() : x(0), y(0) {}

    Point(int _x, int _y) : x(_x), y(_y) {}

    Point operator+(const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator*(const Point& p) const
    {
        return Point(x * p.x, y * p.y);
    }

    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

template <typename T>
class Matrix
{
    T** matrix;
    int rows, cols;

public:
    Matrix();
    Matrix(int _rows, int _cols);
    Matrix(const Matrix<T>& other);
    ~Matrix();

    Matrix<T> SumMatrix(const Matrix<T>& other);
    Matrix<T> MultiMatrix(const Matrix<T>& other);
    Matrix<T> TransposeMatrix();

    void Input();
    void Print() const;
    void SetElement(int row, int col, const T& value);
    T GetElement(int row, int col) const;
};

