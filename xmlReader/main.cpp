#include "tinyxml2.h"
#include <iostream>

int main() {
    tinyxml2::XMLDocument doc;
    doc.LoadFile("/Users/vadim/Desktop/testPage/xmlReader/note.xml");
    const char* info1 = doc.FirstChildElement( "note" )->FirstChildElement( "to" )->GetText();
    const char* info2 = doc.FirstChildElement( "note" )->FirstChildElement( "from" )->GetText();
    const char* info3 = doc.FirstChildElement( "note" )->FirstChildElement( "heading" )->GetText();
    const char* info4 = doc.FirstChildElement( "note" )->FirstChildElement( "body" )->GetText();
    tinyxml2:: XMLText* textNode1 = doc.FirstChildElement( "note" )->FirstChildElement( "to" )->FirstChild()->ToText();
    tinyxml2:: XMLText* textNode2 = doc.FirstChildElement( "note" )->FirstChildElement( "from" )->FirstChild()->ToText();
    tinyxml2:: XMLText* textNode3 = doc.FirstChildElement( "note" )->FirstChildElement( "heading" )->FirstChild()->ToText();
    tinyxml2:: XMLText* textNode4 = doc.FirstChildElement( "note" )->FirstChildElement( "body" )->FirstChild()->ToText();
    info1 = textNode1->Value();
    info2 = textNode2->Value();
    info3 = textNode3->Value();
    info4 = textNode4->Value();
    std::cout<<"- "<<info1<< std::endl;
    std::cout<<"- "<<info2<< std::endl;
    std::cout<<"- "<<info3<< std::endl;
    std::cout<<"- "<<info4<< std::endl;
}
