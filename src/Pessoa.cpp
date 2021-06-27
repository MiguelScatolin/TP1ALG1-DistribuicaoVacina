#include "Pessoa.h"

std::string Pessoa::toString() { return obterStringId() + " " + obterStringIdade() + " " + obterStringEndereco(); }

std::string Pessoa::obterStringId() { return std::to_string(id); };

std::string Pessoa::obterIdentificador() { return "P" + obterStringId(); };

std::string Pessoa::obterStringIdade() { return "Idade: " + std::to_string(idade); };

std::string Pessoa::obterStringEndereco() { return "Endereço: " + endereco.toString(); };

float Pessoa::calculaDistancia(Endereco enderecoParaComparar) { return endereco.calculaDistanciaPara(enderecoParaComparar); };

Endereco Pessoa::obterEndereco() { return endereco; };

int Pessoa::obterIdade() { return idade; };

void Pessoa::adicionarPosto(Posto *posto) {
    float distanciaAoPosto = calculaDistancia(posto->obterEndereco());
    rankingPostos.push_back(PreferenciaPosto(posto, distanciaAoPosto));
    std::sort(rankingPostos.begin(), rankingPostos.end());
};

void Pessoa::printaPreferenciaPostos() {
    std::cout << "Preferencias " << obterStringId() << ": " << std::endl;
    for(int i = 0; i < rankingPostos.size(); i++)
        std::cout << rankingPostos[i].obterPosto()->obterStringId()  << std::endl;
}

void Pessoa::escolherPosto() {
    for(int i = 0; i < rankingPostos.size(); i++) {
        bool pedidoAceito = rankingPostos[i].obterPosto()->processarPedidoPessoa(this);
        if(pedidoAceito)
            break;
    }
}