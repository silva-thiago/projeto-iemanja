/**
 * @file	filacircular.h
 * @brief	Implementação da classe FilaCircular em C++
 * @author	Bruno César L. Silva
 * @since	18/05/2018
 * @date	20/05/2018
 */

#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include "listacircular.h"

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend é preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class FilaCircular; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, FilaCircular<T> const & );
// --

/**
* @brief Implementacao da classe FilaCircular
* @detail Define um template de fila circular
* como classe derivada de ListaCircular
*/
template <typename T>
class FilaCircular{
    
    int tamanho;

    public:

        ListaCircular<T> lista; /**< Container para armazenar conteúdo da fila. */

        /**
        * @brief Método construtor padrão de FilaCircular
        */
        FilaCircular();

        /**
        * @brief Método destrutor de FilaCircular
        */
        ~FilaCircular();

        /**
        * @brief Método para inserir valores.
        * @detail Insere valores no final da fila.
        */
        bool InsereNoFinal( T valor );

        /**
        * @brief Método para remover valores.
        * @detail Remove valores no início da fila.
        */
        bool RemoveNoInicio();

        /**
        * @brief Método que retorna o tamanho da fila
        */
        int getTamanho();

        /**
        * @brief Sobrecarga do operador de inserção.
        * @detail imprime na saída padrão as informações da fila circular
        * @param ostream &o operador de inserção
        * @param FilaCircular<T> l uma instância de FilaCircular
        * @return retorna a instância do operador de inserção
        */
        friend std::ostream& operator<< <T>( std::ostream&, FilaCircular<T> const &l);
        
};

template <typename T>
FilaCircular<T>::FilaCircular(): tamanho( 0 ){}

template <typename T>
FilaCircular<T>::~FilaCircular(){}

template <typename T>
bool FilaCircular<T>::InsereNoFinal( T valor ){
    this->lista.InsereNoFinal( valor );
    this->tamanho++;

    return true;
}

template <typename T>
bool FilaCircular<T>::RemoveNoInicio(){
    this->lista.RemoveNoInicio();
    this->tamanho--;

    return true;
}

template <typename T>
int FilaCircular<T>::getTamanho(){
    return tamanho;
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, FilaCircular<T> const &l) {
    o << l.lista;

	return o;
}

#endif