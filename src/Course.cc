#include "Course.h"

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