// src/Usuario.cpp
#include "Usuario.hpp"
#include <iostream> // Para implementações de placeholder

Usuario::Usuario(std::string id, std::string nome, std::string email, std::string senha, TipoRole role)
    : id(id), nome(nome), email(email), role(role) {
    // Em um sistema real, 'senha' seria hasheada aqui e armazenada em senhaHash.
    // Para este esqueleto, vamos assumir que 'senha' já é um hash ou armazená-la diretamente por simplicidade.
    this->senhaHash = senha; // Placeholder: Hashear a senha adequadamente.
}

std::string Usuario::getId() const { return id; }
std::string Usuario::getNome() const { return nome; }
std::string Usuario::getEmail() const { return email; }
TipoRole Usuario::getRole() const { return role; }

void Usuario::setNome(const std::string& nome) { this->nome = nome; }
void Usuario::setEmail(const std::string& email) { this->email = email; }

bool Usuario::verificarSenha(const std::string& senhaFornecida) const {
    // Placeholder: Comparar senhaFornecida (após hashear) com senhaHash.
    // Esta é uma comparação simplificada. Em um sistema real, use uma biblioteca de hash segura.
    return this->senhaHash == senhaFornecida; 
}

// exibirPainel() é virtual puro e deve ser implementado nas classes derivadas.
// O destrutor é padrão (default) no cabeçalho.
