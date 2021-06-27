#include <algorithm>
#include <functional>
#include "Posto.h"
#include "Pessoa.h"

std::string Posto::toString() { return obterStringId() + " Capacidade: " + std::to_string(capacidade) + " Endereço: " + endereco.toString(); };

std::string Posto::obterStringId() { return "C" + std::to_string(id); };

float Posto::calculaDistancia(Endereco enderecoParaComparar) { return endereco.calculaDistanciaPara(enderecoParaComparar); };

Endereco Posto::obterEndereco() { return endereco; };

void Posto::adicionarPessoa(Pessoa *pessoa) {
    float distanciaAoPessoa = calculaDistancia(pessoa->obterEndereco());
    rankingPessoas.push_back(PreferenciaPessoa(pessoa, distanciaAoPessoa));
    std::sort(rankingPessoas.begin(), rankingPessoas.end(), std::greater<PreferenciaPessoa>()); // ordena de forma descendente
};

void Posto::printaPreferenciaPessoas() {
    std::cout << "Preferencias " << obterStringId() << ": " << std::endl;
    for(int i = 0; i < rankingPessoas.size(); i++)
        std::cout << rankingPessoas[i].obterPessoa()->obterStringId()  << std::endl;
};

void Posto::copiaPreferenciaPessoas(Posto *posto) {
    rankingPessoas = posto->rankingPessoas;
}


Pessoa* Posto::PreferenciaPessoa::obterPessoa() { return pessoa; };
bool Posto::PreferenciaPessoa::operator > (const PreferenciaPessoa& preferenciaPessoa) const
{
    return pessoa->obterIdade() > preferenciaPessoa.pessoa->obterIdade();
};