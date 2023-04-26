#ifndef LISTA_H
#define LISTA_H

#include <iostream>

#include "No.hpp"

using namespace std;

template <class T>
class Lista
{
private:
    No<T> *cabeca;
    No<T> *cauda;

public:
    Lista();
    Lista(T valor);
    ~Lista();

    void inserir(T valor);
    void inserir(T valor, int posicao);
    void remover(T valor);

    void setCabeca(No<T> *cabeca);
    void setCauda(No<T> *cauda);

    No<T> *getCabeca();
    No<T> *getCauda();

    No<T> *buscar(T valor);
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
Lista<T>::Lista(T valor)
{
    No<T> *no = new No<T>(valor);
    this->cabeca = no;
    this->cauda = no;
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
                this->cabeca = atual->getProximo();
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
        }

        anterior = atual;
        atual = atual->getProximo();
    }
}

// Método para buscar um nó da lista
template <class T>
No<T> *Lista<T>::buscar(T valor)
{
    No<T> *atual = this->cabeca;

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

#endif