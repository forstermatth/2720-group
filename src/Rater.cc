#include "Rater.h"
#include <iostream>

Rater::Rater(Options* _opts, CourseCont* _cc) : opts(_opts), cc(_cc){
}

void Rater::rateCourses(){
	cc->begin();
	int count = 0;
	do
	{
		if (count != 0){
			cc->next();
		}
		count = 1;
		processCourse(cc->getCourse());
	}
	while (cc->getCourse().getId() != cc->last().getId());
}

void Rater::processCourse(Course& c){
	unsigned int rating = 0;
	list<unsigned int> requiredCourses = opts->getRequiredCourses();
	list<unsigned int> requiredCourses2 = requiredCourses;
	if (opts->getTimePreference() == Times::Am && c.getEndTime() < 1200){
		rating += 5;
	}
	else if (opts->getTimePreference() == Times::Pm && c.getStartTime() > 1199){
		rating += 5;
	}
	else if (opts->getTimePreference() == Times::None){
		rating += 5;
	}
	if (opts->getBreakStart() >= c.getEndTime() || opts->getBreakEnd() <= c.getStartTime()){
		rating += 5;
	}
	for (std::list<unsigned int>::iterator it=requiredCourses.begin() ; it != requiredCourses.end(); ++it){
		if (requiredCourses2.front() == c.getId()) {
			rating = 30;
		}
		requiredCourses2.pop_front();
	}
	c.setRating(rating);
	if(c.hasLab()==1){
		Lab last = c.lastLab();
		c.labBegin();
		do 
		{
			rating = 0;
			if (opts->getTimePreference() == Times::Am && c.getLab().getEndTime() < 1200){
				rating += 5;
			}
			else if (opts->getTimePreference() == Times::Pm && c.getLab().getStartTime() > 1199){
				rating += 5;
			}
			else if (opts->getTimePreference() == Times::None){
				rating += 5;
			}
			if (opts->getBreakStart() >= c.getLab().getEndTime() || opts->getBreakEnd() <= c.getLab().getStartTime()){
				rating += 5;
			}
			requiredCourses = opts->getRequiredCourses();
			requiredCourses2 = requiredCourses;
			for (std::list<unsigned int>::iterator it=requiredCourses.begin() ; it != requiredCourses.end(); ++it){
				if (requiredCourses2.front() == c.getLab().getId()) {
					rating = 30;
				}
				requiredCourses2.pop_front();
			}
			c.getLab().setRating(rating);
			c.nextLab();
		}
		while (c.getLab().getId() != last.getId());
	}
}
