#include "SistemaAgencia.hpp"
#include <iostream>
#include <limits>

SistemaAgencia::SistemaAgencia() {
    _inicializarDados();
}

void SistemaAgencia::_inicializarDados() {
    // Cria usuários
    _viajantes.push_back(std::make_shared<Viajante>("v001", "Clarice Lispector", "clarice@email.com", "senha123"));
    _viajantes.push_back(std::make_shared<Viajante>("v002", "Carlos Drummond", "carlos@email.com", "senha456"));
    _admins.push_back(std::make_shared<Administrador>("adm001", "Machado de Assis", "machado@email.com", "admin123"));
    _agentes.push_back(std::make_shared<AgenteDeViagem>("agt001", "Cecília Meireles", "cecilia@email.com", "agente123"));

    // Cria pacotes nacionais
    auto pacoteBH_SP = std::make_shared<PacoteTuristico>("pct01", "Belo Horizonte - São Paulo", "Pacote para São Paulo, 4 dias");
    pacoteBH_SP->adicionarProduto(std::make_shared<Voo>("voo001", "Voo BH-SP", "Voo", 1200, 10, "Belo Horizonte", "São Paulo", "2025-10-10", "2025-10-14", "Azul"));
    _pacotesNacionais.push_back(pacoteBH_SP);
    
    auto pacoteBH_RJ = std::make_shared<PacoteTuristico>("pct02", "Belo Horizonte - Rio de Janeiro", "Pacote para o Rio, 5 dias");
    pacoteBH_RJ->adicionarProduto(std::make_shared<Voo>("voo002", "Voo BH-RJ", "Voo", 2000, 15, "Belo Horizonte", "Rio de Janeiro", "2025-11-15", "2025-11-20", "Gol"));
    _pacotesNacionais.push_back(pacoteBH_RJ);
    
    // Cria pacote internacional
    auto pacoteBH_SCL = std::make_shared<PacoteTuristico>("pct03", "Belo Horizonte - Santiago", "Pacote para Santiago, 7 dias");
    pacoteBH_SCL->adicionarProduto(std::make_shared<Voo>("voo003", "Voo BH-SCL", "Voo", 5000, 5, "Belo Horizonte", "Santiago", "2026-01-20", "2026-01-27", "LATAM"));
    _pacotesInternacionais.push_back(pacoteBH_SCL);
}

void SistemaAgencia::_limparBufferEntrada() const {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void SistemaAgencia::_menuPrincipal() {
    std::cout << "\n===== Bem-vindo à Agência de Viagens! =====\n";
    std::cout << "Escolha seu perfil:\n";
    std::cout << "1. Viajante\n";
    std::cout << "2. Administrador\n";
    std::cout << "3. Agente de Viagem\n";
    std::cout << "4. Sair\n";
    std::cout << "Escolha uma opção: ";
}

void SistemaAgencia::run() {
    int escolhaUsuario;
    do {
        _menuPrincipal();
        std::cin >> escolhaUsuario;
        _limparBufferEntrada();

        switch (escolhaUsuario) {
            case 1: _menuViajante(); break;
            case 2: _menuAdministrador(); break;
            case 3: _menuAgenteDeViagem(); break;
            case 4: std::cout << "Saindo do sistema. Até logo!\n"; break;
            default: std::cout << "Opção inválida. Tente novamente.\n"; break;
        }
    } while (escolhaUsuario != 4);
}

void SistemaAgencia::_menuViajante() {
    int escolha;
    do {
        std::cout << "\n--- Menu do Viajante ---\n";
        std::cout << "1. Ver pacotes de viagem nacional\n";
        std::cout << "2. Ver pacotes de viagem internacional\n";
        std::cout << "3. Minhas viagens\n";
        std::cout << "4. Voltar para o menu principal\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;
        _limparBufferEntrada();

        switch (escolha) {
            case 1:
                std::cout << "\n--- Pacotes Nacionais Disponíveis ---\n";
                for (const auto& pacote : _pacotesNacionais) {
                    std::cout << pacote->getDetalhesPacote() << std::endl;
                }
                break;
            case 2:
                std::cout << "\n--- Pacotes Internacionais Disponíveis ---\n";
                for (const auto& pacote : _pacotesInternacionais) {
                    std::cout << pacote->getDetalhesPacote() << std::endl;
                }
                break;
            case 3:
                std::cout << "\n--- Minhas Viagens ---\n";
                std::cout << "Não há nenhuma viagem reservada.\n";
                break;
            case 4: break;
            default: std::cout << "Opção inválida. Tente novamente.\n"; break;
        }
    } while (escolha != 4);
}

void SistemaAgencia::_menuAdministrador() {
    int escolha;
    do {
        std::cout << "\n--- Menu do Administrador ---\n";
        std::cout << "1. Ver clientes cadastrados\n";
        std::cout << "2. Voltar ao menu principal\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;
        _limparBufferEntrada();
        if (escolha == 1) {
            _admins.front()->verClientes(_viajantes);
        }
    } while (escolha != 2);
}

void SistemaAgencia::_menuAgenteDeViagem() {
    int escolha;
    do {
        std::cout << "\n--- Menu do Agente de Viagem ---\n";
        std::cout << "1. Criar novo pacote\n";
        std::cout << "2. Voltar ao menu principal\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> escolha;
        _limparBufferEntrada();
        if (escolha == 1) {
            _agentes.front()->criarPacote(_pacotesNacionais, _pacotesInternacionais);
        }
    } while (escolha != 2);
}
