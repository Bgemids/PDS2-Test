// include/PacoteTuristico.hpp
#ifndef PACOTETURISTICO_HPP
#define PACOTETURISTICO_HPP

#include <string>
#include <vector>
#include <memory> // Para std::shared_ptr ou std::unique_ptr

// Forward declaration
class ProdutoTuristico; 

class PacoteTuristico {
private:
    std::string id;
    std::string nome;
    std::string descricao;
    std::vector<std::shared_ptr<ProdutoTuristico>> produtosInclusos; // Usar smart pointers para gerenciar ciclo de vida

public:
    PacoteTuristico(std::string id, std::string nome, std::string descricao);
    ~PacoteTuristico() = default;

    void adicionarProduto(std::shared_ptr<ProdutoTuristico> produto);
    void removerProduto(const std::string& idProduto);
    double calcularPrecoPacote(double descontoPercentual = 0.0) const; // Desconto opcional
    bool verificarDisponibilidadePacote(int quantidadePacotes = 1) const;
    std::string getDetalhesPacote() const;

    std::string getId() const;
    std::string getNome() const;

    // TODO: Adicionar métodos para serialização/desserialização.
};

#endif // PACOTETURISTICO_HPP
