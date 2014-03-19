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

unsigned int Course::getEndTime() const{
	return endTime;
}

unsigned int Course::getStartTime() const{
	return startTime;
}

string Course::getDays() const{
	return days;
}

string Course::getName() const{
	return courseName;
}

string Course::getLoc() const{
	return courseLoc;
}

unsigned int Course::getId() const{
	return courseId;
}

void Course::setRating(unsigned int _rating){
	rating = _rating;
}

unsigned int Course::getRating() const{
	return rating;
}