#include "rater_testfixture.h"
#include "Exceptions.h"
#include <list>
#include <iostream>

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

void RaterFixture::setRatingForMorningBreakPref(){
	Course c(900, 1015, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 10);
}

void RaterFixture::setRatingForAfternoonBreakPref(){
	Course c(900, 1015, "MW", "name", "loc 640", 894370);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 10);
}

void RaterFixture::setRatingOnMultipleReqCourses(){
	Course c1(900, 1015, "MW", "name", "loc 640", 894372);
	Course c2(1300, 1430, "MW", "name", "loc 640", 894373);
	Course c3(900, 1015, "MW", "name", "loc 640", 894374);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->addCourse(c3);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 30);
	cc->next();
	CPPUNIT_ASSERT(cc->getCourse().getRating() == 30);
}

void RaterFixture::setRatingOnReqCoursesandBreakPref(){
	Course c1(900, 1015, "MW", "name", "loc 640", 894372);
	Course c2(900, 1015, "MW", "name", "loc 640", 894390);
	Course c3(900, 1015, "MW", "name", "loc 640", 894355);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->addCourse(c3);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 30);
	cc->next();
	CPPUNIT_ASSERT(cc->getCourse().getRating() == 10);
}

void RaterFixture::setRatingOnMorningClassPref(){
	Course c1(900, 1015, "MW", "name", "loc 640", 894379);
	cc->addCourse(c1);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 10);
}


