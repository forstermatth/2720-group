#ifndef __COURSEBASE_H
#define __COURSEBASE_H

#include <string>
#include <list>


/// Course base object class for storing course and lab values
class CourseBase {
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
	CourseBase(unsigned int _startTime, unsigned int _endTime, std::string _days, std::string _courseName, std::string _courseLoc, unsigned int _courseId);
	
	/// Copy constuctor - ensures proper assignment
	CourseBase(const CourseBase& _course){
		startTime = _course.startTime;
		endTime =  _course.endTime;
		days =  _course.days;
		courseName =  _course.courseName;
		courseLoc =  _course.courseLoc;
		courseId = _course.courseId;
		rating = _course.rating;
	}

	/// Overloaded assignment operator - ensures proper assignment
	CourseBase& operator= (const CourseBase& rhs);

	/// Constructor - does nothing
	CourseBase(){};

	virtual ~CourseBase(){}

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

protected:
	unsigned int startTime; ///< the course start time
	unsigned int endTime; ///< the course end time
	std::string days; ///< the course days: MTWRF
	std::string courseName; ///< the course name
	std::string courseLoc; ///< the course location
	unsigned int courseId; ///< the course id
	unsigned int rating; ///< the course rating

};

#endif