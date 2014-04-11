#include "CourseCont.h"
#include "Course.h"
#include "Exceptions.h"
#include <iostream>

template <class T> CourseCont<T>::CourseCont(){
	it = courses.begin();
}

template <class T> void CourseCont<T>::add(T _course){
	courses.push_back(_course);
}

template <class T> T& CourseCont<T>::begin(){
	it = courses.begin();
	return *it;
}

template <class T> T& CourseCont<T>::end(){
	it = courses.end();
	--it;
	return *it;
}

template <class T> T& CourseCont<T>::first(){
	return *courses.begin();
}

template <class T> T& CourseCont<T>::last(){
	return *(--courses.end());
}

template <class T> void CourseCont<T>::next(){
	++it;
	if(it == courses.end()){
		it = courses.begin();
	}
}

template <class T> T& CourseCont<T>::get(){
	if(courses.empty()){
		throw EmptyContainer();
	}
	if(it == courses.end()) throw UninitializedIterator();
	return *it;
}

template <class T> void CourseCont<T>::prev(){
	if(it == courses.begin()){
		it = --courses.end();
	}else{
		--it;
	}
}

template <class T> void CourseCont<T>::erase(){
	if(it == courses.end()) throw EmptyContainer();
	courses.erase(it);
}

template <class T> void CourseCont<T>::sort(){
	courses.sort(compareRating<T>);	
}

template <class T> bool compareRating(const T &first, const T &second){
	return first.getRating() > second.getRating();
}

template <class T> int CourseCont<T>::size(){
	return courses.size();
}	