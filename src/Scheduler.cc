#include "Course.h"
#include "CourseCont.h"
#include "Options.h"
#include "Scheduler.h"

#include <iostream>

CourseSched Scheduler::generateSchedule(CourseCont& courseList, Options &opts){
	CourseSched schedule;
	courseList.sort();
	courseList.begin();
	bool reachEnd = false;

	for(int i = 0; i < opts.getNumCourses() && !reachEnd;){
		reachEnd = courseList.getCourse().equal(courseList.last());
		try{
			Course add, comp;
			add = comp = courseList.getCourse(); //.addPadding(opts.getBreakPadding());
			comp.addPadding(opts.getBreakPadding());
			schedule.findConflict(&comp); //will throw and skip if conflict
			schedule.addCourse(add);
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