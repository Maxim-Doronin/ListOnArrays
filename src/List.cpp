#include "List.h"

List::List(int maxSize){
	this->maxSize = maxSize;
	data = new valtype [maxSize];
	nextRefs = new int [maxSize];
	nextRefs[0] = 0;
	nextRefs[1] = -1;
	for (int i = 2; i < maxSize; i++)
		nextRefs[i] = 1;
}

List::~List(){
	delete []data;
	delete []nextRefs;
}

void List::print(){
	int i = nextRefs[0];
	while (i != 0){
		std::cout << data[i] << std::endl;
		i = nextRefs[i];
	}
}

void List::erase(valtype key){
	int i = nextRefs[0];
	int prev = 0;
	while ((i != 0)&&(data[i] != key)){
		prev = i;
		i = nextRefs[i];
	}
	if (i == 0) throw "Not find";
	nextRefs[prev] = nextRefs[i];
	nextRefs[i]    = 1;
}

int List::search(valtype key){
	int i = nextRefs[0];
	while((i != 0)&&(data[i] != key))
		i = nextRefs[i];
	if (i == 0) return -1;
	return i;
}

int List::searchFree(){
	int freeIdx = -1;
	for (int i = 2; i<maxSize; i++)
		if (nextRefs[i] == 1) {
			freeIdx = i;
			return freeIdx;
		}
	if (freeIdx == -1) throw "No memory";
}

void List::insertAfter(valtype elem, valtype key){
	int i = search(elem);
	if (i == -1) throw "Not find";
	int freeIdx = searchFree();
	data[freeIdx] = key;
	nextRefs[freeIdx] = nextRefs[i];
	nextRefs[i] = freeIdx;
}

void List::insertLast(valtype key){
	int freeIdx = searchFree();
	int i = nextRefs[0];
	while (i != 0)
		i = nextRefs[i];
	data[freeIdx] = key;
	nextRefs[i] = freeIdx;
	nextRefs[freeIdx] = 0;
}