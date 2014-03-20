#ifndef __SCHEDULER_TESTFIXTURE_H
#define __SCHEDULER_TESTFIXTURE_H

#include "Scheduler.h"
#include <cppunit/extensions/HelperMacros.h>

/// Test - Scheduler
class SchedulerFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(SchedulerFixture);
	CPPUNIT_TEST_SUITE_END();
private:

public:
	void setUp();
	void tearDown();
};

#endif