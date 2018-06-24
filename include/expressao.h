#ifndef EXPRESSAO_H
#define EXPRESSAO_H
#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include "fila.h"
#include "pilha.h"

#include <algorithm> 

class Expressao {

private:

	string expressao;
	Fila<string> filaEntrada;
	Fila<string> filaSaida;
	Pilha<string> operadores;


public:

	Expressao();
	Expressao(string expressao_);
	~Expressao();

	void setExpressao(string expressao_);
	string getExpressao();

	int validaCaracteres();

	int validaNumeros();

	bool validaParenteses();

	bool expressaoMalformada();

	bool validaExpressao();

	Fila<string> getFilaSaida();


};
#endif