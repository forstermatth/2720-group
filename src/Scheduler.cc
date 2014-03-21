#include "Course.h"
#include "CourseCont.h"
#include "Options.h"
#include "Scheduler.h"

#include <iostream>

CourseSched* Scheduler::generateSchedule(CourseCont& courseList, Options &opts){
	CourseSched *schedule = new CourseSched;
	courseList.sort();
	courseList.begin();
	bool reachEnd = false;

	for(int i = 0; i < opts.getNumCourses() && !reachEnd;){
		reachEnd = courseList.getCourse().equal(courseList.last());
		try{
			courseList.getCourse().addPadding(opts.getBreakPadding());
			schedule->addCourse(courseList.getCourse());
			courseList.next();
			i++;
		}catch(const TimeConflict &expt){
			courseList.next();
		}catch(const EmptyContainer &epct){
			break;
		}
	}
	
	return schedule;
}