#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include "tinyxml2.h"

void parse_testcase(tinyxml2::XMLElement* path, std::ofstream& bigtest);
void parse_expression(tinyxml2::XMLElement* path, std::ofstream& bigtest);
void parse_section(tinyxml2::XMLElement* path, std::ofstream& bigtest);
tinyxml2::XMLElement* yacheika(tinyxml2::XMLElement* path, std::ofstream& bigtest);
tinyxml2::XMLElement* chooseParserFirst(tinyxml2::XMLElement* path, std::ofstream& bigtest);
tinyxml2::XMLElement* chooseParserNext(tinyxml2::XMLElement* path, std::ofstream& bigtest);
void parentParse(tinyxml2::XMLNode* parent,tinyxml2::XMLElement* firstPath,tinyxml2::XMLElement* path, std::ofstream& bigtest);

std::string fileTest;
int i = 1;
int testForStudent;
int passTests = 0;
