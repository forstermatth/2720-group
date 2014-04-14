#include "InputWrap.h"

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
			throw UnknownNode(name);
		}

		optnode = optnode->next_sibling();

	}while(optnode != 0);

	Options ops(numcourse, reqcourses, timepref, breakpad, breakstart, breakend);
	return ops;


}

CourseCont<Course> InputWrap::setCourses(){
	CourseCont<Course> cc;

	//Temporary Storage
	std::list<Lab> labs;
	std::list<Course> courses;

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
		std::string cname = "";
		unsigned int cstart = 0;
		unsigned int cend = 0;
		std::string cdays = "";
		std::string cloc = "";
		unsigned int cid = 0;

		bool haslab = false;
		
		datanode = coursenode->first_node();
		do{

			std::string cnode = datanode->name();
			std::string cval = datanode->value();

			if(cnode == "Lab"){
				haslab = true;
			}else{
				setVars(cnode, cval, cname, cstart, cend, cdays, cloc, cid);
			}
			
			datanode = datanode->next_sibling();
		}while(datanode != 0);

		courses.push_back(Course(cstart, cend, cdays, cname, cloc, cid));

		if(haslab){

			datanode = coursenode->first_node("Lab");

			do{

				std::string lname = "";
				unsigned int lstart = 0;
				unsigned int lend = 0;
				std::string ldays = "";
				std::string lloc = "";
				unsigned int lid = 0;
				
				rapidxml::xml_node<> * labdata = datanode->first_node();
				do{

					std::string lnode = labdata->name();
					std::string labval = labdata->value();
					setVars(lnode, labval, lname, lstart, lend, ldays, lloc, lid);

					labdata = labdata->next_sibling();
				}while(labdata != 0);

				courses.back().labs.add(Lab(lstart, lend, ldays, lname, lloc, lid));

				datanode = datanode->next_sibling("Lab");
			}while(datanode != 0);
			
		}


		coursenode = coursenode->next_sibling();
	}while(coursenode != 0);

	for(std::list<Course>::iterator it = courses.begin(); it != courses.end(); it++){
		cc.add(*it);
	}
	
	cc.begin();
	return cc;
}


void InputWrap::setVars(std::string node, std::string value, std::string &_name, \
            		    unsigned int &_start, unsigned int &_end, \
					    std::string &_days, std::string &_loc, unsigned int &_id){

	if(value.empty()){
		throw NoValue();
	}

	if(node == (std::string) "Name"){
		_name = value;
	}else if(node == "StartTime"){
		_start = atoi(value.c_str());
	}else if(node == "EndTime"){
		_end = atoi(value.c_str());
	}else if(node == "Days"){
		_days = value;
	}else if(node == "Location"){
		_loc = value;
	}else if(node == "id"){
		_id = atoi(value.c_str());
	}else{
		throw UnknownNode(node);
	}

}