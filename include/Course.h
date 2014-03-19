#ifndef __COURSE_H
#define __COURSE_H

#include <string>


class Course {
public:
	Course(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId);
	Course(){};

	unsigned int getEndTime() const;
	unsigned int getStartTime() const;
	std::string getDays() const;
	std::string getName() const;
	std::string getLoc() const;
	unsigned int getId() const;
	unsigned int getRating() const;

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