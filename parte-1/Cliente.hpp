#if !defined(CLIENTE_HPP)
#define CLIENTE_HPP

#include<iostream>
#include<string>
#include <vector>
#include "Data.hpp"

using namespace std;

typedef struct T_cliente{
    string CPF;
    string Nome;
    Data DtNascimento;
    string CNH;

    void dispDadosCliente(){
        system("clear");
        cout << "********* Dados do Cliente *********" << endl << endl;
        cout << "Nome completo: " << this->Nome << endl
            << "CPF: " << this->CPF << endl
            << "Data de nascimento: " << this->DtNascimento.toString() << endl
            << "CNH: " << this->CNH << endl;
        cin.ignore();
        getchar();
    }

    void dispListaClientes(int id){
        cout << endl << "********* Dados do Cliente #" << id
            << " *********" << endl << endl;
        cout << "Nome completo: " << this->Nome << endl
            << "CPF: " << this->CPF << endl
            << "Data de nascimento: " << this->DtNascimento.toString() << endl
            << "CNH: " << this->CNH << endl;
    }

} Cliente;

void setCliente(vector<Cliente> *lista){
    Cliente cliente;
    cin.ignore();
    system("clear");
    cout << "********* Cadastro de Cliente *********" << endl << endl;
    cout << "Informe o nome do cliente: ";
    getline(cin, cliente.Nome);
    cout << "Informe o CPF (Ex.: 123.456.789-10):";
    getline(cin, cliente.CPF);
    cout << "Informe a data de nascimento:";
    setData(&cliente.DtNascimento);
    cout << "Informe o numero da CNH:";
    cin >> cliente.CNH;
    (*lista).push_back(cliente);
    system("clear");
    cout << "********* Cadastro de Cliente *********" << endl << endl;
    cout << "Cliente cadastrado com sucesso!" << endl;
    getchar();
}

int indexCliente(string CPF, vector<Cliente> lista){
    for (size_t i = 0; i < lista.size(); i++){
        if (lista[i].CPF == CPF){
            return i;
        }
    }
    system("clear");
    cout << "CPF informado nao encontrado!" << endl
         << "(Pressione qualquer tecla para continuar...)";
    cin.ignore();
    getchar();
    return -1;
}

void deleteCliente(vector<Cliente> *lista){
    string cpf;
    char op;
    system("clear");
    cout << "Informe o CPF do cliente (Ex.: 123.456.789-10):" << endl << "> ";
    cin >> cpf;
    int idCliente = indexCliente(cpf, *lista);
    if(idCliente < 0){
        return;
    }
    (*lista)[idCliente].dispDadosCliente();
    cout << "Deseja remover este cliente? ([S]im / [N]ao)" << endl << "> ";
    cin >> op;
    if(toupper(op) == 'S'){
        (*lista).erase((*lista).begin()+idCliente);
        cout << "Cliente removido com sucesso!";
        cin.ignore();
        getchar();
    }
    return;
}

void alteraCliente(vector<Cliente> *lista){
    string cpf, nome, cnh;
    int op;
    
    system("clear");
    cin.ignore();
    cout << "Informe o CPF do cliente (Ex.: 123.456.789-10):" << endl << "> ";
    cin >> cpf;
    int idCliente = indexCliente(cpf, *lista);
    if(idCliente < 0){
        return;
    }
    (*lista)[idCliente].dispDadosCliente();

    do{
        op = dispAlteraCliente();
        switch (op){
        case 1:
            cout << "Informe o novo nome do cliente:" << endl << "> ";
            cin.ignore();
            getline(cin, nome);
            (*lista)[idCliente].Nome = nome;
            break;
        case 2:
            cout << "Informe a nova data de nascimento:" << endl << "> ";
            setData(&(*lista)[idCliente].DtNascimento);
            break;
        case 3:
            cout << "Informe o novo numero da CNH:" << endl << "> ";
            cin.ignore();
            getline(cin, cnh);
            (*lista)[idCliente].CNH = cnh;
            break;
        default:
            break;
        }
        if(op != 0){
            cout << "Alteracoes realizadas com sucesso!" << endl;
            cout << "Deseja outra alteração? ([1]Sim / [0]Nao)" << endl << "> ";
            cin >> op;
        }
    } while (op != 0);
}

void listaClientes(vector<Cliente> lista){
    system("clear");
    for (int i = 0; i < lista.size(); i++){
        lista[i].dispListaClientes(i);
    }
    cin.ignore();
    getchar();
}

void buscaCliente(vector<Cliente> lista){
    string cpf;
    
    system("clear");
    cin.ignore();
    cout << "Informe o CPF do cliente (Ex.: 123.456.789-10):" << endl << "> ";
    cin >> cpf;
    int idCliente = indexCliente(cpf, lista);
    if(idCliente < 0){
        return;
    }
    lista[idCliente].dispDadosCliente();
}

#endif