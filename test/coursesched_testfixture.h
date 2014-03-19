#ifndef __COURSESCHED_TESTFIXTURE_H
#define __COURSESCHED_TESTFIXTURE_H

#include "CourseSched.h"
#include <cppunit/extensions/HelperMacros.h>


class CourseSchedFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(CourseSchedFixture);
	CPPUNIT_TEST(testAddCourse);
	CPPUNIT_TEST(testNext);
	CPPUNIT_TEST(testPrev);
	CPPUNIT_TEST_EXCEPTION(testRemoveCourse, EmptyContainer);
	CPPUNIT_TEST_EXCEPTION(testAddTwoMWFConflictingException, TimeConflict);
	CPPUNIT_TEST_EXCEPTION(testAddTwoTRConflictingException, TimeConflict);
	CPPUNIT_TEST_EXCEPTION(testAddMWFandWConflictingException, TimeConflict);
	CPPUNIT_TEST_SUITE_END();
private:
	CourseSched* cs;
public:
	void setUp();
	void tearDown();
	void testAddCourse();
	void testNext();
	void testPrev();
	void testRemoveCourse();
	void testAddTwoMWFConflictingException();
	void testAddTwoTRConflictingException();
	void testAddMWFandWConflictingException();		
};

#endif
