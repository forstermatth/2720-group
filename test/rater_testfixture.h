#ifndef __RATER_TESTFIXTURE_H
#define __RATER_TESTFIXTURE_H

#include "Rater.h"
#include <cppunit/extensions/HelperMacros.h>

///Test - Rater
class RaterFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(RaterFixture);
	CPPUNIT_TEST(setRatingOnReqCourses);
	CPPUNIT_TEST(setRatingForMorningTimePref);
	CPPUNIT_TEST(setRatingForAfternoonTimePref);
	CPPUNIT_TEST(setRatingForNoTimePref);
	CPPUNIT_TEST(ignoreClassOnLunchBreak);
	CPPUNIT_TEST(setRatingForClassesBeforeLunchBreak);
	CPPUNIT_TEST(setRatingForClassesAfterLunchBreak);
	CPPUNIT_TEST(setRatingForMultipleReqCourses);
	CPPUNIT_TEST_SUITE_END();
private:
	Options* opts;
	CourseCont* cc;
public:
	void setUp();
	void setRatingOnReqCourses();
	void setRatingForMorningTimePref();
	void setRatingForAfternoonTimePref();
	void setRatingForNoTimePref();
	void ignoreClassOnLunchBreak();
	void setRatingForClassesBeforeLunchBreak();
	void setRatingForClassesAfterLunchBreak();
	void setRatingForMultipleReqCourses();
	void tearDown();
};

#endif