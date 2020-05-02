#include "parser.h"


using namespace std;
Parser::Parser()
{

}
Parser::getToken(ifstream &_archivo){
    if(!_archivo){
        // if error

        // return error message
        return "\n\t[ ERROR: NO SE PUDO ABRIR EL ARCHIVO ]\n\n";

    }
    else{
        // if open file

        // variables declaration
        bool fin=false;
        int estado=0;
        char caracter='4';

        // clean token
        token="";

        while (!fin) {

            //////////////// state 0 ///////////////
            if(estado==0){

                //get next character
                caracter =_archivo.get();

                if(caracter==delim){
                    estado = 2;
                }
                else if(caracter=='"'){
                    estado = 3;
                }
                else if(caracter=='\n'){

                    estado = 2;
                }
                else{
                    estado = 1;
                    token.push_back(caracter);
                }
            }
            //////////////// state 1 ///////////////
            if(estado==1){

                //get next character
                caracter=_archivo.get();
                if(_archivo.eof() or caracter==delim){
                    estado = 2;
                }
                else if(caracter=='\n'){
                    estado=2;
                }
                else{
                    token.push_back(caracter);
                }
            }
            //////////////// state 3 ///////////////
            if(estado==3){

                //get next character
                caracter=_archivo.get();
                if(caracter=='"'){
                    estado = 4;
                }else{
                    token.push_back(caracter);
                }
            }
            //////////////// state 4 ///////////////
            if(estado==4){

                //get next character
                caracter=_archivo.get();
                if(_archivo.eof() or caracter==delim or caracter=='\n'){
                    estado = 2;
                }
                else if(caracter=='"'){
                    estado=5;
                    token.push_back(caracter);
                }
            }
            //////////////// state 5 ///////////////
            if(estado==5){

                //get next character
                caracter=_archivo.get();

                if(caracter=='"'){
                    estado = 4;
                }
                else{
                    token.push_back(caracter);
                }
            }
            //////////////// state 2 (acceptance) ///////////////
            if(estado==2){

                // end
                fin = true;
            }

        }
        // return token
        return token;
    }

}


Parser::setDelimitador(char _delim){
    delim = _delim;
}
