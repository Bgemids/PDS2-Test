// src/Reserva.cpp
#include "Reserva.hpp"
#include "Viajante.hpp"
#include "ProdutoTuristico.hpp"
#include "PacoteTuristico.hpp"
#include <iostream> // Para placeholders
#include <numeric>  // Para std::accumulate
#include <sstream>
#include <iomanip>

Reserva::Reserva(std::string id, Viajante* viajante, const std::string& dataReserva)
    : id(id), viajante(viajante), dataReserva(dataReserva), status(StatusReserva::PENDENTE), precoTotalCalculado(0.0) {
    if (!viajante) {
        // Lançar exceção ou tratar erro de viajante nulo
        throw std::invalid_argument("Viajante não pode ser nulo para criar uma reserva.");
    }
}

void Reserva::adicionarItem(std::shared_ptr<ProdutoTuristico> produto, int quantidade) {
    if (produto && quantidade > 0) {
        // TODO: Verificar disponibilidade antes de adicionar
        itensIndividuais[produto] += quantidade; // Adiciona ou incrementa
        calcularPrecoTotal(); 
    }
}

void Reserva::removerItem(const std::string& idProduto) {
    // TODO: Implementar remoção de item
    calcularPrecoTotal();
}

void Reserva::adicionarPacote(std::shared_ptr<PacoteTuristico> pacote) {
    if (pacote) {
        // TODO: Verificar disponibilidade do pacote
        pacotesReservados.push_back(pacote);
        calcularPrecoTotal();
    }
}

void Reserva::removerPacote(const std::string& idPacote) {
    // TODO: Implementar remoção de pacote
    calcularPrecoTotal();
}

double Reserva::calcularPrecoTotal() {
    precoTotalCalculado = 0.0;
    for (const auto& par : itensIndividuais) {
        precoTotalCalculado += par.first->getPreco() * par.second;
    }
    for (const auto& pacote : pacotesReservados) {
        precoTotalCalculado += pacote->calcularPrecoPacote(); // Usar preço com desconto se aplicável
    }
    return precoTotalCalculado;
}

bool Reserva::confirmarReserva() {
    // TODO: Verificar disponibilidade de todos os itens e pacotes novamente
    // TODO: Processar pagamento (simulado)
    // TODO: Atualizar disponibilidade dos produtos/pacotes
    if (status == StatusReserva::PENDENTE) {
        // Simulação:
        for (const auto& par : itensIndividuais) {
            if (!par.first->verificarDisponibilidade(par.second)) {
                std::cerr << "Erro: Item " << par.first->getNome() << " não disponível na quantidade desejada." << std::endl;
                return false; // Falha na confirmação
            }
        }
        for (const auto& pacote : pacotesReservados) {
            if (!pacote->verificarDisponibilidadePacote(1)) { // Assumindo 1 pacote
                 std::cerr << "Erro: Pacote " << pacote->getNome() << " não disponível." << std::endl;
                return false; // Falha na confirmação
            }
        }

        // Se tudo ok, atualiza disponibilidade
        for (const auto& par : itensIndividuais) {
            par.first->atualizarDisponibilidade(par.second);
        }
        for (const auto& pacote : pacotesReservados) {
            // Atualizar disponibilidade dos itens dentro do pacote
            // Esta lógica pode ser complexa e precisa ser bem definida
        }

        this->status = StatusReserva::CONFIRMADA;
        std::cout << "Reserva " << id << " confirmada." << std::endl;
        return true;
    }
    return false;
}

bool Reserva::cancelarReserva() {
    // TODO: Implementar lógica de cancelamento (regras, taxas, reestoque)
    if (status == StatusReserva::CONFIRMADA ||
        status == StatusReserva::PENDENTE) {
        this->status = StatusReserva::CANCELADA;
        // TODO: Reverter disponibilidade dos produtos/pacotes se aplicável
        std::cout << "Reserva " << id << " cancelada." << std::endl;
        return true;
    }
    return false;
}

std::string Reserva::getId() const { return id; }
StatusReserva Reserva::getStatus() const { return status; }
const Viajante* Reserva::getViajante() const { return viajante; }
double Reserva::getPrecoTotalCalculado() const { 
    // Recalcula se necessário, ou retorna o valor já calculado
    // Para este esqueleto, retorna o valor armazenado.
    return precoTotalCalculado;
}

void Reserva::setStatus(StatusReserva novoStatus) {
    this->status = novoStatus;
}

std::string Reserva::getDetalhesReserva() const {
    std::ostringstream oss;
    oss << "Detalhes da Reserva ID: " << id << "\n"
        << "Viajante: " << (viajante? viajante->getNome() : "N/A") << "\n"
        << "Data da Reserva: " << dataReserva << "\n"
        << "Status: "; // TODO: Converter enum StatusReserva para string
    switch(status) {
        case StatusReserva::PENDENTE: oss << "Pendente"; break;
        case StatusReserva::CONFIRMADA: oss << "Confirmada"; break;
        case StatusReserva::CANCELADA: oss << "Cancelada"; break;
        case StatusReserva::CONCLUIDA: oss << "Concluída"; break;
    }
    oss << "\nPreço Total: R$ " << std::fixed << std::setprecision(2) << precoTotalCalculado << "\n";
    oss << "Itens Individuais:\n";
    for(const auto& item : itensIndividuais) {
        oss << "- " << item.first->getNome() << " (Qtd: " << item.second << ")\n";
    }
    oss << "Pacotes:\n";
    for(const auto& pacote : pacotesReservados) {
        oss << "- " << pacote->getNome() << "\n";
    }
    return oss.str();
}

// TODO: Implementar serialização/desserialização.