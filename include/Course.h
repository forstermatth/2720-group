#ifndef __COURSE_H
#define __COURSE_H
#include "CourseBase.h"
#include "Lab.h"
#include <list>

/**
	\brief Lab conceptual object - inherits from Course
*/
class Course : public CourseBase {
public:

	/// Constructor - call the parent constructor
	Course() : CourseBase() {}

	/// Constructor - call the parent constructor
	Course(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId) :
		CourseBase(_startTime, _endTime, _days, _courseName, _courseLoc, _courseId) {};

	void addLab(Lab _lab);
	Lab firstLab();

private:
	std::list<Lab> labs;
};


#endif