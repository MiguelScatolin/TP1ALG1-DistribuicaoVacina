#include "IO.h"

std::vector<Posto*> obterPostos() {
    int numeroDePostos;

    std::cin >> numeroDePostos;

    std::vector<Posto*> postos(numeroDePostos);

    for (int i = 0; i < numeroDePostos; i++) {
        int capacidade,
            x,
            y;
        std::cin >> capacidade >> x >> y;
        postos.insert(postos.begin() + i, new Posto(i, capacidade, x, y));
        std::cout << postos[i]->toString() << std::endl;
    }

    return postos;
}

std::vector<Pessoa*> obterPessoas() {
    int numeroDePessoas;

    std::cin >> numeroDePessoas;

    std::vector<Pessoa*> pessoas(numeroDePessoas);

    for (int i = 0; i < numeroDePessoas; i++) {
        int cidade,
            x,
            y;
        std::cin >> cidade >> x >> y;
        pessoas.insert(pessoas.begin() + i, new Pessoa(i, cidade, x, y));
        std::cout << pessoas[i]->toString() << std::endl;
    }

    return pessoas;
}