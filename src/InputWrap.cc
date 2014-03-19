#include "InputWrap.h"
#include "Exceptions.h"
#include <cstdlib>

void InputWrap::parse(std::string _input){
	std::ifstream inputfile;

	try{
		inputfile.open(_input, std::ifstream::in);
	}catch(exception &e){
		std::cout << "Error: Bad input file. " << e.what();
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

	// try to find the options node
	try{
		root_node = doc.first_node("Options");
	}catch(rapidxml::parse_error &e){
		std::cout << "Parse error: " << e.what() << std::endl;
		throw XmlParseExcept();
	}
	if(root_node == 0){
		throw XmlParseExcept();
	}

	rapidxml::xml_node<> * optnode;

	//try to find first options child
	try{
		optnode = root_node->first_node();
	}catch(rapidxml::parse_error &e){
		std::cout << "Parse error: " << e.what() << std::endl;
		throw XmlParseExcept();
	}
	if(optnode == 0){
		throw XmlParseExcept();
	}

	unsigned int numcourse;
	std::list<unsigned int> reqcourses;
	Times timepref;
	unsigned int breakpad;
	unsigned int breakstart;
	unsigned int breakend;

	//iterate through all options
	do{
		std::string name = optnode->name();
		if(name == (std::string) "NumberOfCourses"){
			numcourse = atoi(optnode->value());
		}else if(name == (std::string) "RequiredCourses"){
			rapidxml::xml_node<> * idnode = optnode->first_node();
			do{
				reqcourses.push_back(atoi(idnode->value()));
				idnode = idnode->next_sibling();
			}while(idnode != 0);
		}else if(name == (std::string) "TimePreferences"){
			std::string val = optnode->value();
			if(val == "Am"){
				timepref = Times::Am;
			}else if(val == "Pm"){
				timepref = Times::Pm;
			}else if(val == "None"){
				timepref = Times::None;
			}else{
				throw BadTime();
			}
		}else if(name == (std::string) "BreakPadding"){
			breakpad = atoi(optnode->value());
		}else if(name == (std::string) "BreakStart"){
			breakstart = atoi(optnode->value());
		}else if(name == (std::string) "BreakEnd"){
			breakend =  atoi(optnode->value());
		}else{
			throw UnknownNode();
		}

		optnode = optnode->next_sibling();

	}while(optnode != 0);

	Options ops(numcourse, reqcourses, timepref, breakpad, breakstart, breakend);
	return ops;


}

CourseCont InputWrap::setCourses(){
	CourseCont cc;

	//start at courses header
	try{
		root_node = doc.first_node("Courses");
	}catch(rapidxml::parse_error &e){
		std::cout << "Parse error: " << e.what() << std::endl;
		throw XmlParseExcept();
	}
	if(root_node == 0){
		throw XmlParseExcept();
	}

	rapidxml::xml_node<> * coursenode;

	//try to find first course child
	try{
		coursenode = root_node->first_node();
	}catch(rapidxml::parse_error &e){
		std::cout << "Parse error: " << e.what() << std::endl;
		throw XmlParseExcept();
	}
	if(coursenode == 0){
		throw XmlParseExcept();
	}

	rapidxml::xml_node<> * datanode;
	

	do{
		std::string cname;
		unsigned int cstart;
		unsigned int cend;
		std::string cdays;
		std::string cloc;
		unsigned int cid;
		
		datanode = coursenode->first_node();
		do{
			std::string name = datanode->name();
			if(name == (std::string) "Name"){
				cname = datanode->value();
			}else if(name == "StartTime"){
				cstart = atoi(datanode->value());
			}else if(name == "EndTime"){
				cend = atoi(datanode->value());
			}else if(name == "Days"){
				cdays = datanode->value();
			}else if(name == "Location"){
				cloc = datanode->value();
			}else if(name == "id"){
				cid = atoi(datanode->value());
			}else{
				throw UnknownNode();
			}
			datanode = datanode->next_sibling();
		}while(datanode != 0);

		cc.addCourse(Course(cstart, cend, cdays, cname, cloc, cid));
		coursenode = coursenode->next_sibling();
	}while(coursenode != 0);



	return cc;
}