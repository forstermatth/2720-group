#include "CourseCont.h"

void CourseCont::addCourse(Course _course){
	courses.push_back(_course);
}

Course CourseCont::first(){
	it = courses.begin();
	return *it;
}

Course CourseCont::last(){

}