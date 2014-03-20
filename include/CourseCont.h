#ifndef __COURSECONT_H
#define __COURSECONT_H

#include "Course.h"
#include <list>
using namespace std;

class CourseCont {
public:
	void addCourse(Course _course);
	Course first();
	Course last();
	void next();
	void prev();
	Course getCourse();
	/*
		Sorts the list from highest to lowest rating.
	*/
	void sort();
private:
	list<Course> courses;
	list<Course>::iterator it;
};

/*
	returns true if first has a higher rating then second, false otherwise.
*/
bool compareCourseRating(const Course &first, const Course &second);

#endif