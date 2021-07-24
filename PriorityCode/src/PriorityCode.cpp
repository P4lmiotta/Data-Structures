//============================================================================
// Name        : PriorityCode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "prioritycode.h"
using namespace std;

int main() {

	 PriorityCode<int> C;
	 C.inserisci(1);
	 C.inserisci(12);
	 C.inserisci(19);
	 C.inserisci(7);
	 C.print();

	 cout << "Minimo: " << C.min() << endl;

	 C.cancellaMin();
	 cout << "Coda dopo aver cancellato il minimo:" << endl;
	 C.print();

	 C.inserisci(0);
	 cout << "---------------" << endl;
	 C.print();



	return 0;
}
