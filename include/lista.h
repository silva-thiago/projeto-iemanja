/**
 * @file	lista.h
 * @brief	Implementação da classe ListaLigada em C++
 * @author	Bruno César L. Silva
 * @since	21/06/2018
 * @date	22/06/2018
 */

#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <iostream>

/**
* @breaf Estrutura de nó básica para a composição da lista
*/
template <typename T>
struct no {
	T conteudo; /**< Conteúdo (Valor) do nó da lista */
	struct no * proximo; /**< Ponteiro para o próximo nó da lista */
};

/** 
 * @breaf Definição da classe ListaLigada
 * @detail Define uma lista simplesmente encadeada de tipo genérico
 */
template <typename T>
class ListaLigada {
	struct no<T> * cabeca; /**<< Ponteiro cabeça da lista simplemente encadeada */
	struct no<T> * cauda; /**<< Ponteiro cauda da lista simplesmente encadeada */
	int tamanho; /**<< Define o tamanho da lista */

public:
	/**
	* @brief Método construtor padrão de ListaLigado
	*/
	ListaLigada();

	/**
	* @brief Método destrutor de ListaLigado
	*/
	~ListaLigada();

	/**
	* @brief Método que insere valor no final da lista
	* @param T - recebe o valor para o novo nó
	*/
	void insereNoFinal( T conteudo );

	/**
	* @brief Método que insere valor no inicio da lista
	* @param T - recebe o valor para o novo nó
	*/
	void insereNoInicio( T conteudo );

	/**
	* @brief Método que percorre a lista buscando um valor
	* @param T - Recebe um valor T como argumento
	* @return Retorna um inteiro contendo a posição do conteúdo procurado
	*/
	int  busca( T conteudo );

	/**
	* @brief Método que percorre a lista buscando o índice do valor
	* @param int - Recebe um valor do tipo int como argumento
	* @return Retorna um valor T contendo o valor procurado
	*/
	T    getElemento( int indice );

	T	 getPrimeiroElemento();

	T	 getUltimoElemento();

	/**
	* @brief Método para remover um valor da lista
	* @param T - Recebe um valor do tipo int como argumento
	*/
	void remove( int indice );

	/**
	* @brief Método para limpar todo o conteúdo da lista
	*/
	void limpar();

	/**
	* @brief Método para apontar o tamanho da lista
	* @return Retorna o tamanho da lista
	*/
	int  getTamanho();

	/**
	* @brief Método para verificar se a lista está vazia
	* @return Retorna verdadeiro ou falso em relação a lista vazia
	*/
	bool vazio();

	/**
	* @brief Método para imprimir o conteúdo da lista
	*/
	void imprimir();
};

/**
 * detail Inicializa os atributo proximo dos nós cabeca e cauda como nullptr
 * e o tamanho=0
 */
template <typename T>
ListaLigada<T>::ListaLigada() {
	cabeca = new struct no<T>;
	cabeca->proximo = nullptr;

	cauda = new struct no<T>;
	cauda->proximo = nullptr;

	tamanho = 0;
}

template <typename T>
ListaLigada<T>::~ListaLigada() {

}

template <typename T>
bool ListaLigada<T>::vazio() {
	return tamanho == 0;
}

template <typename T>
void ListaLigada<T>::insereNoInicio( T conteudo ) {
	// instancia um novo nó
	struct no<T> * novoNo = new struct no<T>;
	// atributo conteudo do novoNo recebe o argumento
	novoNo->conteudo = conteudo;
	// novoNo aponta para o primeiro nó atual da lista
	novoNo->proximo = cabeca->proximo;
	// cabeca aponta para o novo nó, tornando o novoNo como primeiro da lista
	cabeca->proximo = novoNo;

	if( vazio() )
		cauda->proximo = novoNo;

	tamanho++;
}

template <typename T>
void ListaLigada<T>::insereNoFinal( T conteudo ) {
	struct no<T> * novoNo = new struct no<T>;
	novoNo->conteudo = conteudo;
	novoNo->proximo = nullptr;

	if( !vazio() )
		cauda->proximo->proximo = novoNo;
	
	cauda->proximo = novoNo;

	if( vazio() )
		cabeca->proximo = novoNo;

	tamanho++;
}

template <typename T>
int ListaLigada<T>::busca( T conteudo ){
	int posicao = 0;
	bool encontrou = false;
	struct no<T> * novoNo = new struct no<T>;
	novoNo = cabeca;

	while( !encontrou && posicao < tamanho ){
		novoNo = novoNo->proximo;
		if( novoNo->conteudo == conteudo ){						
			encontrou = true;
		}
		posicao++;		
	}
	/* Verifica se o valor foi encontrado
	*  se encontrou-true, retorna indice do valor
	*  se não, retorna -1
	*/
	if( encontrou )
		return posicao-1;
	else
		return -1;
}

template <typename T>
T ListaLigada<T>::getElemento( int indice ){	
	struct no<T> * novoNo = new struct no<T>;
	int posicao = 0;
	novoNo = cabeca;

	while( posicao-1 < indice ){
		novoNo = novoNo->proximo;
		posicao++;
	}

	return novoNo->conteudo;
}

template <typename T>
T	 ListaLigada<T>::getPrimeiroElemento(){
	return this->cabeca->proximo->conteudo;
}

template <typename T>
T	 ListaLigada<T>::getUltimoElemento(){
	return this->cauda->proximo->conteudo;
}

template <typename T>
void ListaLigada<T>::remove( int indice ){
	struct no<T> * novoNo = new struct no<T>;
	novoNo = cabeca;

	for( int i = 0; i <= indice-1; i++ ){
		novoNo = novoNo->proximo;
		if( i == indice-1 ){			
			novoNo->proximo = novoNo->proximo->proximo;			
		}
	}

	if(tamanho > 0){
		tamanho--;
	}
}

template <typename T>
void ListaLigada<T>::limpar(){		
	cabeca->proximo = nullptr;	
	tamanho = 0;
}

template <typename T>	
int ListaLigada<T>::getTamanho(){
	return this->tamanho;
}

template <typename T>
void ListaLigada<T>::imprimir() {
	struct no<T> * aux = cabeca->proximo;

	while( aux != nullptr ) {
		std::cout << aux->conteudo << " ";
		aux = aux->proximo;
	}

	std::cout << std::endl;
}

#endif
