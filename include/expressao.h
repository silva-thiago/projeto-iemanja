/**
 * @file	expressao.h
 * @brief	Cabeçalho da classe Expressao em C++
 * @author	David e Eliaquim
 * @since	21/06/2018
 * @date	24/06/2018
 */

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

	/**
	* @brief Método construtor padrão de expressão
	*/
	Expressao();

	/**
	* @brief Método construtor parametizado de expressão
	* @param string expressao_ - recebe uma string a ser processada
	*/
	Expressao(string expressao_);

	/**
	* @brief Método destrutor de expressão
	*/
	~Expressao();

	/** 
	 * @brief atribui uma string ao atributo da classe espressão
	 * @param string expressao_ - recebe uma string a ser atribuida
	*/
	void setExpressao(string expressao_);

	/** 
	 * @brief retorna atributo da classe
	 * @return o atributo da classe - string espressão
	*/
	string getExpressao();

	/** 
	 * @brief Método que verifica se há caracteres inválidos na expressão
	 * @detail Após a validacao adiciona um espaco entre os caracteres para
	 * poder o buffer separar em substrings, em seguida o buffer e adicionado 
	 * em uma fila, dividido em substrings.
	 * @return Retorna 0 para expressão válida ou a posicão do caractere inválido
	 */
	int validaCaracteres();

	/** 
	 * @brief Método que verifica se os numeros da expressão são validos inteiro e real
	 * @return Retorna 0 para expressão válida ou a posicão do número inválido
	 */
	int validaNumeros();

	/** 
	 * @brief Método que verifica o balanceamento dos parênteses
	 * @detail Primeiramente varre a string em busca de um parenteses de abertura
	 * em seguida adiciona o mesmo em uma pilha, continua na varredura da string
	 * em busca de um parenteses de fechamento, ao encontrar verifica se exite um
	 * parenteses de abertura na pilha, caso nao exista, os mesmos nao estao balanceados.
	 * @return Retorna true para correto balanceamento e false para inválido
	 */
	bool validaParenteses();

	/** 
	 * @brief Método que verifica se todos os operadores aparecem entre os operandos
	 * @return Retorna true para expressão infixa correta e false para inválida
	 */
	bool expressaoMalformada();

	/** 
	 * @brief Método que chama as demais validação
	 * @detail Ao chamar pelas validação se ocorrer erro imprimi a mensagem do erro
	 * e encerra o programa, caso passe por todas retorna a filaSaida da classe
	 * @return Retorna Fila<string> filaSaida
	 */
	bool validaExpressao();

	/** 
	 * @brief retorna atributo da classe
	 * @return o atributo da classe - Fila<string>
	*/
	Fila<string> getFilaSaida();


};
#endif