#include <fstream>

void headHTML(std::ofstream& file) {
    file<<"<!DOCTYPE HTML>";
    file<<"<html>";
    file<<"<head>";
    file<<"<meta charset = " <<"utf-8"<< " >";
    file<<"<title>Tests C++</title>";
    file<<"<link href = " <<"styleTest.css"<< " rel = " <<"stylesheet"<< " type = " <<"text/css"<< " />";
    file<<"</head>";
}
