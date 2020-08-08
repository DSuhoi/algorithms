/*
 * bTreeAlgos.h
 * 
 * Copyright 2020 DSuhoi
 * 
 * Библиотека часто используемых функций и алгоритмов
 * для работы с бинарными деревьями. Функции ввода, 
 * вывода, заполнения, поиска и т.п.
 * (C library)
 */

#ifndef __BTREE_LIB_H__
#define __BTREE_LIB_H__


//*********************************
// Основные типы данных
//*********************************

typedef int TBase;	// искомая переменная (тип данных для массива и т.п.)
typedef int TCount;	// переменная для дополнительных данных (константные аргументы функций и т.п.)


//*********************************
// Основные константы
//*********************************
#define DELIM_CHR ' '	// символ разделитель
#define CARR_CHR '\n'	// символ перевода каретки
#define FORMAT_COMMAND "%4d"	// команда форматирования
#define FORMAT_COMMAND_CNT "%4d"	// команда форматирования для доп. данных


//******************************************************
// Основные константы для работы с бинарными деревьями
//******************************************************
#define MAX_BTREE_SIZE 1000	// максимальное кол-во узлов в дереве


//***************************************************
// Основные функции по работе с бинарными деревьями
//***************************************************

typedef struct BTreeNode{
	TBase value;
	BTreeNode* leftNode;
	BTreeNode* rightNode;
} BTreeNode;


// Создание узла дерева со значением value
BTreeNode* InitBTree(TBase newValue);

// Добавление узла со значением value в бинарное дерево с вершиной headNode
BTreeNode* PushBTree(BTreeNode* headNode, TBase newValue);

// Поиск узла со значением findValue в бинарном дереве с вершиной headNode
BTreeNode* FindBTree(BTreeNode* headNode, TBase findValue);

// Получение указателя на узел с наименьшим значением бинарного дерева с вершиной headNode
BTreeNode* GetMinBTree(BTreeNode* headNode);


#endif
