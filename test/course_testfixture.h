#ifndef __COURSE_TESTFIXTURE_H
#define __COURSE_TESTFIXTURE_H

#include "Course.h"
#include <cppunit/extensions/HelperMacros.h>


class CourseFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(CourseFixture);
	CPPUNIT_TEST(testGetEndTime);
	CPPUNIT_TEST(testGetStartTime);
	CPPUNIT_TEST_SUITE_END();
private:

public:
	void setUp();
	void tearDown();

	void testGetEndTime();
	void testGetStartTime();
};

#endif