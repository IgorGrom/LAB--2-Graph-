#include <iostream>
#include <locale.h>
#include <ctime>
#include "Algorithm.h"
#include "PrQueue.h"
#include "DHeap.h"
using namespace std;


void main()
{
	int  b, c, edg, ver;
	float d;
	setlocale(LC_CTYPE, "russian");
	try{
		cout << " Алгоритм Краскола!!!" << endl << endl;
		
		cout << " D - КУЧА" << endl;

		cout << " Введите количество вершин " << endl;
		cin >> ver;
		cout << " Введите количество ребер" << endl;
		cin >> edg;

		Graph<int> *graph = new Graph<int>(ver, edg);

		cout << " Создадим Граф вручную" << endl;
		for (int i = 0; i < edg; i++)
		{
			cout << "  Откуда -> Куда ->( Вес ребра ) " << endl;
			cin >> b >> c >> d;
			graph->Push(b, c, d);
		}



		cout << endl;
		cout << " Исходный граф " << endl;
		graph->Print();

		cout << "  После работы алгоритма КРАСКОЛА" << endl << endl;
		Graph<int> *result = new Graph<int>(ver, edg);
		graph->Sort();


		PrQueue<int> *queue = new DHeapBPQ<int>(edg);

		result = Algorithm<int>::Kruscal(graph, queue);
		cout << endl << endl;
		result->Print();
	}
	catch (const char *exeption){
		cerr << exeption;
	}
	cout << endl;
	system("pause");
}