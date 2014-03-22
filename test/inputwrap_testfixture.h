#ifndef __INPUTWRAP_TESTFIXTURE_H
#define __INPUTWRAP_TESTFIXTURE_H

#include "InputWrap.h"
#include <cppunit/extensions/HelperMacros.h>

/// Test - InputWrap
class InputWrapFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(InputWrapFixture);
	CPPUNIT_TEST(testAddFile);
	CPPUNIT_TEST(testPopulateOptions);
	CPPUNIT_TEST(testPopulateCourse);
	CPPUNIT_TEST(testPopulateMultiCourses);
	CPPUNIT_TEST(testNumberCourses);
	CPPUNIT_TEST(testParseLab);
	CPPUNIT_TEST(testMultiLabs);
	CPPUNIT_TEST(testNumberLabs);
	CPPUNIT_TEST_SUITE_END();
private:
	InputWrap* input;
public:
	void setUp();
	void tearDown();

	void testAddFile();
	void testPopulateOptions();
	void testPopulateCourse();
	void testPopulateMultiCourses();
	void testParseLab();
	void testMultiLabs();
	void testNumberCourses();
	void testNumberLabs();

};

#endif