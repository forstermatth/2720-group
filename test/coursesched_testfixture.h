#ifndef __COURSESCHED_TESTFIXTURE_H
#define __COURSESCHED_TESTFIXTURE_H

#include "CourseSched.h"
#include <cppunit/extensions/HelperMacros.h>


class CourseSchedFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(CourseSchedFixture);
	CPPUNIT_TEST_SUITE_END();
private:

public:
	void setUp();
	void tearDown();
};

#endif