#include "CourseSched.h"

void CourseSched::addCourse(Course _course){
	findConflict(&_course);
	courses.add(_course);
}

void CourseSched::addLab(Lab _lab){
	findConflict(&_lab);
	labs.add(_lab);
}

void CourseSched::findConflict(CourseBase* newCourse){
	string newDays = newCourse->getDays(); //load days of the new course into newDays local variable

	if(courses.size() != 0){
		Course course_ = courses.begin();
		do {
			//test for duplicate course first.
			if(newCourse->getName() == course_.getName()){
				throw DuplicateCourse();
			}

			int i = 0; //counter for new course
			int j = 0; //counter for existing course
			//load days of the existing course into days local variable
			string days = course_.getDays(); 
			int temp;
			do {
				//if newCourse has the same day as course
				if (newDays.at(i) != days.at(j)){ 
					//compare days to determine which counter to increment
					if(compareDays(newDays.at(i), days.at(j)) == 0){ 
						if (i<newDays.length()-1){
							temp=1;
							i++;
						}else{
							temp=0;
						}
					}else{
						if (j<days.length()-1){
							temp=1;
							j++;
						}else{		
							temp=0;
						}
					}
				}else{ //begin time conflict logic
					temp = 0;
					//if new course starts before existing course
					if (newCourse->getStartTime() < course_.getStartTime()){ 
						//if new course ends after existing course starts
						if (newCourse->getEndTime() > course_.getStartTime()){ 
							throw TimeConflict();
						}
					}else{
						//if new course starts before existing course ends
						if (newCourse->getStartTime() < course_.getEndTime()){ 
							throw TimeConflict();
						}
					}
				}
			}while (temp==1);
			courses.next();
			course_ = courses.get();
		}while (!course_.equal(courses.first()));
	}
	
	if(labs.size() != 0){
		Lab lab_ = labs.begin();
		do{
			int i = 0; //counter for new course
			int j = 0; //counter for existing course
			//load days of the existing course into days local variable
			string days = lab_.getDays(); 
			int temp;
			do {
				//if newCourse has the same day as course
				if (newDays.at(i) != days.at(j)){ 
					//compare days to determine which counter to increment
					if(compareDays(newDays.at(i), days.at(j)) == 0){ 
						if (i<newDays.length()-1){
							temp=1;
							i++;
						}else{
							temp=0;
						}
					}else{
						if (j<days.length()-1){
							temp=1;
							j++;
						}else{		
							temp=0;
						}
					}
				}else{ //begin time conflict logic
					temp = 0;
					//if new course starts before existing course
					if (newCourse->getStartTime() < lab_.getStartTime()){ 
						//if new course ends after existing course starts
						if (newCourse->getEndTime() > lab_.getStartTime()){ 
							throw TimeConflict();
						}
					}else{
						//if new course starts before existing course ends
						if (newCourse->getStartTime() < lab_.getEndTime()){ 
							throw TimeConflict();
						}
					}
				}
			}while (temp==1);

			labs.next();
			lab_ = labs.get();
		}while(!lab_.equal(labs.first()));
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
