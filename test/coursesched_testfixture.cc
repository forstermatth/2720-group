#include "CourseSched.h"
#include "coursesched_testfixture.h"
#include "Exceptions.h"
#include "Course.h"
#include <iostream>
void CourseSchedFixture::setUp(){
	cs = new CourseSched();
}

void CourseSchedFixture::tearDown(){
	delete cs;
}

void CourseSchedFixture::testAddCourse(){
	Course c(900, 1015, "MW", "name", "loc 640", 9484739);
	CPPUNIT_ASSERT_NO_THROW(cs->courses.add(c));
	CPPUNIT_ASSERT(cs->courses.begin().getStartTime() == c.getStartTime());
	CPPUNIT_ASSERT(cs->courses.get().getEndTime() == c.getEndTime());
	CPPUNIT_ASSERT(cs->courses.get().getStartTime() == c.getStartTime());
	CPPUNIT_ASSERT(cs->courses.get().getDays() == c.getDays());
	CPPUNIT_ASSERT(cs->courses.get().getName() == c.getName());
	CPPUNIT_ASSERT(cs->courses.get().getLoc() == c.getLoc());
	CPPUNIT_ASSERT(cs->courses.get().getId() == c.getId());
}

void CourseSchedFixture::testRemoveCourse(){
	Course c(900, 1015, "MW", "name", "loc 640", 9484739);
	CPPUNIT_ASSERT_NO_THROW(cs->courses.add(c));
	cs->courses.erase();
	cs->courses.erase();
}

void CourseSchedFixture::testNext(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Course c3(1300, 1400, "TR", "name3", "loc 642", 43588934);

	cs->addCourse(c1);
	cs->addCourse(c2);
	cs->addCourse(c3);

	cs->courses.begin();
	cs->courses.next();
	CPPUNIT_ASSERT(cs->courses.get().getName() == c2.getName());
}

void CourseSchedFixture::testPrev(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Course c3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	cs->addCourse(c1);
	cs->addCourse(c2);
	cs->addCourse(c3);
	cs->courses.begin();
	cs->courses.next();
	cs->courses.prev();
	CPPUNIT_ASSERT(cs->courses.get().getName() == c1.getName());
}

void CourseSchedFixture::testAddTwoMWFConflictingException(){
	Course c1(900, 1015, "MWF", "name", "loc 640", 9484739);
	Course c2(1000, 1050, "MWF", "name2", "loc 641", 9484730);
	cs->addCourse(c1);
	cs->addCourse(c2);
}

void CourseSchedFixture::testAddTwoTRConflictingException(){
	Course c1(900, 1015, "TR", "name", "loc 640", 9484739);
	Course c2(1000, 1050, "TR", "name2", "loc 641", 9484730);
	cs->addCourse(c1);
	cs->addCourse(c2);
	
}

void CourseSchedFixture::testAddMWFandWConflictingException(){
	Course c1(900, 1015, "MWF", "name", "loc 640", 9484739);
	Course c2(1000, 1050, "W", "name2", "loc 641", 9484730);
	cs->addCourse(c1);
	cs->addCourse(c2);
}

void CourseSchedFixture::testAddLab(){
	Lab la(900, 1015, "MWF", "name", "loc 640", 9484739);
	cs->addLab(la);
	cs->labs.begin();
	CPPUNIT_ASSERT(la.getId() == cs->labs.get().getId());
}

void CourseSchedFixture::testAddMultipleLabs(){
	Lab l1(900, 1015, "MWF", "name", "loc 640", 9484739);
	Lab l2(1030, 1050, "T", "name2", "loc 641", 9484730);
	cs->addLab(l1);
	cs->addLab(l2);
	CPPUNIT_ASSERT(l1.getId() == cs->labs.first().getId());
	CPPUNIT_ASSERT(l2.getId() == cs->labs.last().getId());
}

void CourseSchedFixture::testNextLab(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1050, "W", "name2", "loc 641", 9484730);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 5);
	cs->addLab(l1);
	cs->addLab(l2);
	cs->addLab(l3);
	cs->labs.begin();
	CPPUNIT_ASSERT(l1.getId() == cs->labs.get().getId());
	cs->labs.next();
	CPPUNIT_ASSERT(l2.getId() == cs->labs.get().getId());
	cs->labs.next();
	CPPUNIT_ASSERT(l3.getId() == cs->labs.get().getId());
}

void CourseSchedFixture::testPrevLab(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1050, "W", "name2", "loc 641", 9484730);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 5);
	cs->addLab(l1);
	cs->addLab(l2);
	cs->addLab(l3);
	cs->labs.end();
	CPPUNIT_ASSERT(l3.getId() == cs->labs.get().getId());
	cs->labs.prev();
	CPPUNIT_ASSERT(l2.getId() == cs->labs.get().getId());
	cs->labs.prev();
	CPPUNIT_ASSERT(l1.getId() == cs->labs.get().getId());
}

void CourseSchedFixture::testNextLabWraps(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	cs->addLab(l1);
	cs->addLab(l2);
	cs->labs.begin();
	CPPUNIT_ASSERT(l1.getId() == cs->labs.get().getId());
	cs->labs.next();
	CPPUNIT_ASSERT(l2.getId() == cs->labs.get().getId());
	cs->labs.next();
	CPPUNIT_ASSERT(l1.getId() == cs->labs.get().getId());
}

void CourseSchedFixture::testPrevLabWraps(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	cs->addLab(l1);
	cs->addLab(l2);
	cs->labs.end();
	CPPUNIT_ASSERT(l2.getId() == cs->labs.get().getId());
	cs->labs.prev();
	CPPUNIT_ASSERT(l1.getId() == cs->labs.get().getId());
	cs->labs.prev();
	CPPUNIT_ASSERT(l2.getId() == cs->labs.get().getId());
}

void CourseSchedFixture::testLabCollision(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	cs->addLab(l1);
	cs->addLab(l1);
}

void CourseSchedFixture::testCousreLabCollision(){
	Lab l1(900, 1015, "MW", "name", "loc", 1234);
	Course c1(900, 1015, "MW", "name", "loc", 1235);
	cs->addCourse(c1);
	cs->addLab(l1);
}

void CourseSchedFixture::testLabCourseCollision(){
	Lab l1(900, 1015, "MW", "name", "loc", 1234);
	Course c1(900, 1015, "MW", "name", "loc", 1235);
	cs->addLab(l1);
	cs->addCourse(c1);
}

void CourseSchedFixture::testDontAddlab(){
	Course c1(900, 1100, "MW", "name", "loc 640", 1);
	Course c2(1105, 1200, "MW", "name", "loc 641", 2);
	Course c3(1300, 1400, "MW", "name", "loc 3", 3);
	//Lab l1(900, 1100, "M", "lab 1", "loc 1", 13245);
	Lab l2(1300, 1400, "M", "lab 2", "loc 1", 13246);
	cs->addCourse(c1);
	cs->addCourse(c2); 
	cs->addCourse(c3);
	//cs->addLab(l1);
	cs->addLab(l2);
}