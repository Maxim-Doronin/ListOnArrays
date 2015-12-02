#pragma once
#include <iostream>
typedef int valtype;

class List {
private:
	valtype* data;
	int* nextRefs;
	int maxSize;
public: 
	List(int maxSize = 100);
	~List();
	void print();
	void erase(valtype);
	int search(valtype);
	int searchFree();

	void insertAfter(valtype, valtype);
	void insertFirst(valtype);
	void insertLast(valtype);

	void insertInSort(valtype);
	valtype searchMax();
	void negative(List&);
};
