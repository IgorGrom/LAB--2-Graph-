#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <iostream>
#include "Graph.h"
#include "DHeap.h"
#include "PrQueue.h"
#include "Set.h"

using namespace std;


template <typename TYPE>
class Algorithm 
{
	public:
		static Graph<TYPE>* Kruscal(Graph<TYPE>*&gr, PrQueue<TYPE>*& Q); // Алгоритм Краскала
		static TYPE* Deikstra(int, TYPE*&, Graph<TYPE>*&gr); // Алгоритм Дейкстры
		static void Pyramid_Sort(DHeap<TYPE>*&h); // Пирамидальная сортировка

};


template <typename TYPE>
void Algorithm<TYPE>::Pyramid_Sort(DHeap<TYPE>*&h)
{

	int ptr, tmp;
	ptr = h->GetSize();
	/*cout << ptr << endl;*/
	
		while (ptr > 0)
		{
			tmp = ptr - 1;
			h->Trans(0, tmp);
			ptr--;
			h->Pogruzh(0, ptr);
		}
}

template <typename TYPE>
Graph<TYPE>*Algorithm<TYPE>::Kruscal(Graph<TYPE>*&gr, PrQueue<TYPE>*& Q)
{
	int Num, RealLink;
	TYPE u, v;
	Num = gr->GetNodeNum(); //количество вершин
	RealLink = gr->GetLinkReal(); //число ребер
	Graph<TYPE> *ptr = new Graph<TYPE>(Num, RealLink);
	TYPE h;
	Set<TYPE> *s = new Set<TYPE>(Num);
	
	for (int i = 0; i < Num; i++)
	{
		s->CreateSet(i);
	}
	for (int i = 0; i < RealLink; i++)
	{
		h = gr->GetEdge(i)->GetWeight();
		Q->Push(h);
	}
	int TSize = 0;
	int z = 0;
	TYPE tmp, w;

	while (TSize < Num - 1)
	{
		tmp = Q->Pop();

		u = gr->GetEdge(z)->GetBegin();
		v = gr->GetEdge(z)->GetEnd();
		w = tmp;

		
		TYPE c = s->FindM(u);
		TYPE d = s->FindM(v);
		if (c != d)
		{
			s->UnionSet(c, d);
			ptr->Push(u, v, w);
			TSize++;

		}
		z++;

	}

	return ptr;

}

template <typename TYPE>
TYPE* Algorithm<TYPE>::Deikstra(int start, TYPE *&P, Graph<TYPE>*& gr)
{
	int n = gr->GetNodeNum();
	int m = gr->GetLinkReal();
	if ((start < 0) || (start >= n))
		throw " Неверно введены исходные параметры";

	TYPE **graph = new TYPE*[n];
	for (int i = 0; i < n; i++)
		graph[i] = new TYPE[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			graph[i][j] = -1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if ((gr->GetEdge(j)->GetBegin() == i) || (gr->GetEdge(j)->GetEnd() == i))
			{
				graph[gr->GetEdge(j)->GetBegin()][gr->GetEdge(j)->GetEnd()] = gr->GetEdge(j)->GetWeight();
				graph[gr->GetEdge(j)->GetEnd()][gr->GetEdge(j)->GetBegin()] = gr->GetEdge(j)->GetWeight();
			}
		}

	TYPE *dist = new TYPE[n]; 
	int *vis = new int[n]; 
	for (int i = 0; i < n; i++)
		vis[i] = -1;
	vis[0] = start;
	int pyt;
	int w, min;
	
	for (int i = 0; i<n; i++)
	{
		if (graph[start][i] == -1)
			dist[i] = Limit;
		else dist[i] = graph[start][i];
	}
	for (int i = 1; i < n - 1; i++)
	{
		min = Limit;
		for (int k = 0; k < n; k++) {
			if (dist[k] < min && k != start && !gr->Visit(k, vis))
			{
				w = k;
				min = dist[k];
			}
		}
		if (min == Limit) break;
		vis[i] = w;
		for (int j = 0; j < n; j++) {
			if (!gr->Visit(j, vis) && graph[w][j] != -1 && (dist[w] + graph[w][j]) <= dist[j])
			{
				P[j] = w;
				dist[j] = dist[w] + graph[w][j];
			}
		}
	}

	dist[start] = 0;
	return dist;
}






#endif