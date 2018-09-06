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
		int count; // ������
		int *height; // ������
		int *parent; // ��������� �� ��������
	public:
		Set(int a); // ����������� � �����������
		~Set(); // ����������
		void CreateSet(int a); // �������� ��������������� ���������
		TYPE FindM(TYPE a); // � ������ ��������� ����������� �������
		void UnionSet(TYPE a, TYPE b); // ����������� ��������
		
};


template <typename TYPE>
Set<TYPE>::Set(int a)
{
	setlocale(LC_CTYPE, "russian");
	if (a <= 0) throw "������ ������� �������!";
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
	if ((a < 0) || (a > count)) throw  "������� ������� �������� ���������!";
	if (parent[a] != (-1)) return;
	parent[a] = a;
	height[a] = 0;
}

template <typename TYPE>
TYPE Set<TYPE>:: FindM(TYPE a)
{
	setlocale(LC_CTYPE, "russian");
	if ((a < 0) || (a > count)) throw  "������� ������� �������� ���������!";
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
	if (((a < 0) || (a > count)) || ((b < 0) || (b > count))) throw  "������� ������� �������� ���������!";
	if ((parent[a] == (-1)) || (parent[b] == (-1)))
	{
		throw " ������ ���������!";
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