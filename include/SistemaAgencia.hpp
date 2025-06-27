#ifndef SISTEMAAGENCIA_HPP
#define SISTEMAAGENCIA_HPP

#include <vector>
#include <memory>
#include "Viajante.hpp"
#include "Administrador.hpp"
#include "AgenteDeViagem.hpp"
#include "PacoteTuristico.hpp"

class SistemaAgencia {
private:
    // Vetores que armazenam os dados do sistema
    std::vector<std::shared_ptr<Viajante>> _viajantes;
    std::vector<std::shared_ptr<Administrador>> _admins;
    std::vector<std::shared_ptr<AgenteDeViagem>> _agentes;
    std::vector<std::shared_ptr<PacoteTuristico>> _pacotesNacionais;
    std::vector<std::shared_ptr<PacoteTuristico>> _pacotesInternacionais;

    // Métodos privados para organizar a lógica
    void _inicializarDados();
    void _menuPrincipal();
    void _menuViajante();
    void _menuAdministrador();
    void _menuAgenteDeViagem();
    void _limparBufferEntrada() const;

public:
    SistemaAgencia();
    void run();
};

#endif // SISTEMAAGENCIA_HPP
