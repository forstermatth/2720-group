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
	CPPUNIT_ASSERT_NO_THROW(cs->addCourse(c));
	CPPUNIT_ASSERT(cs->getCourse().getStartTime() == c.getStartTime());
	CPPUNIT_ASSERT(cs->getCourse().getEndTime() == c.getEndTime());
	CPPUNIT_ASSERT(cs->getCourse().getStartTime() == c.getStartTime());
	CPPUNIT_ASSERT(cs->getCourse().getDays() == c.getDays());
	CPPUNIT_ASSERT(cs->getCourse().getName() == c.getName());
	CPPUNIT_ASSERT(cs->getCourse().getLoc() == c.getLoc());
	CPPUNIT_ASSERT(cs->getCourse().getId() == c.getId());
}

void CourseSchedFixture::testRemoveCourse(){
	Course c(900, 1015, "MW", "name", "loc 640", 9484739);
	CPPUNIT_ASSERT_NO_THROW(cs->addCourse(c));
	cs->removeCourse();
	cs->removeCourse();
}

void CourseSchedFixture::testNext(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Course c3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	cs->addCourse(c1);
	cs->addCourse(c2);
	cs->addCourse(c3);
	cs->next();
	CPPUNIT_ASSERT(cs->getCourse().getName() == c2.getName());
}

void CourseSchedFixture::testPrev(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Course c3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	cs->addCourse(c1);
	cs->addCourse(c2);
	cs->addCourse(c3);
	cs->next();
	cs->prev();
	CPPUNIT_ASSERT(cs->getCourse().getName() == c1.getName());
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
	cs->beginLab();
	CPPUNIT_ASSERT(la.getId() == cs->getLab().getId());
}

void CourseSchedFixture::testAddMultipleLabs(){
	Lab l1(900, 1015, "MWF", "name", "loc 640", 9484739);
	Lab l2(1000, 1050, "W", "name2", "loc 641", 9484730);
	cs->addLab(l1);
	cs->addLab(l2);
	CPPUNIT_ASSERT(l1.getId() == cs->firstLab().getId());
	CPPUNIT_ASSERT(l2.getId() == cs->lastLab().getId());
}

void CourseSchedFixture::testNextLab(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 5);
	cs->addLab(l1);
	cs->addLab(l2);
	cs->addLab(l3);
	cs->beginLab();
	CPPUNIT_ASSERT(l1.getId() == cs->getLab().getId());
	cs->nextLab();
	CPPUNIT_ASSERT(l2.getId() == cs->getLab().getId());
	cs->nextLab();
	CPPUNIT_ASSERT(l3.getId() == cs->getLab().getId());
}

void CourseSchedFixture::testPrevLab(){
	Lab l1(900, 1015, "MW", "name", "loc 640", 9484739);
	Lab l2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Lab l3(1300, 1400, "TR", "name3", "loc 642", 5);
	cs->addLab(l1);
	cs->addLab(l2);
	cs->addLab(l3);
	cs->endLab();
	CPPUNIT_ASSERT(l3.getId() == cs->getLab().getId());
	cs->prevLab();
	CPPUNIT_ASSERT(l2.getId() == cs->getLab().getId());
	cs->prevLab();
	CPPUNIT_ASSERT(l1.getId() == cs->getLab().getId());
}