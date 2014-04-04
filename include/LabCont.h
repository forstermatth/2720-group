#ifndef __LABCONT_H
#define __LABCONT_H

#include "Lab.h"
#include <list>
using namespace std;


/**
	\brief Course Container - used for storing courses in a size agnostic manner
*/
class LabCont {
public:

	/// Constructor - Initializes iterator
	LabCont();

	/// Adds a course to the container
	/** \param _course the course to add */
	void add(Lab _lab);

	/// Returns a reference to the first object
	Lab& first();

	/// Returns a reference to the last object
	Lab& last();

	/// Moves the iterator to the first element of the container and returns it a reference to that object
	/**
		Must be called after filling the container with objects, i.e. after parse.
	*/
	Lab& begin();

	/// Moves the iterator to the last element of the containter and returns it a reference to that object
	Lab& end();

	/// Move the iterator one forward. If last element, will move to the front.
	void next();

	/// Move the iterator one backward. If the first elemebt, wil move to the back.
	void prev();

	/// Sorts the list from highest to lowest rating.
	void sort();

	/// Return a reference to a course based on the current position of the iterator
	Lab& get();

	///Retuns the number of classes in the course container.
	int size();

	///Removes course at iterator location
	void erase();
protected:
	list<Lab> labs; ///< course container
	list<Lab>::iterator it; ///< course iterator
};

bool compareLabRating(const Lab &first, const Lab &second);


#endif