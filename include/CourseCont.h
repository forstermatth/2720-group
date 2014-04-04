#ifndef __COURSECONT_H
#define __COURSECONT_H


#include "Exceptions.h"
#include <list>
using namespace std;


/**
	\brief Course Container - used for storing courses in a size agnostic manner
*/
template <class T>
class CourseCont {
public:

	/// Constructor - Initializes iterator
	CourseCont(){
		it = courses.begin();
	}

	/// Adds a course to the container
	/** \param _course the course to add */
	void add(T _course){
		courses.push_back(_course);
	}

	/// Returns a reference to the first object
	T& first(){
		return *courses.begin();
	}

	/// Returns a reference to the last object
	T& last(){
		return *(--courses.end());
	}

	/// Moves the iterator to the first element of the container and returns it a reference to that object
	/**
		Must be called after filling the container with objects, i.e. after parse.
	*/
	T& begin(){
		it = courses.begin();
		return *it;
	}

	/// Moves the iterator to the last element of the containter and returns it a reference to that object
	T& end(){
		it = courses.end();
		--it;
		return *it;
	}

	/// Move the iterator one forward. If last element, will move to the front.
	void next(){
		++it;
		if(it == courses.end()){
			it = courses.begin();
		}
	}

	/// Move the iterator one backward. If the first elemebt, wil move to the back.
	void prev(){
		if(it == courses.begin()){
			it = --courses.end();
		}else{
			--it;
		}
	}
	
	void erase(){
		if(it == courses.end()) throw EmptyContainer();
		courses.erase(it);
	}

	/// Sorts the list from highest to lowest rating.
	void sort(){
		courses.sort(compareRating);	
	}


	/// Return a reference to a course based on the current position of the iterator
	T& get(){
		if(courses.empty()){
			throw EmptyContainer();
		}
		if(it == courses.end()) throw UninitializedIterator();
		return *it;
	}

	///Retuns the number of classes in the course container.
	int size(){
		return courses.size();
	}	

private:
	typename std::list<T> courses; ///< course container
	typename std::list<T>::iterator it; ///< course iterator

	static bool compareRating(const T &first, const T &second){
		return first.getRating() > second.getRating();
	}
};

#endif