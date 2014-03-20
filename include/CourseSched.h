#ifndef __COURSESCHED_H
#define __COURSESCHED_H

#include "Course.h"
#include <list>
#include "Exceptions.h"
using namespace std;

class CourseSched{
public:
	void addCourse(Course _course);	//throws Exceptions
	void prev();
	void next();
	void removeCourse();
	Course getCourse();
	void findConflict(Course course);
	int compareDays(char, char);
private:
	list<Course> courses;
	list<Course>::iterator it;
};

#endif
