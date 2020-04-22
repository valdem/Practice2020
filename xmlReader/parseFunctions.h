#pragma once

#include <iostream>
#include <fstream>
#include "tinyxml2.h"

void parse_testcase(tinyxml2::XMLElement* path, std::ofstream& bigtest);
void parse_expression(tinyxml2::XMLElement* path, std::ofstream& bigtest);
void parse_section(tinyxml2::XMLElement* path, std::ofstream& bigtest);
void yacheika(tinyxml2::XMLElement* path, std::ofstream& bigtest);

int i = 0;
