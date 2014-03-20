#ifndef __COURSECONT_H
#define __COURSECONT_H

#include "Course.h"
#include <list>
using namespace std;


/**
	\brief Course Container - used for storing courses in a size agnostic manner
*/
class CourseCont {
public:

	/// Constructor - Initializes iterator
	CourseCont();

	/// Adds a course to the container
	/** \param _course the course to add */
	void addCourse(Course _course);

	/// Moves the iterator to the first element of the container and returns it a reference to that object
	Course& first();

	/// Moves the iterator to the last element of the containter and returns it a reference to that object
	Course& last();

	/// Move the iterator one forward. If last element, will move to the front.
	void next();

	/// Move the iterator one backward. If the first elemebt, wil move to the back.
	void prev();

	/// Return a reference to a course based on the current position of the iterator
	Course& getCourse();

protected:
	list<Course> courses; ///< course container
	list<Course>::iterator it; ///< course iterator
};

#endif