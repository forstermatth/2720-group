#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <exception>

class EmptyContainer : public std::exception{
public:
	virtual const char* what() const noexcept {
		return "Empty Container";
	}
};

class TimeConflict : public std::exception{
public:
	virtual const char* what() const noexcept {
		return "Conflicting class times";
	}
};

class FileExcept : public std::exception{
public:
	virtual const char* what() const noexcept {
		return "Bad File";
	}
};

#endif
