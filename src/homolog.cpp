#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "lista.h"
#include "fila.h"
#include "pilha.h"

int main(){
    Pilha<string> pilha;
    ListaLigada<string> lista;
    /* 
    lista.insereNoInicio("Bruno");
    lista.insereNoInicio("Willian");
    lista.insereNoInicio("Thiago");
    lista.insereNoInicio("Mika");
    lista.insereNoInicio("Agatha");
    lista.imprimir();
    cout << lista.getTamanho() << endl;
    lista.remove(5);
    lista.imprimir();
 */
 
    pilha.insereNoTopo("Bruno");
    pilha.insereNoTopo("Willian");
    pilha.insereNoTopo("Thiago");
    pilha.insereNoTopo("Mika");
    pilha.insereNoTopo("Agatha");
    pilha.imprimir();
    
    cout << pilha.evazio() << endl;
    cout << pilha.topo() << endl;

    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    pilha.removeDoTopo();
    pilha.imprimir();
    
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