#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

typedef struct T_cliente {
    string nome;
    string CPF;
    string DtNascimento;
    string CNH;
}Cliente;

// Função para incluir cliente
void ler (Cliente *leitura_Cliente){
    cin.ignore();
    system("clear");
    cout << "Digite o nome do cliente: " << endl;
    getline(cin, leitura_Cliente->nome);
    cout << "Digite o CPF do cliente: " << endl;
    getline(cin, leitura_Cliente->CPF);
    cout << "Digite a data de nascimento: " << endl;
    getline(cin, leitura_Cliente->DtNascimento);
    cout << "Digite a CNH: " << endl;
    getline(cin, leitura_Cliente->CNH);
}


//Função para excluir cliente
void excluir_Cliente(vector<Cliente> listadeClientes){
    system("clear");
    if(listadeClientes.size()>0){
        string CPF_Cliente;
        bool cliente_encontrado=false;
        cout << "Qual o CPF do cliente: ";
        cin >> CPF_Cliente;

        for(size_t i=0; i>listadeClientes.size(); i++){
            if(CPF_Cliente == listadeClientes.at(i).CPF){
                cliente_encontrado = true;
                listadeClientes.erase(listadeClientes.begin()+i);
            }
        }

        if(cliente_encontrado == false){
            cout << "Cliente nao encontrado " << endl;
            cin.ignore();
            getchar();
        }

    }else{
        cout << "Nao existe cliente cadastrado " << endl;
        cin.ignore();
        getchar();
    }
    }

// Função para alterar cliente
void alterar_Cliente(vector<Cliente>& listadeClientes){

    string CPF;
    cout << "Digite o CPF do cliente que deseja alterar: ";
    cin >> CPF;
    for () {
        if () {
            
            cout << "Cliente alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "CPF não encontrado." << endl;
}



//Função para listar clientes
void Listar_Clientes(vector<Cliente> ListadeClientes){
    system("clear");
    for (int i = 0; i < ListadeClientes.size(); i++){
        mostrar(ListadeClientes[i]);
        cout << endl;
    }
        cin.ignore();
        getchar();
    
}

// Função para buscar CPF
void buscar_CPF(vector<Cliente> ListadeClientes){
    system("clear");
    if(ListadeClientes.size()>0){
        string CPF_Cliente;
        bool cliente_encontrado=false;

        cout << "Qual o CPF do cliente: ";
        cin >> CPF_Cliente;
        
        for(Cliente c : ListadeClientes){
            if(c.CPF == CPF_Cliente){
                cliente_encontrado=true;
                cout << "Cliente encontrado: " << endl;
                cout << c.nome << " - " << c.CPF << endl;
                cin.ignore();
                getchar();
                return;
            }
        }
        
        if(cliente_encontrado == false){
            cout << "Cliente nao encontrado " << endl;
            cin.ignore();
            getchar();
        }

    }else{
        cout << "Nao existe cliente cadastrado " << endl;
        cin.ignore();
        getchar();
    }
}




int menu(){
    int escolha_usuario;
    do{
        system("clear");
        cout << "Escolha a opcao " << endl;
        cout << "1.Incluir cliente " << endl;
        cout << "2.Excluir cliente " << endl;
        cout << "3.ALterar CPF " << endl;
        cout << "4.Listar todos os clientes " << endl;
        cout << "5.Localizar CPF " << endl;
        cout << "0. sair " << endl;
        cin >> escolha_usuario;
    
    } while (escolha_usuario<0 || escolha_usuario>5);
    return escolha_usuario;
    
}


int main(){
    vector<Cliente> Lista_Clientes;
    int recebe_menu;
    Cliente c1_deCliente;
    do{
        recebe_menu=menu();
        switch (recebe_menu){
        case 1:
            ler(&c1_deCliente);
            Lista_Clientes.push_back(c1_deCliente);
            break;
        case 2:
            excluir_cliente(Lista_Clientes);
            break;

        case 3:
            alterar_Cliente(Lista_Clientes);
            break;
        
        case 4:
            Listar_Clientes(Lista_Clientes);
            break;

        case 5:
            buscar_CPF(Lista_Clientes);
            break;

            
        default:
            break;
        }  
    } while (recebe_menu!=0);
    
    
    return 0;
}