#ifndef NO_H
#define NO_H

/*!
 *   @file No.hpp
 *   @brief Definição da classe No
 *   @date 01 de maio de 2023
 *   @author Beatriz G. Gadelha
 */

using namespace std;

/// @brief Implementação de uma classe No
/// @param T Variável template
template <class T>
class No
{
private:
    /// @brief Valor do nó
    T valor;
    /// @brief Iterador para o próximo nó
    No<T> *proximo;

public:
    /// @brief Construtor padrão da classe
    /// @param NULL
    No();
    /// @brief Construtor que inicializa o nó com um valor
    /// @param valor Valor com que o nó será iniciado
    No(T valor);

    /// @brief Função para configurar o valor do nó
    /// @param valor Valor que será atribuído ao nó
    void setValor(T valor);
    /// @brief Função para configurar o próximo nó
    /// @param proximo Iterador para o próximo nó
    void setProximo(No<T> *proximo);

    /// @brief Função que retorna o valor do nó
    /// @return Valor do nó
    T getValor();
    /// @brief Função que retorna o próximo nó
    /// @return Iterador para o próximo nó
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
No<T>::No(T valor /*Valor a ser inicializado o valor do nó*/)
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

#endif // NO_HPP