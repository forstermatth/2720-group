#ifndef __SCHEDULER_H
#define __SCHEDULER_H

#include "Course.h"
#include "CourseCont.h"
#include "CourseSched.h"

/** \class Scheduler
	Class wrapper to generate and return a schedule
*/
class Scheduler{
public:
	CourseSched generateSchedule(CourseCont& courseList, Options &opts);
};

#endif