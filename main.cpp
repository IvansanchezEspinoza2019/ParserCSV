#include <iostream>
#include<fstream>
#include "parser.h"
using namespace std;

void pruebas_csv(std::string&);

int main()
{
    // you can put any other csv directory file, here is an example
    string path="C:/Users/acer/Desktop/ParcerCSV/Parser/CSV_testing_files/UsersImportMinimumSample.csv";

    // call the function
    pruebas_csv(path);

    return 0;
}


void pruebas_csv(std::string &_path){

    // Function that reads csv files
    Parser parser;

    // open file  //
    ifstream archivo(_path,ios::in);

    if ( archivo.is_open()){

        string token;
        parser.setDelimitador(',');  //change de delimiter if necesary

        // while not end of file
        while(!archivo.eof()){

            token = parser.getToken(archivo);   // get token from file
            if(archivo.eof()){
                break;
            }

            if(token!= ""){
                 cout<<"Celda: "<<token<<endl;

             }
        }
    }
    else{
        cout<<"Something went wrong"<<endl;
    }
}
