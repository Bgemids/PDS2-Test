// src/Administrador.cpp
#include "Administrador.hpp"
#include <iostream>

Administrador::Administrador(std::string id, std::string nome, std::string email, std::string senha)
    : Usuario(id, nome, email, senha, TipoRole::ADMINISTRADOR) {
    // Inicialização específica do Administrador.
}

Administrador::~Administrador() {
    // Limpeza específica do Administrador.
}

void Administrador::exibirPainel() const {
    std::cout << "Painel do Administrador: " << nome << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1. Gerenciar Usuários" << std::endl;
    std::cout << "2. Gerenciar Conteúdo" << std::endl;
    std::cout << "3. Visualizar Relatórios" << std::endl;
    std::cout << "4. Sair" << std::endl;
    // TODO: Implementar lógica de interação do painel.
}

// TODO: Implementar outros métodos da classe Administrador.