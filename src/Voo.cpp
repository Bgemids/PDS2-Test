// src/Voo.cpp
#include "Voo.hpp"
#include <sstream> // Para formatar strings
#include <iomanip> // Para std::fixed e std::setprecision

Voo::Voo(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade,
         std::string origem, std::string destino, std::string dataPartida, std::string dataChegada, std::string companhiaAerea)
    : ProdutoTuristico(id, nome, descricao, precoBase, disponibilidade),
      origem(origem), destino(destino), dataPartida(dataPartida), dataChegada(dataChegada), companhiaAerea(companhiaAerea) {}

double Voo::getPreco() const {
    // Exemplo: Preço base + uma taxa de embarque fixa.
    return precoBase + 50.0; // TODO: Implementar lógica de preço real.
}

std::string Voo::getDetalhes() const {
    std::ostringstream oss;
    oss << "Voo: " << nome << " (" << companhiaAerea << ")\n"
        << "De: " << origem << " Para: " << destino << "\n"
        << "Partida: " << dataPartida << " Chegada: " << dataChegada << "\n"
        << "Preço: R$ " << std::fixed << std::setprecision(2) << getPreco() << "\n"
        << "Disponíveis: " << disponibilidade << " assentos.";
    return oss.str();
}

std::string Voo::getOrigem() const { return origem; }
std::string Voo::getDestino() const { return destino; }
std::string Voo::getDataPartida() const { return dataPartida; }

// TODO: Implementar outros getters e setters.