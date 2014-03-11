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

int const Course::getEndTime(){
	return 1500;
}

int const Course::getStartTime(){
	return 1115;
}