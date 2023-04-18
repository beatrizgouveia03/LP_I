#ifndef NO_H
#define NO_H

using namespace std;

template <class T>
class No
{
private:
    T valor;
    No *proximo;

public:
    No();
    No(T valor);

    void setValor(T valor);
    void setProximo(No *proximo);

    T getValor();
    No *getProximo();
};

template <class T>
No<T>::No()
{
    this->proximo = nullptr;
}

template <class T>
No<T>::No(T valor)
{
    this->valor = valor;
    this->proximo = nullptr;
}

template <class T>
void No<T>::setValor(T valor)
{
    this->valor = valor;
}

template <class T>
void No<T>::setProximo(No<T> *proximo)
{
    this->proximo = proximo;
}

template <class T>
T No<T>::getValor()
{
    return this->valor;
}

template <class T>
No<T> *No<T>::getProximo()
{
    return this->proximo;
}

#endif