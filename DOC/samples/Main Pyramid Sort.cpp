#include <iostream>
#include <locale.h>
#include <ctime>
#include "Algorithm.h"
#include "PrQueue.h"
#include "DHeap.h"
using namespace std;

void main()
{
	int arnost, size, ptr;
	setlocale(LC_CTYPE, "russian");
	try{
		cout << " ÏÈÐÀÌÈÄÀËÜÍÀß ÑÎÐÒÈÐÎÂÊÀ !" << endl;
		cout << endl << "-----------------------" << endl;
		cout << "Ââåäèòå ÀÐÍÎÑÒÜ D-êó÷è" << endl;
		cin >> arnost;
		DHeap<int> *heap = new DHeap<int>(arnost, 0);
		cout << "Ââåäèòå êîëè÷åñòâî ýëåìåíòîâ â D-êó÷å: " << endl;
		cin >> size;
		srand(time(NULL));
		cout <<"------------------------------" <<endl;
		for (int i = 0; i < size; i++)
		{
			/*ptr = 1 + static_cast <int> (rand()) / (static_cast <int> (RAND_MAX / (100 - 1)));*/
			/*cout << ptr;*/
			cin >> ptr;
			heap->Insert(ptr);
		}
		cout << endl;
		cout << "------------------------------" << endl;
		cout << "Âû ââåëè èñõîäíóþ ÊÓ×Ó :" << endl;
		heap->Print();
		cout << "------------------------------" << endl;
		cout <<" Ïîñëå Ïèðàìèäàëüíîé Cîðòèðîâêè:"<< endl;
		Algorithm<int>::Pyramid_Sort(heap);
		/*heap ->Okuch();*/
		heap->Print();
	}
		catch (const char* exeption)
		{
		cerr << exeption << endl;
	}
		std::system("pause");
}