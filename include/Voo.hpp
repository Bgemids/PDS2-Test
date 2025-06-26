// include/Voo.hpp
#ifndef VOO_HPP
#define VOO_HPP

#include "ProdutoTuristico.hpp"
#include <string>

class Voo : public ProdutoTuristico {
private:
    std::string origem;
    std::string destino;
    std::string dataPartida; // Formato "AAAA-MM-DD HH:MM"
    std::string dataChegada; // Formato "AAAA-MM-DD HH:MM"
    std::string companhiaAerea;

public:
    Voo(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade,
        std::string origem, std::string destino, std::string dataPartida, std::string dataChegada, std::string companhiaAerea);
    
    ~Voo() override = default;

    double getPreco() const override;
    std::string getDetalhes() const override;

    // Getters específicos de Voo
    std::string getOrigem() const;
    std::string getDestino() const;
    std::string getDataPartida() const;
    // TODO: Adicionar outros getters e setters se necessário.
};

#endif // VOO_HPP
