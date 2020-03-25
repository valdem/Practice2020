#include "tinyxml2.h"
#include <iostream>

int main() {
   tinyxml2::XMLDocument doc;
   doc.LoadFile("/Users/vadim/Desktop/testPage/xmlReader/test_report_xml.xml");
   tinyxml2::XMLElement* miniPath = doc.FirstChildElement("Catch")->FirstChildElement( "Group" )->FirstChildElement("TestCase");
   tinyxml2::XMLElement* next = miniPath->NextSiblingElement("TestCase");
   const char* infoName = miniPath->Attribute("name");
   std::cout<<"Test Case Name - "<<infoName<<std::endl;
   const char* infoFile = miniPath->Attribute("filename");
   std::cout<<"Filename - "<<infoFile<<std::endl;
   const char* infoLine = miniPath->Attribute("line");
   std::cout<<"Line - "<<infoLine<<std::endl;
   const char* infoSuccess = miniPath->FirstChildElement("Expression")->Attribute("success");
   std::cout<<"Success - "<<infoSuccess<<std::endl;
   const char* infoFailLine = miniPath->FirstChildElement("Expression")->Attribute("line");
   std::cout<<"Line of fail - "<<infoFailLine<<std::endl;
   const char* infoPath = miniPath->FirstChildElement("Expression")->Attribute("filename");
   std::cout<<"Path - "<<infoPath<<std::endl;
   const char* infoOriginal = miniPath->FirstChildElement("Expression")->FirstChildElement("Original")->GetText();
   const char* infoExpanded = miniPath->FirstChildElement("Expression")->FirstChildElement("Expanded")->GetText();
   std::cout<<"Original"<<" - "<<infoOriginal<< std::endl;
   std::cout<<"Expanded"<<" - "<<infoExpanded<< std::endl;
   while (next){
       const char* infoName = next->Attribute("name");
       std::cout<<"Test Case Name - "<<infoName<<std::endl;
       const char* infoFile = next->Attribute("filename");
       std::cout<<"Filename - "<<infoFile<<std::endl;
       const char* infoLine = next->Attribute("line");
       std::cout<<"Line - "<<infoLine<<std::endl;
       const char* infoSuccess = next->FirstChildElement("Expression")->Attribute("success");
       std::cout<<"Success - "<<infoSuccess<<std::endl;
       const char* infoFailLine = next->FirstChildElement("Expression")->Attribute("line");
       std::cout<<"Line of fail - "<<infoFailLine<<std::endl;
       const char* infoPath = next->FirstChildElement("Expression")->Attribute("filename");
       std::cout<<"Path - "<<infoPath<<std::endl;
       const char* infoOriginal = next->FirstChildElement("Expression")->FirstChildElement("Original")->GetText();
       const char* infoExpanded = next->FirstChildElement("Expression")->FirstChildElement("Expanded")->GetText();
       std::cout<<"Original"<<" - "<<infoOriginal<< std::endl;
       std::cout<<"Expanded"<<" - "<<infoExpanded<< std::endl;
       next = next->NextSiblingElement("TestCase");
   }
}
