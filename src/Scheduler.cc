#include "Course.h"
#include "CourseCont.h"
#include "Options.h"
#include "Scheduler.h"

#include <iostream>

CourseSched* Scheduler::generateSchedule(CourseCont& courseList, Options &opts){
	CourseSched *schedule = new CourseSched;
	courseList.sort();
	courseList.first();
	for(int i = 0; i < opts.getNumCourses();){
		try{
			schedule->addCourse(courseList.getCourse());
			courseList.next();
			i++;
			std::cout << "didn't catch any fish:(\n";
		}catch(const TimeConflict &expt){
			courseList.next();
			std::cout << "caught an Exceptions\n";
		}
	}
	return schedule;
}