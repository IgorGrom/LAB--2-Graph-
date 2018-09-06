#ifndef EDGE_H
#define EDGE_H
#include <iostream>
using namespace std;

template <typename TYPE>
class Edge{
	private:
		int Begin; // ��������� �������
		int End; // �������� ������� 
		TYPE Weight; // ��� �����
	public:
		Edge(int a, int b, TYPE c); // ����������� � �����������
		int GetBegin(); // ���������� ��������� �������
		int GetEnd(); //���������� �������� �������
		TYPE GetWeight(); // ���������� ��� �����

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