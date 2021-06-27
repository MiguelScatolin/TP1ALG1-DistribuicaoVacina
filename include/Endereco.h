
#ifndef ENDERECO_H
#define ENDERECO_H

#include <string>
#include <cmath>

class Endereco
{
    public:
        Endereco() {}
        Endereco(int x, int y) : x(x), y(y) {}
        float calculaDistanciaPara(Endereco enderecoParaComparar) { return sqrt(pow(x - enderecoParaComparar.x, 2) + pow(y - enderecoParaComparar.y, 2)); };
        std::string toString() { return "(" + std::to_string(x) + "," + std::to_string(y) + ")"; };

    private:
        int x;
        int y;
};

#endif