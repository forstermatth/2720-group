#include "Course.h"
#include "Exceptions.h"

void Course::labBegin(){
	it = labs.begin();
}

void Course::addLab(Lab _lab){
	labs.push_back(_lab);
}

Lab Course::firstLab(){
	std::list<Lab>::iterator iter = labs.begin();
	return *iter;
}

Lab Course::lastLab(){
	std::list<Lab>::iterator iter = labs.end();
	return *--iter;
}

void Course::nextLab(){
	it++;
	if( it == labs.end()){
		it--;
	}
}

void Course::prevLab(){
	if(it == labs.begin()){
		exit;
	}
	it--;
}

Lab Course::getLab(){
	if(labs.empty()){
		throw EmptyContainer();
	}
	return *it;
}

int Course::hasLab(){
	if(labs.empty()){
		return 0;
	}
	return 1;
}