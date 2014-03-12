#ifndef __COURSECONT_H
#define __COURSECONT_H

#include "Course.h"
#include <list>
using namespace std;

class CourseCont {
public:
	void addCourse(Course _course);
	Course first();
private:
	list<Course> courses;
	list<Course>::iterator it;
};

#endif