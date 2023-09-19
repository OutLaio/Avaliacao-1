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

int menu(bool ehCliente);
int menuModulo();
void incluirCliente();
void excluirCliente();
void modificarCliente(int indexCliente);
void alterarCliente();
void listarClientes();
void localizarCliente();
void sistemaClientes();
void incluirVeiculo();
void excluirVeiculo();
void modificarVeiculo(int indexVeiculo);
void alterarVeiculo();
void listarVeiculos();
void localizarVeiculo();
void sistemaVeiculos();

// Variaveis globais;
vector<CLIENTE> clientesLocadora;
vector<VEICULO> veiculosLocadora;

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
    } else{
        cout << "Nenhum cliente cadastrado!" << endl;
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
        string placaExcluir;
        bool veiculoEncontrado;

        cout << "Digite a Placa: ";
        cin >> placaExcluir;

        for(size_t i=0; i<veiculosLocadora.size(); i++){
            if(veiculosLocadora.at(i).placa_veiculo == placaExcluir){
                veiculoEncontrado = true;
                veiculosLocadora.erase(veiculosLocadora.begin() + i);
            }
        }
        if(veiculoEncontrado) cout << "AVISO: Veiculo excluido com sucesso!" << endl;
        else cout << "AVISO: Veiculo não encontrado. Verifique se digitou a placa corretamente." << endl;
    } else cout << "AVISO: Nenhum veiculo cadastrado." << endl;
}
void modificarVeiculo(int indexVeiculo){
    int opcaoUsuario = 0;
    do{
        system(LIMPAR_TELA);
        cout << "Escolha um opção para alterar: " << endl;
        cout << "1. Nº Renavan" << endl;
        cout << "2. Placa do Veiculo" << endl;
        cout << "3. Data Retirada" << endl;
        cout << "4. Data Entrega" << endl;
        cout << "5. Loja Retirada" << endl;
        cout << "0. Sair" << endl << "> ";
        cin >> opcaoUsuario;
        
        if(opcaoUsuario < 0 || opcaoUsuario > 5){
            cout << "AVISO: Opção inválida!" << endl;
            system(PAUSA);
        }
        
        string novoDado;
        switch(opcaoUsuario){
            case 0:
                break;
            case 1:
                cout << "Digite o novo nº Renavan: ";
                cin >> veiculosLocadora.at(indexVeiculo).renavan;
                break;
            case 2:
                cout << "Digite a nova placa: ";
                cin >> veiculosLocadora.at(indexVeiculo).placa_veiculo;
                break;
            case 3:
                cout << "Digite a nova Data de Retirada: ";
                cout << "Dia: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraRetirada.dia;
                cout << "Mes: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraRetirada.mes;
                cout << "Ano: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraRetirada.ano;
                cout << "Hora: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraRetirada.hora;
                cout << "Minutos: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraRetirada.minutos;
                break;
            case 4:
                cout << "Digite a nova Data de Entrega: ";
                cout << "Dia: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraEntrega.dia;
                cout << "Mes: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraEntrega.mes;
                cout << "Ano: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraEntrega.ano;
                cout << "Hora: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraEntrega.hora;
                cout << "Minutos: ";
                cin >> veiculosLocadora.at(indexVeiculo).dataHoraEntrega.minutos;
                break;
            case 5:
                cout << "Digite a nova loja retirada: ";
                cin >> veiculosLocadora.at(indexVeiculo).lojaRetirada;
                break;
            default:
                break;
        }
        cout << endl << "Veiculo alterado com sucesso!";
        system(PAUSA);
    }while(opcaoUsuario != 0);
}
void alterarVeiculo(){
    if(veiculosLocadora.size() > 0){
        string placaAlterar;
        bool veiculoEncontrado;

        cout << "Digite a placa: ";
        cin >> placaAlterar;

        for(size_t i=0; i<veiculosLocadora.size(); i++){
            if(veiculosLocadora.at(i).placa_veiculo == placaAlterar){
                veiculoEncontrado = true;
                modificarVeiculo(i);
                break;
            }
        }
        if(!veiculoEncontrado) cout << "AVISO: Veiculo não encontrado. Verifique se digitou a placa corretamente." << endl;
    } else cout << "AVISO: Nenhum veiculo cadastrado." << endl;
}
void mostrarDataHora(DATA data){
    cout << data.dia << "/" << data.mes << "/" << data.ano
    << "(" << data.hora << ":" << data.minutos << ")";
}
void listarVeiculos(){
    if(veiculosLocadora.size() > 0){
        system(LIMPAR_TELA);
        cout << "Lista de Veiculos:" << endl;
        cout << endl << "Nº RENAVANA / PLACA / RETIRADA / ENTREGA / LOJA RETIRADA" << endl;
        for(size_t i=0; i<veiculosLocadora.size(); i++){
            cout << veiculosLocadora.at(i).renavan << " / "
            << veiculosLocadora.at(i).placa_veiculo << " / "; 
            mostrarDataHora(veiculosLocadora.at(i).dataHoraRetirada);
            cout << " / ";
            mostrarDataHora(veiculosLocadora.at(i).dataHoraEntrega);
            cout << " / " << veiculosLocadora.at(i).lojaRetirada << endl;
        }
        cout << endl;
    } else{
        cout << "Nenhum veiculo cadastrado!" << endl;
    }
}
void localizarVeiculo(){
    if(veiculosLocadora.size() > 0){
        string placaVeiculo;
        bool veiculoEncontrado;

        cout << "Digite a placa: ";
        cin >> placaVeiculo;

        for(size_t i=0; i<veiculosLocadora.size(); i++){
            if(veiculosLocadora.at(i).placa_veiculo == placaVeiculo){
                veiculoEncontrado = true;
                cout << "VEICULO:" << endl;
                cout << veiculosLocadora.at(i).renavan << " / "
                << veiculosLocadora.at(i).placa_veiculo << " / "; 
                mostrarDataHora(veiculosLocadora.at(i).dataHoraRetirada);
                cout << " / ";
                mostrarDataHora(veiculosLocadora.at(i).dataHoraEntrega);
                cout << " / " << veiculosLocadora.at(i).lojaRetirada << endl;
                break;
            }
        }
        if(!veiculoEncontrado) cout << "AVISO: Veiculo não encontrado. Verifique se digitou a placa corretamente." << endl;
    } else cout << "AVISO: Nenhum veiculo cadastrado." << endl;
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
    }while(opcaoUsuario != 0);
}