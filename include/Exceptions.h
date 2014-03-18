#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H


class Exceptions{
	private:
		std::string m_err;
	public:
		Exceptions(std::string err):m_err(err){}
		std::string GetError() {return m_err;}
};

#endif
