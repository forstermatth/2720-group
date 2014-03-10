#ifndef __INPUTWRAP_TESTFIXTURE_H
#define __INPUTWRAP_TESTFIXTURE_H

#include "InputWrap.h"
#include <cppunit/extensions/HelperMacros.h>


class InputWrapFixture : public CppUnit::TestFixture {
public:
	CPPUNIT_TEST_SUITE(InputWrapFixture);
	CPPUNIT_TEST_SUITE_END();
private:

public:
	void setUp();
	void tearDown();
};

#endif