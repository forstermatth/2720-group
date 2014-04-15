#ifndef __COURSE_H
#define __COURSE_H
#include "CourseBase.h"
#include "CourseCont.h"
#include "Lab.h"
#include "Exceptions.h"


/**
	\brief Course conceptual object - inherits from CourseBase
*/

class Course : public CourseBase {
public:

	/// Constructor - call the parent constructor
	Course() : CourseBase() {}

	/// Overloaded copy constructor to ensure proper assignment. Calls parent copy constructor.
	Course(const Course& _course) : CourseBase(_course) { labs = _course.labs; }

	/// Overloaded equals operator to ensure proper assignment. Calls parent operator.
	Course& operator= (const Course& _course);

	/// Constructor - call the parent constructor
	Course(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId) :
		CourseBase(_startTime, _endTime, _days, _courseName, _courseLoc, _courseId) {
		}

	CourseCont<Lab> labs;

private:
	
};


#endif
