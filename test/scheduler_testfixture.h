#ifndef __SCHEDULER_TESTFIXTURE_H
#define __SCHEDULER_TESTFIXTURE_H

#include "Scheduler.h"
#include <cppunit/extensions/HelperMacros.h>


class SchedulerFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(SchedulerFixture);
	CPPUNIT_TEST(testAddCourses);
	CPPUNIT_TEST(testCourseConflict);
	CPPUNIT_TEST_SUITE_END();
private:
	Scheduler *sch;
public:
	void setUp();
	void tearDown();
	void testAddCourses();
	void testCourseConflict();
};

#endif
