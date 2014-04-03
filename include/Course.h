#ifndef __COURSE_H
#define __COURSE_H
#include "CourseBase.h"
#include "Lab.h"
#include <list>

/**
	\brief Course conceptual object - inherits from CourseBase
*/
class Course : public CourseBase {
public:

	/// Constructor - call the parent constructor
	Course() : CourseBase() {}

	/// Overloaded copy constructor to ensure proper assignment. Calls parent copy constructor.
	Course(const Course& _course) : CourseBase(_course) { labs = _course.labs; it = _course.it; }

	/// Overloaded equals operator to ensure proper assignment. Calls parent operator.
	Course& operator= (const Course& _course);

	/// Constructor - call the parent constructor
	Course(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId) :
		CourseBase(_startTime, _endTime, _days, _courseName, _courseLoc, _courseId) {
			it = labs.begin();
		};

	/// Add a lab to the course
	/* \param _lab The lab to add */
	void addLab(Lab _lab);

	/// Return the first lab - moves the lab iterator to the beginning of the list permanently
	Lab& firstLab();

	/// Moves the iterator to the beginning of the lab list
	void labBegin();

	/// Returns the last lab - moves the iterator to the end of the list
	Lab& lastLab();

	/// Moves the iterator to the next lab on the list
	void nextLab();

	/// Moves the iterator to the previous lab on the list
	void prevLab();

	/// Returns the lab that the current iterator is pointing to
	Lab& getLab();

	/// checks to see if there are labs attached to the course, returns 1 or 0
	int hasLab();

	/// returns the amount of labs the class has attached
	int labsize();

	/// returns true if the courses are the same, false otherwise
	/** \param crs the course to compare against */
	bool equal(Course& crs);

	/// Adds the specified amount of padding to start and end time.
	/** \param _padding The amount of padding to add.*/
	void addPadding(unsigned int _padding);

private:
	std::list<Lab> labs; ///< the labs container
	std::list<Lab>::iterator it; ///< the labs iterator
};


#endif