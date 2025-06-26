// include/Administrador.hpp
#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "Usuario.hpp"

class Administrador : public Usuario {
public:
    Administrador(std::string id, std::string nome, std::string email, std::string senha);
    ~Administrador() override;

    void exibirPainel() const override;

    // Funcionalidades do Administrador
    // void gerenciarUsuarios(/.../);
    // void gerenciarPermissoes(/.../);
    // void gerenciarConteudoSite(/.../);
    // void gerarRelatorios(/.../);
    
    // TODO: Implementar métodos específicos do Administrador.
};

#endif // ADMINISTRADOR_HPP
