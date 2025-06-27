#include "AgenteDeViagem.hpp"
#include "Voo.hpp"
#include <iostream>
#include <limits>
#include <string>

// Função para limpar o buffer do console
void clearInputBufferAgent() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

AgenteDeViagem::AgenteDeViagem(std::string id, std::string nome, std::string email, std::string senha)
    : Usuario(id, nome, email, senha, TipoRole::AGENTE_VIAGEM) {}

void AgenteDeViagem::criarPacote(std::vector<std::shared_ptr<PacoteTuristico>>& pacotesNacionais, std::vector<std::shared_ptr<PacoteTuristico>>& pacotesInternacionais) {
    std::cout << "\n--- Criar Novo Pacote ---\n";
    std::string origem, destino, nomePacote, descPacote;
    int dias;
    double preco;

    std::cout << "Cidade de Origem: ";
    std::getline(std::cin, origem);
    std::cout << "Cidade de Destino: ";
    std::getline(std::cin, destino);
    std::cout << "Quantidade de dias: ";
    std::cin >> dias;
    std::cout << "Preço: ";
    std::cin >> preco;
    clearInputBufferAgent();

    nomePacote = origem + " - " + destino;
    descPacote = "Pacote de " + std::to_string(dias) + " dias para " + destino;

    std::shared_ptr<PacoteTuristico> novoPacote = std::make_shared<PacoteTuristico>("pct" + std::to_string(pacotesNacionais.size() + pacotesInternacionais.size() + 1), nomePacote, descPacote);
    novoPacote->adicionarProduto(std::make_shared<Voo>("voo_gen", nomePacote, descPacote, preco, 20, origem, destino, "a definir", "a definir", "a definir"));
    
    std::cout << "Pacote Nacional ou Internacional? (1 - Nacional, 2 - Internacional): ";
    int tipoPacote;
    std::cin >> tipoPacote;
    clearInputBufferAgent();

    if (tipoPacote == 1) {
        pacotesNacionais.push_back(novoPacote);
    } else {
        pacotesInternacionais.push_back(novoPacote);
    }
    std::cout << "Novo pacote criado com sucesso!\n";
}

void AgenteDeViagem::exibirPainel() const {
    std::cout << "\n--- Painel do Agente de Viagem: " << getNome() << " ---" << std::endl;
}
