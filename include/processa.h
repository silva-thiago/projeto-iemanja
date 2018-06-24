#ifndef PROCESSA_H
#define PROCESSA_H

#include <fstream>
#include <iostream>
#include <string>
#include "fila.h"
#include "pilha.h"
#include "expressao.h"

using namespace std;

class Processa{
private:
		string path;

public:
	Processa(string path_);
	~Processa();

	int prioridade(char operador);
	Fila<string> conversaoPosFixa(Fila<string> entrada);
	double calculoPosFixa(Fila<string> entrada);
	void run();
	
};


#endif