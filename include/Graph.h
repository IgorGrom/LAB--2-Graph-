#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <ctime>
#include <locale.h>
#include <cstdlib>
#include "Edge.h"
using namespace std;


template <typename TYPE>
class Graph
{
	private:
		int NodeNum; // ���������� ������
		int LinkNum; // ���������� ����
		int LinkReal; // �������� ���������� ����
		Edge<TYPE>** Elem;
	

	public:
		Graph(int NodeNum_, int LinkNum_); //�����������
		Graph(const Graph &G); // ����������� �����������
		~Graph(); // ����������
		void Push(int a, int b, TYPE c); // �������� �����
		Edge<TYPE>* GetEdge(int c); // ���������� ����� �����
		void Print(); // ����� ����� �� �����
		int GetNodeNum(); // ���������� ���������� ������
		int GetLinkNum(); // ���������� ���������� ����
		int GetLinkReal(); // ���������� �������� ���������� ����
		bool Visit(int a, int *b); // �������� �� ������ �������?!
		void Sort(); // ��������������
};

template <typename TYPE>
Graph<TYPE>::Graph(int NodeNum_ , int LinkNum_) 
{
	setlocale(LC_CTYPE, "russian");
	if (NodeNum_ < 0) {
		throw "������� ������� ���������!";
	}
	 NodeNum = NodeNum_;
	 LinkReal = 0;
	if ((LinkNum_ < 0) || (LinkNum_ > NodeNum*(NodeNum - 1) / 2)) 
		throw " ������� ������� �������� ���������";
	LinkNum = LinkNum_;
	Elem = new Edge<TYPE>*[LinkNum];

}

template <typename TYPE>
Graph<TYPE>::Graph(const Graph &G)
{
	NodeNum = G.NodeNum;
	LinkNum = G.LinkNum;
	Elem = new Edge<TYPE>*[LinkNum];
	for (int i = 0; i < LinkNum; i++)
	{
		Elem[i] = G.Elem[i];
	}

}
template <typename TYPE>
void Graph<TYPE>::Push(int a, int b, TYPE c)
{
	setlocale(LC_CTYPE, "russian");
	/*if (LinkReal == LinkNum) throw "�������� ����� ����������!";*/
	if ((a > NodeNum) || (b > NodeNum)) throw "������!";
	Elem[LinkReal] = new Edge<TYPE>(a,b,c);
	LinkReal++;
}


template <typename TYPE>
int Graph<TYPE>::GetNodeNum()
{
	return NodeNum;
}

template <typename TYPE>
int Graph<TYPE>::GetLinkNum()
{
	return LinkNum;
}

template <typename TYPE>
int Graph<TYPE>::GetLinkReal()
{
	return LinkReal;
}

template <typename TYPE>
Edge<TYPE>* Graph<TYPE>::GetEdge(int c)
{
	return Elem[c];
}

template <typename TYPE>
Graph<TYPE>::~Graph() {
	for (int i = 0; i < LinkNum; i++)
	{
		delete Elem[i];
		delete[] Elem;
	}
}



 template <typename TYPE>
 void Graph<TYPE>::Sort()
 {
	 Edge<TYPE> *tmp = new Edge<TYPE>(0, 0, 0);
	 for (int i = 0; i < LinkNum; i++)
	 {
		 for (int j = LinkNum - 1; j > i; j--)
		 { 
			 if (Elem[j]->GetWeight() < Elem[j - 1]->GetWeight())
			 {
				 tmp = Elem[j];
				 Elem[j] = Elem[j - 1];
				 Elem[j - 1] = tmp;
			 }
		 }
	 }
 
 }

 template <typename TYPE>
 bool Graph<TYPE>::Visit(int a, int* b)
 {
	 bool result = false;
	 for (int i = 0; i < NodeNum; i++)
		 if (b[i] == a)
			 result = true;
	 return result;
 }





template <typename TYPE>
void Graph<TYPE>::Print()
{
	setlocale(LC_CTYPE, "russian");
	cout << "��������� ������� -> �������� ������� ->(��� �����)" << endl << endl;
	 int i = 0;
	while (i < NodeNum)
	{ 
		cout << i << endl;
		for (int j = 0; j < LinkReal; j++)
		{
			if (Elem[j]->GetBegin() == i)
			{
				cout << Elem[j]->GetBegin() << "<->" << Elem[j]->GetEnd() << "  ��� " << Elem[j]->GetWeight() <<endl;

			}
		}
		i++;
	}
}
#endif