#include "InputWrap.h"
#include "inputwrap_testfixture.h"
#include "Exceptions.h"
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