/**
 * @file	listacircular.h
 * @brief	Implementação da classe ListaCircular em C++
 * @author	Bruno César L. Silva
 * @since	18/05/2018
 * @date	20/05/2018
 */

#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <memory>

#include "lista.h"

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend é preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class ListaCircular; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, ListaCircular<T> const & );

/**
* @brief Implementacao da classe ListaCircular
* @detail Define um template de lista circular
* como classe derivada de ListaLigada
*/
template <typename T>
class ListaCircular : public ListaLigada<T>{
    protected:
        /**
        * @brief Método que insere valor no inicio da lista sobrecarregado
        * para ListaCircular
        * @param T - recebe o valor para o novo nó
        * @return Retorna um valor boleano
        */
        bool InsereNoInicio(T _valor);
    
    public:
        /**
        * @brief Método construtor padrão de ListaCircular
        */
        ListaCircular();

        /**
        * @brief Método destrutor de ListaCircular
        */
        ~ListaCircular();
        
        /**
        * @brief Método que insere valor no final da lista
        * sobrecarregado para ListaCircular
        * @param T - recebe o valor para o novo nó
        * @return Retorna um valor boleano
        */
        bool InsereNoFinal(T _valor);
        
        /**
        * @brief Sobrecarga do operador de inserção.
        * @detail imprime na saída padrão as informações da lista circular
        * sobrecarregando a definição de ListaLigada (classe base)
        * @param ostream &o operador de inserção
        * @param ListaCircular<T> l uma instância de ListaCircular
        * @return retorna a instância do operador de inserção
        */
        friend std::ostream& operator<< <T>( std::ostream&, ListaCircular<T> const &l);
};


template <typename T>
ListaCircular<T>::ListaCircular(){}

template <typename T>
ListaCircular<T>::~ListaCircular(){}

template <typename T>
bool ListaCircular<T>::InsereNoInicio( T valor ){
    auto novo = make_shared<Node<T>>( valor );
    // Verifica se o ponteiro alocado em memória
    if( !novo ) return false;

    // Verica se a lista está vazia
    if( this->tamanho == 0){
        // novo aponta pela ela mesmo
        novo->setNext( novo );
        // cauda aponta para novo
        this->cauda = novo;
    }else{
        // novo aponta para para o nó inicial apontado por cabeca
        novo->setNext( this->cabeca );
        // a última posição, definida por cauda, aponta para o inicial a fim de definir a lista circular
        this->cauda->setNext( novo );
    }
    // cabeca aponta para o novo nó
    this->cabeca = novo;
    // o tamanho da lista é incrementado em 1
    this->tamanho++;

    return true;
}

template <typename T>
bool ListaCircular<T>::InsereNoFinal(T valor){
    /* se a lista estiver vazia chama a função InsereNoInicio
    passando valor como parâmetro */
    if( this->tamanho == 0 ){
        InsereNoInicio( valor );
        return true;
    }

    // Define um novo nó
    auto novo = make_shared<Node<T>>( valor );
    // a última posição da lista definida pela cauda recebe a posição de memória do novo nó
    this->cauda->setNext( novo );
    // a cauda recebe recebe a posição de memória do novo nó
    this->cauda = novo;
    // o novo nó aponta para a posição de memória da primeira posição, definida pela cabeca
    novo->setNext( this->cabeca );
    // o tamanho da lista é incrementado em 1
    this->tamanho++;

    return true;
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, ListaCircular<T> const &l ) {
	auto atual = l.cabeca;

    for( int i = 0; i < l.tamanho; i++ ){
        o << atual->getValor() << " ";
		atual = atual->getNext();
    }
    
    return o;
}


#endif