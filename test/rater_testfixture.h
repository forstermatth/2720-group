#ifndef __RATER_TESTFIXTURE_H
#define __RATER_TESTFIXTURE_H

#include "Rater.h"
#include <cppunit/extensions/HelperMacros.h>

///Test - Rater
class RaterFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(RaterFixture);
	CPPUNIT_TEST_SUITE_END();
private:

public:
	void setUp();
	void tearDown();
};

#endif