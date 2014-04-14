#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include "Course.h"
#include "Output.h"
#include "InputWrap.h"
#include "Rater.h"
#include "CourseSched.h"
#include "CourseCont.h"
#include "Options.h"

/** \class Scheduler
	Class wrapper to generate and return a schedule
*/
class Scheduler{
public:

	void grab(std::string inputfile);
	void work();
	void print();

	CourseSched generateSchedule(CourseCont<Course>& courseList, Options &opts);

private:

	std::string file;

	Output out;
	InputWrap in;
	Options ops;
	Rater* rate;
	CourseSched sched;
	CourseCont<Course> cont;
	
};

#endif