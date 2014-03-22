#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <exception>

/// General Exception for the program -  all customs should inherit from this
class ScheduleException : public std::exception{
public:
	virtual const char* what() const noexcept = 0;
};

/// Exception to throw if there is an empty container
class EmptyContainer : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Empty Container";
	}
};

/// Exception to throw if there is a time conflict
class TimeConflict : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Conflicting class times";
	}
};

/// Exception to throw if there is a file problem
class FileExcept : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Bad File";
	}
};

/// Exception to throw if there is a structural parse problem
class XmlParseExcept : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Bad XML Structure";
	}
};

/// Exception to throw if node is not set with a value
class NoValue : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "No value for node";
	}
};

/// Exception to throw if an unkown node is encountered while parsing
class UnknownNode : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Unknown Node";
	}
};

/// Exception to throw if there is a bad time type passed
class BadTime : public ScheduleException{
public:
	virtual const char* what() const noexcept {
		return "Bad Time Value";
	}
};

#endif
