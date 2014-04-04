#include "Course.h"
#include "CourseCont.h"
#include "CourseSched.h"
#include "Options.h"
#include "Scheduler.h"
#include "scheduler_testfixture.h"
#include "Exceptions.h"
#include <list>
using std::list;

void SchedulerFixture::setUp(){
	sch = new Scheduler;
}

void SchedulerFixture::tearDown(){
	delete sch;
}

void SchedulerFixture::testAddCourses(){
	list<unsigned int> requiredCouses;
	CourseCont<Course> cc;
	Options opts(2, requiredCouses, Times::None, 0, 0, 1);
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
	list<unsigned int> requiredCouses;
	CourseCont<Course> cc;
	Options opts(2, requiredCouses, Times::None, 0, 0, 1);
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
	list<unsigned int> requiredCouses;
	CourseCont<Course> cc;
	Options opts(5, requiredCouses, Times::None, 0, 0, 1);
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
	list<unsigned int> requiredCouses;
	CourseCont<Course> cc;
	Options opts(5, requiredCouses, Times::None, 30, 0, 1);
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