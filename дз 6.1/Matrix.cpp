//
//  Matrix.cpp
//  дз 6.1
//
//  Created by Егор Джемлиханов on 14.10.2024.
//

#include "Matrix.hpp"
#include <iostream>

using namespace std;

template <typename T>
Matrix<T>::Matrix() : rows(0), cols(0), matrix(nullptr) {}

template <typename T>
Matrix<T>::Matrix(int _rows, int _cols) : rows(_rows), cols(_cols)
{
    matrix = new T*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new T[cols] {T()};
    }
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols)
{
    matrix = new T*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new T[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

template <typename T>
Matrix<T>::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename T>
Matrix<T> Matrix<T>::SumMatrix(const Matrix<T>& other)
{
    if (rows != other.rows || cols != other.cols)
    {
        cout << "Матрицы разных размеров, сложение невозможно!" << endl;
        return *this;
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::MultiMatrix(const Matrix<T>& other)
{
    if (cols != other.rows)
    {
        cout << "Умножение невозможно: количество столбцов первой матрицы не равно количеству строк второй!" << endl;
        return *this;
    }

    Matrix<T> result(rows, other.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            result.matrix[i][j] = T();
            for (int k = 0; k < cols; k++)
            {
                result.matrix[i][j] = result.matrix[i][j] + (matrix[i][k] * other.matrix[k][j]);
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::TransposeMatrix()
{
    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.matrix[j][i] = matrix[i][j];
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::Input()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = T(rand() % 10, rand() % 10);  // Для Point
        }
    }
}

template <typename T>
void Matrix<T>::Print() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

template <typename T>
void Matrix<T>::SetElement(int row, int col, const T& value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        matrix[row][col] = value;
    }
    else
    {
        cout << "Некорректный индекс!" << endl;
    }
}

template <typename T>
T Matrix<T>::GetElement(int row, int col) const
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return matrix[row][col];
    }
    else
    {
        cout << "Некорректный индекс!" << endl;
        return T();
    }
}

