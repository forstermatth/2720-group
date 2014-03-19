#include "Scheduler.h"
#include "scheduler_testfixture.h"
#include "Exceptions.h"

void SchedulerFixture::setUp(){
	sch = new Scheduler;
}

void SchedulerFixture::tearDown(){
	delete sch;
}
