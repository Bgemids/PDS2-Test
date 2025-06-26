// include/ProdutoTuristico.hpp
#ifndef PRODUTOTURISTICO_HPP
#define PRODUTOTURISTICO_HPP

#include <string>

class ProdutoTuristico {
protected:
    std::string id;
    std::string nome;
    std::string descricao;
    double precoBase;
    int disponibilidade; // Quantidade disponível

public:
    ProdutoTuristico(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade);
    virtual ~ProdutoTuristico() = default;

    // Getters
    std::string getId() const;
    std::string getNome() const;
    std::string getDescricao() const;
    double getPrecoBase() const;
    int getDisponibilidade() const;

    // Setters / Modificadores
    void setPrecoBase(double preco);
    void setDisponibilidade(int novaDisponibilidade);

    /**
     * @brief Calcula o preço final do produto (pode incluir taxas, etc.).
     * @return O preço final.
     */
    virtual double getPreco() const = 0; 

    /**
     * @brief Verifica se há disponibilidade do produto para a quantidade desejada.
     * @param quantidade Quantidade desejada.
     * @return True se disponível, false caso contrário.
     */
    virtual bool verificarDisponibilidade(int quantidade) const;

    /**
     * @brief Atualiza a disponibilidade do produto.
     * @param quantidadeVendida Quantidade que foi vendida (negativo para adicionar de volta).
     */
    virtual void atualizarDisponibilidade(int quantidadeVendida);

    /**
     * @brief Retorna uma string com os detalhes específicos do produto.
     * @return String formatada com os detalhes.
     */
    virtual std::string getDetalhes() const = 0;

    // TODO: Adicionar métodos para serialização/desserialização.
};

#endif // PRODUTOTURISTICO_HPP
