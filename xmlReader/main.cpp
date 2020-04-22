#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "parseFunctions.h"

void chooseParserFirst(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    if (path->FirstChildElement("TestCase")) {
        path = path->FirstChildElement("TestCase");
        std::cout<<"1"<<std::endl;
        parse_testcase(path, bigtest);
    }
    else if (path->FirstChildElement("Expression")) {
        path = path->FirstChildElement("Expression");
        std::cout<<"2"<<std::endl;
        parse_expression(path,bigtest);
    }
    else if (path->FirstChildElement("Section")) {
        path = path->FirstChildElement("Section");
        std::cout<<"3"<<std::endl;
        parse_section(path, bigtest);
    }
    else {
        std::cout<<"4"<<std::endl;
        yacheika(path, bigtest);
        i += 1;
    }
}

void chooseParserNext(tinyxml2::XMLElement* path, std::ofstream& bigtest) {
    if (path->NextSiblingElement("TestCase")) {
        path = path->NextSiblingElement("TestCase");
        std::cout<<"5"<<std::endl;
        parse_testcase(path, bigtest);
    }
    else if (path->NextSiblingElement("Expression")) {
        path = path->NextSiblingElement("Expression");
        std::cout<<"6"<<std::endl;
        parse_expression(path, bigtest);
    }
    else if (path->NextSiblingElement("Section")) {
        path = path->NextSiblingElement("Section");
        std::cout<<"7"<<std::endl;
        parse_section(path, bigtest);
    }
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
    chooseParserNext(path, bigtest);
    
}

int main() {
    tinyxml2::XMLDocument doc;
    doc.LoadFile("/Users/vadim/Documents/GitHub/Practice2020/xmlReader/test_complex_sectionless.xml");
    tinyxml2::XMLElement* firstPath = doc.FirstChildElement("Catch")->FirstChildElement("Group");
    

    std::ofstream bigtest;
    bigtest.open("/Users/vadim/Documents/GitHub/Practice2020/xmlReader/testPage.html");
    if (!bigtest.is_open()) {
        std::cout<<"error";
    }
    
    std::ifstream header("/Users/vadim/Documents/GitHub/Practice2020/xmlReader/header.html");
    std::string header_content;
    while (!header.eof()) {
        header>>header_content;
    }
    bigtest<<header_content;
    
    bigtest<<"<body>";
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
            firstPath = firstPath->FirstChildElement();
            chooseParserFirst(path, bigtest);
        }
        
        tinyxml2::XMLNode* parent = path->Parent();
        
        while (parent) {
            
            if (parent->FirstChildElement()->NextSiblingElement()) {
                firstPath = parent->FirstChildElement();
                
                if (firstPath->NextSiblingElement("TestCase")) {
                    firstPath = firstPath->NextSiblingElement("TestCase");
                    break;
                }
                else if (firstPath->NextSiblingElement("Expression")) {
                    firstPath = firstPath->NextSiblingElement("Expression");
                    break;
                }
                else if (firstPath->NextSiblingElement("Section")) {
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
