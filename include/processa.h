#ifndef PROCESSA_H
#define PROCESSA_H

#include <iostream>
#include <string>
#include "fila.h"
#include "pilha.h"


class Processa{
private:

public:
	Processa();
	~Processa();

	int prioridade(char operador);
	Fila<string> conversaoPosFixa(Fila<string> entrada);
	double calculoPosFixa(Fila<string> entrada);
	void run();
	
};


#endif