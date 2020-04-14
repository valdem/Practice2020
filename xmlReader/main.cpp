#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "headHTML.h"

int main(int argc, char* argv[]) {
    if (argc>=3) {
        tinyxml2::XMLDocument doc;
        doc.LoadFile(argv[1]);
        tinyxml2::XMLElement* miniPath = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase");
        std::string infoName = miniPath->Attribute("name");

        std::ofstream bigtest;
        bigtest.open(argv[2]);
        if (!bigtest.is_open()) {
            std::cout<<"error";
        }
        headHTML(bigtest);
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
        int i = 1;
        while (miniPath) {
            tinyxml2::XMLElement* pathExpression = miniPath->FirstChildElement("Expression");
            while (pathExpression) {
                bigtest<<"<tr>";
                bigtest<<"<td class = " <<"number"<< ">"<< i ;
                std::string infoFile = miniPath->Attribute("filename");
                bigtest<<"<td class = " <<"name"<<">" << infoFile << "</td>" ;
                std::string infoSuccess = pathExpression->Attribute("success");
                if (infoSuccess == "true") {
                    bigtest<<"<td class = " <<"pass"<< ">" << infoSuccess <<" </td>";
                }
                else  {
                    bigtest<<"<td class = " <<"fail"<< ">" << infoSuccess <<" </td>";
                }
                std::string infoFailLine = pathExpression->Attribute("line");
                bigtest<<"<td>"<< infoFailLine << "</td>" ;
                bigtest<<"</tr>";
                pathExpression = pathExpression->NextSiblingElement("Expression");
                i++;
            }
            miniPath = miniPath->NextSiblingElement("TestCase");
            
            
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
}
