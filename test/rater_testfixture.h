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
	CPPUNIT_TEST(ignoreCourseOnLunchBreak);
	CPPUNIT_TEST(setRatingForCourseBeforeLunchBreak);
	CPPUNIT_TEST(setRatingForCourseAfterLunchBreak);
	CPPUNIT_TEST(setRatingForMultipleReqCourses);
	CPPUNIT_TEST(ignoreCourseOverlappingLunch);
	CPPUNIT_TEST(setRatingOnReqLab);
	CPPUNIT_TEST(setRatingForLabMorningPref);
	CPPUNIT_TEST(setRatingForLabAfternoonPref);
	CPPUNIT_TEST(setRatingForLabBeforeLunchBreak);
	CPPUNIT_TEST(setRatingForLabAfterLunchBreak);
	CPPUNIT_TEST(setRatingForMultipleLabs);
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
	void ignoreCourseOnLunchBreak();
	void setRatingForCourseBeforeLunchBreak();
	void setRatingForCourseAfterLunchBreak();
	void setRatingForMultipleReqCourses();
	void ignoreCourseOverlappingLunch();
	void setRatingOnReqLab();
	void setRatingForLabMorningPref();
	void setRatingForLabAfternoonPref();
	void setRatingForLabBeforeLunchBreak();
	void setRatingForLabAfterLunchBreak();
	void setRatingForMultipleLabs();
	void tearDown();
};

#endif