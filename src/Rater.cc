#include "Rater.h"
#include <iostream>

Rater::Rater(Options* _opts, CourseCont* _cc) : opts(_opts), cc(_cc){
}

void Rater::rateCourses(){
	cc->begin();
	unsigned int rating = 0;
	int count = 0;
	do
	{
		if (count != 0){
			cc->next();
		}
		count = 1;
		list<unsigned int> requiredCourses = opts->getRequiredCourses();
		list<unsigned int> requiredCourses2 = requiredCourses;
		if (opts->getTimePreference() == Times::Am && cc->getCourse().getEndTime() < 1200){
			rating += 5;
		}
		else if (opts->getTimePreference() == Times::Pm && cc->getCourse().getStartTime() > 1199){
			rating += 5;
		}
		else if (opts->getTimePreference() == Times::None){
			rating += 5;
		}
		if (opts->getBreakStart() >= cc->getCourse().getEndTime() || opts->getBreakEnd() <= cc->getCourse().getStartTime()){
			rating += 5;
		}
		for (std::list<unsigned int>::iterator it=requiredCourses.begin() ; it != requiredCourses.end(); ++it){
			if (requiredCourses2.front() == cc->getCourse().getId()) {
				rating = 30;
			}
			requiredCourses2.pop_front();
		}
		cc->getCourse().setRating(rating);
		rating = 0;
	}
	while (cc->getCourse().getId() != cc->last().getId());
}
