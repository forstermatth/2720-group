#ifndef __COURSECONT_H
#define __COURSECONT_H

#include "Course.h"
#include <list>
using namespace std;

class CourseCont {
public:

	CourseCont();

	void addCourse(Course _course);
	Course& first();
	Course& last();
	void next();
	void prev();
	Course& getCourse();
private:
	list<Course> courses;
	list<Course>::iterator it;
};

#endif