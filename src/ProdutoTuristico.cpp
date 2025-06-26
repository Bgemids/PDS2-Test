// src/ProdutoTuristico.cpp
#include "ProdutoTuristico.hpp"

ProdutoTuristico::ProdutoTuristico(std::string id, std::string nome, std::string descricao, double precoBase, int disponibilidade)
    : id(id), nome(nome), descricao(descricao), precoBase(precoBase), disponibilidade(disponibilidade) {}

std::string ProdutoTuristico::getId() const { return id; }
std::string ProdutoTuristico::getNome() const { return nome; }
std::string ProdutoTuristico::getDescricao() const { return descricao; }
double ProdutoTuristico::getPrecoBase() const { return precoBase; }
int ProdutoTuristico::getDisponibilidade() const { return disponibilidade; }

void ProdutoTuristico::setPrecoBase(double preco) { this->precoBase = preco; }
void ProdutoTuristico::setDisponibilidade(int novaDisponibilidade) { this->disponibilidade = novaDisponibilidade; }

bool ProdutoTuristico::verificarDisponibilidade(int quantidade) const {
    return this->disponibilidade >= quantidade;
}

void ProdutoTuristico::atualizarDisponibilidade(int quantidadeVendida) {
    this->disponibilidade -= quantidadeVendida;
    if (this->disponibilidade < 0) {
        this->disponibilidade = 0; // Não permitir disponibilidade negativa
    }
}

// getPreco() e getDetalhes() são virtuais puros.