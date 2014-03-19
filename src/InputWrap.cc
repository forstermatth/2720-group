#include "InputWrap.h"
#include "Exceptions.h"


void InputWrap::parse(std::string _input){
	std::ifstream inputfile;

	try{
		inputfile.open(_input, std::ifstream::in);
	}catch(FileExcept &e){
		std::cout << "Error: Bad input file.";
		return;
	}

	if(!inputfile.is_open()){
		throw FileExcept();
	}
	
	buffer.assign(std::istreambuf_iterator<char>(inputfile), std::istreambuf_iterator<char>());
	buffer.push_back('\0');

	doc.parse<0>(&buffer[0]);

	inputfile.close();
}

Options InputWrap::setOptions(){
	Options ops;

	try{
		root_node = doc.first_node("Options");
	}catch(rapidxml::parse_error &e){
		std::cout << "Parse error: " << e.what() << std::endl;
	}
	if(root_node == 0){
		throw XmlParseExcept();
	}

	rapidxml::xml_node<> * optnode;

	try{
		optnode = root_node->first_node();
	}catch(rapidxml::parse_error &e){
		std::cout << "Parse error: " << e.what() << std::endl;
	}
	if(optnode == 0){
		throw XmlParseExcept();
	}

	do{

	}while(optnode != 0);

	return ops;
}