/**
 * @file	processa.h
 * @brief	Cabeçalho da classe Processa em C++
 * @author	William e David
 * @since	21/06/2018
 * @date	22/06/2018
 */

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
	/**
	* @brief Método construtor parametizado 
	* @param string path_ - endereço do arquivo que possui as expressões
	*/
	Processa(string path_);

	/**
	* @brief Método destrutor de Processa
	*/
	~Processa();

	/** 
	 * @brief Método que descreve a prioridades dos operadores matemáticos
	 * @param char - Recebe o caracter referente a operação
	 * @return Retorna inteiro de 2 a 5 de acordo com o operando
	 */
	int prioridade(char operador);

	/** 
	 * @brief Método que converte uma expressão algébrica infixa para posfixa
	 * @detail A conversão é realizada com o auxílio de 3 estruturas. Fila de entrada,
	 * uma Pilha para operadore e "()" e uma Fila para saída
	 * @param Fila<string> - Recebe uma fila que contém uma expressão algébrica infixa
	 * @return Retorna uma fila<string> contendo a expressão algébrica posfixa
	 */
	Fila<string> conversaoPosFixa(Fila<string> entrada);

	/** 
	 * @brief Método que calcula uma expressão algébrica posfixa
	 * @detail Utiliza uma fila que contem a expressão posfixa e uma pilha de operandos
	 * que será responsável por receber todos os operandos existentes na fila
	 * @param Fila<string> - Recebe uma fila que contém uma expressão algébrica posfixa
	 * @return Retorna o resultado do cálculo da expressão posfixa
	 */
	double calculoPosFixa(Fila<string> entrada);

	void run();
	
};


#endif