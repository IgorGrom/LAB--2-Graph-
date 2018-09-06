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
		cout << " �������� ��������!!!" << endl << endl;
		
		cout << " D - ����" << endl;

		cout << " ������� ���������� ������ " << endl;
		cin >> ver;
		cout << " ������� ���������� �����" << endl;
		cin >> edg;

		Graph<int> *graph = new Graph<int>(ver, edg);

		cout << " �������� ���� �������" << endl;
		for (int i = 0; i < edg; i++)
		{
			cout << "  ������ -> ���� ->( ��� ����� ) " << endl;
			cin >> b >> c >> d;
			graph->Push(b, c, d);
		}



		cout << endl;
		cout << " �������� ���� " << endl;
		graph->Print();

		cout << "  ����� ������ ��������� ��������" << endl << endl;
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