#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "lista2.h"

int main(){
    ListaLigada<string> lista;
    lista.insereNoFinal("Bruno");
    lista.insereNoFinal("Willian");
    lista.insereNoInicio("Thiago");
    lista.insereNoInicio("Mika");
    lista.insereNoInicio("Agatha");
    lista.imprimir();
    string nome = "Agatha";
    cout << lista.busca(nome) << endl;
    cout << lista.getElemento(2) << endl;
    cout << lista.getTamanho() << endl;
    lista.remove(2);
    lista.imprimir();
    lista.limpar();
    lista.imprimir();






    return 0;
}