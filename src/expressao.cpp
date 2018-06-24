/**
 * @file	expressao.cpp
 * @brief	Implementação da classe expressao em C++
 * @author	David e Eliaquim
 * @since	21/06/2018
 * @date	24/06/2018
 */
#include "expressao.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using std::stringstream;

/**
* @brief Método construtor padrão de expressão
*/
Expressao::Expressao():expressao(""){}

/**
* @brief Método construtor parametizado de expressão
* @param string expressao_ - recebe uma string a ser processada
*/
Expressao::Expressao(string expressao_):expressao(expressao_){}

/**
* @brief Método destrutor de expressão
*/
Expressao::~Expressao(){}

/** 
 * @breaf atribui uma string ao atributo da classe espressão
 * @param string expressao_ - recebe uma string a ser atribuida
*/
void Expressao::setExpressao(string expressao_){
	expressao = expressao_;
}

/** 
 * @breaf retorna atributo da classe
 * @return o atributo da classe - string espressão
*/
string Expressao::getExpressao(){
	return expressao;
}
/** 
 * @breaf Método que verifica se há caracteres inválidos na expressão
 * @detail Após a validacao adiciona um espaco entre os caracteres para
 * poder o buffer separar em substrings, em seguida o buffer e adicionado 
 * em uma fila, dividido em substrings.
 * @return Retorna 0 para expressão válida ou a posicão do caractere inválido
 */
int Expressao::validaCaracteres(){
	stringstream ss;
	string aux= "";
	//varre a string caractere a caractere
	for(int i=0; expressao[i] !='\0'; i++){
			//verifica caracteres validos
			if(((expressao[i] == '+') || (expressao[i] == '-') || (expressao[i] == '*') || (expressao[i] == '^') || 
				(expressao[i] == ' ') || (expressao[i] == '(') || (expressao[i] == ')') || (expressao[i] >= 46)) && (expressao[i] <= 57)){
					
					//adiciona espaco entre os caractere para poder separar no buffer
					if((expressao[i] == '+') || (expressao[i] == '-') || (expressao[i] == '*') || (expressao[i] == '^') || 
					  (expressao[i] == ' ') || (expressao[i] == '(') || (expressao[i] == ')')){
						
					   ss << " "<< expressao[i] << " " ;
					}else
						ss << expressao[i];
			}else{ 
				//retorna a posicao (caso de erro)
				return i + 1;
			}
	}
	//adiciona conteudo do buffer na fila
	while(ss >> aux){
		filaEntrada.insereNoFinal(aux);
	}
	//expressao ok ok=0
	return 0;

}

/** 
 * @breaf Método que verifica se os numeros da expressão são validos inteiro e real
 * @return Retorna 0 para expressão válida ou a posicão do número inválido
 */
int Expressao::validaNumeros(){
	//recebe a posição na expressão que possui o primeiro caractere inválido de um número inválido
	int posicaoDoErro = 0;

	//string que recebe cada substring que representa um número da expressão
	string aux = "";
		
	//conta quantos pontos um número possui
	int contPontos = 0;
	
	//Obtem o indice de um número na string da expressão presente no arquivo
	int indiceNaExpressao = 0;

	//tamanho da string/variável 'aux'
	int auxTam = 0;
	
	//indica se um bloco da expressão possui algarismos ou não (se é um número)
	bool possuiNum = false;
	
	//percorre a fila de entrada
	for(int i = 0; i < (int) filaEntrada.getTamanho(); i++){
		//recebe o conteúdo da fila de Entrada no índice i;
		aux = filaEntrada+i;

		//a variável possuiNum é reinicializada para false
		possuiNum = false;				
		
		//o contador de pontos é zerado
		contPontos = 0;	
		
		//a variável recebe o tamanho atual da string aux
		auxTam = aux.size();

		//analisa se o bloco da expressão atual possui algarismos (0-9)
		for(int j = 0; j < auxTam; j++){
			if(aux[j] >= 48 && aux[j] <= 57){
				//algarismo encontrado
				possuiNum = true;
				break;
			}
		}
		//se o bloco da expressão possuir algum algarismo...
		if(possuiNum){
			//verifica se o primeiro caractere de um número é um ponto
			if(aux[0] == '.'){				
				//procura a posição do bloco aux na expressão inicial
				indiceNaExpressao = expressao.find(aux);				
				posicaoDoErro = indiceNaExpressao + 1;	
				//retorna a posição do primeiro caractere inválido do número						
				return posicaoDoErro;
			}
			//verifica se o último caractere de um número é um ponto
			if(aux[auxTam-1] == '.'){															
				//procura a posição do bloco aux na expressão inicial
				indiceNaExpressao = expressao.find(aux);					
				posicaoDoErro = auxTam + indiceNaExpressao;
				//retorna a posição do primeiro caractere inválido do número
				return posicaoDoErro;
			}
			//percorre o bloco da fila de entrada indicado pelo contador i;
			for(int j = 0; j < auxTam; j++){				
				//verifica se o caractere atual é um ponto
				if(aux[j] == '.'){
					contPontos++;
					if(contPontos > 1){					
						//procura a posição do bloco aux na expressão inicial
						indiceNaExpressao = expressao.find(aux);									
						posicaoDoErro = j + indiceNaExpressao + 1;
						//retorna a posição do primeiro caractere inválido do número
						return posicaoDoErro;
					} 
				//verifica se o caractere atual do bloco não é um número
				}else if(aux[j] < 48 || aux[j] > 57){		
					//procura a posição do bloco aux na expressão inicial
					indiceNaExpressao = expressao.find(aux);																																														
					posicaoDoErro = j + indiceNaExpressao + 1;				
					//retorna a posição do primeiro caractere inválido do número
					return posicaoDoErro;																																	
				}	
			}			
		}		
	}
	
	//retorna 0 caso não hajam erros
	return 0;
	
}

