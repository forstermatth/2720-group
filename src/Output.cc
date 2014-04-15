#include "Output.h"

using namespace std;

void Output::generate(Options opts, CourseSched sched){
  // Number of Options and and required classes
	cout << "Options: " << endl
		 << "Number of classes:" << opts.getNumCourses() << endl
		 << "Required Courses: " << endl;
	// Gets the required courses
	 list<unsigned int> reqs = opts.getRequiredCourses();
	 list<unsigned int>::iterator it;
	 // iterates and outputs the required course IDs
	 for(it = reqs.begin(); it != reqs.end(); it++){
	 	cout << *it << endl;
	 }
	 // Display current time preferences and breaks
	 cout << "Time Preference: " << opts.getTimePreference() << endl
	 	  << "Time Between Classes: " << opts.getBreakPadding()*2 << endl
	 	  << "Specific Break Start: " << opts.getBreakStart() << endl
	 	  << "Specific Break End: "	  << opts.getBreakEnd() << endl;
	 // Outputs the suggested schedule generated
	cout << "Suggested schedule: " << endl;
	// starts are the beginning of container
	Course c = sched.courses.begin();
	do{
	  // Displays the Course
	  cout << setw(10) << c.getId() 		<< " " 
 			<< setw(20) << c.getName() 	<< " " 
 			<< setw(6) << c.getLoc() 		<< " " 
 			<< setfill('0') << setw(4) << c.getStartTime() << "-" << setfill('0') << setw(4) <<  c.getEndTime() << " " 
 			<< setfill(' ') << setw(4) << c.getDays() << endl;
	  
	  // if there are labs connected to the course, then they are displayed after
		if(c.labs.size() > 0){
			cout << setw(15) << "Labs: " << endl;
			Lab l = c.labs.begin();
			do{
			  cout << setw(15) << l.getId() 		<< " " 
 			 		<< setw(20) << l.getName() 	<< " " 
 					<< setw(6) << l.getLoc() 		<< " " 
 			 		<< setfill('0') << setw(4) << l.getStartTime() << "-" << setfill('0') << setw(4) << l.getEndTime() << " " 
 			 		<< setfill(' ') << setw(4) << l.getDays() << endl;

			  c.labs.next(); // move to next lab (if exists)
			  l = c.labs.get(); // assign the lab
			}while(!l.equal(c.labs.first()));
		}

		sched.courses.next(); // move to next course
		c = sched.courses.get(); // assign the course
	}while(!c.equal(sched.courses.first())); 

}
