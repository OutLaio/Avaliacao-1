#include<iostream>
#include<string>
#include<vector>
#include "Veiculo.hpp"
#include "Data.hpp"
#include "Menu.hpp"
#include "Cliente.hpp"
#include "Utilitarios.hpp"

using namespace std;

int main(){
    int op;
    vector<Veiculo> lista;
    Veiculo veiculo;

    do{
        op = dispMenuVeiculo();
        switch (op){
        case 1:
            setVeiculo(&lista);
            break;
        case 2:
            deleteVeiculo(&lista);
            break;
        case 3:
            alteraVeiculo(&lista);
            break;
        case 4:
            listaVeiculos(lista);
            break;
        case 5:
            buscaVeiculo(lista);
            break;
        default:
            break;
        }
    } while (op != 0);
    



    return 0;
}