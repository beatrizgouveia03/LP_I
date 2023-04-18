#ifndef LISTA_H
#define LISTA_H

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
    Lista(No<T> *no);
    ~Lista();

    void inserir(T valor);
    void inserir(T valor, int posicao);
    void remover(T valor);

    void setCabeca(No<T> *cabeca);
    void setCauda(No<T> *cauda);

    No<T> *getCabeca();
    No<T> *getCauda();
};

template <class T>
Lista<T>::Lista()
{
    this->cabeca = nullptr;
    this->cauda = nullptr;
}

template <class T>
Lista<T>::Lista(No<T> *no)
{
    this->cabeca = no;
    this->cauda = no;
}

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

template <class T>
void Lista<T>::inserir(T valor)
{
    No<T> *novo = new No(valor);

    if (this->cabeca == nullptr)
    {
        this->cabeca = novo;
        this->cauda = novo;
    }
    else
    {
        this->cauda->setProximo(novo);
        this->cauda = novo;
    }
}

template <class T>
void Lista<T>::inserir(T valor, int posicao)
{
    No<T> *novo = new No(valor);

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

template <class T>
void Lista<T>::remover(T valor)
{
    No<T> *atual = this->cabeca;
    No<T> *anterior = nullptr;

    while (atual != nullptr)
    {
        if (atual->getValor() == valor)
        {
            if (anterior == nullptr)
            {
                this->cabeca = atual->getProximo();
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

template <class T>
void Lista<T>::setCabeca(No<T> *cabeca)
{
    this->cabeca = cabeca;
}

template <class T>
void Lista<T>::setCauda(No<T> *cauda)
{
    this->cauda = cauda;
}

template <class T>
No<T> *Lista<T>::getCabeca()
{
    return this->cabeca;
}

template <class T>
No<T> *Lista<T>::getCauda()
{
    return this->cauda;
}

#endif