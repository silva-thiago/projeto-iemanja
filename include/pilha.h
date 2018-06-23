/**
 * @file	pilha.h
 * @brief	Implementação da classe Pilha em C++
 * @author	Bruno César Lopes Silva
 * @since	22/06/2018
 * @date	22/06/2018
 */

#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend é preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class Pilha; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, Pilha<T> const & );
// --

/**
* @brief Implementacao da classe Pilha
* @detail Define um template de pilha
* usando como container padrão uma lista
*/
template <typename T>
class Pilha{
    ListaLigada<T> pilha; /**< Container para armazenar conteúdo da pilha. */

    public:      

        /**
        * @brief Método construtor padrão de Pilha
        */
        Pilha();

        /**
        * @brief Método destrutor de Pilha
        */
        ~Pilha();

        /**
        * @brief Método para inserir valores.
        * @detail Insere valores no topo da pilha.
        * @return Retorna valor boleano.
        */
        bool insereNoTopo( T conteudo );

        /**
        * @brief Método para remover valores.
        * @detail Remove o valor no topo da fila.
        * @return Retorna valor boleano.
        */
        bool removeDoTopo();

        /**
        * @brief Método que retorna o tamanho da pilha
        */
        int getTamanho();

        /**
        * @brief Método que retorna o elemento do topo da pilha
        * @return Retorna o conteúdo do topo da pilha
        */
        T topo();

        /**
        * @brief Método para verificar se a pilha está vazia
        * @return Retorna verdadeiro ou falso em relação a pilha vazia
        */
        bool evazio();

        /**
        * @brief Método para imprimir o conteúdo da pilha
        */
        void imprimir();

        /**
        * @brief Sobrecarga do operador de inserção.
        * @detail imprime na saída padrão as informações da pilha
        * @param ostream &o operador de inserção
        * @param Pilha<T> f uma instância de Pilha
        * @return retorna a instância do operador de inserção
        */
        friend std::ostream& operator<< <T>( std::ostream&, Pilha<T> const &p);
        
};

template <typename T>
Pilha<T>::Pilha(){}

template <typename T>
Pilha<T>::~Pilha(){}

template <typename T>
bool Pilha<T>::insereNoTopo( T conteudo ){
    this->pilha.insereNoInicio( conteudo );

    return true;
}

template <typename T>
bool Pilha<T>::removeDoTopo(){
    this->pilha.remove(0);

    return true;
}

template <typename T>
int Pilha<T>::getTamanho(){
    return pilha.getTamanho();
}

template <typename T>
T Pilha<T>::topo(){
    return pilha.getPrimeiroElemento();
}

template <typename T>
bool Pilha<T>::evazio(){
    return pilha.vazio();
}

template <typename T>
void Pilha<T>::imprimir(){
    pilha.imprimir();
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, Pilha<T> const &p) {
    //auto atual = f.cabeca;
    //o << f.imprimir();
/* 
    for(int i = 0; i < (int)f.getTamanho(); i++)
        o << f.getElemento(i);
 */    return o;
}

#endif
