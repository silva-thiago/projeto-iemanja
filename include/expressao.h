#ifndef EXPRESSAO_H
#define EXPRESSAO_H
#include <iostream>
using std::cout;
using std::endl;

#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <queue>
using std::queue;

#include <stack>
using std::stack;

class Expressao {

private:

	string expressao;
	//LinkedList numeros -> Fila numeros // quando a fila estiver pronta ?
	//LinkedList<float> numeros;
	queue<string> filaEntrada;
	queue<string> filaSaida;
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

	bool validaExpressao();


};
#endif