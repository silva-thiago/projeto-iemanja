/**
 * @file	conversao.cpp
 * @brief	Implementação da classe ListaLigada em C++
 * @author	Bruno César Lopes Silva
 * @since	21/06/2018
 * @date	22/06/2018
 */

#include <iostream>
#include <string>
#include "fila.h"
#include "pilha.h"
using namespace std;

/** 
 * @breaf Método que descreve a prioridades dos operadores matemáticos
 * @param char - Recebe o caracter referente a operação
 * @return Retorna inteiro de 2 a 5 de acordo com o operando
 */
int prioridade(char operador){
    if(operador == '+' || operador == '-' ) return 4;
    if(operador == '*' || operador == '/' ) return 3;
    if(operador == '^') return 2;
    if(operador == '(') return 5;
    return 0;
}

/** 
 * @breaf Método que converte uma expressão algébrica infixa para posfixa
 * @detail A conversão é realizada com o auxílio de 3 estruturas. Fila de entrada,
 * uma Pilha para operadore e "()" e uma Fila para saída
 * @param Fila<string> - Recebe uma fila que contém uma expressão algébrica infixa
 * @return Retorna uma fila<string> contendo a expressão algébrica posfixa
 */
Fila<string> conversaoPosFixa(Fila<string> entrada){
    Fila<string> saida;
    Pilha<string> operadores;

    int tamanho = entrada.getTamanho();

    // Percorre toda fila com a expressão infixa
    for(int i = 0; i < tamanho ; i++){
        string expressao = entrada.getPrimeiroElemento();
        /* Obtém um componente da fila de entrada. Se for operando, insere na fila de saída;
         se for "(", insere automaticamente na pilha de operadores; se for componente de ")",
         desempilha todo os operadores até encontrar o "(", inserindo-os na fila de saída; se for
         operador, desempilha todos os operadores cuja precedência sejam maiores ou igual que a sua
         e os coloca na fila de saída. Em seguida, empilha o operador em questão. Após ter processado
         todos os componentes da fila de entrada. Caso hajam operadores na pilha, estes são colocados
         na fila de saída */
        switch (expressao.at(0)){
            case '+': 
                if(operadores.evazio()){
                    operadores.insereNoTopo(expressao);
                }else if(prioridade(expressao.at(0)) >= prioridade(operadores.topo().at(0))) {
                    saida.insereNoFinal(operadores.topo());
                    operadores.removeDoTopo();
                    operadores.insereNoTopo(expressao);
                }else{
                    operadores.insereNoTopo(expressao);
                }
                break;
            case '-':
                if(operadores.evazio()){
                    operadores.insereNoTopo(expressao);
                }else if(prioridade(expressao.at(0)) >= prioridade(operadores.topo().at(0))) {
                    saida.insereNoFinal(operadores.topo());
                    operadores.removeDoTopo();
                    operadores.insereNoTopo(expressao);
                }else{
                    operadores.insereNoTopo(expressao);
                }
                break;
            case '*':
                if(operadores.evazio()){
                    operadores.insereNoTopo(expressao);
                }else if(prioridade(expressao.at(0)) >= prioridade(operadores.topo().at(0))) {
                    saida.insereNoFinal(operadores.topo());
                    operadores.removeDoTopo();
                    operadores.insereNoTopo(expressao);
                }else{
                    operadores.insereNoTopo(expressao);
                }
                break;
            case '/':
                if(operadores.evazio()){
                    operadores.insereNoTopo(expressao);
                }else if(prioridade(expressao.at(0)) >= prioridade(operadores.topo().at(0))) {
                    saida.insereNoFinal(operadores.topo());
                    operadores.removeDoTopo();
                    operadores.insereNoTopo(expressao);
                }else{
                    operadores.insereNoTopo(expressao);
                }
                break;
            case '(':
                operadores.insereNoTopo(expressao);
                break;
            case ')':
                while(operadores.topo() != "("){
                    saida.insereNoFinal(operadores.topo());
                    operadores.removeDoTopo();
                }
                operadores.removeDoTopo();
                break;
            default:
                saida.insereNoFinal(expressao);
                break;
        }      
        entrada.removeNoInicio();
    }
    
    while(!operadores.evazio()){
        saida.insereNoFinal(operadores.topo());
        operadores.removeDoTopo();
    }
    
    return saida;
}

/** 
 * @breaf Método que calcula uma expressão algébrica posfixa
 * @detail Utiliza uma fila que contem a expressão posfixa e uma pilha de operandos
 * que será responsável por receber todos os operandos existentes na fila
 * @param Fila<string> - Recebe uma fila que contém uma expressão algébrica posfixa
 * @return Retorna o resultado do cálculo da expressão posfixa
 */
double calculoPosFixa(Fila<string> entrada){
    Pilha<string> operandos;
    /* variáveis das operações binárias
        h -> variável responsável para receber o operando 1
        h'-> variável responsável para receber o operando 2 */
    double haga = 0, hagalinha = 0;

    int tamanho = entrada.getTamanho();
    // Percorre toda fila com a expressão posfixa
    for(int i = 0; i < tamanho ; i++){
        string expressao = entrada.getPrimeiroElemento();
        /* Obtem um componente da fila com a expressão posfixa. Se o componente for um
        operando, insere-o na pilha de operandos; se o componente for um operador, desempilha
        dois operandos presentes na pilha e realiza a operação associada. Em seguida, empilha
        o resultado na pilha. Ao terminar de ler a expressão posfixa, o resultado é retornado */
        switch (expressao.at(0)){
            case '+': 
                hagalinha = stod(operandos.topo());
                operandos.removeDoTopo();
                haga = stod(operandos.topo());
                operandos.removeDoTopo();
                operandos.insereNoTopo(to_string(haga + hagalinha));
                break;
            case '-':
                hagalinha = stod(operandos.topo());
                operandos.removeDoTopo();
                haga = stod(operandos.topo());
                operandos.removeDoTopo();
                operandos.insereNoTopo(to_string(haga - hagalinha));
                break;
            case '*':
                hagalinha = stod(operandos.topo());
                operandos.removeDoTopo();
                haga = stod(operandos.topo());
                operandos.removeDoTopo();
                operandos.insereNoTopo(to_string(haga * hagalinha));
                break;
            case '/':
                hagalinha = stod(operandos.topo());
                operandos.removeDoTopo();
                haga = stod(operandos.topo());
                operandos.removeDoTopo();
                operandos.insereNoTopo(to_string(haga / hagalinha));
                break;
            default:
                operandos.insereNoTopo(expressao);
                break;
        }      
        entrada.removeNoInicio();
    }

    return stod(operandos.topo());
}

int main(){

    Fila<string> entrada;
    Fila<string> saida;

    entrada.insereNoFinal("1");
    entrada.insereNoFinal("+");
    entrada.insereNoFinal("8.2");
    entrada.insereNoFinal("*");
    entrada.insereNoFinal("(");
    entrada.insereNoFinal("15");
    entrada.insereNoFinal("-");
    entrada.insereNoFinal("5");
    entrada.insereNoFinal("/");
    entrada.insereNoFinal("2.5");
    entrada.insereNoFinal(")");

    saida = conversaoPosFixa(entrada);
    double resultado = calculoPosFixa(saida);
    saida.imprimir();
    cout << " = " << resultado << endl;
    return 0;

}


 