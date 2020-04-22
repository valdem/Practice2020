#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "parseFunctions.h"

void parse_testcase(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    if (path->FirstChildElement("TestCase")) {
        path = path->FirstChildElement("TestCase");
        parse_testcase(path, bigtest);
    }
    else if (path->FirstChildElement("Expression")) {
        path = path->FirstChildElement("Expression");
        parse_expression(path,bigtest);
    }
    else if (path->FirstChildElement("Section")) {
        path = path->FirstChildElement("Section");
        parse_section(path, bigtest);
    }
    else {
        yacheika(path, bigtest);
        i += 1;
    }
}

void parse_section(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    if (path->FirstChildElement("TestCase")) {
        path = path->FirstChildElement("TestCase");
        parse_testcase(path, bigtest);
    }
    else if (path->FirstChildElement("Expression")) {
        path = path->FirstChildElement("Expression");
        parse_expression(path,bigtest);
    }
    else if (path->FirstChildElement("Section")) {
        path = path->FirstChildElement("Section");
        parse_section(path, bigtest);
    }
    else {
        yacheika(path, bigtest);
        i += 1;
    }
}
void parse_expression(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
   if (path->FirstChildElement("TestCase")) {
        path = path->FirstChildElement("TestCase");
        parse_testcase(path, bigtest);
    }
    else if (path->FirstChildElement("Expression")) {
        path = path->FirstChildElement("Expression");
        parse_expression(path,bigtest);
    }
    else if (path->FirstChildElement("Section")) {
        path = path->FirstChildElement("Section");
        parse_section(path, bigtest);
    }
    else {
        yacheika(path, bigtest);
        i += 1;
    }
}

void yacheika(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
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
    bigtest<<"<td>"<< infoFailLine << "</td>" ;
    bigtest<<"</tr>";
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
    
}

int main(int argc, char* argv[]) {
    if(argc<3){
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
    
    std::ifstream header(argv[3]);
    std::string header_content;
    while (!header.eof()) {
        header>>header_content;
    }
    bigtest<<header_content;
    
    bigtest<<"<div id = " <<"page"<< ">";
    bigtest<<"<h1>"<<"</h1><br/>";
    bigtest<<"<div id = " <<"info"<< "> ";
    bigtest<<"<p><i>Фомин Вадим Евгеньевич<br/>";
    bigtest<<"группа КМБО-02-19<br/>";
    bigtest<<"4 марта 2020<i/></p><br/>";
    bigtest<<"</div>";
    bigtest<<"<table id = " <<"tests"<< ">";
    bigtest<<"<tbody>";
    
    while (firstPath) {
        
        tinyxml2::XMLElement* path = firstPath;
        
        while (path) {
            
            if (firstPath->FirstChildElement("TestCase")) {
                firstPath = firstPath->FirstChildElement("TestCase");
                path = path->FirstChildElement("TestCase");
                parse_testcase(path, bigtest);
                break;
            }
            
            else if (firstPath->FirstChildElement("Expression")) {
                path = path->FirstChildElement("Expression");
                firstPath = firstPath->FirstChildElement("Expression");
                parse_expression(path, bigtest);
                break;
            }
            
            else if (firstPath->FirstChildElement("Section")) {
                path = path->FirstChildElement("Section");
                firstPath = firstPath->FirstChildElement("Section");
                parse_section(path, bigtest);
                break;
            }
            
            else {
                yacheika(path, bigtest);
                break;
            }
            
        }
        
        tinyxml2::XMLNode* parent = path->Parent();
        
        while (parent) {
            
            if (parent->FirstChildElement()->NextSiblingElement()) {
              
                firstPath = parent->FirstChildElement();
                
                if (firstPath->NextSiblingElement("TestCase")) {
                    firstPath = firstPath->NextSiblingElement("TestCase");
                    break;
                }
                
                if (firstPath->NextSiblingElement("Expression")) {
                    firstPath = firstPath->NextSiblingElement("Expression");
                    break;
                }
                
                if (firstPath->NextSiblingElement("Section")) {
                    firstPath = firstPath->NextSiblingElement("Section");
                    break;
                }
                
            }
            
            else {
                parent = parent->Parent();
            }
            
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
