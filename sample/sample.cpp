#include "List.h"
#include <iostream>
using namespace std;

int main(){

	List list;

	for (int i = -31; i < 50; i += 5) {
		list.insertLast(i);
	}
	list.print();

	list.insertInSort(27);
	list.print();

	
	cout << "max = " << list.searchMax() << endl;

	List negList;
	list.negative(negList);
	
	negList.print();



	return 0;
}