#ifndef __OPTIONS_TESTFIXTURE_H
#define __OPTIONS_TESTFIXTURE_H

#include "Options.h"
#include <cppunit/extensions/HelperMacros.h>


class OptionsFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(OptionsFixture);
	CPPUNIT_TEST(testNumberOfCourses);
	CPPUNIT_TEST(testRequiredCourses);
	CPPUNIT_TEST(testTimePreference);
	CPPUNIT_TEST(testBreakPadding);
	CPPUNIT_TEST(testBreakStart);
	CPPUNIT_TEST(testBreakEnd);
	CPPUNIT_TEST_SUITE_END();
private:
	Options* opts;
public:
	void setUp();
	void tearDown();
	void testNumberOfCourses();
	void testRequiredCourses();
	void testTimePreference();
	void testBreakPadding();
	void testBreakStart();
	void testBreakEnd();
};

#endif