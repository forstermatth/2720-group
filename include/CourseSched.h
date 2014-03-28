#ifndef __COURSESCHED_H
#define __COURSESCHED_H

#include "Course.h"
#include <list>
#include "Exceptions.h"
#include "CourseCont.h"
#include "Lab.h"
using namespace std;


/**
	Course Schedule Container
	Holds a created schedule, checks for time conflicts
*/
class CourseSched : public CourseCont{
public:
	/// Add a course to the schedule. Checks for conflicts.
	/** \param _course the course to add */
	void addCourse(Course _coursem, int padding = 0);

	/// remove the current course from the container
	void removeCourse();

	/// find a time conflict
	/** \param course a course not yet in the schedule - compared to all that are */
	void findCourseConflict(Course course, int padding = 0);

	/// find a lab time conflict
	/** \param lab a lab not yet in the schedule*/
	void findLabConflict(Lab lab);

	/**
	Sets a numeric value to d1,d2 according to c1,c2 day of the week (M=1,T=2...)
	Compares d1 and d2, if d1 is earlier the week return 0, if d2 is earlier return 1
	\param char the first character to compare
	\param char the second character to compare
	*/
	int compareDays(char, char);

	/// Adds a lab.
	void addLab(Lab _lab);

	///gets the current lab
	Lab& getLab();

	Lab& firstLab();

	Lab& lastLab();

	/// Moves the iterator to the first element of the container and returns it a reference to that object
	/**
		Must be called after filling the container with objects, e.g. after parse.
	*/
	Lab& beginLab();

	/// Move the iterator one forward. If last element, will move to the front.
	void nextLab();

	///Moves the lab iterator to the end of the list and returns a reference to the lab
	Lab& endLab();

	///Move the iterator one backward. If last element, will move to the end.
	void prevLab();

private:
	list<Lab> labs;
	list<Lab>::iterator labsit;
};

#endif
