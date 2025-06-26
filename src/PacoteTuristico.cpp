// src/PacoteTuristico.cpp
#include "PacoteTuristico.hpp"
#include "ProdutoTuristico.hpp" // Precisa da definição completa aqui
#include <numeric> // Para std::accumulate
#include <algorithm> // Para std::remove_if
#include <sstream>
#include <iomanip>

PacoteTuristico::PacoteTuristico(std::string id, std::string nome, std::string descricao)
    : id(id), nome(nome), descricao(descricao) {}

void PacoteTuristico::adicionarProduto(std::shared_ptr<ProdutoTuristico> produto) {
    if (produto) {
        produtosInclusos.push_back(produto);
    }
}

void PacoteTuristico::removerProduto(const std::string& idProduto) {
    produtosInclusos.erase(
        std::remove_if(produtosInclusos.begin(), produtosInclusos.end(),
                       [&idProduto](const std::shared_ptr<ProdutoTuristico>& p) {
                           return p->getId() == idProduto;
                       }),
        produtosInclusos.end());
}

double PacoteTuristico::calcularPrecoPacote(double descontoPercentual) const {
    double precoTotalItens = 0.0;
    for (const auto& produto : produtosInclusos) {
        precoTotalItens += produto->getPreco();
    }
    if (descontoPercentual > 0.0 && descontoPercentual <= 100.0) {
        return precoTotalItens * (1.0 - (descontoPercentual / 100.0));
    }
    return precoTotalItens; // TODO: Implementar lógica de preço mais sofisticada.
}

bool PacoteTuristico::verificarDisponibilidadePacote(int quantidadePacotes) const {
    if (produtosInclusos.empty()) return false;
    for (const auto& produto : produtosInclusos) {
        if (!produto->verificarDisponibilidade(quantidadePacotes)) { // Assume 1 unidade de cada produto por pacote
            return false;
        }
    }
    return true;
}

std::string PacoteTuristico::getDetalhesPacote() const {
    std::ostringstream oss;
    oss << "Pacote Turístico: " << nome << "\n"
        << "Descrição: " << descricao << "\n"
        << "Preço Total (sem desconto): R$ " << std::fixed << std::setprecision(2) << calcularPrecoPacote(0.0) << "\n"
        << "Itens Inclusos:\n";
    for (const auto& produto : produtosInclusos) {
        oss << "- " << produto->getNome() << " (Tipo: " << typeid(*produto).name() << ")\n"; // Mostra o tipo real
    }
    return oss.str();
}

std::string PacoteTuristico::getId() const { return id; }
std::string PacoteTuristico::getNome() const { return nome; }

// TODO: Implementar serialização/desserialização.