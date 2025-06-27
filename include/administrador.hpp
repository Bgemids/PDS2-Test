#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"
#include <vector>
#include <memory>

class Viajante; // Forward declaration

class Administrador : public Usuario {
public:
    Administrador(std::string id, std::string nome, std::string email, std::string senha);
    void exibirPainel() const override;
    void verClientes(const std::vector<std::shared_ptr<Viajante>>& viajantes) const;
};

#endif // ADMINISTRADOR_HPP
