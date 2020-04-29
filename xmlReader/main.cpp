#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "parseFunctions.h"
#include <stdlib.h>

void parentParse(tinyxml2::XMLNode* parent,tinyxml2::XMLElement* firstPath,tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    firstPath = parent->FirstChildElement()->NextSiblingElement();
    while(firstPath) {
        path = firstPath;
        path = chooseParserFirst(path, bigtest);
        if (firstPath->NextSiblingElement("TestCase")||firstPath->NextSiblingElement("Expression")||firstPath->NextSiblingElement("Section")) {
            firstPath = firstPath->NextSiblingElement();
        }
        else {
            break;
        }
    }
}

tinyxml2::XMLElement* chooseParserFirst(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    if (path->FirstChildElement("TestCase")) {
        path = path->FirstChildElement("TestCase");
        parse_testcase(path, bigtest);
    }
    else if (path->FirstChildElement("Expression")) {
        path = path->FirstChildElement("Expression");
        parse_expression(path, bigtest);
    }
    else if (path->FirstChildElement("Section")) {
        path = path->FirstChildElement("Section");
        parse_section(path, bigtest);
    }
    else {
        yacheika(path, bigtest);
    }
    return path;
}

tinyxml2::XMLElement* chooseParserNext(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    if (path->NextSiblingElement("TestCase")) {
        path = path->NextSiblingElement("TestCase");
        parse_testcase(path, bigtest);
    }
    else if (path->NextSiblingElement("Expression")) {
        path = path->NextSiblingElement("Expression");
        parse_expression(path, bigtest);
    }
    else if (path->NextSiblingElement("Section")) {
        path = path->NextSiblingElement("Section");
        parse_section(path, bigtest);
    }

    return path;
}

void parse_testcase(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    chooseParserFirst(path, bigtest);
}

void parse_section(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    chooseParserFirst(path, bigtest);
}

void parse_expression(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
   chooseParserFirst(path, bigtest);
}

tinyxml2::XMLElement* yacheika(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    bigtest<<"<tr>";
    bigtest<<"<td class = " <<"number"<< ">"<< i ;
    std::string infoFile = path->Attribute("filename");
    bigtest<<"<td class = " <<"name"<<">" << infoFile << "</td>" ;
    
    std::string infoSuccess = path->Attribute("success");
    if (infoSuccess == "true") {
        bigtest<<"<td class = " <<"pass"<< ">" << infoSuccess <<" </td>";
    }
    else  {
        bigtest<<"<td class = " <<"fail"<< ">" << infoSuccess <<" </td>";
    }
    
    std::string infoFailLine = path->Attribute("line");
    bigtest<<"<td>"<<infoFailLine<<"</td>";
    int failLine = atoi(infoFailLine.c_str());
    std::ifstream lines;
    lines.open(fileTest);
    std::string lines_content;
    for (size_t i = 0; i<failLine-3; i++) {
        std::getline(lines, lines_content);
    }
    bigtest<<"<td>";
    bigtest<<"<pre><code data-language = c>";
    for (size_t i = 0; i<6; i++) {
        std::getline(lines, lines_content);
        bigtest<<lines_content<<std::endl;
    }
    bigtest<<"</code></pre>";
    bigtest<<"</td>";
    lines.close();
    
    bigtest<<"</tr>";
    i++;
    path = chooseParserNext(path, bigtest);

    return path;
}

int main(int argc, char* argv[]) {
    if (argc<4) {
        return -1;
    }
    
    tinyxml2::XMLDocument doc;
    doc.LoadFile(argv[1]);
    tinyxml2::XMLElement* firstPath = doc.FirstChildElement("Catch")->FirstChildElement("Group");
    

    std::ofstream bigtest;
    bigtest.open(argv[2]);
    if (!bigtest.is_open()) {
        std::cout<<"error";
    }
    
    std::ifstream header;
    header.open(argv[3]);
    std::string header_content;
    while (std::getline(header, header_content)) {
        header>>header_content;
    }
    bigtest<<header_content;
    header.close();
        
    fileTest = argv[4];
    
    bigtest<<"<div id = " <<"page"<< ">";
    bigtest<<"<h1>"<<"</h1><br/>";
    bigtest<<"<div id = " <<"info"<< "> ";
    bigtest<<"<p><i>Фомин Вадим Евгеньевич<br/>";
    bigtest<<"группа КМБО-02-19<br/>";
    bigtest<<"4 марта 2020<i/></p><br/>";
    bigtest<<"</div>";
    bigtest<<"<table id = " <<"tests"<< ">";
    bigtest<<"<tbody>";
    bigtest<<"<tr>";
    bigtest<<"<td class = number>№</td>";
    bigtest<<"<td class = name>Name</td>";
    bigtest<<"<td>Passing</td>";
    bigtest<<"<td>Line of fail</td>";
    bigtest<<"<td>Fail</td>";
    bigtest<<"</tr>";
    
    tinyxml2::XMLElement* path = firstPath;
    

    firstPath = firstPath->FirstChildElement();
    path = chooseParserFirst(path, bigtest);
    tinyxml2::XMLNode* parent = path->Parent()->FirstChild();
    while(parent->FirstChildElement("TestCase")||parent->FirstChildElement()->FirstChildElement("Expression")||parent->FirstChildElement()->FirstChildElement("Section")) {
        if (parent->FirstChildElement()->NextSiblingElement("TestCase")||parent->FirstChildElement()->NextSiblingElement("Expression")||parent->FirstChildElement()->NextSiblingElement("Section")) {
            parentParse(parent, firstPath, path, bigtest);
            parent = parent->Parent();
        }
        else if(parent->Parent()){
            parent = parent->Parent();
        }
    }
    
    bigtest<<"</tbody>";
    bigtest<<"</table>";
    bigtest<<"</div>";
    bigtest<<"</body>";
    bigtest<<"</html>";
    bigtest.close();
    if (!bigtest.is_open()) {
        std::cout<<"error";
    }
}
