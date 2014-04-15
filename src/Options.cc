#include "Options.h"

Options::Options()
	: numClasses(0){

}

Options::Options(unsigned int nc, list<unsigned int> rc, Times tp, unsigned int bp = 0, unsigned int bs = 0, unsigned int be = 1)
	: numClasses(nc), requiredCourses(rc), timePreference(tp), breakPadding(bp), breakStart(bs), breakEnd(be){

}

unsigned int const Options::getNumCourses(){
	return numClasses;
}

list<unsigned int> & Options::getRequiredCourses(){
	return requiredCourses;
}

Times const Options::getTimePreference(){
	return timePreference;
}

unsigned int const Options::getBreakPadding(){
	return breakPadding;
}

unsigned int const Options::getBreakStart(){
	return breakStart;
}

unsigned int const Options::getBreakEnd(){
	return breakEnd;
}