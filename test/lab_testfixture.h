#ifndef __LAB_TESTFIXTURE_H
#define __LAB_TESTFIXTURE_H

#include <cppunit/extensions/HelperMacros.h>
#include "Lab.h"

///Test - Lab
class LabFixture : public CppUnit::TestFixture{
public:
	CPPUNIT_TEST_SUITE(LabFixture);
	CPPUNIT_TEST(testGetEndTime);
	CPPUNIT_TEST(testGetStartTime);
	CPPUNIT_TEST(testConstructor);
	CPPUNIT_TEST(testGetDays);
	CPPUNIT_TEST(testGetName);
	CPPUNIT_TEST(testGetLoc);
	CPPUNIT_TEST(testGetId);
	CPPUNIT_TEST(testRating);
	CPPUNIT_TEST_SUITE_END();
private:
	Lab * l;
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
};



#endif