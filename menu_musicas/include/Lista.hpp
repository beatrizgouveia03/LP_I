#ifndef LISTA_H
#define LISTA_H

/*!
 *   @file Lista.hpp
 *   @brief Definição da classe Lista
 *   @date 01 de maio de 2023
 *   @author Beatriz G. Gadelha
 */

#include <iostream>

#include "No.hpp"

using namespace std;

/// @class Lista Lista.hpp "include/Lista.hpp"
/// @brief Implementação de uma classe Lista
/// @param T Variável template
template <class T>
class Lista
{
private:
    /// @brief Iterador para indicar o head/início da lista
    No<T> *cabeca;
    /// @brief Iterador para indicar o tail/cauda da lista
    No<T> *cauda;

public:
    /// @brief Construtor padrão da classe
    /// @param NULL
    Lista();
    /// @brief Construtor que inicializa a lista com um nó
    /// @param valor Valor com que o nó será iniciado
    Lista(T valor);

    Lista(Lista<T> *lista);

    /// @brief Destrutor padrão da classe
    /// @param NULL
    ~Lista();

    /// @brief Função para configurar o head/cabeça da lista
    /// @param cabeca Iterador para o nó que será a cabeça da lista
    void setCabeca(No<T> *cabeca);
    /// @brief Função para configurar o tail/cauda da lista
    /// @param cauda Iterador para o nó que será a cauda da lista
    void setCauda(No<T> *cauda);

    /// @brief Função que retorna um ponteiro indicando o head/cabeça da lista
    /// @return Iterador para a cabeça da lista
    No<T> *getCabeca();
    /// @brief Função que retorna um ponteiro indicando o tail/cauda da lista
    /// @return Iterador para a cauda da lista
    No<T> *getCauda();

    /// @brief Função para inserir um elemento na lista
    /// @param valor Valor que será inserido no novo fim da lista
    void inserir(T valor);
    /// @brief Função para inserir um elemento na lista no índice especificado
    /// @param valor Valor que será inserido no novo nó da lista
    /// @param posicao Posição em que o novo elemento será inserido
    void inserir(T valor, int posicao);

    void adicionarElementos(Lista<T> *lista);

    /// @brief Função para excluir um elemento da lista
    /// @param valor Valor que será removido da lista
    void remover(T valor);

    void removerElementos(Lista<T> *lista);

    /// @brief Função que returna o tamanho da lista
    /// @return Tamanho da lista
    int tamanho();

    /// @brief Função que busca um elemento na lista. Caso o encontre retorna um ponteiro para ele, caso não, retorna um nullptr
    /// @param valor Valor do elemento a ser procurado na lista
    /// @return Interador para o elemento ou nullptr
    No<T> *buscar(T valor);
    /// @brief Função que busca se existe um elemento na lista no índice indicado. Caso exista, retorna um ponteiro para ele, cano nãõ~retorna um nullptr
    /// @param indice Indice do elemento a ser procurado na lista
    /// @return Interador para o elemento ou nullptr
    No<T> *buscarPorIndice(int indice);

    Lista<T> *operator+(Lista<T> &lista);

    Lista<T> *operator-(Lista<T> &lista);

    friend void operator>>(Lista<T> &lista, No<T> *no);

    friend void operator<<(Lista<T> &lista, T valor);
};

// Construtor padrão
template <class T>
Lista<T>::Lista()
{
    this->cabeca = nullptr;
    this->cauda = nullptr;
}

// Construtor que inializa a lista com um nó
template <class T>
Lista<T>::Lista(T valor /*Nó a ser inicializado junto com a construção da lista*/)
{
    No<T> *no = new No<T>(valor);
    this->cabeca = no;
    this->cauda = no;
}

template <class T>
Lista<T>::Lista(Lista<T> *lista)
{
    this->cabeca = nullptr;
    this->cauda = nullptr;

    No<T> *atual = lista->getCabeca();

    while (atual != nullptr)
    {
        this->inserir(atual->getValor());
        atual = atual->getProximo();
    }
}

// Desconstrutor padrão
template <class T>
Lista<T>::~Lista()
{
    No<T> *atual = this->cabeca;
    No<T> *proximo = nullptr;

    while (atual != nullptr)
    {
        proximo = atual->getProximo();
        delete atual;
        atual = proximo;
    }
}

// Métodos setters e getters para o atributo Cabeca
template <class T>
void Lista<T>::setCabeca(No<T> *cabeca)
{
    this->cabeca = cabeca;
}

