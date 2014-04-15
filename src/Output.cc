#include "Output.h"

using namespace std;

void Output::generate(Options opts, CourseSched sched){
  // Number of Options and and required classes
	cout << endl << "Options: " << endl
		 << "Number of classes: " << opts.getNumCourses() << endl
		 << "Required Courses: " << endl;
	// Gets the required courses
	 list<unsigned int> reqs = opts.getRequiredCourses();
	 list<unsigned int>::iterator it;
	 // iterates and outputs the required course IDs
	 for(it = reqs.begin(); it != reqs.end(); it++){
	 	cout << setw(15) << *it << endl;
	 }
	 // Display current time preferences and breaks
	 cout << "Time Preference: " << opts.getTimePreference() << endl
	 	  << "Time Between Classes: " << opts.getBreakPadding() << endl
	 	  << "Specific Break Start: " << opts.getBreakStart() << endl
	 	  << "Specific Break End: "	  << opts.getBreakEnd() << endl;
	 // Outputs the suggested schedule generated
	cout << endl << "Suggested schedule: " << endl;
	// starts are the beginning of container
	Course c = sched.courses.begin();
	do{
	  // Displays the Course
	  cout << setw(10) << c.getId() 		<< " " 
 			<< setw(17) << c.getName() 	<< " " 
 			<< setw(6) << c.getLoc() 		<< " " 
 			<< setfill('0') << setw(4) << c.getStartTime() << "-" << setfill('0') << setw(4) <<  c.getEndTime() << " " 
 			<< setfill(' ') << setw(3) << c.getDays() << endl;
		sched.courses.next(); // move to next course
		c = sched.courses.get(); // assign the course
	}while(!c.equal(sched.courses.first())); 
	 // if there are labs scheduled
	if(sched.labs.size() > 0){
		Lab l = sched.labs.begin();
		do{
		  cout << setw(10) << l.getId() 		<< " " 
			 		<< setw(17) << l.getName() 	<< " " 
					<< setw(6) << l.getLoc() 		<< " " 
			 		<< setfill('0') << setw(4) << l.getStartTime() << "-" << setfill('0') << setw(4) << l.getEndTime() << " " 
			 		<< setfill(' ') << setw(3) << l.getDays() << endl;

		  sched.labs.next(); // move to next lab (if exists)
		  l = sched.labs.get(); // assign the lab
		}while(!l.equal(sched.labs.first()));
	}

}
