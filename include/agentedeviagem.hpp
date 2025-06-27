#ifndef AGENTEDEVIAGEM_HPP
#define AGENTEDEVIAGEM_HPP

#include "Usuario.hpp"
#include "PacoteTuristico.hpp"
#include <vector>
#include <memory>

class AgenteDeViagem : public Usuario {
public:
    AgenteDeViagem(std::string id, std::string nome, std::string email, std::string senha);
    void exibirPainel() const override;
    void criarPacote(std::vector<std::shared_ptr<PacoteTuristico>>& pacotesNacionais, std::vector<std::shared_ptr<PacoteTuristico>>& pacotesInternacionais);
};

#endif // AGENTEDEVIAGEM_HPP
