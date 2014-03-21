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
	CPPUNIT_ASSERT(co.getDays() == "MWF");
	CPPUNIT_ASSERT(co.getName() == "coursename");
	CPPUNIT_ASSERT(co.getLoc() == "courseloc");
	CPPUNIT_ASSERT(co.getId() == 788934);
}

void CourseFixture::testGetDays(){
	CPPUNIT_ASSERT(c->getDays() == "TR");
}

void CourseFixture::testGetName(){
	CPPUNIT_ASSERT(c->getName() == "course");
}

void CourseFixture::testGetLoc(){
	CPPUNIT_ASSERT(c->getLoc() == "location");
}

void CourseFixture::testGetId(){
	CPPUNIT_ASSERT(c->getId() == 894372);
}

void CourseFixture::testRating(){
	c->setRating(5);
	CPPUNIT_ASSERT(c->getRating() == 5);
}

void CourseFixture::testEqual(){
	Course co(945, 1215, "MWF", "coursename", "courseloc", 788934);
	CPPUNIT_ASSERT(co.equal(co));
}

void CourseFixture::testNotEqual(){
	Course c0(945, 1215, "MWF", "coursename", "courseloc", 788934);
	Course c1(1300, 1400, "TR", "name3", "loc 642", 43588934);
	CPPUNIT_ASSERT(!c0.equal(c1));
}