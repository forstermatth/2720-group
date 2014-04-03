#include "Rater.h"
#include "rater_testfixture.h"
#include "Exceptions.h"
#include <iostream>
void RaterFixture::setUp(){
	cc = new CourseCont();
}

void RaterFixture::tearDown(){
	delete opts;
	delete cc;
}

void RaterFixture::setRatingOnReqCourses(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::Pm, 30, 1000, 1230);
	Course c(900, 1015, "MW", "name", "loc 640", 894372);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 30);
}

void RaterFixture::setRatingForMorningTimePref(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1000, 1230);
	Course c(900, 1015, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 5);
}

void RaterFixture::setRatingForAfternoonTimePref(){
	Course c(1300, 1415, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::Pm, 30, 1200, 1330);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 5);
}

void RaterFixture::setRatingForNoTimePref(){
	Course c(1300, 1415, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::None, 30, 1200, 1330);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 5);
}

void RaterFixture::ignoreCourseOnLunchBreak(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1000, 1230);
	Course c(1200, 1230, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 0);
}

void RaterFixture::setRatingForCourseBeforeLunchBreak(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::Pm, 30, 1100, 1230);
	Course c(900, 1015, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 5);
}

void RaterFixture::setRatingForCourseAfterLunchBreak(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1000, 1230);
	Course c(1300, 1515, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 5);
}

void RaterFixture::setRatingForMultipleReqCourses(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	requiredCourses.push_back(894373);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1000, 1230);
	Course c1(900, 1015, "MW", "name", "loc 640", 894372);
	Course c2(1300, 1430, "MW", "name", "loc 640", 894373);
	Course c3(1300, 1515, "MW", "name", "loc 640", 894370);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->addCourse(c3);
	Rater r(opts, cc);
	r.rateCourses();
	cc->begin();
	CPPUNIT_ASSERT(cc->getCourse().getRating() == 30);
	cc->next();
	CPPUNIT_ASSERT(cc->getCourse().getRating() == 30);
	cc->next();
	CPPUNIT_ASSERT(cc->getCourse().getRating() == 5);
}

void RaterFixture::ignoreCourseOverlappingLunch(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1000, 1230);
	Course c(1215, 1345, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 0);
}

void RaterFixture::setRatingOnReqLab(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894370);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1000, 1230);
	Course c(1215, 1345, "MW", "name", "loc 640", 894370);
	Lab l(915, 1000, "F", "courselab", "labloc", 894370);
	c.addLab(l);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().firstLab().getRating() == 30);
}

void RaterFixture::setRatingForLabMorningPref(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894371);
	opts = new Options(5, requiredCourses, Times::Am, 30, 900, 1230);
	Course c(1215, 1345, "MW", "name", "loc 640", 894370);
	Lab l(915, 1000, "F", "courselab", "labloc", 894370);
	c.addLab(l);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().firstLab().getRating() == 5);
}

void RaterFixture::setRatingForLabAfternoonPref(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894371);
	opts = new Options(5, requiredCourses, Times::Pm, 30, 1000, 1330);
	Course c(1215, 1345, "MW", "name", "loc 640", 894370);
	Lab l(1315, 1430, "F", "courselab", "labloc", 894370);
	c.addLab(l);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().firstLab().getRating() == 5);
}

void RaterFixture::setRatingForLabBeforeLunchBreak(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894371);
	opts = new Options(5, requiredCourses, Times::Pm, 30, 1000, 1230);
	Course c(1215, 1345, "MW", "name", "loc 640", 894370);
	Lab l(915, 945, "F", "courselab", "labloc", 894370);
	c.addLab(l);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().firstLab().getRating() == 5);
}

void RaterFixture::setRatingForLabAfterLunchBreak(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894371);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1000, 1230);
	Course c(1215, 1345, "MW", "name", "loc 640", 894370);
	Lab l(1445, 1600, "F", "courselab", "labloc", 894370);
	c.addLab(l);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().firstLab().getRating() == 5);
}