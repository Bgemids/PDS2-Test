// src/main.cpp
#include <iostream>
#include <vector>
#include <memory> // Para std::shared_ptr

// Inclua os cabeçalhos das classes que você quer usar
#include "EnumTypes.hpp"
#include "Viajante.hpp"
#include "AgenteDeViagem.hpp"
#include "Administrador.hpp"
#include "Voo.hpp"
//#include "Hotel.hpp" // Supondo que Hotel.hpp exista
//#include "Passeio.hpp" // Supondo que Passeio.hpp exista
#include "PacoteTuristico.hpp"
#include "Reserva.hpp"
// #include "Pagamento.hpp"
// #include "Itinerario.hpp"
// #include "Notificacao.hpp"
// #include "FiltroBusca.hpp"

// Função auxiliar para exibir menu e obter escolha (exemplo)
int exibirMenuPrincipal() {
    int escolha;
    std::cout << "\n===== Sistema de Agência de Viagem =====" << std::endl;
    std::cout << "1. Login como Viajante" << std::endl;
    std::cout << "2. Login como Agente de Viagem" << std::endl;
    std::cout << "3. Login como Administrador" << std::endl;
    std::cout << "4. Criar nova conta de Viajante" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opção: ";
    std::cin >> escolha;
    // TODO: Adicionar validação de entrada
    return escolha;
}


int main() {
    std::cout << "Sistema de Agência de Viagem - Inicializando..." << std::endl;

    // TODO: Carregar dados persistidos (usuários, produtos, etc.) aqui.
    // Exemplo de criação de alguns objetos (para teste, idealmente viriam da persistência ou cadastro)
    std::vector<std::shared_ptr<Usuario>> usuarios;
    usuarios.push_back(std::make_shared<Viajante>("v001", "Alice Silva", "alice@email.com", "senha123"));
    usuarios.push_back(std::make_shared<AgenteDeViagem>("a001", "Bob Costa", "bob@agencia.com", "agente789"));
    usuarios.push_back(std::make_shared<Administrador>("adm001", "Carlos Ad M.", "admin@sistema.com", "adminpass"));

    std::vector<std::shared_ptr<ProdutoTuristico>> produtos;
    produtos.push_back(std::make_shared<Voo>("voo001", "Voo SP-RJ", "Voo de São Paulo para Rio de Janeiro", 350.00, 50, "GRU", "SDU", "2025-07-10 10:00", "2025-07-10 11:00", "Azul"));
    // produtos.push_back(std::make_shared<Hotel>(/.../)); // Adicionar hotéis
    // produtos.push_back(std::make_shared<Passeio>(/.../)); // Adicionar passeios

    // Loop principal da aplicação (exemplo muito simplificado)
    // int escolhaMenu;
    // Usuario* usuarioLogado = nullptr; // Ou std::shared_ptr<Usuario>

    // do {
    //     escolhaMenu = exibirMenuPrincipal();
    //     switch (escolhaMenu) {
    //         case 1: // Login Viajante
    //             // TODO: Implementar lógica de login
    //             // Se login bem-sucedido:
    //             // usuarioLogado = encontrarUsuarioPorEmailEsenha(TipoRole::VIAJANTE);
    //             // if (usuarioLogado) usuarioLogado->exibirPainel(); else std::cout << "Login falhou.\n";
    //             std::cout << "Funcionalidade de login do Viajante a ser implementada.\n";
    //             break;
    //         // TODO: Implementar outros casos do menu (Agente, Admin, Criar Conta)
    //         case 0:
    //             std::cout << "Saindo do sistema..." << std::endl;
    //             break;
    //         default:
    //             std::cout << "Opção inválida. Tente novamente." << std::endl;
    //     }
    // } while (escolhaMenu!= 0);

    // TODO: Salvar dados persistidos antes de sair.

    // Exemplo de uso (descomente e adapte conforme implementa as classes):
    /*
    if (!usuarios.empty() && usuarios->getRole() == TipoRole::VIAJANTE) {
        Viajante* alice = static_cast<Viajante*>(usuarios.get());
        alice->exibirPainel();
        
        if(!produtos.empty()){
            Reserva reserva1("r001", alice, "2025-05-24");
            if (auto voo = std::dynamic_pointer_cast<Voo>(produtos)) {
                 reserva1.adicionarItem(voo, 2); // Reserva 2 passagens
            }
            std::cout << reserva1.getDetalhesReserva() << std::endl;
            reserva1.confirmarReserva(); // Tenta confirmar
            std::cout << "Disponibilidade do voo apos reserva: " << produtos->getDisponibilidade() << std::endl;
        }
    }
    */

    std::cout << "Sistema finalizado." << std::endl;
    return 0;
}