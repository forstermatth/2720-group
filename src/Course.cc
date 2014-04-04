#include "Course.h"
#include "Exceptions.h"

void Course::addPadding(unsigned int _padding){
	startTime -= _padding;
	endTime += _padding;

}

Course& Course::operator= (const Course& _course){

	this->CourseBase::operator=(_course);
	this->labs = _course.labs;

	return *this;
}


