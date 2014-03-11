#include "Course.h"
#include "course_testfixture.h"
#include "Exceptions.h"

void CourseFixture::setUp(){
	c = new Course;
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