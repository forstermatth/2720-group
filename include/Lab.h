#ifndef __LAB_H
#define __LAB_H
#include "CourseBase.h"


/**
	\brief Lab conceptual object - inherits from Course
*/
class Lab : public CourseBase {
public:

	///Constructor - call the parent constructor
	Lab() : CourseBase() {}

	Lab(const Lab& _lab) : CourseBase(_lab) {}

	///Constructor - call the parent constructor
	Lab(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId) :
		CourseBase(_startTime, _endTime, _days, _courseName, _courseLoc, _courseId) {};
private:

};


#endif