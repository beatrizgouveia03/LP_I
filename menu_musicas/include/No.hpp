#ifndef NO_H
#define NO_H

using namespace std;

template <class T>
class No
{
private:
    T valor;
    No<T> *proximo;

public:
    No();
    No(T valor);

    void setValor(T valor);
    void setProximo(No<T> *proximo);

    T getValor();
    No<T> *getProximo();
};


// Construtor padrão
template <class T>
No<T>::No()
{
    this->value = T();
    this->proximo = nullptr;
}

// Construtor que inicializa o valor do nó
template <class T>
No<T>::No(T valor)
{
    this->valor = valor;
    this->proximo = nullptr;
}

// Métodos setters e getters para o atributo valor
template <class T>
void No<T>::setValor(T valor)
{
    this->valor = valor;
}

template <class T>
T No<T>::getValor()
{
    return this->valor;
}

// Métodos setters e getters para o atributo proximo
template <class T>
void No<T>::setProximo(No<T> *proximo)
{
    this->proximo = proximo;
}

template <class T>
No<T> *No<T>::getProximo()
{
    return this->proximo;
}

#endif