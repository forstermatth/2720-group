#include "Course.h"
#include "CourseCont.h"
#include "Options.h"
#include "Scheduler.h"

#include <iostream>

CourseSched Scheduler::generateSchedule(CourseCont<Course>& courseList, Options &opts){
	CourseSched schedule;
	courseList.sort();
	courseList.begin();
	bool reachEnd = false;

	for(int i = 0; i < opts.getNumCourses() && !reachEnd;){
		reachEnd = courseList.get().equal(courseList.last());
		try{
			Course add, comp;
			add = comp = courseList.get(); 
			if(add.labs.size() > 0){
				schedule.addLab(add.labs.begin());
			}
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