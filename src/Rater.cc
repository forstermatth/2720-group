#include "Rater.h"
#include <iostream>

Rater::Rater(Options* _opts, CourseCont* _cc) : opts(_opts), cc(_cc){
}

void Rater::rateCourses(){
	Course end = cc->last();
	cc->first();
	do
	{
		rating = 0;
		if (cc->getCourse().getStartTime() > opts->getBreakEnd() || cc->getCourse().getEndTime() < opts->getBreakStart()){
			rating += 5;
		}
		if (opts->getTimePreference() == Times::Am && cc->getCourse().getStartTime() < 1130){
			rating += 5;
		}
		list<unsigned int> requiredCourses = opts->getRequiredCourses();
		list<unsigned int> requiredCourses2 = requiredCourses;
		for (std::list<unsigned int>::iterator it=requiredCourses.begin() ; it != requiredCourses.end(); ++it){
			if (requiredCourses2.front() == cc->getCourse().getId()) {
				rating = 30;
			}
			requiredCourses2.pop_front();
		}
		cc->getCourse().setRating(rating);
		cc->next();
	}
	while (cc->getCourse().getId() != end.getId());
	
}
