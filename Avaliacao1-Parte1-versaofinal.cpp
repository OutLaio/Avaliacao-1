#include <iostream>
#include <vector>
#include <string>

// Definição da estrutura Cliente
struct Cliente {
    std::string cpf;
    std::string nome;
    std::string dataNascimento;
    std::string cnh;
};

// Função para incluir um novo cliente
void incluirCliente(std::vector<Cliente> &clientes) {
    Cliente novoCliente;
    std::cout << "CPF: ";
    std::cin >> novoCliente.cpf;
    std::cout << "Nome: ";
    std::cin.ignore();
    std::getline(std::cin, novoCliente.nome);
    std::cout << "Data de Nascimento: ";
    std::cin >> novoCliente.dataNascimento;
    std::cout << "CNH: ";
    std::cin >> novoCliente.cnh;
    clientes.push_back(novoCliente);
    std::cout << "Cliente adicionado com sucesso!" << std::endl;
}

// Função para excluir um cliente através do CPF
void excluirCliente(std::vector<Cliente> &clientes) {
    std::string cpf;
    std::cout << "Informe o CPF do cliente a ser excluído: ";
    std::cin >> cpf;
    
    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->cpf == cpf) {
            clientes.erase(it);
            std::cout << "Cliente removido com sucesso!" << std::endl;
            return;
        }
    }
    
    std::cout << "Cliente com CPF " << cpf << " não encontrado." << std::endl;
}

// Função para alterar dados de um cliente através do CPF
void alterarCliente(std::vector<Cliente> &clientes) {
    std::string cpf;
    std::cout << "Informe o CPF do cliente a ser alterado: ";
    std::cin >> cpf;
    
    for (auto &cliente : clientes) {
        if (cliente.cpf == cpf) {
            std::cout << "Dados atuais do cliente:" << std::endl;
            std::cout << "Nome: " << cliente.nome << std::endl;
            std::cout << "Data de Nascimento: " << cliente.dataNascimento << std::endl;
            std::cout << "CNH: " << cliente.cnh << std::endl;
            
            std::cout << "Deseja alterar o nome? (S/N): ";
            char opcao;
            std::cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                std::cout << "Novo nome: ";
                std::cin.ignore();
                std::getline(std::cin, cliente.nome);
            }
            
            std::cout << "Deseja alterar a data de nascimento? (S/N): ";
            std::cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                std::cout << "Nova data de Nascimento: ";
                std::cin >> cliente.dataNascimento;
            }
            
            std::cout << "Deseja alterar a CNH? (S/N): ";
            std::cin >> opcao;
            if (opcao == 'S' || opcao == 's') {
                std::cout << "Nova CNH: ";
                std::cin >> cliente.cnh;
            }
            
            std::cout << "Dados do cliente alterados com sucesso!" << std::endl;
            return;
        }
    }
    
    std::cout << "Cliente com CPF " << cpf << " não encontrado." << std::endl;
}

// Função para listar todos os clientes
void listarClientes(const std::vector<Cliente> &clientes) {
    std::cout << "Lista de Clientes:" << std::endl;
    for (const auto &cliente : clientes) {
        std::cout << "CPF: " << cliente.cpf << std::endl;
        std::cout << "Nome: " << cliente.nome << std::endl;
        std::cout << "Data de Nascimento: " << cliente.dataNascimento << std::endl;
        std::cout << "CNH: " << cliente.cnh << std::endl;
        std::cout << "----------------------" << std::endl;
    }
}

// Função para localizar um cliente através do CPF
void localizarCliente(const std::vector<Cliente> &clientes) {
    std::string cpf;
    std::cout << "Informe o CPF do cliente a ser localizado: ";
    std::cin >> cpf;
    
    for (const auto &cliente : clientes) {
        if (cliente.cpf == cpf) {
            std::cout << "Dados do Cliente:" << std::endl;
            std::cout << "CPF: " << cliente.cpf << std::endl;
            std::cout << "Nome: " << cliente.nome << std::endl;
            std::cout << "Data de Nascimento: " << cliente.dataNascimento << std::endl;
            std::cout << "CNH: " << cliente.cnh << std::endl;
            return;
        }
    }
    
    std::cout << "Cliente com CPF " << cpf << " não encontrado." << std::endl;
}

int main() {
    std::vector<Cliente> clientes;
    int opcao;
    
    do {
        std::cout << "MENU DE CLIENTES" << std::endl;
        std::cout << "1. Incluir Cliente" << std::endl;
        std::cout << "2. Excluir Cliente" << std::endl;
        std::cout << "3. Alterar Cliente" << std::endl;
        std::cout << "4. Listar Clientes" << std::endl;
        std::cout << "5. Localizar Cliente" << std::endl;
        std::cout << "6. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        
        switch (opcao) {
            case 1:
                incluirCliente(clientes);
                break;
            case 2:
                excluirCliente(clientes);
                break;
            case 3:
                alterarCliente(clientes);
                break;
            case 4:
                listarClientes(clientes);
                break;
            case 5:
                localizarCliente(clientes);
                break;
            case 6:
                std::cout << "Saindo do programa." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida." << std::endl;
        }
    } while (opcao != 6);
    
    return 0;
}
