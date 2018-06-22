#include "expressao.h"
#include <iostream>

Expressao::Expressao():expressao(""){}
Expressao::Expressao(string expressao_):expressao(expressao_){}
Expressao::~Expressao(){

}

int Expressao::validaCaracteres(){
	
	//varre a string caractere a caractere
	for(int i=0; expressao[i] !='\0'; i++){
			//verifica caracteres validos
			if(((expressao[i] == '+') || (expressao[i] == '-') || (expressao[i] == '*') || (expressao[i] == '/') || (expressao[i] == '^') ||
			   (expressao[i] == ' ') || (expressao[i] == '(') || (expressao[i] == ')') || (expressao[i] >= 46)) && (expressao[i] <= 57)){
			}
			else{ 
				//retorna a posicao
				return i + 1;
			}
	}

	//expressao ok ok=0
	return 0;

}

int Expressao::validaNumeros(){
	//auxiliar para manipular variavél no código como 'aux' ao invés de 'filaEntradaTemp.GetElement(i)'
	auto aux = filaEntradaTemp.GetElement(0);	
	
	//conta quantos pontos um número possui
	int cont_pontos = 0;
	
	//indica o sinal para adicionar ou não um número para a fila de números
	int indice_na_expressao = 0;

	//tamanho da variável auxiliar
	int aux_tam = 0;
	
	//indica se um bloco da expressão possui algarismos ou não (se é um número)
	bool possui_num = false;
	
	//Mensagem de erro para número inválido;
	string msg = "Erro 2: Número inválido encontrado a partir da posição ";

	
	//percorre a fila de entrada
	for(int i = 0; i < filaEntradaTemp.Length(); i++){
		
		//a variável possui_num é reinicializada para false
		possui_num = false;				
		
		//o contador de pontos recebe o valor 0
		cont_pontos = 0;	

		//aux recebe o conteúdo de um bloco da fila de entrada na posição indicada pelo contador i
		aux = filaEntradaTemp.GetElement(i);

		//a variável recebe o tamanho atual da string aux
		aux_tam = aux.size();
		
		
		//analisa se o bloco da expressão atual possui numeros
		for(int j = 0; j < aux_tam; j++){
			if(aux[j] >= 48 && aux[j] <= 57){
				//algarismo encontrado
				possui_num = true;
				break;
			}
		}


		//se o bloco da expressão possuir algum algarismo...
		if(possui_num){

			//procura a posição do bloco aux na expressão inicial
			indice_na_expressao = expressao.find(aux);	

			//verifica se o primeiro caractere de um número é um ponto
			if(aux[0] == '.'){				
				std::cout << msg << indice_na_expressao+1 << "." << std::endl;			

				//retorna a posição do primeiro caractere inválido do número
				return indice_na_expressao+1;
			}

			//verifica se o último caractere de um número é um ponto
			if(aux[aux_tam-1] == '.'){						
				std::cout << msg << aux_tam+indice_na_expressao << "." << std::endl;	

				//retorna a posição do primeiro caractere inválido do número
				return aux_tam+indice_na_expressao;
			}

			//percorre o bloco da fila de entrada indicado pelo contador i
			for(int j = 0; j < aux_tam; j++){				
				//verifica se o caractere atual é um ponto
				if(aux[j] == '.'){
					cont_pontos++;
					if(cont_pontos > 1){							
						std::cout << msg << j+indice_na_expressao+1 << "." << std::endl;

						//retorna a posição do primeiro caractere inválido do número
						return j+indice_na_expressao+1;
					} 

				//verifica se o caractere atual do bloco não é um número
				}else if(aux[j] < 48 || aux[j] > 57){																																										
					std::cout << msg << j+indice_na_expressao+1 << "." << std::endl;

					//retorna a posição do primeiro caractere inválido do número					
					return j+indice_na_expressao+1;																																	
				}	
			}		

			//adiciona à fila de números, o numero validado pelos "for"s acima;
			//stof converte a string aux em um número 
			numeros.PushBack(std::stof(aux));		
		}			
	}
	//retorna 0 caso não hajam erros
	return 0;
}

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



