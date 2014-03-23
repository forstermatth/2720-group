#ifndef __RATER_H
#define __RATER_H
#include "CourseCont.h"
#include "Course.h"
#include "Options.h"
class Rater{
private:
	Options* opts;
	CourseCont* cc;
public:
	/**
		Constructor 
		@param _opts Specific options set by the user
		@param _cc Course container that hold the entire set of courses that are to be rated
	*/
	Rater(Options* _opts, CourseCont* _cc);
	/**
		Looks at each course in the course container and gives them each a rating 
			according to the options.
	*/
	void rateCourses();
};

#endif