#ifndef __INPUTWRAP_H
#define __INPUTWRAP_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "rapidxml/rapidxml.hpp"
#include "Options.h"

class InputWrap{
public:
		void parse(std::string _input);
		void setOptions(Options &ops);

private:
		std::vector<char> buffer;
		rapidxml::xml_document<> doc;
		rapidxml::xml_node<> * root_node;
};

#endif