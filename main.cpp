#include <iostream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#define LIMPAR_TELA "cls"
#define PAUSA "pause"
#else
#include <unistd.h>
#define LIMPAR_TELA "clear"
#define PAUSA "read -p \"Aperte ENTER para continuar...\" saindo"
#endif

using namespace std;

struct DATA{
    int dia, mes, ano;
    int hora, minutos;
};
struct CLIENTE{
    string cpf;
    string nome;
    string dtNascimento;
    string cnh;
};
struct VEICULO{
    string renavan;
    string placa_veiculo;
    DATA dataHoraRetirada;
    DATA dataHoraEntrega;
    string lojaRetirada;
};

// Variaveis globais;
vector<CLIENTE> clientesLocadora;
vector<VEICULO> veiculosLocadora;

int menu(bool ehCliente);
int menuModulo();
void incluirCliente();
void sistemaClientes();
void sistemaVeiculos();

int main(){
    int opcaoUsuario = 0;
    do{
        system(LIMPAR_TELA);
        opcaoUsuario = menuModulo();
        switch(opcaoUsuario){
            case 0:
                cout << "AVISO: Encerrando sistema..." << endl;
                break;
            case 1:
                sistemaClientes();
                break;
            case 2:
                sistemaVeiculos();
                break;
            default:
                cout << "AVISO: Opção inválida!" << endl;
                system(PAUSA);
                break;
        }
    }while(opcaoUsuario != 0);
    return 0;
}

