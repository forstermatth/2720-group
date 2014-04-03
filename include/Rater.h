#ifndef __RATER_H
#define __RATER_H
#include "CourseCont.h"
#include "Course.h"
#include "Options.h"
class Rater{

/** \class Rater
	\brief Rates all courses in the course container according to the user-set options.
*/
private:
	Options* opts; /// holds the user's options
	CourseCont* cc; /// holds all courses

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
	void processCourse(Course&);
	void processLab(Lab&);
};

#endif