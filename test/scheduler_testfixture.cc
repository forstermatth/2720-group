#include "Course.h"
#include "CourseCont.h"
#include "CourseSched.h"
#include "Options.h"
#include "Scheduler.h"
#include "scheduler_testfixture.h"
#include "Exceptions.h"
#include <list>
#include <iostream>
using std::list;

void SchedulerFixture::setUp(){
	sch = new Scheduler;
}

void SchedulerFixture::tearDown(){
	delete sch;
}

void SchedulerFixture::testAddCourses(){
	list<unsigned int> requiredCourses;
	CourseCont<Course> cc;
	Options opts(2, requiredCourses, Times::None, 0, 0, 1);
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1015, "TR", "name2", "loc 641", 453224);
	c1.setRating(1);
	c2.setRating(2);
	cc.add(c1);
	cc.add(c2);
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.courses.get().getId() == c2.getId());
	cs.courses.next();
	CPPUNIT_ASSERT(cs.courses.get().getId() == c1.getId());
	CPPUNIT_ASSERT(cs.courses.size() == 2);
}

void SchedulerFixture::testCourseConflict(){
	list<unsigned int> requiredCourses;
	CourseCont<Course> cc;
	Options opts(2, requiredCourses, Times::None, 0, 0, 1);
	Course c1(900, 1100, "MW", "name", "loc 640", 9484739);
	Course c2(1015, 1045, "MW", "name", "loc 641", 453224);
	Course c3(1030, 1015, "TR", "name", "loc 641", 462348);
	c1.setRating(10);
	c2.setRating(9);
	c3.setRating(8);
	cc.add(c1);
	cc.add(c2);
	cc.add(c3);
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.courses.get().getId() == c1.getId());
	cs.courses.next();
	CPPUNIT_ASSERT(cs.courses.get().getId() == c3.getId());
	CPPUNIT_ASSERT(cs.courses.size() == 2);
}

void SchedulerFixture::testNotEnoughCourses(){
	list<unsigned int> requiredCourses;
	CourseCont<Course> cc;
	Options opts(5, requiredCourses, Times::None, 0, 0, 1);
	Course c1(900, 1100, "MW", "name", "loc 640", 9484739);
	Course c2(1015, 1045, "MW", "name", "loc 641", 453224);
	Course c3(1030, 1015, "TR", "name", "loc 641", 462348);
	c1.setRating(10);
	c2.setRating(9);
	c3.setRating(8);
	cc.add(c1);
	cc.add(c2);
	cc.add(c3);
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.courses.get().getId() == c1.getId());
	cs.courses.next();
	CPPUNIT_ASSERT(cs.courses.get().getId() == c3.getId());
	CPPUNIT_ASSERT(cs.courses.size() == 2);
}

void SchedulerFixture::testCoursesWithPadding(){
	list<unsigned int> requiredCourses;
	CourseCont<Course> cc;
	Options opts(5, requiredCourses, Times::None, 30, 0, 1);
	Course c1(900, 1100, "MW", "name", "loc 640", 9484739);
	Course c2(1105, 1200, "MW", "name", "loc 641", 453224);
	Course c3(1030, 1015, "TR", "name", "loc 641", 462348);
	c1.setRating(10);
	c2.setRating(9);
	c3.setRating(8);
	cc.add(c1);
	cc.add(c2);
	cc.add(c3);
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.courses.get().getId() == c1.getId());
	cs.courses.next();
	CPPUNIT_ASSERT(cs.courses.get().getId() == c3.getId());
	CPPUNIT_ASSERT(cs.courses.size() == 2);
}

void SchedulerFixture::testAddLab(){
	Lab l1(900, 1100, "MW", "lab", "loc 1", 13245);
	Course c1(1200, 1300, "MWF", "course", "loc 2", 13244);
	CourseCont<Course> cc;
	list<unsigned int> requiredCourses;
	Options opts(5, requiredCourses, Times::None, 0, 0, 1);
	c1.labs.add(l1);
	cc.add(c1);
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.labs.first().getId() == 13245);
}

void SchedulerFixture::testLabConflict(){
	list<unsigned int> requiredCourses;
	Options opts(5, requiredCourses, Times::None, 0, 0, 1);
	Course c1(900, 1100, "MW", "name", "loc 640", 9484739);
	Course c2(1105, 1200, "MW", "name", "loc 641", 453224);
	Lab l1(900, 1100, "MW", "lab", "loc 1", 13245);
	CourseCont<Course> cc;
	c1.setRating(10);
	c2.setRating(9);
	c2.labs.add(l1);
	cc.add(c1);
	cc.add(c2); 
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.courses.last().getId() == 9484739);
}

void SchedulerFixture::testAddSecondLab(){
	list<unsigned int> requiredCourses;
	Options opts(5, requiredCourses, Times::None, 0, 0, 1);
	Course c1(900, 1100, "MW", "name", "loc 640", 9484739);
	Course c2(1105, 1200, "MW", "name", "loc 641", 453224);
	Lab l1(900, 1100, "M", "lab 1", "loc 1", 13245);
	Lab l2(1300, 1400, "M", "lab 2", "loc 1", 13246);
	CourseCont<Course> cc;
	c1.setRating(10);
	c2.setRating(9);
	c2.labs.add(l1);
	c2.labs.add(l2);
	cc.add(c1);
	cc.add(c2); 
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.courses.last().getId() == 453224);
	CPPUNIT_ASSERT(cs.labs.last().getId() == 13246);
}

void SchedulerFixture::testDontAddLab(){
	list<unsigned int> requiredCourses;
	Options opts(5, requiredCourses, Times::None, 0, 0, 1);
	Course c1(900, 1100, "MWF", "name", "loc 640", 1);
	Course c2(1105, 1200, "MWF", "name", "loc 641", 2);
	Course c3(1300, 1400, "MWF", "name", "loc 3", 3);
	Lab l1(900, 1100, "MWF", "lab 1", "loc 1", 13245);
	Lab l2(1300, 1400, "MWF", "lab 2", "loc 1", 13246);
	CourseCont<Course> cc;
	c1.setRating(10);
	c2.setRating(8);
	c3.setRating(90);
	c2.labs.add(l1);
	c2.labs.add(l2);
	cc.add(c1);
	cc.add(c2); 
	cc.add(c3);
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.labs.size() == 0);
}

void SchedulerFixture::testRemoveLab(){
	list<unsigned int> requiredCourses;
	Options opts(5, requiredCourses, Times::None, 0, 0, 1);
	Course c1(900, 1100, "MWF", "name", "loc 132", 1);
	Course c2(900, 1100, "MWF", "name", "loc 321", 2);
	Lab l1(1200, 1400, "M", "lab", "132456", 3);
	CourseCont<Course> cc;
	c1.setRating(20);
	c2.setRating(10);
	c2.labs.add(l1);
	cc.add(c1);
	cc.add(c2);
	CourseSched cs = sch->generateSchedule(cc, opts);
	CPPUNIT_ASSERT(cs.labs.size() == 0);
}