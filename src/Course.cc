#include "Course.h"
#include "Exceptions.h"

Course& Course::operator= (const Course& _course){

	this->CourseBase::operator=(_course);
	this->labs = _course.labs;

	return *this;
}


