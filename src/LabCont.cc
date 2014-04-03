#include "LabCont.h"
#include "Lab.h"
#include "Exceptions.h"
#include <iostream>

LabCont::LabCont(){
	it = labs.begin();
}

void LabCont::add(Lab _Lab){
	labs.push_back(_Lab);
}

Lab& LabCont::begin(){
	it = labs.begin();
	return *it;
}

Lab& LabCont::end(){
	it = labs.end();
	--it;
	return *it;
}

Lab& LabCont::first(){
	return *labs.begin();
}

Lab& LabCont::last(){
	return *(--labs.end());
}

void LabCont::next(){
	++it;
	if(it == labs.end()){
		it = labs.begin();
	}
}

Lab& LabCont::get(){
	if(labs.empty()){
		throw EmptyContainer();
	}
	if(it == labs.end()) throw UninitializedIterator();
	return *it;
}

void LabCont::prev(){
	if(it == labs.begin()){
		it = --labs.end();
	}else{
		--it;
	}
}

void LabCont::erase(){
	if(it == labs.end()) throw EmptyContainer();
	labs.erase(it);
}

void LabCont::sort(){
	labs.sort(compareLabRating);	
}
bool compareLabRating(const Lab &first, const Lab &second){
	return first.getRating() > second.getRating();
}

int LabCont::size(){
	return labs.size();
}	