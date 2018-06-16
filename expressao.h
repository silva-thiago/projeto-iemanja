#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#include <string>
using std::string;

#include <list>
using std::list;

#include <stack>
using std::stack;

class Expressao {

private:

	string expressao;
	list<string> filaEntrada;
	list<string> filaSaida;
	stack<string> operadores;


public:

	Expressao();
	Expressao(string expressao_);
	~Expressao();

	void setExpressao(string expressao_);
	string getExpressao();

	//valida a expressao <retorna posicao do caractere invalido ou 0=ok>
	int validaCaracteres();

	void validaNumeros();

	void validaParenteses();

	void expressaoMalformada();


};
#endif