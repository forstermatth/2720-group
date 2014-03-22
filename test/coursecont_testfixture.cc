#include "Course.h"
#include "CourseCont.h"
#include "coursecont_testfixture.h"
#include "Exceptions.h"

void CourseContFixture::setUp(){
	cc = new CourseCont();
}

void CourseContFixture::tearDown(){
	delete cc;
}

void CourseContFixture::testAddCourse(){
	Course c(900, 1015, "MW", "name", "loc 640", 9484739);
	CPPUNIT_ASSERT_NO_THROW(cc->addCourse(c));
	CPPUNIT_ASSERT(cc->first().getStartTime() == c.getStartTime());
	CPPUNIT_ASSERT(cc->first().getEndTime() == c.getEndTime());
	CPPUNIT_ASSERT(cc->first().getStartTime() == c.getStartTime());
	CPPUNIT_ASSERT(cc->first().getDays() == c.getDays());
	CPPUNIT_ASSERT(cc->first().getName() == c.getName());
	CPPUNIT_ASSERT(cc->first().getLoc() == c.getLoc());
	CPPUNIT_ASSERT(cc->first().getId() == c.getId());
}


void CourseContFixture::testReturnFirst(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	cc->addCourse(c1);
	cc->addCourse(c2);
	CPPUNIT_ASSERT(cc->first().getStartTime() == c1.getStartTime());
	CPPUNIT_ASSERT(cc->first().getEndTime() == c1.getEndTime());
	CPPUNIT_ASSERT(cc->first().getStartTime() == c1.getStartTime());
	CPPUNIT_ASSERT(cc->first().getDays() == c1.getDays());
	CPPUNIT_ASSERT(cc->first().getName() == c1.getName());
	CPPUNIT_ASSERT(cc->first().getLoc() == c1.getLoc());
	CPPUNIT_ASSERT(cc->first().getId() == c1.getId());
}

void CourseContFixture::testReturnLast(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	cc->addCourse(c1);
	cc->addCourse(c2);
	CPPUNIT_ASSERT(cc->last().getStartTime() == c2.getStartTime());
	CPPUNIT_ASSERT(cc->last().getEndTime() == c2.getEndTime());
	CPPUNIT_ASSERT(cc->last().getStartTime() == c2.getStartTime());
	CPPUNIT_ASSERT(cc->last().getDays() == c2.getDays());
	CPPUNIT_ASSERT(cc->last().getName() == c2.getName());
	CPPUNIT_ASSERT(cc->last().getLoc() == c2.getLoc());
	CPPUNIT_ASSERT(cc->last().getId() == c2.getId());
}

void CourseContFixture::testNext(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Course c3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->addCourse(c3);
	cc->begin();
	cc->next();
	CPPUNIT_ASSERT(cc->getCourse().getName() == c2.getName());
}

void CourseContFixture::testPrev(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Course c3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->addCourse(c3);
	cc->begin();
	cc->next();
	cc->prev();
	CPPUNIT_ASSERT(cc->getCourse().getName() == c1.getName());
}

void CourseContFixture::testBegin(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->begin();
	CPPUNIT_ASSERT(cc->getCourse().getStartTime() == c1.getStartTime());
	CPPUNIT_ASSERT(cc->getCourse().getEndTime() == c1.getEndTime());
	CPPUNIT_ASSERT(cc->getCourse().getStartTime() == c1.getStartTime());
	CPPUNIT_ASSERT(cc->getCourse().getDays() == c1.getDays());
	CPPUNIT_ASSERT(cc->getCourse().getName() == c1.getName());
	CPPUNIT_ASSERT(cc->getCourse().getLoc() == c1.getLoc());
	CPPUNIT_ASSERT(cc->getCourse().getId() == c1.getId());
}

void CourseContFixture::testEnd(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->end();
	CPPUNIT_ASSERT(cc->getCourse().getStartTime() == c2.getStartTime());
	CPPUNIT_ASSERT(cc->getCourse().getEndTime() == c2.getEndTime());
	CPPUNIT_ASSERT(cc->getCourse().getStartTime() == c2.getStartTime());
	CPPUNIT_ASSERT(cc->getCourse().getDays() == c2.getDays());
	CPPUNIT_ASSERT(cc->getCourse().getName() == c2.getName());
	CPPUNIT_ASSERT(cc->getCourse().getLoc() == c2.getLoc());
	CPPUNIT_ASSERT(cc->getCourse().getId() == c2.getId());
}

void CourseContFixture::testSort(){
	Course c1(900, 1015, "MW", "name", "loc 640", 9484739);
	Course c2(1030, 1200, "MW", "name2", "loc 641", 453224);
	Course c3(1300, 1400, "TR", "name3", "loc 642", 43588934);
	c1.setRating(1);
	c2.setRating(2);
	c3.setRating(3);
	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->addCourse(c3);
	cc->sort();
	CPPUNIT_ASSERT(cc->first().getId() == c3.getId());
	CPPUNIT_ASSERT(cc->last().getId() == c1.getId());
}

void CourseContFixture::testOverflow(){
	Course c1;
	Course c2;

	cc->addCourse(c1);
	cc->addCourse(c2);
	cc->begin();
	CPPUNIT_ASSERT_NO_THROW(cc->getCourse());
	CPPUNIT_ASSERT_NO_THROW(cc->next());
	CPPUNIT_ASSERT_NO_THROW(cc->next());
	CPPUNIT_ASSERT_NO_THROW(cc->next());
}