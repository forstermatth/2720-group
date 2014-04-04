#include "CourseCont.h"
#include "Course.h"
#include "Exceptions.h"
#include <iostream>

CourseCont::CourseCont(){
	it = courses.begin();
}

void CourseCont::add(Course _course){
	courses.push_back(_course);
}

Course& CourseCont::begin(){
	it = courses.begin();
	return *it;
}

Course& CourseCont::end(){
	it = courses.end();
	--it;
	return *it;
}

Course& CourseCont::first(){
	return *courses.begin();
}

Course& CourseCont::last(){
	return *(--courses.end());
}

void CourseCont::next(){
	++it;
	if(it == courses.end()){
		it = courses.begin();
	}
}

Course& CourseCont::get(){
	if(courses.empty()){
		throw EmptyContainer();
	}
	if(it == courses.end()) throw UninitializedIterator();
	return *it;
}

void CourseCont::prev(){
	if(it == courses.begin()){
		it = --courses.end();
	}else{
		--it;
	}
}

void CourseCont::erase(){
	if(it == courses.end()) throw EmptyContainer();
	courses.erase(it);
}

void CourseCont::sort(){
	courses.sort(compareCourseRating);	
}
bool compareCourseRating(const Course &first, const Course &second){
	return first.getRating() > second.getRating();
}


int CourseCont::size(){
	return courses.size();
}	