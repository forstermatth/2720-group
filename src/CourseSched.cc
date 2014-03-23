#include "CourseSched.h"
#include "Lab.h"
#include <iostream>
#include <string>

void CourseSched::addCourse(Course _course){
	findConflict(_course);
	
	courses.push_back(_course);
	it = courses.begin();
}

void CourseSched::removeCourse(){
	if (courses.empty()){
		throw EmptyContainer();
	}
	it = courses.erase(it);
}

void CourseSched::findConflict(Course newCourse){
	int i = 0; //counter for new course
	int j = 0; //counter for existing course
	string newDays = newCourse.getDays(); //load days of the new course into newDays local variable
	for (std::list<Course>::iterator it=courses.begin() ; it != courses.end(); ++it) {
		string days = getCourse().getDays(); //load days of the existing course into days local variable
		int temp;
		do {
			if (newDays.at(i) != days.at(j)){ //if newCourse has the same day as course
				if(compareDays(newDays.at(i), days.at(j)) == 0){ //compare days to determine which counter to increment
					if (i<newDays.length()-1){
						temp=1;
						i++;
					}
					else{
						temp=0;
					}
				}
				else{
					if (j<days.length()-1){
						temp=1;
						j++;
					}
					else{		
						temp=0;
					}
				}
			}
			else //begin time conflict logic
			{
				temp = 0;
				if (newCourse.getStartTime() < getCourse().getStartTime()) //if new course starts before existing course
				{
					if (newCourse.getEndTime() > getCourse().getStartTime()) //if new course ends after existing course starts
					{
						throw TimeConflict();
					}
				}
				else
				{
					if (newCourse.getStartTime() < getCourse().getEndTime()) //if new course starts before existing course ends
					{
						throw TimeConflict();
					}
				}
			}
		}
		while (temp==1);
	}
}

/*
	Sets a numeric value to d1,d2 according to c1,c2 day of the week (M=1,T=2...)
	Compares d1 and d2, if d1 is earlier the week return 0, if d2 is earlier return 1
*/
int CourseSched::compareDays(char c1, char c2){
	int d1;
	int d2;
	if (c1 == 'M'){
		d1=1;}
	else if (c1 == 'T'){
		d1=2;}
	else if (c1 == 'W'){
		d1=3;}
	else if (c1 == 'R'){
		d1=4;}
	else{
		d1=5;}
	if (c2 == 'M'){
		d2=1;}
	else if (c2 == 'T'){
		d2=2;}
	else if (c2 == 'W'){
		d2=3;}
	else if (c2 == 'R'){
		d2=4;}
	else{
		d2=5;}
	if (d1 < d2)
		return 0;
	else
		return 1;
}

void CourseSched::addLab(Lab _lab){
	labs.push_back(_lab);
}

Lab& CourseSched::getLab(){
	return *labsit;
}

Lab& CourseSched::firstLab(){
	return labs.front();
}

Lab& CourseSched::lastLab(){
	return labs.back();
}

Lab& CourseSched::beginLab(){
	labsit = labs.begin();
	return labs.front();
}

void CourseSched::nextLab(){
	labsit++;
}

Lab& CourseSched::endLab(){
	labsit = --labs.end();
	return labs.back();
}

void CourseSched::prevLab(){
	labsit--;
}