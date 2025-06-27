#include "Administrador.hpp"
#include "Viajante.hpp"
#include <iostream>
#include <limits>

// Função para limpar o buffer do console
void clearInputBufferAdmin() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

Administrador::Administrador(std::string id, std::string nome, std::string email, std::string senha)
    : Usuario(id, nome, email, senha, TipoRole::ADMINISTRADOR) {}

void Administrador::verClientes(const std::vector<std::shared_ptr<Viajante>>& viajantes) const {
    std::cout << "\n--- Clientes com Reserva ---\n";
    std::cout << "Total de viajantes cadastrados: " << viajantes.size() << std::endl;
    for (const auto& viajante : viajantes) {
        std::cout << " - " << viajante->getNome() << std::endl;
    }
}

void Administrador::exibirPainel() const {
    // Esta função poderia ser usada para um painel mais complexo no futuro.
    // Por enquanto, a lógica está na main para manter a simplicidade do exemplo.
    std::cout << "\n--- Painel do Administrador: " << getNome() << " ---" << std::endl;
}
