#include <iostream>
#include <fstream>
#include <sstream>
#include "Pessoa.h"
#include "Posto.h"
#include "IO.h"

int main(int argc, char* argv[]) {
    try {
        std::vector<Posto> postos = obterPostos();
        std::vector<Pessoa> pessoas = obterPessoas();

        return 0;
    }
    catch (char exception[]) {
    }
}

