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



