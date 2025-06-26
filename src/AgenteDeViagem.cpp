// src/AgenteDeViagem.cpp
#include "AgenteDeViagem.hpp"
#include <iostream>

AgenteDeViagem::AgenteDeViagem(std::string id, std::string nome, std::string email, std::string senha)
    : Usuario(id, nome, email, senha, TipoRole::AGENTE_VIAGEM) {
    // Inicialização específica do AgenteDeViagem.
}

AgenteDeViagem::~AgenteDeViagem() {
    // Limpeza específica do AgenteDeViagem.
}

void AgenteDeViagem::exibirPainel() const {
    std::cout << "Painel do Agente de Viagem: " << nome << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "1. Gerenciar Reservas de Clientes" << std::endl;
    std::cout << "2. Criar Pacotes Turísticos" << std::endl;
    std::cout << "3. Atualizar Disponibilidade" << std::endl;
    std::cout << "4. Sair" << std::endl;
    // TODO: Implementar lógica de interação do painel.
}

//AgenteDeViagem.cppr outros métodos da classe AgenteDeViagem.