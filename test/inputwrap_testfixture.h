#ifndef __INPUTWRAP_TESTFIXTURE_H
#define __INPUTWRAP_TESTFIXTURE_H

#include "InputWrap.h"
#include <cppunit/extensions/HelperMacros.h>


class InputWrapFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(InputWrapFixture);
	CPPUNIT_TEST(testAddFile);
	CPPUNIT_TEST(testPopulateOptions);
	CPPUNIT_TEST(testPopulateCourses);
	CPPUNIT_TEST_SUITE_END();
private:
	InputWrap* input;
public:
	void setUp();
	void tearDown();

	void testAddFile();
	void testPopulateOptions();
	void testPopulateCourses();

};

#endif