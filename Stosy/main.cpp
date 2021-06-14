#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include "TStack.hpp"
#include "LStack.hpp"

using namespace std;

int main()
{
	string fileName = "data.txt";
	bool print = true;
	unsigned int stackSize = 1000;

	clock_t start, stop, time_1, time_2;

	StackTab<int> stos_1(stackSize);
	StackList<int> stos_2;
	

	start = clock();

	for (unsigned int i = 0; i < stos_1.maxSize(); i++)
		stos_1.push(pow(i, 2));

	if (print)
		stos_1.print();
	stos_1.clear();
	if (print)
		stos_1.print();

	for (unsigned int i = 0; i < stos_1.maxSize() / 2; i++)
		stos_1.push(pow(i, 3));

	while (stos_1.curSize() > 0) {
		if (print)
		{
			cout << stos_1.pop() << endl;
		}
		else
			stos_1.pop();
	}
	
	stop = clock();
	time_1 = 1000000 * (stop - start) / (float)CLOCKS_PER_SEC;


	printf("*********************\n");

	stos_2.print();
	start = clock();

	for (unsigned int i = 0; i < stackSize; i++)
		stos_2.push(pow(i, 2));

	if (print)
		stos_2.print();
	stos_2.clear();
	if (print)
		stos_2.print();
	for (unsigned int i = 0; i < stackSize / 2; i++)
		stos_2.push(pow(i, 3));

	while (stos_2.size() > 0) 
	{
		if (print) 
		{
			cout << stos_2.pop() << endl;
		}
		else
			stos_2.pop();
	}

	stop = clock();
	time_2 = 1000000 * (stop - start) / (float)CLOCKS_PER_SEC;

	cout << "Czas tab 1: " << time_1 << " us" << endl;
	cout << "Czas list 2: " << time_2 << " us" << endl;

	/*****************************************************/
	fstream file(fileName, fstream::out);

	file << "Czas tab 1: " << time_1 << " us" << endl;
	file << "Czas list 2: " << time_2 << " us" << endl;

	file.close();
}

