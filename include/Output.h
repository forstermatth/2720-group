#ifndef __OUTPUT_H
#define __OUTPUT_H

#include <iomanip>
#include <iostream>
#include <list>
#include "CourseSched.h"
#include "Options.h"
#include "Course.h"
#include "Lab.h"

class Output{
public:
	void generate(Options opts, CourseSched sched);

};

#endif