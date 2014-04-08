#include "Output.h"
#include <iomanip>
#include <iostream>
#include <list>
#include "CourseSched.h"
#include "Options.h"
#include "Course.h"
#include "Lab.h"
using namespace std;

void Output::generate(Options opts, CourseSched sched){
	cout << "Options: " << endl
		 << "Number of classes:" << opts.getNumCourses() << endl
		 << "Required Courses: " << endl;
	 list<unsigned int> reqs = opts.getRequiredCourses();
	 list<unsigned int>::iterator it;
	 for(it = reqs.begin(); it != reqs.end(); it++){
	 	cout << *it << endl;
	 }
	 cout << "Time Preference: " << opts.getTimePreference() << endl
	 	  << "Time Between Classes: " << opts.getBreakPadding()*2 << endl
	 	  << "Specific Break Start: " << opts.getBreakStart() << endl
	 	  << "Specific Break End: "	  << opts.getBreakEnd() << endl;

	cout << "Suggested schedule: " << endl;
	Course c = sched.courses.begin();
	do{
		cout << c.getId() 		<< " " 
			 << c.getName() 	<< " " 
			 << c.getLoc() 		<< " " 
			 << c.getStartTime() << "-" << c.getEndTime() << " " 
			 << c.getDays() << endl;

		if(c.labs.size() > 0){
			cout << "Labs: " << endl;
			Lab l = c.labs.begin();
			do{
				cout << l.getId() 		<< " " 
			 		 << l.getName() 	<< " " 
					 << l.getLoc() 		<< " " 
			 		 << l.getStartTime() << "-" << l.getEndTime() << " " 
			 		 << l.getDays() << endl;

			 		 c.labs.next();
			 		 l = c.labs.get();
			}while(!l.equal(c.labs.end()));
		}

		sched.courses.next();
		c = sched.courses.get();
	}while(!c.equal(sched.courses.last())); 

}