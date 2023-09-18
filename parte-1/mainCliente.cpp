#include<iostream>
#include<string>
#include<vector>
#include "Veiculo.hpp"
#include "Data.hpp"
#include "Menu.hpp"
#include "Cliente.hpp"

using namespace std;

int main(){
    int op;
    vector<Cliente> lista;
    Cliente cliente;

    do{
        op = dispMenuCliente();
        switch (op){
        case 1:
            setCliente(&lista);
            break;
        case 2:
            deleteCliente(&lista);
            break;
        case 3:
            alteraCliente(&lista);
            break;
        case 4:
            listaClientes(lista);
            break;
        case 5:
            buscaCliente(lista);
            break;
        default:
            break;
        }
    } while (op != 0);
    



    return 0;
}