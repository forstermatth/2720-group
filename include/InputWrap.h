#ifndef __INPUTWRAP_H
#define __INPUTWRAP_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "rapidxml/rapidxml.hpp"
#include "Options.h"
#include "CourseCont.h"


/**
	\brief Input wrapper for RapidXML, used for parsing and populating courses and options
*/
class InputWrap{
public:
		/// Parse the FILENAME passed, requires extension (.xml)
		/** \param _input the file name to parse (needs .xml) */
		void parse(std::string _input);

		/// Populate options with the parse xml file, returns populated object
		Options setOptions();

		/// Populate course container with courses from xml file, returns populated object
		CourseCont setCourses();

private:
		std::vector<char> buffer; ///< the file buffer stored after parse
		rapidxml::xml_document<> doc; ///< the DOM tree parsed
		rapidxml::xml_node<> * root_node; ///the root node of the tree
};

#endif