#if !defined(VEICULO_HPP)
#define VEICULO_HPP

#include<iostream>
#include<string>
#include <vector>
#include "Data.hpp"
#include "Menu.hpp"

using namespace std;

typedef struct T_veiculo{
    string Renavan;
    string Placa;
    Data Data_Hora_Retirada;
    Data Data_Hora_Entrega;
    string Loja_Retirada;

    void dispDadosVeiculo(){
        system("clear");
        cout << "********* Dados do Veiculo *********" << endl << endl;
        cout << "Renavan: " << this->Renavan << endl
            << "Placa: " << this->Placa << endl
            << "Data e hora da retirada (prevista): " << this->Data_Hora_Retirada.getHora()
            << " " << this->Data_Hora_Retirada.toString() << endl
            << "Data e hora da entrega (prevista): " << this->Data_Hora_Entrega.getHora()
            << " " << this->Data_Hora_Entrega.toString() << endl
            << "Loja de retirada: " << this->Loja_Retirada << endl;
        cin.ignore();
        getchar();
    }

    void dispListaVeiculos(int id){
        cout << endl << "********* Dados do Veiculo #" << id
            << " *********" << endl << endl;
        cout << "Renavan: " << this->Renavan << endl
            << "Placa: " << this->Placa << endl
            << "Data e hora da retirada (prevista): " << this->Data_Hora_Retirada.getHora()
            << " " << this->Data_Hora_Retirada.toString() << endl
            << "Data e hora da entrega (prevista): " << this->Data_Hora_Entrega.getHora()
            << " " << this->Data_Hora_Entrega.toString() << endl
            << "Loja de retirada: " << this->Loja_Retirada << endl;
    }

} Veiculo;

void setVeiculo(vector<Veiculo> *lista){
    Veiculo veiculo;
    cin.ignore();
    system("clear");
    cout << "********* Cadastro de Veiculo *********" << endl << endl;
    cout << "Informe o renavan do veiculo: ";
    getline(cin, veiculo.Renavan);
    cout << "Informe a placa do veiculo:";
    getline(cin, veiculo.Placa);
    cout << "Informe a data prevista de retirada do veiculo:" << endl;
    setHora(&veiculo.Data_Hora_Retirada);
    setData(&veiculo.Data_Hora_Retirada);
    cout << "Informe a data prevista de entrega do veiculo:" << endl;
    setHora(&veiculo.Data_Hora_Entrega);
    setData(&veiculo.Data_Hora_Entrega);
    cout << "Informe o nome da loja de retirada: ";
    cin >> veiculo.Loja_Retirada;
    (*lista).push_back(veiculo);
    system("clear");
    cout << "********* Cadastro de Veiculo *********" << endl << endl;
    cout << "Veiculo cadastrado com sucesso!" << endl;
    getchar();
}

int indexVeiculo(string Placa, vector<Veiculo> lista){
    for (size_t i = 0; i < lista.size(); i++){
        if (lista[i].Placa == Placa){
            return i;
        }
    }
    system("clear");
    cout << "Placa informada nao encontrada!" << endl
         << "(Pressione qualquer tecla para continuar...)";
    cin.ignore();
    getchar();
    return -1;
}

void deleteVeiculo(vector<Veiculo> *lista){
    string placa;
    char op;
    system("clear");
    cout << "Informe a placa do veiculo:" << endl << "> ";
    cin >> placa;
    int idVeiculo = indexVeiculo(placa, *lista);
    if(idVeiculo < 0){
        return;
    }
    (*lista)[idVeiculo].dispDadosVeiculo();
    cout << "Deseja remover este veiculo? ([S]im / [N]ao)" << endl << "> ";
    cin >> op;
    if(toupper(op) == 'S'){
        (*lista).erase((*lista).begin()+idVeiculo);
        cout << "Veiculo removido com sucesso!";
        cin.ignore();
        getchar();
    }
    return;
}

void alteraVeiculo(vector<Veiculo> *lista){
    string texto;
    int op;
    
    system("clear");
    cin.ignore();
    cout << "Informe a placa do veiculo:" << endl << "> ";
    cin >> texto;
    int idVeiculo = indexVeiculo(texto, *lista);
    if(idVeiculo < 0){
        return;
    }
    (*lista)[idVeiculo].dispDadosVeiculo();

    do{
        op = dispAlteraVeiculo();
        switch (op){
        case 1:
            cout << "Informe o novo renavan do veiculo:" << endl << "> ";
            cin.ignore();
            getline(cin, texto);
            (*lista)[idVeiculo].Renavan = texto;
            break;
        case 2:
            cout << "Informe a nova data e hora de retirada:" << endl;
            setHora(&(*lista)[idVeiculo].Data_Hora_Retirada);
            setData(&(*lista)[idVeiculo].Data_Hora_Retirada);
            break;
        case 3:
            cout << "Informe a nova data e hora de entrega:" << endl;
            setHora(&(*lista)[idVeiculo].Data_Hora_Entrega);
            setData(&(*lista)[idVeiculo].Data_Hora_Entrega);
            break;
        case 4:
            cout << "Informe o novo nome da loja de retirada:" << endl << "> ";
            cin.ignore();
            getline(cin, texto);
            (*lista)[idVeiculo].Loja_Retirada = texto;
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

void listaVeiculos(vector<Veiculo> lista){
    system("clear");
    for (int i = 0; i < lista.size(); i++){
        lista[i].dispListaVeiculos(i);
    }
    cin.ignore();
    getchar();
}

void buscaVeiculo(vector<Veiculo> lista){
    string placa;
    
    system("clear");
    cin.ignore();
    cout << "Informe a placa do veiculo:" << endl << "> ";
    cin >> placa;
    int idVeiculo = indexVeiculo(placa, lista);
    if(idVeiculo < 0){
        return;
    }
    lista[idVeiculo].dispDadosVeiculo();
}

#endif