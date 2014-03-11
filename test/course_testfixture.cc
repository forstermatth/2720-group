#include "Course.h"
#include "course_testfixture.h"
#include "Exceptions.h"

void CourseFixture::setUp(){
	c = new Course(1115, 1500, "TR", "course", "location", 894372);
}

void CourseFixture::tearDown(){
	delete c;
}

void CourseFixture::testGetEndTime(){
	CPPUNIT_ASSERT(c->getEndTime() == 1500);
}

void CourseFixture::testGetStartTime(){
	CPPUNIT_ASSERT(c->getStartTime() == 1115);
}

void CourseFixture::testConstructor(){
	Course co(945, 1215, "MWF", "coursename", "courseloc", 788934);
	CPPUNIT_ASSERT(co.getStartTime() == 945);
	CPPUNIT_ASSERT(co.getEndTime() == 1215);
}

void CourseFixture::testGetDays(){
	CPPUNIT_ASSERT(c->getDays() == "TR");
}