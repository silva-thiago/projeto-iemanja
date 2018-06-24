/**
 * @file	pilha.h
 * @brief	Implementação da classe Pilha em C++
 * @author	Bruno César Lopes Silva e Thiago Silva
 * @since	22/06/2018
 * @date	24/06/2018
 */

#ifndef PILHA_H
#define PILHA_H

#include "lista.h"

/**
 * Para permitir sobrecarregar o operador de insercao
 * numa classe template como friend é preciso adicionar
 * o trecho de codigo a seguir
 */
template <typename T>
class Pilha; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream &operator<<(std::ostream &, Pilha<T> const &);

/**
 * @brief Implementacao da classe Pilha
 * @detail Define um template de pilha
 * usando como container padrão uma lista
 */
template <typename T>
class Pilha {
    ListaLigada<T> pilha; /**< Container para armazenar conteúdo da pilha. */
    T *conteudo;
    int tamanho;
    int topo;

  public:
    /**
     * @brief Método construtor padrão de Pilha
     */
    Pilha(int tamanho);
    
    /**
     * @brief Método destrutor de Pilha
     */
    ~Pilha();
    
    /**
     * @brief Método para inserir valores.
     * @detail Insere valores no topo da pilha.
     * @return Retorna valor boleano.
     */
    bool insereNoTopo(T conteudo);

    /**
     * @brief Método para remover valores.
     * @detail Remove o valor no topo da fila.
     * @return Retorna valor boleano.
     */
    bool removeDoTopo();

    /**
     * @brief Método que retorna o tamanho da pilha
     */
    int getTamanho(); // <- É REALMENTE NECESSÁRIO???
    
    /**
     * @brief Método que retorna o elemento do topo da pilha
     * @return Retorna o conteúdo do topo da pilha
     */
    T topo();

    /**
     * @brief Método para verificar se a pilha está cheia
     * @return Retorna verdadeiro ou falso em relação a pilha cheia
     */
    bool estaCheia();

    /**
     * @brief Método para verificar se a pilha está vazia
     * @return Retorna verdadeiro ou falso em relação a pilha vazia
     */
    bool estaVazia();

    /**
     * @brief Método para imprimir o conteúdo da pilha
     */
    void imprimir();
    
    /**
     * @brief Método utilizado pelo destrutor para limpar toda a pilha
     */
    void limpar();
    
    /**
     * @brief Sobrecarga do operador de inserção.
     * @detail imprime na saída padrão as informações da pilha
     * @param ostream &o operador de inserção
     * @param Pilha<T> f uma instância de Pilha
     * @return retorna a instância do operador de inserção
     */
    friend std::ostream &operator<<<T>(std::ostream &, Pilha<T> const &p);
};

template <typename T>
Pilha<T>::Pilha(int tamanho) {
    conteudo = new T[tamanho];
    this->tamanho = tamanho;
    topo = -1;
}

template <typename T>
Pilha<T>::~Pilha() {
    limpar();
}

template <typename T>
bool Pilha<T>::insereNoTopo(T conteudo) {
    if(estaCheia()) {
        std::cout << "Erro: Impossível inserir conteúdo. Pilha cheia!" << std::endl;
    } else {
        this->conteudo[++topo] = conteudo;
    }

    return true; // <- É REALMENTE NECESSÁRIO???
}

template <typename T>
bool Pilha<T>::removeDoTopo() {
    if(estaVazia()) {
        std::cout << "Erro: Impossível remover conteúdo. Pilha vazia!" << std::endl;
        exit(1);
    }

    T aux = topo();
    topo--;
    return aux;
    // return true;
}

template <typename T>
int Pilha<T>::getTamanho() {
    return this->tamanho // <- É REALMENTE NECESSÁRIO???
}

template <typename T>
T Pilha<T>::topo() {
    if(estaVazia()) {
        std::cout << "Erro: A pilha está vazia!" std::endl;
        exit(1);
    }

    return conteudo[topo];
}

template <typename T>
bool Pilha<T>::estaCheia() {
    return topo == tamanho -1;
}

template <typename T>
bool Pilha<T>::estaVazia() {
    return topo == -1;
}

template <typename T>
void Pilha<T>::imprimir() {
    for(int i = topo; i > -1; i--) {
        std::cout << conteudo[i] << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void Pilha<T>::limpar() {
    delete [] conteudo;
    topo = -1;
}

template <typename T>
std::ostream &operator<<(std::ostream &o, Pilha<T> const &p) {
    /* auto atual = f.cabeca;
    o << f.limpar();
    for (int i = 0; i < (int)f.getTamanho(); i++)
        o << f.getElemento(i);
    return o; */
}

#endif
