#include "SistemaAgencia.hpp"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        SistemaAgencia sistema;
        sistema.run();
    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro inesperado e o sistema sera encerrado: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
