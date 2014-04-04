#ifndef __COURSECONT_TESTFIXTURE_H
#define __COURSECONT_TESTFIXTURE_H

#include "CourseCont.h"
#include <cppunit/extensions/HelperMacros.h>

/// Test - CourseCont
class CourseContFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(CourseContFixture);
	CPPUNIT_TEST(testAddCourse);
	CPPUNIT_TEST(testReturnLast);
	CPPUNIT_TEST(testReturnFirst);
	CPPUNIT_TEST(testNext);
	CPPUNIT_TEST(testPrev);
	CPPUNIT_TEST(testBegin);
	CPPUNIT_TEST(testEnd);
	CPPUNIT_TEST(testSort);
	CPPUNIT_TEST(testOverflow);
	CPPUNIT_TEST_SUITE_END();
private:
	CourseCont<Course>* cc;
public:
	void setUp();
	void tearDown();

	void testAddCourse();
	void testReturnLast();
	void testReturnFirst();
	void testNext();
	void testPrev();
	void testBegin();
	void testEnd();
	void testSort();
	void testOverflow();

};

#endif