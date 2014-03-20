#ifndef __COURSE_TESTFIXTURE_H
#define __COURSE_TESTFIXTURE_H

#include "Course.h"
#include <cppunit/extensions/HelperMacros.h>

///Test - Course
class CourseFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(CourseFixture);
	CPPUNIT_TEST(testGetEndTime);
	CPPUNIT_TEST(testGetStartTime);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testGetDays);
	CPPUNIT_TEST(testGetName);
	CPPUNIT_TEST(testGetLoc);
	CPPUNIT_TEST(testGetId);
	CPPUNIT_TEST(testRating);
	CPPUNIT_TEST(testAddLab);
	CPPUNIT_TEST(testReturnLast);
	CPPUNIT_TEST(testNext);
	CPPUNIT_TEST(testPrev);
	CPPUNIT_TEST_SUITE_END();
private:
	Course * c;
public:
	void setUp();
	void tearDown();

	void testGetEndTime();
	void testGetStartTime();
	void testConstructor();
	void testGetDays();
	void testGetName();
	void testGetLoc();
	void testGetId();
	void testRating();
	void testAddLab();
	void testReturnLast();
	void testNext();
	void testPrev();
};

#endif