#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    tinyxml2::XMLDocument doc;
    doc.LoadFile("/Users/vadim/Desktop/testPage/xmlReader/test_report_xml.xml");
    tinyxml2::XMLElement* miniPath = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase");
    tinyxml2::XMLElement* next = miniPath->NextSiblingElement("TestCase");
    std::string infoName = miniPath->Attribute("name");
    std::string infoFile = miniPath->Attribute("filename");
    std::string infoSuccess = miniPath->FirstChildElement("Expression")->Attribute("success");
    std::string infoFailLine = miniPath->FirstChildElement("Expression")->Attribute("line");
    std::cout<<infoFailLine;
    
    std::ofstream bigtest;
    bigtest.open("/Users/vadim/Desktop/testPage/testPage/testPage.html");
    if (!bigtest.is_open()) {
        std::cout<<"error";
    }
    bigtest<<"<!DOCTYPE HTML>";
    bigtest<<"<html>";
    bigtest<<"<head>";
    bigtest<<"<meta charset = " <<"utf-8"<< " >";
    bigtest<<"<title>Tests C++</title>";
    bigtest<<"<link href = " <<"styleTest.css"<< " rel = " <<"stylesheet"<< " type = " <<"text/css"<< " />";
    bigtest<<"</head>";
    bigtest<<"<body>";
    bigtest<<"<div id = " <<"page"<< ">";
    bigtest<<"<h1>"<<infoName<<"</h1><br/>";
    bigtest<<"<div id = " <<"info"<< "> ";
    bigtest<<"<p><i>Фомин Вадим Евгеньевич<br/>";
    bigtest<<"группа КМБО-02-19<br/>";
    bigtest<<"4 марта 2020<i/></p><br/>";
    bigtest<<"</div>";
    bigtest<<"<table id = " <<"tests"<< ">";
    bigtest<<"<tbody>";
    bigtest<<"<tr>";
    bigtest<<"<td class = " <<"number"<< ">№</td>";
    bigtest<<"<td class = " <<"name"<< ">Name</td>";
    bigtest<<"<td>Passing</td>";
    bigtest<<"<td>Line of fail</td>";
    bigtest<<"</tr>";
    bigtest<<"<tr>";
    bigtest<<"<td class = " <<"number"<< ">1</td>";
    bigtest<<"<td class = " <<"name"<< ">" << infoFile << "</td>" ;
    if (infoSuccess == "pass") {
        bigtest<<"<td class = " <<"pass"<< ">" << infoSuccess <<" </td>";
    }
    else {
        bigtest<<"<td class = " <<"fail"<< ">" << infoSuccess <<" </td>";
    }
    bigtest<<"<td>"<< infoFailLine << "</td>" ;
    bigtest<<"</tr>";
    for (int i = 2; next; i++) {
        bigtest<<"<tr>";
        bigtest<<"<td class = " <<"number"<< ">"<< i ;
        std::string infoFile = next->Attribute("filename");
        bigtest<<"<td class = " <<"name"<<">" << infoFile << "</td>" ;
        std::string infoSuccess = next->FirstChildElement("Expression")->Attribute("success");
        if (infoSuccess == "pass") {
            bigtest<<"<td class = " <<"pass"<< ">" << infoSuccess <<" </td>";
        }
        else {
            bigtest<<"<td class = " <<"fail"<< ">" << infoSuccess <<" </td>";
        }
        std::string infoFailLine = next->FirstChildElement("Expression")->Attribute("line");
        bigtest<<"<td>"<< infoFailLine << "</td>" ;
        bigtest<<"</tr>";
        next = next->NextSiblingElement("TestCase");
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
