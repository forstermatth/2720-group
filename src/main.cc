#include "Output.h"
#include "InputWrap.h"
#include "Rater.h"
#include "Scheduler.h"
#include "CourseSched.h"
#include "CourseCont.h"
#include "Options.h"
#include "Course.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  Output outp;
  InputWrap input;
  CourseCont<Course> _courseCont;
  Options opt;
  input.parse("../testfiles/testinput.xml");
  opt = input.setOptions();
  _courseCont = input.setCourses();
  Rater _rater(&opt, &_courseCont);
  _rater.rateCourses();
  CourseSched sched;
  Scheduler _scheduler;
  sched = _scheduler.generateSchedule(_courseCont, opt);
  outp.generate(opt, sched);
}
