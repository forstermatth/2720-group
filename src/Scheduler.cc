#include "Course.h"
#include "CourseCont.h"
#include "Options.h"
#include "Scheduler.h"

#include <iostream>

CourseSched* Scheduler::generateSchedule(CourseCont& courseList, Options &opts){
	CourseSched *schedule = new CourseSched;
	courseList.sort();
	courseList.first();
	std::cout << "Making a schedule.\n";
	for(int i = 0; i < opts.getNumCourses() && courseList.getCourse() != courseList.last();){
		std::cout << "Adding a course.\n";
		try{
			schedule->addCourse(courseList.getCourse());
			courseList.next();
			i++;
		}catch(const TimeConflict &expt){
			courseList.next();
		}
	}
	std::cout << "schedule size: " << schedule->size() << std::endl;
	return schedule;
}