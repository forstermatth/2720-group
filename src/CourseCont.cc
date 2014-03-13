#include "CourseCont.h"

void CourseCont::addCourse(Course _course){
	courses.push_back(_course);
}

Course CourseCont::first(){
	it = courses.begin();
	return *it;
}

Course CourseCont::last(){
	it = courses.end();
	it--;
	return *it;
}

void CourseCont::next(){
	++it;
}

Course CourseCont::getCourse(){
	return *it;
}

void CourseCont::prev(){
	--it;
}