#include "InputWrap.h"
#include "inputwrap_testfixture.h"
#include "Exceptions.h"
#include "Options.h"
#include "CourseCont.h"
#include "Course.h"
#include "Lab.h"

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

	CPPUNIT_ASSERT(cc.begin().getName() == comp.getName());
	CPPUNIT_ASSERT(cc.get().getStartTime() == comp.getStartTime());
	CPPUNIT_ASSERT(cc.get().getDays() == comp.getDays());
	CPPUNIT_ASSERT(cc.get().getLoc() == comp.getLoc());
	CPPUNIT_ASSERT(cc.get().getId() == comp.getId());
	
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
	CPPUNIT_ASSERT(cc.begin().getName() == comp1.getName());
	cc.next();
	CPPUNIT_ASSERT(cc.get().getName() == comp2.getName());
	cc.next();
	CPPUNIT_ASSERT(cc.get().getName() == comp3.getName());
	cc.next();
	CPPUNIT_ASSERT(cc.get().getName() == comp4.getName());

}

void InputWrapFixture::testParseLab(){
	std::string str = "testfiles/testinput.xml";
	CourseCont cc;
	Lab la;
	Lab lcomp(1040, 1200, "MWF", "course1lab", "AH250", 1920933);

	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(cc = input->setCourses());

	CPPUNIT_ASSERT_NO_THROW(cc.first().labs.begin());
	CPPUNIT_ASSERT(cc.first().labs.size() > 0);
	CPPUNIT_ASSERT_NO_THROW(la = cc.first().labs.get());

	CPPUNIT_ASSERT(la.getName() == lcomp.getName());
	CPPUNIT_ASSERT(la.getStartTime() == lcomp.getStartTime());
	CPPUNIT_ASSERT(la.getDays() == lcomp.getDays());
	CPPUNIT_ASSERT(la.getLoc() == lcomp.getLoc());
	CPPUNIT_ASSERT(la.getId() == lcomp.getId());
}

void InputWrapFixture::testNumberCourses(){
	std::string str = "testfiles/testinput.xml";
	CourseCont cc;
	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(cc = input->setCourses());
	CPPUNIT_ASSERT(cc.size() == 4);
}

void InputWrapFixture::testNumberLabs(){
	std::string str = "testfiles/testinput.xml";
	CourseCont cc;
	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(cc = input->setCourses());
	
	CPPUNIT_ASSERT(cc.begin().labs.size() == 3);
	cc.next();
	cc.next();
	CPPUNIT_ASSERT(cc.get().labs.size() == 3);
}

void InputWrapFixture::testMultiLabs(){
	std::string str = "testfiles/testinput.xml";
	CourseCont cc;
	Course parsed;
	Lab lcomp1(925, 1030, "MWF", "course1lab", "AH250", 1920933);
	Lab lcomp2(1040, 1300, "MWF", "course3lab1", "AH250", 1920931);
	Lab lcomp3(1140, 1400, "TR", "course3lab2", "AH250", 1920934);
	Lab lcomp4(1240, 1500, "MWF", "course3lab3", "AH250", 1920935);

	input->parse(str);
	CPPUNIT_ASSERT_NO_THROW(cc = input->setCourses());
	cc.begin();

	cc.next();
	cc.next();

    CPPUNIT_ASSERT(cc.get().labs.size() == 3);
	parsed = cc.get();

	CPPUNIT_ASSERT(parsed.labs.size() > 0);
	CPPUNIT_ASSERT_NO_THROW(parsed.labs.begin());

	CPPUNIT_ASSERT(parsed.labs.get().getName() == lcomp2.getName());
	parsed.labs.next();
	CPPUNIT_ASSERT(parsed.labs.get().getName() == lcomp3.getName());
	parsed.labs.next();
	CPPUNIT_ASSERT(parsed.labs.get().getName() == lcomp4.getName());

}
