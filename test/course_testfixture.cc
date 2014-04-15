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
	c->labs.add(la);
	c->labs.begin();
	CPPUNIT_ASSERT(c->labs.first().getName() == la.getName());
}

void CourseFixture::testReturnLast(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	c->labs.add(l1);
	c->labs.add(l2);
	CPPUNIT_ASSERT(c->labs.last().getName() == l2.getName());
}

void CourseFixture::testNext(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	c->labs.add(l1);
	c->labs.add(l2);
	c->labs.add(l3);
	c->labs.begin();
	c->labs.next();
	CPPUNIT_ASSERT(c->labs.get().getName() == l2.getName());
}

void CourseFixture::testPrev(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	c->labs.add(l1);
	c->labs.add(l2);
	c->labs.add(l3);
	c->labs.begin();
	c->labs.next();
	c->labs.next();
	c->labs.prev();
	CPPUNIT_ASSERT(c->labs.get().getName() == l2.getName());
}

void CourseFixture::testOverflow(){
	Lab l1;
	Lab l2;

	c->labs.add(l1);
	c->labs.add(l2);
	c->labs.begin();
	CPPUNIT_ASSERT_NO_THROW(c->labs.get());
	CPPUNIT_ASSERT_NO_THROW(c->labs.next());
	CPPUNIT_ASSERT_NO_THROW(c->labs.next());
	CPPUNIT_ASSERT_NO_THROW(c->labs.next());
}

void CourseFixture::testHasLab(){
	Lab la(915, 1000, "F", "courselab", "labloc", 000101);
	CPPUNIT_ASSERT(c->labs.size() == 0);
	c->labs.add(la);
	CPPUNIT_ASSERT(c->labs.size() == 1);
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

void CourseFixture::testAddPadding(){
	Course c0(945, 1215, "MWF", "coursename", "courseloc", 788934);
	c0.addPadding(15);
	CPPUNIT_ASSERT(c0.getStartTime() == 930);
	CPPUNIT_ASSERT(c0.getEndTime() == 1230);
}

void CourseFixture::testAddPaddingRounds(){
	Course c0(900, 950, "MWF", "courseName", "courseloc", 1);
	c0.addPadding(10);
	CPPUNIT_ASSERT(c0.getStartTime() == 850);
	CPPUNIT_ASSERT(c0.getEndTime() == 1000);
}