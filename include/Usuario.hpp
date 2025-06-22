
// include/Usuario.hpp
#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include "EnumTypes.hpp" // Para TipoRole

// Declaração antecipada para evitar dependência circular, se Reserva* for usado.
// class Reserva; 

class Usuario {
protected:
    std::string id;
    std::string nome;
    std::string email;
    std::string senhaHash; // Armazenar um hash, não texto plano
    TipoRole role;

public:
    /**
     * @brief Construtor da classe Usuario.
     * @param id Identificador único do usuário.
     * @param nome Nome do usuário.
     * @param email Email do usuário.
     * @param senha Senha (deve ser hasheada antes de armazenar).
     * @param role Papel do usuário no sistema.
     */
    Usuario(std::string id, std::string nome, std::string email, std::string senha, TipoRole role);
    
    /**
     * @brief Destrutor virtual padrão.
     */
    virtual ~Usuario() = default;

    // Getters
    std::string getId() const;
    std::string getNome() const;
    std::string getEmail() const;
    TipoRole getRole() const;

    // Setters / Modificadores
    void setNome(const std::string& nome);
    void setEmail(const std::string& email);
    // A senha deve ser tratada com cuidado, ex: método alterarSenha que refaz o hash.

    /**
     * @brief Verifica se a senha fornecida corresponde à senha armazenada.
     * @param senhaFornecida Senha em texto plano para verificação.
     * @return True se a senha corresponder, false caso contrário.
     */
    virtual bool verificarSenha(const std::string& senhaFornecida) const;

    /**
     * @brief Exibe o painel principal específico para o tipo de usuário.
     *        Método virtual puro, tornando Usuario uma classe abstrata.
     */
    virtual void exibirPainel() const = 0; 

    // TODO: Adicionar métodos para serialização/desserialização (ex: paraJson, deJson)
    // para persistência de dados, possivelmente usando uma biblioteca como nlohmann/json.
};

#endif // USUARIO_HPP
