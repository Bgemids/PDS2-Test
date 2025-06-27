#include "Administrador.hpp"
#include "Viajante.hpp"
#include <iostream>
#include <limits>

Administrador::Administrador(std::string id, std::string nome, std::string email, std::string senha)
    : Usuario(id, nome, email, senha, TipoRole::ADMINISTRADOR) {}

void Administrador::verClientes(const std::vector<std::shared_ptr<Viajante>>& viajantes) const {
    std::cout << "\n--- Clientes com Reserva ---\n";
    std::cout << "Total de viajantes cadastrados: " << viajantes.size() << std::endl;
    for (const std::shared_ptr<Viajante>& viajante : viajantes) {
        std::cout << " - " << viajante->getNome() << std::endl;
    }
}

void Administrador::exibirPainel() const {
    std::cout << "\n--- Painel do Administrador: " << getNome() << " ---" << std::endl;
}
