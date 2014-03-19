#include "InputWrap.h"
#include "inputwrap_testfixture.h"
#include "Exceptions.h"
#include "Options.h"

#include <string>

void InputWrapFixture::setUp(){
	input = new InputWrap();
}

void InputWrapFixture::tearDown(){
	delete input;
}

void InputWrapFixture::testAddFile(){
	std::string str = "testinput";
	CPPUNIT_ASSERT_NO_THROW(input->parse(str));
}

void InputWrapFixture::testPopulateOptions(){
	std::string str = "testinput";
	Options ops;
	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(input->setOptions(ops));
	CPPUNIT_ASSERT(ops.getNumCourses() != 0);
}