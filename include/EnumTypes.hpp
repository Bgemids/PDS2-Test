// include/EnumTypes.hpp
#ifndef ENUMTYPES_HPP
#define ENUMTYPES_HPP

enum class TipoRole {
    VIAJANTE,
    AGENTE_VIAGEM,
    ADMINISTRADOR
};

enum class StatusReserva {
    PENDENTE,
    CONFIRMADA,
    CANCELADA,
    CONCLUIDA
};

enum class MetodoPagamento {
    CARTAO_CREDITO,
    PIX,
    PAYPAL,
    BOLETO
};

enum class StatusPagamento {
    PENDENTE,
    APROVADO,
    REJEITADO,
    REEMBOLSADO
};

enum class TipoNotificacao {
    CONFIRMACAO_RESERVA,
    ALTERACAO_RESERVA,
    LEMBRETE_VIAGEM,
    PROMOCAO
};

#endif // ENUMTYPES_HPP
