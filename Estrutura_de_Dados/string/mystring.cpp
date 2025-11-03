#include "mystring.h"
#include <iostream>
#include <cstring>

//strcpy apenas quando tratando de strings no estilo c Char* e nao std::string
//strlen(dado) nao conta o "\0"
String::String (const char* dado, int tamanho){
    this->_data = (char*) malloc(sizeof(char) * (strlen(dado) + 1));
    strcpy(this->_data, dado);
    this->tam = tamanho;
}


String::String(const String& other){
    this->_data = (char*) malloc(sizeof(char) * (strlen(other._data) + 1));
    strcpy(this->_data, other._data);
    this->tam = other.tam;
}

String String::operator=(const String& other){
    if (&other == this){
        return *this;
    }
    
    this->_data = (char*) realloc(this->_data, sizeof(char) * (strlen(other._data) + 1));
    this->tam = other.tam;
    strcpy(this->_data, other._data);


    
    return *this;    
}

String String::operator+(const String& s1) const{
    int tamanho = this->tam + s1.tam;
    char* concaten = (char*) malloc(tamanho + 1);

    strcpy(concaten, this->_data);
    strcat(concaten, s1._data);

    String resultado(concaten, tamanho);
    free(concaten);

    return resultado;
}

const char* String::c_str() const{
    return this->_data;
}