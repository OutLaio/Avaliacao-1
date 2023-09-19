#if !defined(MENU_HPP)
#define MENU_HPP

#include<iostream>
#include<string>
#include<vector>
#include "Data.hpp"
#include "Utilitarios.hpp"

using namespace std;

int dispMenuCliente(void){
    int op = 0;
    Data data = getDataAtual();

    limpaTela();
    cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
    data.toString();
    cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
        << "#1. Incluir um novo cliente" << endl
        << "#2. Excluir um cliente" << endl
        << "#3. Alterar (apenas por CPF)" << endl 
        << "#4. Listar todos os clientes" << endl 
        << "#5. Localizar um cliente (por CPF)" << endl 
        << "#0. Sair" << endl << endl
        << "> #";
    cin >> op;
    limpaBuffer();
        
    while (op < 0 || op > 5){
        limpaTela();
        cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
        data.toString();
        cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
            << "#1. Incluir um novo cliente" << endl
            << "#2. Excluir um cliente" << endl
            << "#3. Alterar (apenas por CPF)" << endl 
            << "#4. Listar todos os clientes" << endl 
            << "#5. Localizar um cliente (por CPF)" << endl 
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> #";
        cin >> op;
        limpaBuffer();
    }
    
    return op;
}

int dispMenuVeiculo(void){
    int op = 0;
    Data data = getDataAtual();

    limpaTela();
    cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
    data.toString();
    cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
        << "#1. Incluir um novo veiculo" << endl
        << "#2. Excluir um veiculo" << endl
        << "#3. Alterar (apenas por Placa)" << endl 
        << "#4. Listar todos os veiculos" << endl 
        << "#5. Localizar um veiculo (por Placa)" << endl 
        << "#0. Sair" << endl << endl
        << "> #";
    cin >> op;
    limpaBuffer();
        
    while (op < 0 || op > 5){
        limpaTela();
        cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
        data.toString();
        cout << endl << "Seja bem vindo(a)! O que deseja?" << endl << endl
            << "#1. Incluir um novo veiculo" << endl
            << "#2. Excluir um veiculo" << endl
            << "#3. Alterar (apenas por Placa)" << endl 
            << "#4. Listar todos os veiculos" << endl 
            << "#5. Localizar um veiculo (por Placa)" << endl 
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> #";
        cin >> op;
        limpaBuffer();
    }
    
    return op;
}

int dispAlteraVeiculo(void){
    int op = 0;
    Data data = getDataAtual();

    limpaTela();
    cout << endl << "O que deseja alterar?" << endl << endl
        << "#1. Renavam" << endl
        << "#2. Data e hora de retirada" << endl
        << "#3. Data e hora de entrega" << endl
        << "#4. Loja de retirada" << endl 
        << "#0. Sair" << endl << endl
        << "> #";
    cin >> op;
    limpaBuffer();
        
    while (op < 0 || op > 4){
        limpaTela();
        cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
        data.toString();
        cout << endl << "O que deseja alterar?" << endl << endl
            << "#1. Renavam" << endl
            << "#2. Data e hora de retirada" << endl
            << "#3. Data e hora de entrega" << endl
            << "#4. Loja de retirada" << endl 
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> #";
        cin >> op;
        limpaBuffer();
    }
    
    return op;
}

int dispAlteraCliente(void){
    int op = 0;
    Data data = getDataAtual();

    limpaTela();
    cout << endl << "O que deseja alterar?" << endl << endl
        << "#1. Nome" << endl
        << "#2. Data de nascimento" << endl
        << "#3. CNH" << endl 
        << "#0. Sair" << endl << endl
        << "> #";
    cin >> op;
    limpaBuffer();
        
    while (op < 0 || op > 3){
        limpaTela();
        cout << "********* LocaFINA S/A *********" << endl << endl << "\t";
        data.toString();
        cout << endl << "O que deseja alterar?" << endl << endl
            << "#1. Nome" << endl
            << "#2. Data de nascimento" << endl
            << "#3. CNH" << endl 
            << "#0. Sair" << endl << endl
            << endl << "Digite uma opcao valida!" << endl
            << "> #";
        cin >> op;
        limpaBuffer();
    }
    
    return op;
}

#endif // MENU_HPP