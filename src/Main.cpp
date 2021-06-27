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

        for(int postoIndex = 0; postoIndex < postos.size(); postoIndex++) {
            for(int pessoaIndex = 0; pessoaIndex < pessoas.size(); pessoaIndex++) {
                pessoas[pessoaIndex]->adicionarPosto(postos[postoIndex]);
                postos[postoIndex]->adicionarPessoa(pessoas[pessoaIndex]);
            }
        }

        for(int i = 0; i < pessoas.size(); i++) {
            pessoas[i]->printaPreferenciaPostos();
            std::cout << std::endl;
        }

        return 0;
    }
    catch (char exception[]) {
    }
}

