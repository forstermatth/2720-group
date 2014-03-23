#include "Rater.h"
#include "rater_testfixture.h"
#include "Exceptions.h"

void RaterFixture::setUp(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	requiredCourses.push_back(894373);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1200, 1230);
	cc = new CourseCont();
}

void RaterFixture::tearDown(){
	delete opts;
	delete cc;
}

void RaterFixture::setRatingOnReqCourses(){
	Course c(900, 1015, "MW", "name", "loc 640", 894372);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 30);
}

void RaterFixture::setRatingForMorningTimePref(){
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
	Options* newopts = new Options(5, requiredCourses, Times::Pm, 30, 1200, 1230);
	Rater r(newopts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 5);
	delete newopts;
}

void RaterFixture::setRatingForNoTimePref(){
	Course c(1300, 1415, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	Options* newopts = new Options(5, requiredCourses, Times::None, 30, 1200, 1230);
	Rater r(newopts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 5);
	delete newopts;
}

void RaterFixture::ignoreClassOnLunchBreak(){
	Course c(1230, 1330, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 0);
}