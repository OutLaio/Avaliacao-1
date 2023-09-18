#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definindo a classe Veiculo
class Veiculo {
public:
    string renavan;
    string placa;
    string dataHoraRetirada;
    string dataHoraEntrega;
    string lojaRetirada;
};

// Função para incluir um novo veículo
void incluirVeiculo(vector<Veiculo>& veiculos) {
    Veiculo novoVeiculo;
    cout << "Digite o Renavan do veículo: ";
    cin >> novoVeiculo.renavan;
    cout << "Digite a placa do veículo: ";
    cin >> novoVeiculo.placa;
    cout << "Digite a data e hora de retirada: ";
    cin >> novoVeiculo.dataHoraRetirada;
    cout << "Digite a data e hora de entrega: ";
    cin >> novoVeiculo.dataHoraEntrega;
    cout << "Digite a loja de retirada: ";
    cin >> novoVeiculo.lojaRetirada;
    veiculos.push_back(novoVeiculo);
    cout << "Veículo incluído com sucesso!" << endl;
}

// Função para excluir um veículo através do Renavan
void excluirVeiculo(vector<Veiculo>& veiculos) {
    string renavan;
    cout << "Digite o Renavan do veículo que deseja excluir: ";
    cin >> renavan;
    for (auto it = veiculos.begin(); it != veiculos.end(); ++it) {
        if (it->renavan == renavan) {
            veiculos.erase(it);
            cout << "Veículo excluído com sucesso!" << endl;
            return;
        }
    }
    cout << "Veículo não encontrado." << endl;
}

// Função para alterar informações de um veículo através do Renavan
void alterarVeiculo(vector<Veiculo>& veiculos) {
    string renavan;
    cout << "Digite o Renavan do veículo que deseja alterar: ";
    cin >> renavan;
    for (auto& veiculo : veiculos) {
        if (veiculo.renavan == renavan) {
            cout << "Digite a nova placa do veículo: ";
            cin >> veiculo.placa;
            cout << "Digite a nova data e hora de retirada: ";
            cin >> veiculo.dataHoraRetirada;
            cout << "Digite a nova data e hora de entrega: ";
            cin >> veiculo.dataHoraEntrega;
            cout << "Digite a nova loja de retirada: ";
            cin >> veiculo.lojaRetirada;
            cout << "Veículo alterado com sucesso!" << endl;
            return;
        }
    }
    cout << "Veículo não encontrado." << endl;
}

// Função para listar todos os veículos
void listarVeiculos(const vector<Veiculo>& veiculos) {
    if (veiculos.empty()) {
        cout << "Nenhum veículo cadastrado." << endl;
    } else {
        cout << "Lista de veículos:" << endl;
        for (const auto& veiculo : veiculos) {
            cout << "Renavan: " << veiculo.renavan << endl;
            cout << "Placa: " << veiculo.placa << endl;
            cout << "Data e hora de retirada: " << veiculo.dataHoraRetirada << endl;
            cout << "Data e hora de entrega: " << veiculo.dataHoraEntrega << endl;
            cout << "Loja de retirada: " << veiculo.lojaRetirada << endl;
            cout << "------------------------" << endl;
        }
    }
}

// Função para localizar um veículo através do Renavan
void localizarVeiculo(const vector<Veiculo>& veiculos) {
    string renavan;
    cout << "Digite o Renavan do veículo que deseja localizar: ";
    cin >> renavan;
    for (const auto& veiculo : veiculos) {
        if (veiculo.renavan == renavan) {
            cout << "Veículo encontrado:" << endl;
            cout << "Renavan: " << veiculo.renavan << endl;
            cout << "Placa: " << veiculo.placa << endl;
            cout << "Data e hora de retirada: " << veiculo.dataHoraRetirada << endl;
            cout << "Data e hora de entrega: " << veiculo.dataHoraEntrega << endl;
            cout << "Loja de retirada: " << veiculo.lojaRetirada << endl;
            return;
        }
    }
    cout << "Veículo não encontrado." << endl;
}

int main() {
    vector<Veiculo> veiculos;
    int opcao;

    do {
        cout << "Menu:" << endl;
        cout << "1. Incluir veículo" << endl;
        cout << "2. Excluir veículo" << endl;
        cout << "3. Alterar veículo" << endl;
        cout << "4. Listar veículos" << endl;
        cout << "5. Localizar veículo" << endl;
        cout << "0. Sair do menu" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                incluirVeiculo(veiculos);
                break;
            case 2:
                excluirVeiculo(veiculos);
                break;
            case 3:
                alterarVeiculo(veiculos);
                break;
            case 4:
                listarVeiculos(veiculos);
                break;
            case 5:
                localizarVeiculo(veiculos);
                break;
            case 6:
                cout << "Saindo do menu." << endl;
                break;
            default:
                cout << "Opcao invalida." << endl;
        }
    } while (opcao != 6);

    return 0;
}
