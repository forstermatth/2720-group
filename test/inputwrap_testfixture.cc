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
	std::string str = "testfiles/testinput.xml";
	CPPUNIT_ASSERT_NO_THROW(input->parse(str));
}

void InputWrapFixture::testPopulateOptions(){
	std::string str = "testfiles/testinput.xml";
	Options ops;
	std::list<unsigned int> reqCourses;
	reqCourses.push_back(100102);
	reqCourses.push_back(122102);

	Options compare(4, reqCourses, Times::None, 0, 1200, 1300);
	
	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(ops = input->setOptions());
	CPPUNIT_ASSERT(ops.getNumCourses() == compare.getNumCourses());
	CPPUNIT_ASSERT(ops.getRequiredCourses() == compare.getRequiredCourses());
	CPPUNIT_ASSERT(ops.getTimePreference() == compare.getTimePreference());
	CPPUNIT_ASSERT(ops.getBreakPadding() == compare.getBreakPadding());
	CPPUNIT_ASSERT(ops.getBreakStart() == compare.getBreakStart());
	CPPUNIT_ASSERT(ops.getBreakEnd() == compare.getBreakEnd());
}