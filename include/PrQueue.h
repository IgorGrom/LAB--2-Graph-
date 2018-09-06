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
		PrQueue(void) {}; // Конструктор
		virtual ~PrQueue() {}; // Деструктор
		virtual void Push(TYPE) = 0; // Положить элемент в приоритетную очередь
		virtual TYPE Pop() = 0; // Удаление элемента с максимальным приоритетом
		virtual bool Is_Empty() = 0; // Проверка на пустоту
};

template <typename TYPE>
class DHeapBPQ: public PrQueue<TYPE>
{
private:
	DHeap<TYPE> *heap;
public:
	DHeapBPQ(int ar); // Конструктор
	virtual ~DHeapBPQ() { delete heap; }; // Деструктор
	void Push(TYPE x); //Положить элемент
	bool Is_Empty(); // Проверка на пустоту
	TYPE Pop(); //  Удаляет элемент с максимальным приоритетом
	
};




template <typename TYPE>
DHeapBPQ<TYPE>::DHeapBPQ(int ar)
{
	setlocale(LC_CTYPE, "russian");
	if (ar <= 0) throw "Неверно введены исходные параметры";
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
	if (Is_Empty()) throw " Очередь пуста!!!";
	TYPE tmp = heap->MIN_Remove();
	return tmp;
}


#endif