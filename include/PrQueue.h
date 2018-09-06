#ifndef PRQUEUE_H
#define PRQUEUE_H
#include <locale.h>
#include <iostream>
#include "DHeap.h"


using namespace std;

template <typename TYPE>
class PrQueue
{
	public:
		PrQueue(void) {}; // �����������
		virtual ~PrQueue() {}; // ����������
		virtual void Push(TYPE) = 0; // �������� ������� � ������������ �������
		virtual TYPE Pop() = 0; // �������� �������� � ������������ �����������
		virtual bool Is_Empty() = 0; // �������� �� �������
};

template <typename TYPE>
class DHeapBPQ: public PrQueue<TYPE>
{
private:
	DHeap<TYPE> *heap;
public:
	DHeapBPQ(int ar); // �����������
	virtual ~DHeapBPQ() { delete heap; }; // ����������
	void Push(TYPE x); //�������� �������
	bool Is_Empty(); // �������� �� �������
	TYPE Pop(); //  ������� ������� � ������������ �����������
	
};




template <typename TYPE>
DHeapBPQ<TYPE>::DHeapBPQ(int ar)
{
	setlocale(LC_CTYPE, "russian");
	if (ar <= 0) throw "������� ������� �������� ���������";
	heap = new DHeap<TYPE> (ar, 0);
}

template <typename TYPE>
bool DHeapBPQ<TYPE>::Is_Empty()
{
	return (heap->GetSize() == 0);

}

template <typename TYPE>
void DHeapBPQ<TYPE>::Push(TYPE x)
{
	/*setlocale(LC_CTYPE, "russian");*/
	heap->Insert(x);
	
}

template <typename TYPE>
TYPE DHeapBPQ<TYPE>::Pop()
{
	setlocale(LC_CTYPE, "russian");
	if (Is_Empty()) throw " ������� �����!!!";
	TYPE tmp = heap->MIN_Remove();
	return tmp;
}


#endif