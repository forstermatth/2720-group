#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <exception>

class ScheduleException : public std::exception{
public:
	virtual const char* what() const noexcept = 0;
};

class EmptyContainer : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Empty Container";
	}
};

class TimeConflict : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Conflicting class times";
	}
};

class FileExcept : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Bad File";
	}
};

class XmlParseExcept : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Bad XML Structure";
	}
};

class UnknownNode : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Unknown Node";
	}
};

class BadTime : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Bad Time Value";
	}
};

#endif
