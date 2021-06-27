
#ifndef IO_H
#define IO_H

#include <iostream>
#include <vector>
#include "Pessoa.h"
#include "Posto.h"

std::vector<Posto*> obterPostos();
std::vector<Pessoa*> obterPessoas();

#endif