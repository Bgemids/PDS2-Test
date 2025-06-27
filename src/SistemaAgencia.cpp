// src/SistemaAgencia.cpp

void SistemaAgencia::_menuViajante() {
    int escolha;
    do {
        std::cout << "\n--- Menu do Viajante ---\n";
        std::cout << "Escolha uma opção:\n"; // <== CORREÇÃO 2
        std::cout << "1. Ver pacotes de viagem nacional\n";
        std::cout << "2. Ver pacotes de viagem internacional\n";
        std::cout << "3. Minhas viagens\n";
        std::cout << "4. Voltar para o menu principal\n";
        
        std::cin >> escolha;
        _limparBufferEntrada();

        switch (escolha) {
            case 1:
                std::cout << "\n--- Pacotes Nacionais Disponíveis ---\n";
                for (const std::shared_ptr<PacoteTuristico>& pacote : _pacotesNacionais) {
                    std::cout << pacote->getDetalhesPacote() << std::endl;
                }
                std::cout << "\nPressione Enter para voltar ao menu..."; // <== CORREÇÃO 1
                _limparBufferEntrada();
                break;
            case 2:
                std::cout << "\n--- Pacotes Internacionais Disponíveis ---\n";
                for (const std::shared_ptr<PacoteTuristico>& pacote : _pacotesInternacionais) {
                    std::cout << pacote->getDetalhesPacote() << std::endl;
                }
                std::cout << "\nPressione Enter para voltar ao menu..."; // <== CORREÇÃO 1
                _limparBufferEntrada();
                break;
            case 3:
                std::cout << "\n--- Minhas Viagens ---\n";
                std::cout << "Não há nenhuma viagem reservada.\n";
                std::cout << "\nPressione Enter para voltar ao menu...";
                _limparBufferEntrada();
                break;
            case 4: break;
            default: std::cout << "Opção inválida. Tente novamente.\n"; break;
        }
    } while (escolha != 4);
}
