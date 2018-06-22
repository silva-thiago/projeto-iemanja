#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "lista.h"
#include "fila.h"

int main(){
    Fila<string> fila;
    ListaLigada<string> lista;
    
    

    fila.insereNoFinal("Bruno");
    fila.insereNoFinal("Willian");
    fila.insereNoFinal("Thiago");
    fila.insereNoFinal("Mika");
    fila.insereNoFinal("Agatha");
    fila.imprimir();
    cout << fila;
    cout << fila.evazio() << endl;
    cout << fila.getPrimeiroElemento() << endl;

    cout << fila;
    //cout << lista.getUltimoElemento() << endl;
    /*
    string nome = "Agatha";
    cout << lista.busca(nome) << endl;
    cout << lista.getElemento(2) << endl;
    cout << lista.getTamanho() << endl;
    lista.remove(2);
    lista.imprimir();
    lista.limpar();
    lista.imprimir();

 */




    return 0;
}