int menu(bool ehCliente){
    int opcao = 0;
    do{
        system(LIMPAR_TELA);
        if(ehCliente)cout << "== CLIENTES ==" << endl;
        else cout << "== VEICULOS ==" << endl;
        cout << "Escolha uma opção:" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar" << endl;
        cout << "0. Sair" << endl;
        cout << "> ";
        cin >> opcao;
        if(opcao < 0 || opcao > 5){
            cout << "AVISO: Opção inválida! Digite novamente." << endl;
            system(PAUSA);
        }
    }while(opcao < 0 || opcao > 5);
    return opcao;
}
int menuModulo(){
    int opcao = 0;
    do{
        system(LIMPAR_TELA);
        cout << "Escolha uma opção:" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Veiculos" << endl;
        cout << "0. Sair" << endl;
        cout << "> ";
        cin >> opcao;
        if(opcao < 0 || opcao > 2){
            cout << "AVISO: Opção inválida! Digite novamente." << endl;
            system(PAUSA);
        }
    }while(opcao < 0 || opcao > 2);
    return opcao;
}
void incluirCliente(){
    CLIENTE cliente;
    system(LIMPAR_TELA);
    cout << "Digite o CPF (somente nº): ";
    cin >> cliente.cpf;
    cout << "Digite o Nome: ";
    cin >> cliente.nome;
    cout << "Digite a Data de Nascimento (xx/xx/xxxx): ";
    cin >> cliente.dtNascimento;
    cout << "Digite a CNH: ";
    cin >> cliente.cnh;
    clientesLocadora.push_back(cliente);
    cout << "AVISO: Cliente cadastrado com sucesso!" << endl;
}
void excluirCliente(){
    if(clientesLocadora.size() > 0){
        string cpfExcluir;
        bool clienteEncontrado;

        cout << "Digite o CPF: ";
        cin >> cpfExcluir;

        for(size_t i=0; i<clientesLocadora.size(); i++){
            if(clientesLocadora.at(i).cpf == cpfExcluir){
                clienteEncontrado = true;
                clientesLocadora.erase(clientesLocadora.begin() + i);
            }
        }
        if(clienteEncontrado) cout << "AVISO: Cliente excluido com sucesso!" << endl;
        else cout << "AVISO: Cliente não encontrado. Verifique se digitou CPF corretamente." << endl;
    } else cout << "AVISO: Nenhum cliente cadastrado." << endl;
}
void modificarCliente(int indexCliente){
    int opcaoUsuario = 0;
    do{
        system(LIMPAR_TELA);
        cout << "Escolha um opção para alterar: " << endl;
        cout << "1. CPF" << endl;
        cout << "2. Nome" << endl;
        cout << "3. Data de Nascimento" << endl;
        cout << "4. CNH" << endl;
        cout << "0. Sair" << endl << "> ";
        cin >> opcaoUsuario;
        
        if(opcaoUsuario < 0 || opcaoUsuario > 4){
            cout << "AVISO: Opção inválida!" << endl;
            system(PAUSA);
        }
        string novoDado;
        switch(opcaoUsuario){
            case 0:
                break;
            case 1:
                cout << "Digite o novo CPF: ";
                cin >> novoDado;
                clientesLocadora.at(indexCliente).cpf = novoDado;
                break;
            case 2:
                cout << "Digite o novo Nome: ";
                cin >> novoDado;
                clientesLocadora.at(indexCliente).cpf = novoDado;
                break;
            case 3:
                cout << "Digite a nova Data de Nascimento: ";
                cin >> novoDado;
                clientesLocadora.at(indexCliente).cpf = novoDado;
                break;
            case 4:
                cout << "Digite a nova CNH: ";
                cin >> novoDado;
                clientesLocadora.at(indexCliente).cpf = novoDado;
                break;
            default:
                break;
        }
        cout << endl << "Cliente alterado com sucesso!";
        system(PAUSA);
    }while(opcaoUsuario != 0);
}
void alterarCliente(){
    if(clientesLocadora.size() > 0){
        string cpfAlterar;
        bool clienteEncontrado;

        cout << "Digite o CPF: ";
        cin >> cpfAlterar;

        for(size_t i=0; i<clientesLocadora.size(); i++){
            if(clientesLocadora.at(i).cpf == cpfAlterar){
                clienteEncontrado = true;
                modificarCliente(i);
                break;
            }
        }
        if(!clienteEncontrado) cout << "AVISO: Cliente não encontrado. Verifique se digitou CPF corretamente." << endl;
    } else cout << "AVISO: Nenhum cliente cadastrado." << endl;
}
void listarClientes(){
    if(clientesLocadora.size() > 0){
        system(LIMPAR_TELA);
        cout << "Lista de Clientes:" << endl;
        cout << endl << "CPF / NOME / DATA DE NASCIMENTO / CNH" << endl;
        for(size_t i=0; i<clientesLocadora.size(); i++){
            cout << clientesLocadora.at(i).cpf << " / "
            << clientesLocadora.at(i).nome << " / " 
            << clientesLocadora.at(i).dtNascimento << " / " 
            << clientesLocadora.at(i).cnh << endl;
        }
        cout << endl;
        system(PAUSA);
    } else{
        cout << "Nenhum cliente cadastrado!" << endl;
        system(PAUSA);
    }
}
void localizarCliente(){
    if(clientesLocadora.size() > 0){
        string cpfLocalizar;
        bool clienteEncontrado;

        cout << "Digite o CPF: ";
        cin >> cpfLocalizar;

        for(size_t i=0; i<clientesLocadora.size(); i++){
            if(clientesLocadora.at(i).cpf == cpfLocalizar){
                clienteEncontrado = true;
                cout << "CLIENTE:" << endl;
                cout << clientesLocadora.at(i).cpf << " / "
                << clientesLocadora.at(i).nome << " / " 
                << clientesLocadora.at(i).dtNascimento << " / " 
                << clientesLocadora.at(i).cnh << endl;
                break;
            }
        }
        if(!clienteEncontrado) cout << "AVISO: Cliente não encontrado. Verifique se digitou CPF corretamente." << endl;
    } else cout << "AVISO: Nenhum cliente cadastrado." << endl;
}
void sistemaClientes(){
    int opcaoUsuario = 0;
    do{
        system(LIMPAR_TELA);
        opcaoUsuario = menu(true);
        switch(opcaoUsuario){
            case 0:
                return;
                break;
            case 1:
                incluirCliente();
                system(PAUSA);
                break;
            case 2:
                excluirCliente();
                system(PAUSA);
                break;
            case 3:
                alterarCliente();
                system(PAUSA);
                break;
            case 4:
                listarClientes();
                system(PAUSA);
                break;
            case 5:
                localizarCliente();
                system(PAUSA);
                break;
            default:
                cout << "AVISO: Opção inválida!" << endl;
                break;
        }
    }while(opcaoUsuario != 0);
}
void incluirVeiculo(){
    VEICULO veiculo;
    system(LIMPAR_TELA);
    cout << "Digite o nº Renavan (somente nº): ";
    cin >> veiculo.renavan;
    cout << "Digite a Placa do Veiculo: ";
    cin >> veiculo.placa_veiculo;
    cout << "Digite a Data de Retirada: " << endl;
    cout << "Dia: ";
    cin >> veiculo.dataHoraRetirada.dia;
    cout << "Mes: ";
    cin >> veiculo.dataHoraRetirada.mes;
    cout << "Ano: ";
    cin >> veiculo.dataHoraRetirada.ano;
    cout << "Hora: ";
    cin >> veiculo.dataHoraRetirada.hora;
    cout << "Minutos: ";
    cin >> veiculo.dataHoraRetirada.minutos;
    cout << "Digite a Data de Entrega: " << endl;
    cout << "Dia: ";
    cin >> veiculo.dataHoraEntrega.dia;
    cout << "Mes: ";
    cin >> veiculo.dataHoraEntrega.mes;
    cout << "Ano: ";
    cin >> veiculo.dataHoraEntrega.ano;
    cout << "Hora: ";
    cin >> veiculo.dataHoraEntrega.hora;
    cout << "Minutos: ";
    cin >> veiculo.dataHoraEntrega.minutos;
    cout << "Digite o nome da Loja: ";
    cin >> veiculo.lojaRetirada;
    veiculosLocadora.push_back(veiculo);
    cout << "AVISO: Veiculo cadastrado com sucesso!" << endl;
}
void excluirVeiculo(){
    if(veiculosLocadora.size() > 0){
        string cpfExcluir;
        bool clienteEncontrado;

        cout << "Digite o CPF: ";
        cin >> cpfExcluir;

        for(size_t i=0; i<clientesLocadora.size(); i++){
            if(clientesLocadora.at(i).cpf == cpfExcluir){
                clienteEncontrado = true;
                clientesLocadora.erase(clientesLocadora.begin() + i);
            }
        }
        if(clienteEncontrado) cout << "AVISO: Cliente excluido com sucesso!" << endl;
        else cout << "AVISO: Cliente não encontrado. Verifique se digitou CPF corretamente." << endl;
    } else cout << "AVISO: Nenhum cliente cadastrado." << endl;
}
void sistemaVeiculos(){
    int opcaoUsuario = 0;
    do{
        system(LIMPAR_TELA);
        opcaoUsuario = menu(false);
        switch(opcaoUsuario){
            case 0:
                return;
                break;
            case 1:
                incluirVeiculo();
                system(PAUSA);
                break;
            case 2:
                excluirVeiculo();
                system(PAUSA);
                break;
            case 3:
                alterarVeiculo();
                system(PAUSA);
                break;
            case 4:
                listarVeiculos();
                system(PAUSA);
                break;
            case 5:
                localizarVeiculo();
                system(PAUSA);
                break;
            default:
                cout << "AVISO: Opção inválida!" << endl;
                break;
        }
    }while(opcaoUsuario < 0 || opcaoUsuario > 5);
}