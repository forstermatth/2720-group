#ifndef __OPTIONS_TESTFIXTURE_H
#define __OPTIONS_TESTFIXTURE_H

#include "Options.h"
#include <cppunit/extensions/HelperMacros.h>


class OptionsFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(OptionsFixture);
	CPPUNIT_TEST_SUITE_END();
private:

public:
	void setUp();
	void tearDown();
};

#endif