#ifndef __SCHEDULER_TESTFIXTURE_H
#define __SCHEDULER_TESTFIXTURE_H

#include "Scheduler.h"
#include <cppunit/extensions/HelperMacros.h>

/// Test - Scheduler
class SchedulerFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(SchedulerFixture);
	CPPUNIT_TEST(testAddCourses);
	CPPUNIT_TEST(testCourseConflict);
	CPPUNIT_TEST(testNotEnoughCourses);
	CPPUNIT_TEST(testCoursesWithPadding);
	CPPUNIT_TEST(testAddLab);
	CPPUNIT_TEST(testLabConflict);
	CPPUNIT_TEST(testAddSecondLab);
	CPPUNIT_TEST(testDontAddLab);
	CPPUNIT_TEST(testRemoveLab);
	CPPUNIT_TEST(testLabsWithPadding);
	CPPUNIT_TEST(testLabsWithRating);
	CPPUNIT_TEST(testDontScheduleDuplicateCourse);
	CPPUNIT_TEST_SUITE_END();
private:
	Scheduler *sch;
public:
	void setUp();
	void tearDown();
	void testAddCourses();
	void testCourseConflict();
	void testNotEnoughCourses();
	void testCoursesWithPadding();
	void testAddLab();
	void testLabConflict();
	void testAddSecondLab();
	void testDontAddLab();
	void testRemoveLab();
	void testLabsWithPadding();
	void testLabsWithRating();
	void testDontScheduleDuplicateCourse();
};

#endif
