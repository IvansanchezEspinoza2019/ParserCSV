#ifndef PARSER_H
#define PARSER_H
#include<iostream>
#include<fstream>
class Parser
{
private:
    char delim;             // file delimiter
    std::string token;      // to save a csv file token
public:
    Parser();
    std::string getToken(std::ifstream &);  // return tokens
    void setDelimitador(char);              // function to change the file delimiter

};

#endif // PARSER_H
