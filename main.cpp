#include <iostream>
#include <string>  
#include "expressao.h"


using namespace std;

int main(){

	Expressao n("1 + 8.2 *  (15 - 5 / 2.5) ().");

	//##############################TESTES###########################
	//teste verifição 1
	
	if(n.validaCaracteres() == 0)
		cout << "expressão ok - verifição 1" << endl;
	else
		cout << "Erro 1 - Caractere inválido encontrado na posição " << n.validaCaracteres()  << "."<< endl;
	//##############################################################
	//teste verificacao 2 (em desenvolvimento)
	/*


	*/
	//##############################################################
	//teste verificacao 3
	if(n.validaParenteses())
		cout << "expressão ok - verifição 3" << endl;
	else
		cout << "Erro 3 - Os parênteses da expressão estão desbalanceados. " <<  endl;
	//##############################################################



return 0;

}


 