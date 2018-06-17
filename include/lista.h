/**
 * @file	lista.h
 * @brief	Implementação da classe Node em C++
 * @author	Bruno César L. Silva
 * @since	19/05/2018
 * @date	19/05/2018
 */

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <memory>

using namespace std;

// Para permitir sobrecarregar o operador de insercao
// numa classe template como friend eh preciso adicionar
// o trecho de codigo a seguir
template <typename T> class Node; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, Node<T> const & );
// --

/**
* @brief Implementacao da classe Node
* @detail Define os nós generalizando-os com templates
*/
template <typename T>
class Node{
private:
	T valor; /**< Valor para inserir no nó */
	shared_ptr<Node<T>> proximo; /**< Apontador para a próxima posição */
public:
	/**
	* @brief Método construtor padrão de Node
	*/
	Node();

	/**
	* @brief Método construtor parametrizado de Node
	* @param T - valor do nó
	*/  
	Node(T _valor);

	/**
	* @brief Método destrutor de Node
	*/
	~Node();

	/**
	* @brief Método construtor parametrizado de Node
	* @param T - valor do nó
	* @param shared_ptr<Node> - ponteiro para a próxima posição
	*/ 
	Node(T num, shared_ptr<Node> nextPtr);

	/**
	* @brief Método get de valor
	* @return Retorna o valor da posição
	*/
	T getValor();

	/**
	* @brief Método get de proximo
	* @return Retorna a posiçao de memória do próximo nó
	*/
	shared_ptr<Node<T>> getNext();

	/**
	* @brief Método set de proximo
	* @param shared_ptr<Node<T>> - define o a posição de memória do próximo nó
	*/
	void setNext(shared_ptr<Node<T>> nextPtr);

	/**
	* @brief Sobrecarga do operador de inserção.
	* @detail imprime na saída padrão as informações de Node
	* @param ostream &o operador de inserção
	* @param Node<T> n uma instância de Node<T>
	* @return retorna a instância do operador de inserção
	*/
	friend std::ostream& operator<< <T>(std::ostream &o, Node<T> const &n);
};

/* Construtor padrão - valor recebe=<vazio> e proximo=nullptr */
template <typename T>
Node<T>::Node() : valor(), proximo(nullptr) {}

/* Construtor padrão - valor recebe=_valor e proximo=nullptr */
template <typename T>
Node<T>::Node(T _valor) : valor(_valor), proximo(nullptr) {}

/* Destrutor - Na remoção é exibido o valor que está sendo removido  */
template <typename T>
Node<T>::~Node() {
	cout << "Node(" << valor << ") removido." << endl;
}

/* Construtor padrão - valor recebe=_valor e proximo=nullptr */
template <typename T>
Node<T>::Node(T _valor, shared_ptr<Node<T>> nextPtr) : valor(_valor), proximo(nextPtr) {}

template <typename T>
T Node<T>::getValor() {
	return valor;
}

template <typename T>
shared_ptr<Node<T>> Node<T>::getNext() {
	return proximo;
}

template <typename T>
void Node<T>::setNext(shared_ptr<Node<T>> nextPtr) {
	proximo = nextPtr;
}

template <typename T>
std::ostream& operator<< (std::ostream &o, Node<T> const &n) {
	o << n.valor;
	return o;
}

/**
 * @file	lista.h
 * @brief	Implementação da classe ListaLigada em C++
 * @author	Bruno César L. Silva
 * @since	19/05/2018
 * @date	20/05/2018
 */

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend é preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class ListaLigada; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, ListaLigada<T> const & );
// --

/**
* @brief Implementacao da classe ListaLigada
* @detail Define um template de lista
*/
template <typename T>
class ListaLigada {
protected:
	shared_ptr<Node<T>> cabeca; /**< define a sentinela cabeca que aponta para o inicio da lista*/
	shared_ptr<Node<T>> cauda; /**< define a sentinela cauda que aponta para o fim da lista */
	int tamanho; /**< define o tamanho da lista */

	/**
	* @brief Método que insere valor no inicio da lista
	* @param T - recebe o valor para o novo nó
	*/
	bool InsereNoInicio(T _valor);

	/**
	* @brief Método que insere valor no final da lista
	* @param T - recebe o valor para o novo nó
	* @return Retorna um valor boleano
	*/
	bool InsereNoFinal(T _valor);

	/**
	* @brief Método que insere valor em um valor qualquer
	* @param int - recebe a posição da lista
	* @param T - recebe o valor para o novo nó
	* @return Retorna um valor boleano
	*/
	bool InsereNaPosicao(int pos, T _valor);
	
	/**
	* @brief Método que remove valor no final da lista
	* @return Retorna um valor boleano
	*/
	bool RemoveNoFinal();

	/**
	* @brief Método que remove valor em uma posição qualquer
	* @param int - Recebe a posição a qual deseja remover
	* @return Retorna um valor boleano
	*/
	bool RemoveNaPosicao(int pos);

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
	* @brief Método que remove valor no inicio da lista
	* @return Retorna um valor boleano
	*/
	bool RemoveNoInicio();

	/**
	* @brief Método que exibe tamanho da lista
	* @return Retorna o tamanho da lista
	*/
	int size();

	/**
	* @brief Sobrecarga do operador de inserção.
	* @detail imprime na saída padrão as informações da lista ligada
	* @param ostream &o operador de inserção
	* @param ListaLigada<T> l uma instância de ListaLigada
	* @return retorna a instância do operador de inserção
	*/
	friend std::ostream& operator<< <T>( std::ostream&, ListaLigada<T> const &l);
};

