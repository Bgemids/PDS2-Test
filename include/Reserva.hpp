// include/Reserva.hpp
#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>
#include <vector>
#include <map>
#include <memory> // Para std::shared_ptr
#include "EnumTypes.hpp"

// Forward declarations
class Viajante;
class ProdutoTuristico;
class PacoteTuristico;

class Reserva {
private:
    std::string id;
    Viajante* viajante; // Ponteiro não proprietário para o viajante
    std::map<std::shared_ptr<ProdutoTuristico>, int> itensIndividuais; // Produto e quantidade
    std::vector<std::shared_ptr<PacoteTuristico>> pacotesReservados; // Pacotes e quantidade (assumindo 1 por entrada)
    std::string dataReserva;
    StatusReserva status;
    double precoTotalCalculado;

public:
    Reserva(std::string id, Viajante* viajante, const std::string& dataReserva);
    ~Reserva() = default;

    void adicionarItem(std::shared_ptr<ProdutoTuristico> produto, int quantidade);
    void removerItem(const std::string& idProduto);
    void adicionarPacote(std::shared_ptr<PacoteTuristico> pacote);
    void removerPacote(const std::string& idPacote);
    
    double calcularPrecoTotal();
    bool confirmarReserva(); // Muda status, atualiza disponibilidade dos produtos
    bool cancelarReserva();  // Muda status, pode reverter disponibilidade

    // Getters
    std::string getId() const;
    StatusReserva getStatus() const;
    const Viajante* getViajante() const;
    double getPrecoTotalCalculado() const;

    // Setters
    void setStatus(StatusReserva novoStatus);

    std::string getDetalhesReserva() const;

    // TODO: Adicionar métodos para serialização/desserialização.
};

#endif // RESERVA_HPP
