#include "Course.h"
#include "course_testfixture.h"
#include "Exceptions.h"
#include "Lab.h"

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

void CourseFixture::testAddLab(){
	Lab la(915, 1000, "F", "courselab", "labloc", 000101);
	c->addLab(la);
	c->labBegin();
	CPPUNIT_ASSERT(c->firstLab().getName() == la.getName());
}

void CourseFixture::testReturnLast(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	c->addLab(l1);
	c->addLab(l2);
	CPPUNIT_ASSERT(c->lastLab().getName() == l2.getName());
}

void CourseFixture::testNext(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	c->addLab(l1);
	c->addLab(l2);
	c->addLab(l3);
	c->labBegin();
	c->nextLab();
	CPPUNIT_ASSERT(c->getLab().getName() == l2.getName());
}

void CourseFixture::testPrev(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	c->addLab(l1);
	c->addLab(l2);
	c->addLab(l3);
	c->labBegin();
	c->nextLab();
	c->nextLab();
	c->prevLab();
	CPPUNIT_ASSERT(c->getLab().getName() == l2.getName());
}