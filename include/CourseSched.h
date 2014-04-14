#ifndef __COURSESCHED_H
#define __COURSESCHED_H

#include "CourseBase.h"
#include "CourseCont.h"
#include "Course.h"
#include "Lab.h"
#include "Exceptions.h"
#include <string>
#include <list>
using namespace std;


/**
	Course Schedule Container
	Holds a created schedule, checks for time conflicts
*/
class CourseSched{
public:
	/// Add a course to the schedule. Checks for conflicts.
	/** \param _course the course to add */
	void addCourse(Course _course);
	void addLab(Lab _lab);

	/// find a time conflict
	/** \param course a course not yet in the schedule - compared to all that are */
	void findConflict(CourseBase* course);

	/**
	Sets a numeric value to d1,d2 according to c1,c2 day of the week (M=1,T=2...)
	Compares d1 and d2, if d1 is earlier the week return 0, if d2 is earlier return 1
	\param char the first character to compare
	\param char the second character to compare
	*/
	int compareDays(char, char);

	CourseCont<Course> courses;
	CourseCont<Lab> labs;

private:

};

#endif
