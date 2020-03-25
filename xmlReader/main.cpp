#include "tinyxml2.h"
#include <iostream>

int main() {
   tinyxml2::XMLDocument doc;
   doc.LoadFile("/Users/vadim/Desktop/testPage/xmlReader/test_report_xml.xml");
   do {
       const char* infoName = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("name");
       std::cout<<"Test Case Name - "<<infoName<<std::endl;
       const char* infoFile = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("filename");
       std::cout<<"Filename - "<<infoFile<<std::endl;
       const char* infoLine = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("line");
       std::cout<<"Line - "<<infoLine<<std::endl;
       const char* infoSuccess = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("success");
       std::cout<<"Success - "<<infoSuccess<<std::endl;
       const char* infoFailLine = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("line");
       std::cout<<"Line of fail - "<<infoFailLine<<std::endl;
       const char* infoPath = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("filename");
       std::cout<<"Path - "<<infoPath<<std::endl;
       const char* infoOriginal = doc.FirstChildElement( "Catch" )->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->FirstChildElement("Original")->GetText();
       const char* infoExpanded = doc.FirstChildElement( "Catch" )->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->FirstChildElement("Expanded")->GetText();
       std::cout<<"Original"<<" - "<<infoOriginal<< std::endl;
       std::cout<<"Expanded"<<" - "<<infoExpanded<< std::endl;
   }
   while (doc.FirstChildElement("Catch")->FirstChildElement("Group")->NextSiblingElement("TestCase"));{
       const char* infoName = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("name");
       std::cout<<"Test Case Name - "<<infoName<<std::endl;
       const char* infoFile = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("filename");
       std::cout<<"Filename - "<<infoFile<<std::endl;
       const char* infoLine = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->Attribute("line");
       std::cout<<"Line - "<<infoLine<<std::endl;
       const char* infoSuccess = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("success");
       std::cout<<"Success - "<<infoSuccess<<std::endl;
       const char* infoFailLine = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("line");
       std::cout<<"Line of fail - "<<infoFailLine<<std::endl;
       const char* infoPath = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->Attribute("filename");
       std::cout<<"Path - "<<infoPath<<std::endl;
       const char* infoOriginal = doc.FirstChildElement( "Catch" )->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->FirstChildElement("Original")->GetText();
       const char* infoExpanded = doc.FirstChildElement( "Catch" )->FirstChildElement( "Group" )->FirstChildElement("TestCase")->FirstChildElement("Expression")->FirstChildElement("Expanded")->GetText();
       std::cout<<"Original"<<" - "<<infoOriginal<< std::endl;
       std::cout<<"Expanded"<<" - "<<infoExpanded<< std::endl;
   }
}
