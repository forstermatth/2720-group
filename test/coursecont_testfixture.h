#ifndef __COURSECONT_TESTFIXTURE_H
#define __COURSECONT_TESTFIXTURE_H

#include "CourseCont.h"
#include <cppunit/extensions/HelperMacros.h>


class CourseContFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(CourseContFixture);
	CPPUNIT_TEST(testAddCourse);
	CPPUNIT_TEST(testReturnLast);
	CPPUNIT_TEST(testNext);
	CPPUNIT_TEST(testPrev);
	CPPUNIT_TEST(testSort);
	CPPUNIT_TEST_SUITE_END();
private:
	CourseCont* cc;
public:
	void setUp();
	void tearDown();

	void testAddCourse();
	void testReturnLast();
	void testNext();
	void testPrev();
	void testSort();

};

#endif