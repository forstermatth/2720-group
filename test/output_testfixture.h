#ifndef __OUTPUT_TESTFIXTURE_H
#define __OUTPUT_TESTFIXTURE_H

#include "Output.h"
#include <cppunit/extensions/HelperMacros.h>

/// Test - Output
class OutputFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(OutputFixture);
	CPPUNIT_TEST_SUITE_END();
private:
	Output* out;
public:
	void setUp();
	void tearDown();
};

#endif