#ifndef __INPUTWRAP_H
#define __INPUTWRAP_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "rapidxml/rapidxml.hpp"

class InputWrap{
public:
		void parse(std::string _input);
private:
		std::vector<char> buffer;
		rapidxml::xml_document<> doc;
		rapidxml::xml_node<> * root_node;
};

#endif