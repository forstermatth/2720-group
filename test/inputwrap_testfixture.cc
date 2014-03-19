#include "InputWrap.h"
#include "inputwrap_testfixture.h"
#include "Exceptions.h"
#include "Options.h"
#include "CourseCont.h"
#include "Course.h"

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

void InputWrapFixture::testPopulateCourse(){
	std::string str = "testfiles/testinput.xml";
	CourseCont cc;
	Course comp(925, 1030, "MWF", "course1", "AH250", 1920932);

	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(cc = input->setCourses());
	CPPUNIT_ASSERT(cc.first().getName() == comp.getName());
	CPPUNIT_ASSERT(cc.getCourse().getStartTime() == comp.getStartTime());
	CPPUNIT_ASSERT(cc.getCourse().getDays() == comp.getDays());
	CPPUNIT_ASSERT(cc.getCourse().getLoc() == comp.getLoc());
	CPPUNIT_ASSERT(cc.getCourse().getId() == comp.getId());
	
}

void InputWrapFixture::testPopulateMultiCourses(){
	std::string str = "testfiles/testinput.xml";
	CourseCont cc;
	Course comp1(925, 1030, "MWF", "course1", "AH250", 1920932);
	Course comp2(1045, 1200, "MWF", "course2", "AH251", 43573094);
	Course comp3(1300, 1415, "TR", "course3", "AH252", 3453434);
	Course comp4(1430, 1630, "TR", "course4", "AH253", 87364832);

	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(cc = input->setCourses());
	CPPUNIT_ASSERT(cc.first().getName() == comp1.getName());
	cc.next();
	CPPUNIT_ASSERT(cc.getCourse().getName() == comp2.getName());
	cc.next();
	CPPUNIT_ASSERT(cc.getCourse().getName() == comp3.getName());
	cc.next();
	CPPUNIT_ASSERT(cc.getCourse().getName() == comp4.getName());

}