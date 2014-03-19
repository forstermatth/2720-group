#include "InputWrap.h"
#include "Exceptions.h"


void InputWrap::parse(std::string _input){
	std::ifstream inputfile;
	std::string input = _input+".xml";

	try{
		inputfile.open(input);
	}catch(FileExcept e){
		std::cout << "Error: Bad input file.";
		return;
	}
	
	buffer.assign(std::istreambuf_iterator<char>(inputfile), std::istreambuf_iterator<char>());
	buffer.push_back('\0');

	doc.parse<0>(&buffer[0]);

}