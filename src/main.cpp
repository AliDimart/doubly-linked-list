#include <iostream>
#include "deque.h"
#include "DLList.h"

int main()
{
	DLList<int> lst;

	lst.push_back(17);
	lst.push_back(10);
	lst.push_back(9);

	lst.Print();

	int a = 3;
	lst.insert(7, a);

	lst.Print();
	lst.InversePrint();

	lst.remove(a);

	lst.Print();
	lst.InversePrint();

	return 0;
}
