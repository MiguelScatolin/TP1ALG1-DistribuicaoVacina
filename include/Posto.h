
#ifndef POSTO_H
#define POSTO_H

#include <string>
#include <cmath>
#include "Endereco.h"

class Posto
{
    public:
        Posto() {}
        Posto(int id, int capacidade, int x, int y) : id(id), capacidade(capacidade), endereco(Endereco(x,y)) {}
        std::string ToString() { return "C" + std::to_string(id) + " Capacidade: " + std::to_string(capacidade) + " Endereço: " + endereco.ToString(); };
        float CalculaDistancia(Endereco enderecoParaComparar) { return endereco.CalculaDistanciaPara(enderecoParaComparar); };

    private:
        Endereco endereco;
        int id;
        int capacidade;
};

#endif