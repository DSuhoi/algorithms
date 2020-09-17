/*
 * array_algos.hpp
 * 
 * Copyright 2020 DSuhoi
 * 
 * Библиотека часто используемых функций и алгоритмов
 * для работы с массивами. Функции ввода, вывода, сортировки
 * и т.п.
 * (C++ library)
 */

#ifndef __ARRAY_LIB_HPP__
#define __ARRAY_LIB_HPP__

#include <iostream>
#include <ctime>


//*********************************
// Основные константы
//*********************************
#define DELIM_CHR ' '           // символ разделитель


//********************************************
// Основные константы для работы с массивами
//********************************************
#define MAX_ARR_SIZE 1000       // максимальная длина массива
// Для заполнения массивов случайными числами раскомментируйте флаг
// и укажите диапазон для чисел RANDOM_RANGE
#define RANDOM_RANGE 100


//*****************************************
// Основные функции по работе с массивами
//*****************************************

// Выделение памяти под одномерный массив длины _len
// и возвращение указателя на начало массива
/*
 * Освобождение памяти:
 * delete [] arr;
 */
template <typename T>
T *initArr(const unsigned int _len)
{
    if((_len < 1) || (MAX_ARR_SIZE < _len))
        return nullptr;
    
    T *arr = new T [_len];
    
    #ifdef RANDOM_RANGE
        // Заполнение случайными числами
        srand(time(NULL));
        for(size_t i = 0; i < _len; i++)
            arr[i] = rand() % RANDOM_RANGE;
    #else
        // Обнуление элементов массива
        memset(arr, 0, _len);
    #endif
    
    return arr;
}

// Выделение памяти под двумерный массив (с _row кол-вом рядов и _column кол-вом слобцов)
// и возвращение указателя на начало массива
/*
 * Освобождение памяти:
 * delete [] arr[0];
 * delete [] arr;
 */
template <typename T>
T **initArr2(const unsigned int _row, const unsigned int _column)
{
    if(((_row * _column) < 1) || (MAX_ARR_SIZE < (_row * _column)))
        return nullptr;

    // Выделение памяти под указатели на указатели на элементы
    T **arr = new T* [_row];
    // Установка первого указателя
    arr[0] = new T [_row * _column];
    
    for(size_t row = 0; row < _row; row++) {
        // Установка следующих указателей
        arr[row] = arr[0] + _column*row;
        
    #ifdef RANDOM_RANGE
        // Заполнение случайными числами
        srand(time(NULL));
        for(size_t column = 0; column < _column; column++)
            arr[row][column] = rand() % RANDOM_RANGE;
    #else
        // Обнуление элементов массива
        memset(arr[row], 0, _column);
    #endif
    }
    
    return arr;
}


// Вывод _len элементов массива Arr
template <typename T>
void printArr(T *arr, const unsigned int _len)
{
    for(size_t i = 0; i < _len; i++)
        std::cout << arr[i] << DELIM_CHR;   // Вывод элемента и символа разделителя
    std::cout << std::endl;                 // Вывод символа перевода каретки
}

// Вывод _row строк и _column столбцов элементов массива Arr
template <typename T>
void printArr2(T **arr, const unsigned int _row, const unsigned int _column)
{
    for(size_t row = 0; row < _row; row++) {
        for(size_t column = 0; column < _column; column++)
            std::cout << arr[row][column] << DELIM_CHR; // Вывод элемента и символа разделителя
        std::cout << std::endl;                         // Вывод символа перевода каретки
    }
}


// Ввод элементов и длины массива (p_len - указатель на длину) и выделение памяти под него
template <typename T>
T *scanArr(unsigned int &p_len)
{
    std::cout << "Enter the length of the array: ";
    // Ввод длины массива и проверка вводимых данных
    do {
        std::cin >> p_len;
    } while(p_len < 0 || MAX_ARR_SIZE < p_len);
    // Выделение памяти под массив
    T *arr = initArr<T>(p_len);
    // Ввод элементов
    for(size_t i = 0; i < p_len; i++) {
        std::cout << "Enter the value [" << i << "] element: ";
        std::cin >> arr[i];
    }
    return arr;
}

// Ввод элементов, кол-ва строк и столбцов массива (p_row и p_column - указатели на кол-во строк и столбцов)
// и выделение памяти под него
template <typename T>
T **scanArr2(unsigned int &p_row, unsigned int &p_column)
{
    // Ввод кол-ва строк и столбцов и проверка вводимых данных
    std::cout << "Enter the number of rows in the array: ";
    do {
        std::cin >> p_row;
    } while(p_row < 0 || MAX_ARR_SIZE < p_row);
    
    std::cout << "Enter the number of rows in the array: ";
    do {
        std::cin >> p_column;
    } while(p_column < 0 || MAX_ARR_SIZE < p_column);
    
    T **arr = initArr2<T>(p_row, p_column);
    
    for(size_t row = 0; row < p_row; row++) {
        for(size_t column = 0; column < p_column; column++) {
            std::cout << "Enter the value [" << row << "][" << column << "] element: "; // Ввод элемента
            std::cin >> arr[row][column];
        }
        std::cout << std::endl; // Вывод символа перевода каретки
    }
    return arr;
}


// Сортировка по направлению sortVector (1 - по увеличению, 0 - по уменьшению) 
// элементов массива Arr в диапазоне [_left; _right] (вариант замены sort из стандартной библиотеки)
// Метод Ч.А.Р. Хоара (1962г)
template <typename T>
void quickSortArr(T *arr, const unsigned int _left, const unsigned int _right, bool sortVector)
{
    // Условие выхода из рекурсии
    if(_left>=_right)
        return;
    // Перемещение опорного элемента в левый край массива
    swapArr(arr, _left, (_left + _right)/2);
    // Сохранение индекса крайнего левого (опорного) элемента
    unsigned int lastLeft = _left;
    // Сортировка с учётом направления sortVector
    for(size_t index = _left+1; index<=_right; index++)
        if( (arr[index]<arr[_left] && sortVector==true) ||
            (arr[index]>arr[_left] && sortVector==false) )
            swapArr(arr, index, ++lastLeft);
    // Перемещение опорного элемента за сортируемую область
    swapArr(arr, _left, lastLeft);
    // Рекурсивный вызов сортировки элементов слудующих частей массива
    quickSortArr(arr, _left, lastLeft-1, sortVector);
    quickSortArr(arr, lastLeft+1, _right, sortVector);
}

// Замена местами элементов под индексами indexA и indexB массива Arr
template <typename T>
void swapArr(T *arr, const unsigned int indexA, const unsigned int indexB)
{
    T oldElement = arr[indexB];
    arr[indexB] = arr[indexA];
    arr[indexA] = oldElement;
}

#endif