/** 
 * @breaf Método que verifica o balanceamento dos parênteses
 * @detail Primeiramente varre a string em busca de um parenteses de abertura
 * em seguida adiciona o mesmo em uma pilha, continua na varredura da string
 * em busca de um parenteses de fechamento, ao encontrar verifica se exite um
 * parenteses de abertura na pilha, caso nao exista, os mesmos nao estao balanceados.
 * @return Retorna true para correto balanceamento e false para inválido
 */
bool Expressao::validaParenteses(){

	Pilha<char> expTemp;

	 bool valid = false;

	 for(int i=0; i < (int)expressao.size(); i++) {
		//busca abertura `(`
		if(expressao[i] == '(')
		 	expTemp.insereNoTopo(expressao[i]);
		//caso encontre um fechamento `)` 	
		else if(expressao[i] == ')'){ 
				//verifica se tem um de abertura na pilha (pilha limpa nao tem expTemp.empty() ==true)
	  		 	if(expTemp.evazio())
			  		return false;
			  	else
	  				expTemp.removeDoTopo(); //se tiver retira... e prossegue a varredura
 		}
 	}
 	
 	//pilha tem q esta vazia no final (true)
 	valid = expTemp.evazio();

  if(valid)
  	return true;
  else
  	return false;
}


/** 
 * @breaf Método que verifica se todos os operadores aparecem entre os operandos
 * @return Retorna true para expressão infixa correta e false para inválida
 */
/** 
 * @breaf Método que verifica se todos os operadores aparecem entre os operandos
 * @return Retorna true para expressão infixa correta e false para inválida
 */
bool Expressao::expressaoMalformada(){
	int operando = 0;
	int outros = 0;
	int colchetes = 0;

	while(!filaEntrada.evazio()){
		//conta os operandos
		if((filaEntrada.getPrimeiroElemento() == "+") || (filaEntrada.getPrimeiroElemento() == "-") || (filaEntrada.getPrimeiroElemento() == "*") || (filaEntrada.getPrimeiroElemento() == "/")){
			operando++;
			filaSaida.insereNoFinal(filaEntrada.getPrimeiroElemento());
			filaEntrada.removeNoInicio();
		}else
			if((filaEntrada.getPrimeiroElemento() == "(") || (filaEntrada.getPrimeiroElemento() == ")")){ //conta os colchetes

				colchetes++;
				filaSaida.insereNoFinal(filaEntrada.getPrimeiroElemento());
				filaEntrada.removeNoInicio();
				
			}else{
				outros++;
				filaSaida.insereNoFinal(filaEntrada.getPrimeiroElemento());
				filaEntrada.removeNoInicio();
			}
	}
			

	//numeros uma unidade a menos q os operandos
	// colchetes par, abertura e fechamento
	
	if(operando == outros -1 && colchetes % 2 == 0)
		return true;
	else
		return false;
	
}

/** 
 * @breaf Método que chama as demais validação
 * @detail Ao chamar pelas validação se ocorrer erro imprimi a mensagem do erro
 * e encerra o programa, caso passe por todas retorna a filaSaida da classe
 * @return Retorna Fila<string> filaSaida
 */
bool Expressao::validaExpressao(){

	//variável auxiliar que recebe os valores retornados pelos métodos 
	//validaCaracteres e validaNumeros
	int retorno = 0; 

	retorno = validaCaracteres();
	if(retorno != 0){
		cout << "Erro 1 - Caractere inválido encontrado na posição " << retorno  << "."<< endl;
		cout << expressao << endl;
		//adiciona uma 'seta' (^) apontando para o caractere inválido
		cout << std::setfill (' ') << std::setw (retorno) << '^' << endl;	
		return false;
	}

	retorno = validaNumeros();
	if(retorno != 0){
		cout << "Erro 2: Número inválido encontrado a partir da posição " << retorno << "." << endl;
		cout << expressao << endl;
		//adiciona uma 'seta' (^) apontando para o caractere inválido de um número
		cout << std::setfill (' ') << std::setw (retorno) << '^' << endl;
		return false;
	}

	if(!validaParenteses()){
		cout << "Erro 3 - Os parênteses da expressão estão desbalanceados. " <<  endl;
		return false;
	}

	if(!expressaoMalformada()){
		cout << "Erro 4 - Expressão infixa malformada. " <<  endl;
		return false;
	}

	return true;
}

/** 
 * @breaf retorna atributo da classe
 * @return o atributo da classe - Fila<string>
*/
Fila<string> Expressao::getFilaSaida(){

	return filaSaida;
}