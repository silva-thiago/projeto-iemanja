#include <iostream>
#include <string>  
#include "expressao.h"


using namespace std;

int main(){

	//testes verifição 1
	Expressao n("1 + 8.2 * (15 - 5 / 2.5) .");

	if(n.validaCaracteres() == 0)
		cout << "expressão ok - verifição 1" << endl;
	else
		cout << "Erro 1 - Caractere inválido encontrado na posição " << n.validaCaracteres()  << "."<< endl;

return 0;

}


 