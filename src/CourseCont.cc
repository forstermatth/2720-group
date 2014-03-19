#include "CourseCont.h"
#include "Exceptions.h"

CourseCont::CourseCont(){
	it = courses.begin();
}

void CourseCont::addCourse(Course _course){
	courses.push_back(_course);
}

Course& CourseCont::first(){
	it = courses.begin();
	return *it;
}

Course& CourseCont::last(){
	it = courses.end();
	it--;
	return *it;
}

void CourseCont::next(){
	++it;
	if(it == courses.end()){
		it = courses.begin();
	}
}

Course& CourseCont::getCourse(){
	if(courses.empty()){
		throw EmptyContainer();
	}
	return *it;
}

void CourseCont::prev(){
	if(it == courses.begin()){
		it = courses.end();
	}else{
		--it;
	}
}