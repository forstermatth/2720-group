#include "Options.h"
#include "options_testfixture.h"
#include "Exceptions.h"
#include<list>
using namespace std;

void OptionsFixture::setUp(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(2720);
	requiredCourses.push_back(3740);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1200, 1230);
}

void OptionsFixture::tearDown(){
	delete opts;
}

void OptionsFixture::testNumberOfCourses(){
	//test to make sure that getNumCourses returns 5.
	CPPUNIT_ASSERT(5 == opts->getNumCourses());
}

void OptionsFixture::testRequiredCourses(){
	//test to make sure that the list returned by required courses contains the correct courses.
	list<unsigned int> rCourses;
	rCourses.push_back(2720);
	rCourses.push_back(3740);
	list<unsigned int> returnedCourses = opts->getRequiredCourses();
	CPPUNIT_ASSERT(rCourses.front() == returnedCourses.front());
	CPPUNIT_ASSERT(rCourses.back() == returnedCourses.back());
}

void OptionsFixture::testTimePreference(){
	//test to make sure that the correct time preference is returned.
	CPPUNIT_ASSERT(Times::Am == opts->getTimePreference());
}

void OptionsFixture::testBreakPadding(){
	//test to make sure that the correct amount of padding for breaks is returned.
	CPPUNIT_ASSERT(30 == opts->getBreakPadding());
}

void OptionsFixture::testBreakStart(){
	//test to make sure that the correct start time is returned for a break.
	CPPUNIT_ASSERT(1200 == opts->getBreakStart());
}

void OptionsFixture::testBreakEnd(){
	//test to make sure that the correct end time is returned for a break.
	CPPUNIT_ASSERT(1230 == opts->getBreakEnd());
}