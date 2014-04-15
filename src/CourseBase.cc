#include "CourseBase.h"
using namespace std;

CourseBase::CourseBase(unsigned int _startTime, unsigned int _endTime, string _days, string _courseName, string _courseLoc, unsigned int _courseId){
	startTime = _startTime;
	endTime = _endTime;
	days = _days;
	courseName = _courseName;
	courseLoc = _courseLoc;
	courseId = _courseId;
}

unsigned int CourseBase::getEndTime() const{
	return endTime;
}

unsigned int CourseBase::getStartTime() const{
	return startTime;
}

string CourseBase::getDays() const{
	return days;
}

string CourseBase::getName() const{
	return courseName;
}

string CourseBase::getLoc() const{
	return courseLoc;
}

unsigned int CourseBase::getId() const{
	return courseId;
}

void CourseBase::setRating(unsigned int _rating){
	rating = _rating;
}

unsigned int CourseBase::getRating() const{
	return rating;
}

bool CourseBase::equal(CourseBase& crs){
	return (crs.getEndTime() == endTime
		&& crs.getStartTime() == startTime
		&& crs.getDays() == days
		&& crs.getName() == courseName
		&& crs.getId() == courseId
		&& crs.getLoc() == courseLoc);
}

CourseBase& CourseBase::operator= (const CourseBase& rhs){
	
	this->startTime = rhs.getStartTime();
	this->endTime = rhs.getEndTime();
	this->days = rhs.getDays();
	this->courseName = rhs.getName();
	this->courseLoc = rhs.getLoc();
	this->courseId = rhs.getId();

	return *this;
}

void CourseBase::addPadding(unsigned int _padding){
	startTime = (((startTime/100 - _padding/60) - ((int((startTime%100) - (_padding%60))<0)?1:0))*100) + (((int(startTime%100 - _padding%60)<0)?60:0) + int(startTime%100 - _padding%60));
	endTime = (((endTime/100 + _padding/60) + (endTime%100 + _padding%60)/60)*100) +(endTime%100 + _padding%60)%60;
}