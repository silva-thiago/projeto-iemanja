#include <iostream>
#include <string>  
#include "expressao.h"


using namespace std;

int main(){

	Expressao n("1 + 8.2 * (15 - 5 / 2.5)");
	if(n.validaExpressao())
		cout << "expressao ok" << endl;

	

return 0;

}


 