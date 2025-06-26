// src/Viajante.cpp
#include "Viajante.hpp"
#include <iostream>

Viajante::Viajante(std::string id, std::string nome, std::string email, std::string senha)
    : Usuario(id, nome, email, senha, TipoRole::VIAJANTE) {
    // Inicialização específica do Viajante, se houver.
}

Viajante::~Viajante() {
    // Limpeza específica do Viajante, se houver (ex: liberar memória de historicoViagens se usar ponteiros crus).
}

void Viajante::exibirPainel() const {
    std::cout << "Painel do Viajante: " << nome << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1. Buscar Voos/Hotéis/Pacotes" << std::endl;
    std::cout << "2. Ver Minhas Reservas" << std::endl;
    std::cout << "3. Ver Meus Itinerários" << std::endl;
    std::cout << "4. Minha Conta" << std::endl;
    std::cout << "5. Sair" << std::endl;
    // TODO: Implementar lógica de interação do painel.
}

// TODO: Implementar outros métodos da classe Viajante.
// Exemplo:
// void Viajante::buscarProdutos(const FiltroBusca& filtro) {
//     std::cout << "Viajante " << nome << " buscando produtos..." << std::endl;
//     // Lógica de busca
// }
