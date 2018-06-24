#include "expressao.h"
#include <iostream>
#include <sstream>

using std::queue;
using std::stringstream;

Expressao::Expressao():expressao(""){}
Expressao::Expressao(string expressao_):expressao(expressao_){}
Expressao::~Expressao(){

}
//funcao que verifica se exite algum caractere invalido na expressao
//em seguinda adiciona em uma fila de entrada
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
		filaEntrada.push(aux);
	}
	//expressao ok ok=0
	return 0;

}
//funcao que verifica se os numeros da expressao sao validos
int Expressao::validaNumeros(){
	//iterador que percorre a fila de entrada
	auto iterador = &filaEntrada.front();
	//auxiliar para manipular variavél no código como 'aux' ao invés de '*iterador'
	string aux = *iterador;	
	
	//conta quantos pontos um número possui
	int contPontos = 0;
	
	//Obtem o indice de um número na string da expressão presente no arquivo
	int indiceNaExpressao = 0;

	//tamanho da string presente na variável 'aux'
	int auxTam = 0;
	
	//indica se um bloco da expressão possui algarismos ou não (se é um número)
	bool possuiNum = false;
	
	//percorre a fila de entrada
	for(int i = 0; i < (int) filaEntrada.size(); i++){

		//a variável possuiNum é reinicializada para false
		possuiNum = false;				
		
		//o contador de pontos é zerado
		contPontos = 0;	

		//aux recebe o conteúdo de um bloco da fila de entrada na posição indicada pelo contador i
		aux = *iterador;

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

			//procura a posição do bloco aux na expressão inicial
			indiceNaExpressao = expressao.find(aux);	

			//verifica se o primeiro caractere de um número é um ponto
			if(aux[0] == '.'){				

				//retorna a posição do primeiro caractere inválido do número
				return indiceNaExpressao+1;
			}

			//verifica se o último caractere de um número é um ponto
			if(aux[auxTam-1] == '.'){						

				//retorna a posição do primeiro caractere inválido do número
				return auxTam+indiceNaExpressao;
			}

			//percorre o bloco da fila de entrada indicado pelo contador i;
			//começa no j = 1 e vai até auxTam-1 porque os verificações no inicio e
			//fim já foram realizadas acima
			for(int j = 1; j < auxTam-1; j++){				
				//verifica se o caractere atual é um ponto
				if(aux[j] == '.'){
					contPontos++;
					if(contPontos > 1){							

						//retorna a posição do primeiro caractere inválido do número
						return j+indiceNaExpressao+1;
					} 

				//verifica se o caractere atual do bloco não é um número
				}else if(aux[j] < 48 || aux[j] > 57){																																										

					//retorna a posição do primeiro caractere inválido do número					
					return j+indiceNaExpressao+1;																																	
				}	
			}			
		}		
		//incrementa o iterador para acessar o próximo bloco da fila de entrada
		iterador++;	
	}
	//retorna 0 caso não hajam erros
	return 0;
}

//funcao que verifica se exite um parenteses de fechamento para cada um de abertura
bool Expressao::validaParenteses(){

	stack<char> expTemp;

	 bool valid = false;

	 for(int i=0; i < (int)expressao.size(); i++) {
		//busca abertura `(`
		if(expressao[i] == '(')
		 	expTemp.push(expressao[i]);
		//caso entro um fechamento `)` 	
		else if(expressao[i] == ')'){ 
				//verifica se tem um de abertura na pilha (pilha limpa nao tem expTemp.empty() ==true)
	  		 	if(expTemp.empty())
			  		return false;
			  	else
	  				expTemp.pop(); //se tiver retira... e prossegue a varredura
 		}
 	}
 	
 	//pilha tem q esta vazia no final (true)
 	valid = expTemp.empty();

  if(valid)
  	return true;
  else
  	return false;
}


//funcao para verificar se exite algum operando sem ultilizar 

bool Expressao::expressaoMalformada(){
	int operando = 0;
	int outros = 0;
	int colchetes = 0;

	while(!filaEntrada.empty()){
		//conta os operandos
		if((filaEntrada.front() == "+") || (filaEntrada.front() == "-") || (filaEntrada.front() == "*") || (filaEntrada.front() == "/")){
			operando++;
			filaEntrada.pop();
		}else
			if((filaEntrada.front() == "(") || (filaEntrada.front() == ")")){ //conta os colchetes

				colchetes++;
				filaEntrada.pop();
				
			}else{
				outros++;
				filaEntrada.pop();
			}
	}
			

	//numeros uma unidade a menos q os operandos
	// colchetes par, abertura e fechamento
	if(operando == outros -1 && colchetes % 2 == 0)
		return true;
	else
		return false;

}

//funcao encarregada de fazer todas as outras verificacoes juntas
bool Expressao::validaExpressao(){

	if(validaCaracteres() != 0){
		cout << "Erro 1 - Caractere inválido encontrado na posição " << validaCaracteres()  << "."<< endl;
		return false;
	}
	if(validaNumeros()!=0){
		cout << "Erro 2: Número inválido encontrado a partir da posição " << validaNumeros() << "." << endl;
		return false;
	}
	if(!validaParenteses()){
		cout << "Erro 3 - Os parênteses da expressão estão desbalanceados. " <<  endl;
	}

	if(!expressaoMalformada()){
		cout << "Erro 4 - Expressão infixa malformada. " <<  endl;
	}

	//se passar por todas validacao retorna true=ok
	return true;
}