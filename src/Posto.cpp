#include <algorithm>
#include <functional>
#include "Posto.h"
#include "Pessoa.h"

std::string Posto::toString() { return obterStringId() + " Capacidade: " + std::to_string(capacidade) + " Endereço: " + endereco.toString(); };

std::string Posto::obterStringId() { return std::to_string(id); };

std::string Posto::obterIdentificador() { return "C" + obterStringId(); };

float Posto::calculaDistancia(Endereco enderecoParaComparar) { return endereco.calculaDistanciaPara(enderecoParaComparar); };

Endereco Posto::obterEndereco() { return endereco; };

void Posto::adicionarPessoa(Pessoa *pessoa) {
    float distanciaAoPessoa = calculaDistancia(pessoa->obterEndereco());
    rankingPessoas.push_back(PreferenciaPessoa(pessoa, distanciaAoPessoa));
    std::sort(rankingPessoas.begin(), rankingPessoas.end(), std::greater<PreferenciaPessoa>()); // ordena de forma descendente
};

void Posto::printaPreferenciaPessoas() {
    std::cout << std::to_string(id) << std::endl;
    for(int i = 0; i < rankingPessoas.size(); i++)
        std::cout << rankingPessoas[i].obterPessoa()->obterStringId()  << std::endl;
};

void Posto::printaPessoasParaVacinar() {
    if(pessoasParaVacinar.size() == 0)
        return;
    
    std::cout << obterStringId() << std::endl;

    for(int i = 0; i < pessoasParaVacinar.size(); i++)
        std::cout << pessoasParaVacinar[i]->obterStringId() << " ";
    std::cout << std::endl;
};

void Posto::copiaPreferenciaPessoas(Posto *posto) {
    rankingPessoas = posto->rankingPessoas;
}

struct mais_prioritario
{
    inline bool operator() (Pessoa* pessoa1, Pessoa* pessoa2)
    {
        return (pessoa1->obterIdade() > pessoa2->obterIdade());
    }
};

bool Posto::processarPedidoPessoa(Pessoa *pessoa) {
    if(pessoasParaVacinar.size() < capacidade) {
        pessoasParaVacinar.push_back(pessoa);
        sort(pessoasParaVacinar.begin(), pessoasParaVacinar.end(), mais_prioritario());
        return true;
    } else {
        Pessoa* pessoaMaisNovaNaListaDeVacinacao = pessoasParaVacinar[pessoasParaVacinar.size() - 1];
        if(pessoa->obterIdade() > pessoaMaisNovaNaListaDeVacinacao->obterIdade()) {
            pessoasParaVacinar[pessoasParaVacinar.size() - 1] = pessoa;
            sort(pessoasParaVacinar.begin(), pessoasParaVacinar.end(), mais_prioritario());
            pessoaMaisNovaNaListaDeVacinacao->escolherPosto();
            return true;
        }
        else
            return false;

    }
}

Pessoa* Posto::PreferenciaPessoa::obterPessoa() { return pessoa; };
bool Posto::PreferenciaPessoa::operator > (const PreferenciaPessoa& preferenciaPessoa) const
{
    return pessoa->obterIdade() > preferenciaPessoa.pessoa->obterIdade();
};