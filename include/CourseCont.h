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

	/// Returns a reference to the first object
	Course& first();

	/// Returns a reference to the last object
	Course& last();

	/// Moves the iterator to the first element of the container and returns it a reference to that object
	Course& begin();

	/// Moves the iterator to the last element of the containter and returns it a reference to that object
	Course& end();

	/// Move the iterator one forward. If last element, will move to the front.
	void next();

	/// Move the iterator one backward. If the first elemebt, wil move to the back.
	void prev();
	
	/// Sorts the list from highest to lowest rating.
	void sort();

	/// Return a reference to a course based on the current position of the iterator
	Course& getCourse();

	///Retuns the number of classes in the course container.
	int size();
protected:
	list<Course> courses; ///< course container
	list<Course>::iterator it; ///< course iterator
};

/**
	returns true if first has a higher rating then second, false otherwise.
*/
bool compareCourseRating(const Course &first, const Course &second);

#endif