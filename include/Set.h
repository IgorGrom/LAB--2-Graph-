#ifndef SET_H
#define SET_H
#include <iostream>
#include <stack>
#include <locale.h>
#include <cstdlib>
#include "DHeap.h"
using namespace std;


template <typename TYPE>
class Set{
	private:
		int count; // Размер
		int *height; // Высота
		int *parent; // Указатель на родителя
	public:
		Set(int a); // Конструктор с параметрами
		~Set(); // Деструктор
		void CreateSet(int a); // Создание одноэлементного множества
		TYPE FindM(TYPE a); // К какому множеству принадлежит элемент
		void UnionSet(TYPE a, TYPE b); // Объединение множеств
		
};


template <typename TYPE>
Set<TYPE>::Set(int a)
{
	setlocale(LC_CTYPE, "russian");
	if (a <= 0) throw "Данные введены неверно!";
	parent = new int[a];
	for (int i = 0; i < a; i++)
		parent[i] = -1;
	height = new int [a];
	count = a;
}

template <typename TYPE>
Set<TYPE>::~Set()
{
	delete[] parent;
	delete[] height;

}

template <typename TYPE>
void Set <TYPE>::CreateSet(int a)
{
	setlocale(LC_CTYPE, "russian");
	if ((a < 0) || (a > count)) throw  "Неверно введены исходные параметры!";
	if (parent[a] != (-1)) return;
	parent[a] = a;
	height[a] = 0;
}

template <typename TYPE>
TYPE Set<TYPE>:: FindM(TYPE a)
{
	setlocale(LC_CTYPE, "russian");
	if ((a < 0) || (a > count)) throw  "Неверно введены исходные параметры!";
	if (parent[a] == (-1)) return -1;
	while (parent[a]!=a)
	{
		a = parent[a];

 }
	return a;
}

template <typename TYPE>
void Set<TYPE>::UnionSet(TYPE a, TYPE b)
{
	setlocale(LC_CTYPE, "russian");
	if (((a < 0) || (a > count)) || ((b < 0) || (b > count))) throw  "Неверно введены исходные параметры!";
	if ((parent[a] == (-1)) || (parent[b] == (-1)))
	{
		throw " Пустое множество!";
	}
	a = FindM(a);
	b = FindM(b);
	if (height[a] > height[b])
		parent[b] = a;
	else if (height[a] < height[b])
		parent[a] = b;
	else {
		parent[b] = a;
		height++;
	}

}




#endif