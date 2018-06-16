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
			if(expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == '^' ||
			   expressao[i] == ' ' || expressao[i] == '(' || expressao[i] == ')' || expressao[i] >= 46 && expressao[i] <= 57){
			}
			else{ 
				//retorna a posicao
				return i + 1;
			}
	}

	//expressao ok ok=0
	return 0;

}