template <class T>
No<T> *Lista<T>::getCabeca()
{
    return this->cabeca;
}

// Métodos setters e getters para o atributo Cabeca
template <class T>
void Lista<T>::setCauda(No<T> *cauda)
{
    this->cauda = cauda;
}

template <class T>
No<T> *Lista<T>::getCauda()
{
    return this->cauda;
}

// Método para adicionar um nó no final da lista
template <class T>
void Lista<T>::inserir(T valor)
{
    No<T> *novo = new No<T>(valor);

    if (this->cabeca == nullptr)
    {
        this->setCabeca(novo);
        this->setCauda(novo);
    }
    else
    {
        this->cauda->setProximo(novo);
        this->setCauda(novo);
    }
}

// Método para adicionar um nó em uma posição específica da lista
template <class T>
void Lista<T>::inserir(T valor, int posicao)
{
    No<T> *novo = new No<T>(valor);

    if (posicao == 0)
    {
        novo->setProximo(this->cabeca);
        this->cabeca = novo;
    }
    else
    {
        No<T> *atual = this->cabeca;
        No<T> *anterior = nullptr;

        for (int i = 0; i < posicao; i++)
        {
            anterior = atual;
            atual = atual->getProximo();
        }

        novo->setProximo(atual);
        anterior->setProximo(novo);
    }
}

// Método para adicionar os elementos de uma lista em outra
template <class T>
void Lista<T>::adicionarElementos(Lista<T> *lista)
{
    No<T> *atual = lista->getCabeca();

    while (atual != nullptr)
    {
        this->inserir(atual->getValor());
        atual = atual->getProximo();
    }
}

// Método para remover um nó da lista
template <class T>
void Lista<T>::remover(T valor)
{
    No<T> *atual = this->cabeca;
    No<T> *anterior = nullptr;

    while (atual != nullptr)
    {
        if (atual->getValor() == valor)
        {
            if (atual == this->cabeca)
            {
                this->cabeca = cabeca->getProximo();
            }
            else if (atual == this->cauda)
            {
                this->cauda = anterior;
                this->cauda->setProximo(nullptr);
            }
            else
            {
                anterior->setProximo(atual->getProximo());
            }

            delete atual;
            break;
        }

        anterior = atual;
        atual = atual->getProximo();
    }
}

// Método para remover os elementos de uma lista em outra
template <class T>
void Lista<T>::removerElementos(Lista<T> *lista)
{
    No<T> *atual = lista->getCabeca();

    while (atual != nullptr)
    {
        this->remover(atual->getValor());
        atual = atual->getProximo();
    }
}

// Método para buscar um nó da lista
template <class T>
No<T> *Lista<T>::buscar(T valor)
{
    No<T> *atual = this->getCabeca();

    while (atual != nullptr)
    {
        if (atual->getValor() == valor)
        {
            return atual;
        }

        atual = atual->getProximo();
    }

    return nullptr;
}

// Método para retornar o tamanho da lista
template <class T>
int Lista<T>::tamanho()
{
    int tamanho = 0;
    No<T> *atual = this->cabeca;

    while (atual != nullptr)
    {
        tamanho++;
        atual = atual->getProximo();
    }

    return tamanho;
}

// Método para buscar um nó da lista por índice
template <class T>
No<T> *Lista<T>::buscarPorIndice(int indice)
{
    No<T> *atual = this->cabeca;

    for (int i = 0; i < indice; i++)
    {
        atual = atual->getProximo();
    }

    return atual;
}

// Método para concatenar duas listas
template <class T>
Lista<T> *Lista<T>::operator+(Lista<T> &lista)
{
    Lista<T> *novaLista = new Lista<T>(this);

    novaLista->adicionarElementos(&lista);

    return novaLista;
}

template <class T>
Lista<T> *Lista<T>::operator-(Lista<T> &lista)
{
    Lista<T> *novaLista = new Lista<T>(this);

    novaLista->removerElementos(&lista);

    return novaLista;
}

// Sobrecarga do operador de extração
template <class T>
void operator>>(Lista<T> &lista, No<T> *no)
{
    if (lista->tamanho() == 0)
    {
        no->setValor(nullptr);
        return;
    }

    No<T> *ultimo = lista->getCauda();
    no->setValor(ultimo->getValor());
}

// Sobrecarga do operador de inserção
template <class T>
void operator<<(Lista<T> &lista, T valor)
{
    if (valor->getValor() == nullptr)
        return;

    lista.inserir(valor->getValor());
}

#endif // LISTA_HPP