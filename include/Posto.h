
#ifndef POSTO_H
#define POSTO_H
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Endereco.h"

class Pessoa;

class Posto
{
    public:
        Posto() {}
        Posto(int id, int capacidade, int x, int y) : id(id), capacidade(capacidade), endereco(Endereco(x,y)) {}
        std::string toString();
        std::string obterStringId();
        std::string obterIdentificador();
        float calculaDistancia(Endereco enderecoParaComparar);
        Endereco obterEndereco();
        void adicionarPessoa(Pessoa *pessoa);
        void printaPreferenciaPessoas();
        void printaPessoasParaVacinar();
        void copiaPreferenciaPessoas(Posto *posto);
        bool processarPedidoPessoa(Pessoa *pessoa);

    private:
        class PreferenciaPessoa
        {
            public:
                PreferenciaPessoa(Pessoa* pessoa, float distancia) : pessoa(pessoa), distancia(distancia) {}
                Pessoa* obterPessoa();
                bool operator > (const PreferenciaPessoa& preferenciaPessoa) const;

            private:
                Pessoa* pessoa;
                float distancia;
        };
        
        Endereco endereco;
        int id;
        int capacidade;
        std::vector<PreferenciaPessoa> rankingPessoas;
        std::vector<Pessoa*> pessoasParaVacinar;

};

#endif