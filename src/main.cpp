#include <iostream>
#include <string>  
#include "processa.h"

using namespace std;

int main(int argc, char *argv[]){

	if (argc == 2) {
		Processa arquivo(argv[1]);
		arquivo.run();
	}else{
		cout << "Erro :( Para verificar um arquivo com varias expressões execute:  \n./prog /path/arquivo.txt" << endl;
	}
	

return 0;

}


 