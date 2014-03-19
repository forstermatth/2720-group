#ifndef __COURSE_H
#define __COURSE_H

#include <string>


class Course {
public:
	Course(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId);
	Course(){};

	unsigned int const getEndTime();
	unsigned int const getStartTime();
	std::string const getDays();
	std::string const getName();
	std::string const getLoc();
	unsigned int const getId();
	unsigned int const getRating();

	void setRating(unsigned int _rating);

private:
	unsigned int startTime;
	unsigned int endTime;
	std::string days;
	std::string courseName;
	std::string courseLoc;
	unsigned int courseId;
	unsigned int rating;

};

#endif