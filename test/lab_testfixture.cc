#include "Lab.h"
#include "lab_testfixture.h"
#include "Exceptions.h"

void LabFixture::setUp(){
	l = new Lab(1115, 1500, "TR", "course", "location", 894372);
}

void LabFixture::tearDown(){
	delete l;
}

void LabFixture::testGetEndTime(){
	CPPUNIT_ASSERT(l->getEndTime() == 1500);
}

void LabFixture::testGetStartTime(){
	CPPUNIT_ASSERT(l->getStartTime() == 1115);
}

void LabFixture::testConstructor(){
	Lab la(945, 1215, "MWF", "coursename", "courseloc", 788934);
	CPPUNIT_ASSERT(la.getStartTime() == 945);
	CPPUNIT_ASSERT(la.getEndTime() == 1215);
	CPPUNIT_ASSERT(la.getDays() == "MWF");
	CPPUNIT_ASSERT(la.getName() == "coursename");
	CPPUNIT_ASSERT(la.getLoc() == "courseloc");
	CPPUNIT_ASSERT(la.getId() == 788934);
}

void LabFixture::testGetDays(){
	CPPUNIT_ASSERT(l->getDays() == "TR");
}

void LabFixture::testGetName(){
	CPPUNIT_ASSERT(l->getName() == "course");
}

void LabFixture::testGetLoc(){
	CPPUNIT_ASSERT(l->getLoc() == "location");
}

void LabFixture::testGetId(){
	CPPUNIT_ASSERT(l->getId() == 894372);
}

void LabFixture::testRating(){
	l->setRating(5);
	CPPUNIT_ASSERT(l->getRating() == 5);
}