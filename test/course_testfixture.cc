#include "Course.h"
#include "course_testfixture.h"
#include "Exceptions.h"

void CourseFixture::setUp(){

}

void CourseFixture::tearDown(){

}

void CourseFixture::testGetEndTime(){
	Course c;
	CPPUNIT_ASSERT(c.getEndTime() == 1500);
}