#include "CourseCont.h"

void CourseCont::addCourse(Course _course){
	courses.push_front(_course);
}

Course CourseCont::first(){
	it = courses.begin();
	return *it;
}