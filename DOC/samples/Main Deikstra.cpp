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
		cout << " ��������  ��������!!!" << endl << endl;
		cout << " ������� ���������� ������ " << endl;
		cin >> edg;
		cout << " ������� ���������� �����" << endl;
		cin >> ver;

		Graph<int> *graph = new Graph<int>(edg, ver);
		int *arr = new int[edg];

		cout << " �������� ���� �������" << endl;
		for (int i = 0; i < ver; i++)
		{
			cout << "  ������ -> ���� ->( ��� ����� ) " << endl;
			cin >> b >> c >> d;
			graph->Push(b, c, d);
		}



		cout << endl;
		cout << " �������� ���� " << endl;
		graph->Print();

		cout << " ������� ����� ����� :" << endl;
		cin >> a;
		for (int i = 0; i <= edg; i++)
			arr[i] = a;
		int *dist = Algorithm<int>::Deikstra(a, arr, graph);
		cout << " ����� ������ ��������� �������� " << endl << endl;
		for (int i = 0; i < edg; i++)
			cout << i << ' ';
		cout << " ������ ������ " << endl << endl;
		for (int i = 0; i < edg; i++)
			if (dist[i] == Limit)
				cout << 0 << ' ';
			else
				cout << dist[i] << ' ';
		cout << " ���������� ���� " << endl << endl;
		for (int i = 0; i < edg; i++)
			cout << arr[i] << ' ';
		cout << "���������� ������� " << endl << endl;
	}
	catch (const char *exeption){
		cerr << exeption;
	}
	cout << endl;
	system("pause");
}