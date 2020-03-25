#include "tinyxml2.h"
#include <iostream>

int main() {
    tinyxml2::XMLDocument doc;
    doc.LoadFile("/Users/vadim/Desktop/testPage/xmlReader/test_report_xml.xml");
    const char* infoOriginal = doc.FirstChildElement( "Catch" )->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->FirstChildElement("Original")->GetText();
    const char* infoExpanded = doc.FirstChildElement( "Catch" )->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->FirstChildElement("Expanded")->GetText();
    const char* infoName = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("name");
    const char* infoFile = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("filename");
    const char* infoLine = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("line");
    const char* infoSuccess = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("success");
    const char* infoFailLine = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("line");
    std::cout<<"Test Case Name - "<<infoName<<std::endl;
    std::cout<<"Filename - "<<infoFile<<std::endl;
    std::cout<<"Line - "<<infoLine<<std::endl;
    std::cout<<"Success - "<<infoSuccess<<std::endl;
    std::cout<<"Line of fail - "<<infoFailLine<<std::endl;
    std::cout<<"Original"<<" - "<<infoOriginal<< std::endl;
    std::cout<<"Expanded"<<" - "<<infoExpanded<< std::endl;
}
