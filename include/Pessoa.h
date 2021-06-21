
#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <cmath>
#include "Endereco.h"

class Pessoa
{
    public:
        Pessoa() {}
        Pessoa(int id, int idade, int x, int y) : id(id), idade(idade), endereco(Endereco(x,y)) {}
        std::string ToString() { return "P" + std::to_string(id) + " Idade:" + std::to_string(idade) + "Endereço: " + endereco.ToString(); };
        float CalculaDistancia(Endereco enderecoParaComparar) { return endereco.CalculaDistanciaPara(enderecoParaComparar); };

    private:
        Endereco endereco;
        int id;
        int idade;
};

#endif