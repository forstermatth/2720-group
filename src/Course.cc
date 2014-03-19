#include "Course.h"
#include <string>
using namespace std;

Course::Course(unsigned int _startTime, unsigned int _endTime, string _days, string _courseName, string _courseLoc, unsigned int _courseId){
	startTime = _startTime;
	endTime = _endTime;
	days = _days;
	courseName = _courseName;
	courseLoc = _courseLoc;
	courseId = _courseId;
}

unsigned int const Course::getEndTime(){
	return endTime;
}

unsigned int const Course::getStartTime(){
	return startTime;
}

string const Course::getDays(){
	return days;
}

string const Course::getName(){
	return courseName;
}

string const Course::getLoc(){
	return courseLoc;
}

unsigned int const Course::getId(){
	return courseId;
}

void Course::setRating(unsigned int _rating){
	rating = _rating;
}

unsigned int const Course::getRating(){
	return rating;
}