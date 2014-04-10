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
		Course add, comp;
		bool labAdded = true;
		add = comp = courseList.get(); 

		if(add.labs.size() > 0){
			labAdded = false;
			add.labs.begin();
			while(!labAdded){
				try{
					schedule.addLab(add.labs.get());
					labAdded = true;
				}catch(const TimeConflict &expt){
					add.labs.next();
					if(add.labs.get().equal(add.labs.first())){
						break;
					}
				}
			}
		}

		try{
			if(labAdded){
				comp.addPadding(opts.getBreakPadding());
				schedule.findConflict(&comp); //will throw and skip if conflict
				schedule.addCourse(add);
			}
			i++;
		}catch(const TimeConflict &expt){
			if(add.labs.size() > 0){
				//since the course has a lab, and the course couldn't be added, we need to remove
				//the last lab in the schedul container, since we can't add the class it belongs to.
				schedule.labs.end();
				schedule.labs.erase();
			}
		}catch(const EmptyContainer &epct){
			break;
		}
		courseList.next();
	}
	
	return schedule;
}