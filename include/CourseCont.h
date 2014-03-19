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
	void sort();
private:
	list<Course> courses;
	list<Course>::iterator it;
};

bool compareCourseRating(const Course &first, const Course &second);

#endif