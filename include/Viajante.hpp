// include/Viajante.hpp
#ifndef VIAJANTE_HPP
#define VIAJANTE_HPP

#include "EnumTypes.hpp"
#include "Usuario.hpp"
#include <vector>
// #include "Reserva.hpp" // Incluir se Reserva for usado diretamente
// #include "Itinerario.hpp" // Incluir se Itinerario for usado diretamente
// #include "FiltroBusca.hpp" // Incluir se FiltroBusca for usado
// #include "ProdutoTuristico.hpp" // Incluir se ProdutoTuristico for usado

// Declarações antecipadas para ponteiros/referências se inclusões completas causarem ciclos
class Reserva;
class Itinerario;
class FiltroBusca;
class ProdutoTuristico;
//class MetodoPagamento; // Supondo que MetodoPagamento seja uma classe/enum mais complexa

class Viajante : public Usuario {
private:
    // std::vector<Reserva*> historicoViagens; // Exemplo de atributo específico
    // PreferenciasNotificacao preferencias; // Exemplo

public:
    Viajante(std::string id, std::string nome, std::string email, std::string senha);
    ~Viajante() override;

    void exibirPainel() const override;

    // Funcionalidades do Viajante (baseadas nas User Stories)
    // void buscarProdutos(const FiltroBusca& filtro);
    // Reserva* iniciarReserva();
    // bool confirmarReserva(Reserva* reserva /, MetodoPagamento metodo/); // MetodoPagamento pode ser enum
    // void cancelarReserva(Reserva* reserva);
    // Itinerario* visualizarItinerario(const Reserva* reserva) const;
    // void gerenciarNotificacoes(/.../);

    // TODO: Implementar métodos específicos do Viajante.
};

#endif // VIAJANTE_HPP
