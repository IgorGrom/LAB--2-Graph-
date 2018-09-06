#include <iostream>
#include <locale.h>
#include <ctime>
#include "Algorithm.h"
#include "PrQueue.h"
#include "DHeap.h"
using namespace std;


void main()
{
	int a, b, c, edg, ver;
	float d;
	setlocale(LC_CTYPE, "russian");
	try{
		cout << " Алгоритм  Дейкстры!!!" << endl << endl;
		cout << " Введите количество вершин " << endl;
		cin >> edg;
		cout << " Введите количество ребер" << endl;
		cin >> ver;

		Graph<int> *graph = new Graph<int>(edg, ver);
		int *arr = new int[edg];

		cout << " Создадим Граф вручную" << endl;
		for (int i = 0; i < ver; i++)
		{
			cout << "  Откуда -> Куда ->( Вес ребра ) " << endl;
			cin >> b >> c >> d;
			graph->Push(b, c, d);
		}



		cout << endl;
		cout << " Исходный граф " << endl;
		graph->Print();

		cout << " Введите точку входа :" << endl;
		cin >> a;
		for (int i = 0; i <= edg; i++)
			arr[i] = a;
		int *dist = Algorithm<int>::Deikstra(a, arr, graph);
		cout << " После работы алгоритма ДЕЙКСТРЫ " << endl << endl;
		for (int i = 0; i < edg; i++)
			cout << i << ' ';
		cout << " Номера вершин " << endl << endl;
		for (int i = 0; i < edg; i++)
			if (dist[i] == Limit)
				cout << 0 << ' ';
			else
				cout << dist[i] << ' ';
		cout << " Кратчайшие пути " << endl << endl;
		for (int i = 0; i < edg; i++)
			cout << arr[i] << ' ';
		cout << "Предыдущие вершины " << endl << endl;
	}
	catch (const char *exeption){
		cerr << exeption;
	}
	cout << endl;
	system("pause");
}