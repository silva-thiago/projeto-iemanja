/**
 * @file    fila.h
 * @brief   Implementação da classe Fila em C++
 * @author  Bruno e Eliaquim
 * @since   21/06/2018
 * @date    24/06/2018
 */

#ifndef FILA_H
#define FILA_H

#include "lista.h"

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend é preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class Fila; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, Fila<T> const & );

template <typename T>// Definicao antecipada do template para o operador de adição
T operator+(Fila<T> const &, int);
// --

/**
* @brief Implementacao da classe Fila
* @detail Define um template de fila
* usando como container padrão uma lista
*/
template <typename T>
class Fila{
    ListaLigada<T> fila; /**< Container para armazenar conteúdo da fila. */

    public:      

        /**
        * @brief Método construtor padrão de Fila
        */
        Fila();

        /**
        * @brief Método destrutor de Fila
        */
        ~Fila();

        /**
        * @brief Método para inserir valores.
        * @detail Insere valores no final da fila.
        * @return Retorna valor boleano.
        */
        bool insereNoFinal( T conteudo );

        /**
        * @brief Método para remover valores.
        * @detail Remove valores no início da fila.
        * @return Retorna valor boleano.
        */
        bool removeNoInicio();

        /**
        * @brief Método que retorna o tamanho da fila
        */
        int getTamanho();

        /**
        * @brief Método que retorna o primeiro elemento da fila
        * @return Retorna o conteúdo da primeira posição da fila
        */
        T getPrimeiroElemento();

        /**
        * @brief Método para verificar se a fila está vazia
        * @return Retorna verdadeiro ou falso em relação a fila vazia
        */
        bool evazio();

        /**
        * @brief Método para imprimir o conteúdo da fila
        */
        void imprimir();

        /**
        * @brief Sobrecarga do operador de inserção.
        * @detail imprime na saída padrão as informações da fila
        * @param ostream &o operador de inserção
        * @param Fila<T> f uma instância de Fila
        * @return retorna a instância do operador de inserção
        */
        friend std::ostream& operator<< <T>( std::ostream&, Fila<T> const &f);  
        /**
        * @brief Sobrecarga do operador de adição
        * @param f - Fila a ser manipulada
        * @param incremento - Indice do elemento a ser retornado
        * @return o conteúdo nó da fila no índice 'incremento'
        */      
        friend T operator+ <T>(Fila<T> const &f, int incremento);     
        
};

template <typename T>
Fila<T>::Fila(){}

template <typename T>
Fila<T>::~Fila(){}

template <typename T>
bool Fila<T>::insereNoFinal( T conteudo ){
    this->fila.insereNoFinal( conteudo );
    
    return true;
}

template <typename T>
bool Fila<T>::removeNoInicio(){
    this->fila.remove(0);
    
    return true;
}

template <typename T>
int Fila<T>::getTamanho(){
    return fila.getTamanho();
}

template <typename T>
T Fila<T>::getPrimeiroElemento(){
    return fila.getPrimeiroElemento();
}

template <typename T>
bool Fila<T>::evazio(){
    return fila.vazio();
}

template <typename T>
void Fila<T>::imprimir(){
    fila.imprimir();
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, Fila<T> const &f) {
    //auto atual = f.cabeca;
    //o << f.imprimir();
/* 
    for(int i = 0; i < (int)f.getTamanho(); i++)
        o << f.getElemento(i);
 */    return o;
}

template <typename T>
T operator+(Fila<T> const &f, int incremento){    
    return f.fila + incremento;
}

#endif