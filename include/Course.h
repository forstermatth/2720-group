#ifndef __COURSE_H
#define __COURSE_H

#include <string>
using namespace std;

class Course {
public:
	Course(unsigned int _startTime, unsigned int _endTime, string _days, string _courseName, string _courseLoc, unsigned int _courseId);
	Course(){};

	int const getEndTime();
	int const getStartTime();
	string const getDays();
	string const getName();
	string const getLoc();
	int const getId();

private:
	unsigned int startTime;
	unsigned int endTime;
	string days;
	string courseName;
	string courseLoc;
	unsigned int courseId;

};

#endif