/* Inicializa atibutos da lista ligada com nullptr para cabeca e cauda e tamanho=0 */
template <typename T>
ListaLigada<T>::ListaLigada(): cabeca(nullptr), cauda(nullptr), tamanho(0) {}

template <typename T>
ListaLigada<T>::~ListaLigada() {
	/* Percorre a lista a partir das posições de memoria de seus nós 
	enquanto cabeca != cauda atribuindo o valor da próxima posição a cabeca*/
	while (cabeca != this->cauda)
		cabeca = cabeca->getNext();
}

template <typename T>
bool ListaLigada<T>::InsereNoInicio(T _valor) {
	auto novo = make_shared<Node<T>>(_valor);
	// Verica se o ponteiro foi definido na memória
	if (!novo) return false;

	// novo aponta para a posicao definida pela cabeca
	novo->setNext(this->cabeca);
	// cabeca aponta para o novo nó
	this->cabeca = novo;
	// o tamanho da lista é incrementado em 1
	this->tamanho++;

	return true;
}

template <typename T>
bool ListaLigada<T>::InsereNoFinal(T _valor) {
	// Verifica se a lista é vazia
	if (this->cabeca == nullptr) {
		/* Chama função InsereNoInicio passando como parâmetro _valor
		a fim de definir o primeiro valor da lista */
		return InsereNoInicio(_valor);
	} else {
		/* guarda a posição de memória do primeiro nó da lista
		definida na cabeca */
		auto atual = this->cabeca;
		/* Percorre a lista a partir das posições de memória 
		até encontrar a posição apontada pela cauda */
		while (atual->getNext() != this->cauda)
			atual = atual->getNext();
		
		// Define um novo nó
		auto novo = make_shared<Node<T>>(_valor);
		// Verica se o ponteiro foi definido na memória
		if (!novo) return false;

		// Última posição da lista aponta para a posição de memória do novo nó
		atual->setNext(novo);
		// novo aponta para o valor definido em cauda (nullptr)
		novo->setNext(this->cauda);
		// Tamanho da lista é incrementado em 1
		this->tamanho++;
	}

	return true;
}

template <typename T>
bool ListaLigada<T>::InsereNaPosicao(int pos, T _valor) {
	// Verica se a posição selecionada encontra-se no intervalo
	if (pos<0) return false; // Deve ser adicionado condição maior que o tamanho da lista
	// Se a posição for a primeira chama InserirNoInicio passando _valor
	if (pos==0)	return InsereNoInicio(_valor);

	// Guarda posição atual da lista definida na cabeca
	auto atual = this->cabeca;
	int posAtual = 0;

	// Percorre a lista a fim de encontrar a posição selecionada no intervalor entre cabeca e cauda
	while (atual->getNext() != this->cauda && posAtual < pos-1) {
		// Guarda a posição de memória da posição selecionada
		atual = atual->getNext();
		posAtual++;
	}
	
	auto novo = make_shared<Node<T>>(_valor);
	// Verica se o nó foi alocado em memória
	if (!novo) return false;

	// Novo nó aponta para seu valor da sequencia baseado na posição de memória a qual ira ficar
	novo->setNext(atual->getNext());
	// A posição atual aponta para o novo nó
	atual->setNext(novo);
	// O tamanho da lista é incrementado em 1
	this->tamanho++;
	
	return true;
}

template <typename T>
bool ListaLigada<T>::RemoveNoInicio() {
	// Verifica se a lista está vazia
	if (this->cabeca==nullptr) return false;
	// cabeca aponta para a próxima posição de memória
	cabeca = cabeca->getNext();
	// tamanho da lista é decrementado em 1
	this->tamanho--;

	return true;
}

template <typename T>
bool ListaLigada<T>::RemoveNoFinal() {
	// Verifica se a lista está vazia
	if (this->cabeca==nullptr) return false;

	// Verifica se tem apenas um valor na lista
	/* Verifica se a primeira posição da lista, apontado por cabeca,
	aponta para nullptr (cauda) */
	if (this->cabeca->getNext()==this->cauda) {
		// cabeca aponta para cauda (nullptr)
		this->cabeca = this->cauda;
		// tamanho da lista é decrementado em 1
		this->tamanho--;

		return true;
	}

	// Guarda posição de memória apontada por cabeca (primeira posição da lista)
	auto atual = this->cabeca;
	// Percorre a lista a fim de encontrar o final
	while (atual->getNext()->getNext() != this->cauda)
		atual = atual->getNext();
	// Define o apontador da última posição da lista para nullptr
	atual->setNext(this->cauda);
	// tamanho da lista é decrementado em 1
	this->tamanho--;

	return true;
}

template <typename T>
bool ListaLigada<T>::RemoveNaPosicao(int pos) {
	// Verica se a posição selecionada encontra-se no intervalo
	if (pos<0) return false;
	// Se a posição for a primeira chama RemoverNoInicio
	if (pos==0)	return RemoveNoInicio();

	// Guarda posição atual da lista definida na cabeca
	auto atual = this->cabeca;
	int posAtual = 0;
	while (atual->getNext()->getNext() != this->cauda && posAtual < (pos-1)) {
		// Guarda a posição de memória da posição selecionada
		atual = atual->getNext();
		posAtual++;
	}

	// atual passa a apontar para atual+2 posições de memória
	// ou seja, apontará para o próximo de seu sucessor atual
	atual->setNext(atual->getNext()->getNext());
	// O tamanho da lista é incrementado em 1
	this->tamanho--;

	return true;
}

template <typename T>
int ListaLigada<T>::size() {
	return this->tamanho;
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, ListaLigada<T> const &l) {
	auto atual = l.cabeca;
	while (atual != l.cauda) {
		o << atual->getValor() << " ";
		atual = atual->getNext();
	}

	return o;
}

#endif