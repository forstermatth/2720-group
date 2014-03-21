
#include "lab_testfixture.h"
#include "course_testfixture.h"
#include "coursecont_testfixture.h"
#include "coursesched_testfixture.h"
#include "inputwrap_testfixture.h"
#include "options_testfixture.h"
#include "output_testfixture.h"
#include "rater_testfixture.h"
#include "scheduler_testfixture.h"

#include <cppunit/ui/text/TestRunner.h>

/// run the testing suite
int main(){
	
	CppUnit::TextUi::TestRunner runnner;
	runnner.addTest(LabFixture::suite());
	runnner.addTest(CourseFixture::suite());
	runnner.addTest(CourseContFixture::suite());
	runnner.addTest(CourseSchedFixture::suite());
	runnner.addTest(InputWrapFixture::suite());
	runnner.addTest(OptionsFixture::suite());
	runnner.addTest(OutputFixture::suite());
	runnner.addTest(RaterFixture::suite());
	runnner.addTest(SchedulerFixture::suite());
	runnner.run();


	return 0;
}
