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

#include <stack>
using std::stack;

#include <algorithm> 

class Expressao {

private:

	string expressao;
	//LinkedList numeros -> Fila numeros // quando a fila estiver pronta ?
	//LinkedList<float> numeros;
	Fila<string> filaEntrada;
	Fila<string> filaSaida;
	stack<string> operadores;


public:

	Expressao();
	Expressao(string expressao_);
	~Expressao();

	void setExpressao(string expressao_);
	string getExpressao();

	//valida a expressao <retorna posicao do caractere invalido ou 0=ok>
	int validaCaracteres();

	int validaNumeros();

	bool validaParenteses();

	bool expressaoMalformada();

	Fila<string> validaExpressao();


};
#endif