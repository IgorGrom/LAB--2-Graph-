#ifndef EDGE_H
#define EDGE_H
#include <iostream>
using namespace std;

template <typename TYPE>
class Edge{
	private:
		int Begin; // Стартовая вершина
		int End; // Конечная вершина 
		TYPE Weight; // Вес ребра
	public:
		Edge(int a, int b, TYPE c); // Конструктор с параметрами
		int GetBegin(); // Возвращает стартовую вершину
		int GetEnd(); //Возвращает конечную вершину
		TYPE GetWeight(); // Возвращает вес ребра

};

template <typename TYPE>
Edge<TYPE>::Edge(int a, int b, TYPE c) 
{
	Begin = a;
	End = b;
	Weight = c;
}

template <typename TYPE>
int Edge<TYPE>::GetBegin(){
	return Begin;
}

template <typename TYPE>
int Edge<TYPE>::GetEnd() {
	return End;
}

template <typename TYPE>
TYPE Edge<TYPE>::GetWeight() {
	return Weight;
}

#endif