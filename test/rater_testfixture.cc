#include "Rater.h"
#include "rater_testfixture.h"
#include "Exceptions.h"

void RaterFixture::setUp(){
	list<unsigned int> requiredCourses;
	requiredCourses.push_back(894372);
	requiredCourses.push_back(894373);
	opts = new Options(5, requiredCourses, Times::Am, 30, 1200, 1230);
	cc = new CourseCont();
}

void RaterFixture::tearDown(){
	delete opts;
	delete cc;
}

void RaterFixture::setRatingOnReqCourses(){
	Course c(900, 1015, "MW", "name", "loc 640", 894372);
	cc->addCourse(c);
	Rater r(opts, cc);
	r.rateCourses();
	CPPUNIT_ASSERT(cc->first().getRating() == 30);
}