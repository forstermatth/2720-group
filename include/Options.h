#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <list>
using namespace std;

enum Times {Am, Pm, None};

class Options{
private:
	unsigned int numClasses;
	list<unsigned int> requiredCourses;
	Times timePreference;
	unsigned int breakPadding;
	unsigned int breakStart;
	unsigned int breakEnd;
public:
	/**
		Default constructor for the options class, sets everything to 0.
	*/
	Options();

	/**
		Constructor for the options class.
		@param numClasses The number of classes that the user wants to take in a semester.
		@param requiredCourses A list containing any required course ids.
		@param time The users time preference.
		@param breakPadding The amount of time that should be inbetween two given classes. Optional parameter,
		will default to 0.
		@param breakStart The start time of a desired break in 24 hour time. Optional parameter, will default to 0.
		@param breakEnd The end time of a desired berak in 24 hour time. Optional parameter, will default to 1.
	*/
	Options(unsigned int numClasses, list<unsigned int> requiredCouses, Times time, unsigned int breakPadding,
		unsigned int breakStart, unsigned int breakEnd);

	/**
		Returns the desired number of classes
	*/
	unsigned int const getNumCourses();

	/**
		Returns a refernence to a constent list of required course ids.
	*/
	list<unsigned int> & getRequiredCourses();

	/**
		Returns the uses class time preference.
	*/
	Times const getTimePreference();

	/**
		Returns the amount of time that should be added before and after a class time
		to correctly adjust for the uses desired break. eg: user wants a 30 min break
		inbetween classes, function will return 15.
	*/
	unsigned int const getBreakPadding();

	/**
		Returns the start time of a desired break in 24 hour time.
	*/
	unsigned int const getBreakStart();

	/**
		Returns the end time of a desired break in 24 hour time.
	*/
	unsigned int const getBreakEnd();
};

#endif