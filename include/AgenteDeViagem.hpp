// include/AgenteDeViagem.hpp
#ifndef AGENTEDEVIAGEM_HPP
#define AGENTEDEVIAGEM_HPP

#include "Usuario.hpp"
// #include "Reserva.hpp"
// #include "PacoteTuristico.hpp"

class AgenteDeViagem : public Usuario {
public:
    AgenteDeViagem(std::string id, std::string nome, std::string email, std::string senha);
    ~AgenteDeViagem() override;

    void exibirPainel() const override;

    // Funcionalidades do Agente de Viagem
    // void gerenciarReservaCliente(/.../);
    // void criarPacoteTuristico(/.../);
    // void atualizarPacoteTuristico(/.../);
    // void verificarDisponibilidadeGlobal();

    // TODO: Implementar métodos específicos do AgenteDeViagem.
};

#endif // AGENTEDEVIAGEM_HPP
