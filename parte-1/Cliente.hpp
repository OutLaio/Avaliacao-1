#if !defined(CLIENTE_HPP)
#define CLIENTE_HPP

#include<iostream>
#include<string>
#include <vector>
#include "Data.hpp"
#include "Utilitarios.hpp"

using namespace std;

typedef struct T_cliente{
    string CPF;
    string Nome;
    Data DtNascimento;
    string CNH;

    void dispDadosCliente(){
        limpaTela();
        cout << "********* Dados do Cliente *********" << endl << endl;
        cout << "Nome completo: " << this->Nome << endl
            << "CPF: " << getCPF() << endl
            << "Data de nascimento: " << this->DtNascimento.toString() << endl
            << "CNH: " << this->CNH << endl;
        getchar();
    }

    void dispListaClientes(int id){
        cout << endl << "********* Dados do Cliente #" << id
            << " *********" << endl << endl;
        cout << "Nome completo: " << this->Nome << endl
            << "CPF: " << getCPF() << endl
            << "Data de nascimento: " << this->DtNascimento.toString() << endl
            << "CNH: " << this->CNH << endl;
    }

    string getCPF(){
        string cpf = "";
        
        cpf.insert(cpf.end(), this->CPF.end()-2, this->CPF.end());
        cpf.insert(0, "-");
        cpf.insert(cpf.begin(), this->CPF.end()-5, this->CPF.end()-2);
        cpf.insert(0, ".");
        cpf.insert(cpf.begin(), this->CPF.end()-8, this->CPF.end()-5);
        cpf.insert(0, ".");
        cpf.insert(cpf.begin(), this->CPF.end()-11, this->CPF.end()-8);
        return cpf;
    }

} Cliente;

bool hasCPF(string CPF, vector<Cliente> lista){
    for (size_t i = 0; i < lista.size(); i++){
        if (lista[i].CPF == CPF){
            return true;
        }
    }
    return false;
}

void setCliente(vector<Cliente> *lista){
    Cliente cliente;
    limpaTela();
    cout << "********* Cadastro de Cliente *********" << endl << endl;
    cout << "Informe o nome do cliente: ";
    getline(cin, cliente.Nome);
    cout << "Informe o CPF (apenas numeros): ";
    getline(cin, cliente.CPF);
    while((cliente.CPF.size() > 11 || cliente.CPF.size() < 9) || hasCPF(cliente.CPF, *lista)){
        cout << "CPF invalido ou ja cadastrado!" << endl;
        cout << "Informe um CPF valido (apenas numeros): ";
        getline(cin, cliente.CPF);
    }
    cout << "Informe a data de nascimento:" << endl;
    setData(&cliente.DtNascimento);
    while (!cliente.DtNascimento.isData()){
        cout << "Informe uma data valida:" << endl;
        setData(&cliente.DtNascimento);
    }
    cout << "Informe o numero da CNH:";
    getline(cin, cliente.CNH);
    (*lista).push_back(cliente);
    limpaTela();
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
    limpaTela();
    cout << "CPF informado nao encontrado!" << endl
         << "(Pressione qualquer tecla para continuar...)";
    getchar();
    return -1;
}

void deleteCliente(vector<Cliente> *lista){
    string cpf;
    char op;
    limpaTela();
    cout << "Informe o CPF do cliente (apenas numeros):" << endl << "> ";
    getline(cin, cpf);
    while(cpf.size() > 11 || cpf.size() < 9){
        cout << "Informe um CPF valido (apenas numeros): ";
        getline(cin, cpf);
    }
    int idCliente = indexCliente(cpf, *lista);
    if(idCliente < 0){
        return;
    }
    (*lista)[idCliente].dispDadosCliente();
    cout << "Deseja remover este cliente? ([S]im / [N]ao)" << endl << "> ";
    cin >> op;
    limpaBuffer();
    if(toupper(op) == 'S'){
        (*lista).erase((*lista).begin()+idCliente);
        cout << "Cliente removido com sucesso!";
        getchar();
    }
    return;
}

void alteraCliente(vector<Cliente> *lista){
    string cpf, nome, cnh;
    int op;
    
    limpaTela();
    cout << "Informe o CPF do cliente (apenas numeros):" << endl << "> ";
    getline(cin, cpf);
    while(cpf.size() > 11 || cpf.size() < 9){
        cout << "Informe um CPF valido (apenas numeros): ";
        getline(cin, cpf);
    }
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
            getline(cin, nome);
            (*lista)[idCliente].Nome = nome;
            break;
        case 2:
            cout << "Informe a nova data de nascimento:" << endl << "> ";
            setData(&(*lista)[idCliente].DtNascimento);
            while (!(*lista)[idCliente].DtNascimento.isData()){
                cout << "Informe uma data valida:" << endl;
                setData(&(*lista)[idCliente].DtNascimento);
            }
            break;
        case 3:
            cout << "Informe o novo numero da CNH:" << endl << "> ";
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
            limpaBuffer();
        }
    } while (op != 0);
}

void listaClientes(vector<Cliente> lista){
    limpaTela();
    for (size_t i = 0; i < lista.size(); i++){
        lista[i].dispListaClientes(i+1);
    }
    getchar();
}


void buscaCliente(vector<Cliente> lista){
    string cpf;

    limpaTela();
    cout << "Informe o CPF do cliente (apenas numeros):" << endl << "> ";
    getline(cin, cpf);
    while(cpf.size() > 11 || cpf.size() < 9){
        cout << "Informe um CPF valido (apenas numeros): ";
        getline(cin, cpf);
    }
    int idCliente = indexCliente(cpf, lista);
    if(idCliente < 0){
        return;
    }
    lista[idCliente].dispDadosCliente();
}

#endif