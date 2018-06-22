/**
 * @file	fila.h
 * @brief	Implementação da classe Fila em C++
 * @author	Bruno César L. Silva
 * @since	22/06/2018
 * @date	22/06/2018
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
// --

/**
* @brief Implementacao da classe Fila
* @detail Define um template de fila
* como classe derivada de Lista
*/
template <typename T>
class Fila{

    public:

        ListaLigada<T> fila; /**< Container para armazenar conteúdo da fila. */

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

        bool evazio();

        /**
        * @brief Sobrecarga do operador de inserção.
        * @detail imprime na saída padrão as informações da fila circular
        * @param ostream &o operador de inserção
        * @param Fila<T> l uma instância de Fila
        * @return retorna a instância do operador de inserção
        */
        friend std::ostream& operator<< <T>( std::ostream&, Fila<T> const &f);
        
};

template <typename T>
Fila<T>::Fila(): tamanho( 0 ){}

template <typename T>
Fila<T>::~Fila(){}

template <typename T>
bool Fila<T>::insereNoFinal( T conteudo ){
    this->fila.insereNoFinal( conteudo );
    //this->tamanho++;
    //fila.getTamanho();

    return true;
}

template <typename T>
bool Fila<T>::RemoveNoInicio(){
    this->fila.RemoveNoInicio();
    //this->tamanho--;

    return true;
}

template <typename T>
int Fila<T>::getTamanho(){
    return fila.getTamanho();
}

template <typename T>
bool Fila<T>::evazio(){
    return fila.vazio();
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, Fila<T> const &l) {
    o << l.lista;

	return o;
}

#endif