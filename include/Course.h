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

	Course(const Course& _course) : CourseBase(_course) { labs = _course.labs; it = _course.it; }

	Course& operator= (const Course& _course);

	/// Constructor - call the parent constructor
	Course(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId) :
		CourseBase(_startTime, _endTime, _days, _courseName, _courseLoc, _courseId) {
			it = labs.begin();
		};

	void addLab(Lab _lab);
	Lab firstLab();
	void labBegin();
	Lab lastLab();
	void nextLab();
	void prevLab();
	Lab getLab();
	int hasLab();
	int labsize();

	/// returns true if the courses are the same, false otherwise
	/** \param crs the course to compare against */
	bool equal(Course& crs);

	/// Adds the specified amount of padding to start and end time.
	/** \param _padding The amount of padding to add.*/
	void addPadding(unsigned int _padding);

private:
	std::list<Lab> labs;
	std::list<Lab>::iterator it;
};


#endif