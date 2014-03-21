#ifndef __COURSE_H
#define __COURSE_H

#include <string>

/// Course object class for storing course values
class Course {
public:

	/// Constructor - initializes members with values given
	/**
		\param _startTime the start time of the course
		\param _endTime the end time of the course
		\param _days the days of the week the class lies: MTWRF
		\param _courseName the name of the course
		\param _courseLoc the location of the course
		\param _courseId the unique identifier of the course
	*/
	Course(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId);
	
	/// Constructor - does nothing
	Course(){};

	/// returns the course end time
	unsigned int getEndTime() const;

	/// returns the course start time
	unsigned int getStartTime() const;

	/// returns the course days
	std::string getDays() const;

	/// returns the course name
	std::string getName() const;

	///returns the course location
	std::string getLoc() const;

	/// returns the course id
	unsigned int getId() const;

	/// returns the course rating
	unsigned int getRating() const;

	/// sets the course rating
	/** \param _rating the rating to set for the course */
	void setRating(unsigned int _rating);

	/// returns true if the courses are the same, false otherwise
	/** \param crs the course to compare against */
	bool equal(Course& crs);

	/// Adds the specified amount of padding to start and end time.
	/** \param _padding The amount of padding to add.*/
	void addPadding(unsigned int _padding);

private:
	unsigned int startTime; ///< the course start time
	unsigned int endTime; ///< the course end time
	std::string days; ///< the course days: MTWRF
	std::string courseName; ///< the course name
	std::string courseLoc; ///< the course location
	unsigned int courseId; ///< the course id
	unsigned int rating; ///< the course rating

};

#endif