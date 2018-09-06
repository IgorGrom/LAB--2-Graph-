#ifndef DHEAP_H
#define DHEAP_H
#include <iostream>
#include <locale.h>
#include <cmath>
#include <cstdlib>
#include "Graph.h"

#define Limit 1000

using namespace std;



template <typename TYPE>
class DHeap
{
	private:
		int size; // ���������� ��������� � ����
		int d; // �������  D-���� 
		TYPE* key; // ��������� �� ������ ������� ������� D-���� 
		int Min(int a, int b); // ���������� ������������ ��������
	public:
		DHeap(int arn, int count); // ����������� � ����������� (������� ����, ���������� ���������)
		DHeap(const DHeap &H); // ����������� �����������
		~DHeap(); // ����������
		void Trans(const int i, const int j); // ����������������
		int GetParent(int p); // ���������� ������ ��������
		void Vspl(int c); // ��������
		void Pogruzh(int d, int size); // ����������
		void Okuch(); // ����������
		int Minchild(int a, int size); // ��������� ������� �������� � ����������� ������
		TYPE MIN_Remove(); // ������� ��-�� � ����������� ������
		void Insert(TYPE b); // ������� ��������
		int GetSize(); // ���������� ���������� ��-��� � ����
		void Print(); // ����� �� �����
};

template <typename TYPE>
void DHeap<TYPE>::Insert(TYPE b)
{
	setlocale(LC_CTYPE, "russian");
	TYPE tmp = b;
	size++;
	key[size - 1] = tmp;
	Vspl(size - 1);
}




template <typename TYPE>
DHeap<TYPE>::DHeap(int arn, int count)
{
	setlocale(LC_CTYPE, "russian");
	if ((arn <= 0) || (count < 0) || (count > Limit))
		throw "������ ������� �������!";
		d = arn;
		size = count;
		key = new TYPE [Limit];
}


template <typename TYPE>
DHeap<TYPE>::DHeap(const DHeap&H)
{
	d = H.d;
	size = H.count;
	key = new TYPE [count];
	for (int i = 0; i < count ; i++)
	{
		key[i] = H.key[i];
	}

}

template <typename TYPE>
DHeap<TYPE>::~DHeap() {
	delete [] key;

}


template <typename TYPE>
int DHeap<TYPE>::Min(int a, int b)
{
	if (a <= b) return a;
	else return b;
}


template <typename TYPE>
int DHeap<TYPE>::GetParent(int p)
{
	int p1;
	p1 = (p - 1) / d;
	return p1;
}


template <typename TYPE>
void DHeap<TYPE>::Trans(const int i,const int j)
{
	setlocale(LC_CTYPE, "russian");
	if ((i < 0) || (j < 0))
	{
		throw " ������� ������� ���������!!";
	}
		TYPE tmp;
		tmp = key[i];
		key[i] = key[j];
		key[j] = tmp;
}

template <typename TYPE>
void DHeap<TYPE>::Vspl(int a) 
{
	setlocale(LC_CTYPE, "russian");
	if ((a >= size)||(a < 0)) throw " ��������� ����! ";
	int p;
	p = GetParent(a);
	while ((p >= 0) && ((key[p] >= key[a])))
	{
		
		if (p == 0)
		{
			Trans(p, a);
			return;
		}
		Trans(p, a);
		a = p;
		p = GetParent(a);
	}
	
}

template <typename TYPE>
int DHeap<TYPE>::Minchild(int a, int size)
{
	int minchild, maxchild;

	if (a*d+1 > size - 2) return -1; //���� 
   
	minchild = a*d + 1;
	maxchild = Min(a*d + d, (size - 1));
	for (int i = minchild; i <= maxchild; i++)
	{
		if (key[i] < key[minchild])
		{
			minchild = i;
		}

	}

	return minchild;
}

template <typename TYPE>
int DHeap<TYPE>::GetSize() 
{
	return size;
}


template <typename TYPE>
void DHeap<TYPE>::Pogruzh(int a, int size)
	{
	setlocale(LC_CTYPE, "russian");
	if (a < 0)
	{
		throw "��������!";
	}

		int c;
	c = Minchild(a, size);
	/*cout << c << endl;*/
	while (c != (-1) && (key[c] < key[a]))
		{
			Trans(c, a);
			a = c;
			c = Minchild(a, size);
		}
	}


template <typename TYPE>
void DHeap<TYPE>::Okuch()
{
	int i;
	i = size - 1;
	/*cout << i << endl;*/
	while (i >= 0)
	{
		Pogruzh(i);
		i--;
	}
	
}

template <typename TYPE>
TYPE DHeap<TYPE>::MIN_Remove() 
{
	    
	   TYPE tmp = key[0];
	   Trans(0, size - 1);
		size--;
		Pogruzh(0, size);
		return tmp;
}

template <typename TYPE>
void DHeap<TYPE>::Print()
{
	int i = 0;
	int k = 1;
	while (i < size) {
		while ((i < k) && (i < size)) {
			cout << key[i] <<" ";
			i++;
		}
		cout << endl;
		k = k * d + 1;
	}

}

#endif