
#ifndef PESSOA_H
#define PESSOA_H
#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Endereco.h"
#include "Posto.h"

class Pessoa
{
    public:
        Pessoa() {}
        Pessoa(int id, int idade, int x, int y) : id(id), idade(idade), endereco(Endereco(x,y)) {}
        std::string toString();
        std::string obterStringId();
        std::string obterStringIdade();
        std::string obterIdentificador();
        std::string obterStringEndereco();
        float calculaDistancia(Endereco enderecoParaComparar);
        Endereco obterEndereco();
        int obterIdade();
        void adicionarPosto(Posto *posto);
        void printaPreferenciaPostos();
        void escolherPosto();

    private:

        class PreferenciaPosto
        {
            public:
                PreferenciaPosto(Posto* posto, float distancia) : posto(posto), distancia(distancia) {}
                Posto* obterPosto() { return posto; }
                bool operator < (const PreferenciaPosto& preferenciaPosto) const
                {
                    return (distancia < preferenciaPosto.distancia);
                }

            private:
                Posto* posto;
                float distancia;
        };
        
        Endereco endereco;
        int id;
        int idade;
        std::vector<PreferenciaPosto> rankingPostos;
        Posto* postoEscolhido;
        
};

#endif