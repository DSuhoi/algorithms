/*
 * matrix_algos.h
 * 
 * Библиотека по работе с квадратными матрицами
 * (C++)
 */

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>

class Matrix {
private:
    // Указатель на указатели на элементы матрицы
    double **matrix;
    // Размерность матрицы
    unsigned int sizeMatrix;
    
    // Вычисление подматрицы
    double **getSubMatrix(double **_matrix, unsigned int size, unsigned int delim_x, unsigned int delim_y);
    // Вычисление определителя
    double procDeterm(double **_matrix, unsigned int size);
public:
    // Конструктор матрицы
    Matrix(unsigned int _size = 3);
    // Конструктор матрицы по двумерному массиву
    Matrix(double **_array, unsigned int _size);
    // Деструктор матрицы
    ~Matrix();
    // Фукнция получения определителя
    double getDeterm();
    // Получение размера матрицы
    unsigned char size();
    // Вывод матрицы
    void print(unsigned int _t = 5);
    // Ввод матрицы
    void scan();
    // Заполнение матрицы случайными числами
    void random(const long range = 1000);
    // Транспонирование матрицы
    void transpose();
    // Получение обратной матрицы
    void inverse();
    // Возвращение строки матрицы
    double *operator[](unsigned int _row);
    // Сложение матриц
    Matrix &operator+=(Matrix &matr);
};

#endif
