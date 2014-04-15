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

#include "Scheduler.h"
#include <iostream>
using namespace std;

int main(){
	Scheduler _scheduler;

	string userinput;

	cout << "XML Input (filename including .xml): ";
	cin >> userinput;

	_scheduler.grab(userinput);
	_scheduler.work();
	_scheduler.print();
	
}

