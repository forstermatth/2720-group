#ifndef __RATER_H
#define __RATER_H
#include "CourseCont.h"
#include "Course.h"
#include "Options.h"
class Rater{
private:
	Options* opts;
	CourseCont* cc;
	unsigned int rating;
public:
	Rater(Options* _opts, CourseCont* _cc);
	void rateCourses();
};

#endif
