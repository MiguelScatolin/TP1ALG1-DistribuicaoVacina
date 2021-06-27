#include <iostream>
#include <fstream>
#include <sstream>
#include "Pessoa.h"
#include "Posto.h"
#include "IO.h"

int main(int argc, char* argv[]) {
    try {
        std::vector<Posto*> postos = obterPostos();
        std::vector<Pessoa*> pessoas = obterPessoas();

        definirPreferenciaDePostosEPessoas(postos, pessoas);

        gerarCasamento(pessoas);
        
        printarCasamento(postos);

        return 0;
    }
    catch (char exception[]) {
    }
}

void definirPreferenciaDePostosEPessoas(std::vector<Posto*>  &postos, std::vector<Pessoa*> &pessoas) {
    for(int postoIndex = 0; postoIndex < postos.size(); postoIndex++) {
        for(int pessoaIndex = 0; pessoaIndex < pessoas.size(); pessoaIndex++) {
            pessoas[pessoaIndex]->adicionarPosto(postos[postoIndex]);

            if(postoIndex == 0)
                postos[postoIndex]->adicionarPessoa(pessoas[pessoaIndex]);
            else
                postos[postoIndex]->copiaPreferenciaPessoas(postos[0]); // a lista de preferencias de todos os postos será igual

        }
    }
}

void gerarCasamento(std::vector<Pessoa*> &pessoas) {
    for(int pessoaIndex = 0; pessoaIndex < pessoas.size(); pessoaIndex++) {
        pessoas[pessoaIndex]->escolherPosto();
    }
}

void printarCasamento(std::vector<Posto*>  &postos) {
    for(int postoIndex = 0; postoIndex < postos.size(); postoIndex++) {
        postos[postoIndex]->printaPessoasParaVacinar();
    }
}