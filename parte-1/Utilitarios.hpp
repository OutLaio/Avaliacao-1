#if !defined(UTILITARIOS_HPP)
#define UTILITARIOS_HPP

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void limpaTela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpaBuffer(){
    int ch;
    while ( ( ch = fgetc ( stdin ) ) != EOF && ch != '\n' );
}

#endif