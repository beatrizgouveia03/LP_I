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
    Lista()
    {
        cabeca = nullptr;
        cauda = nullptr;
    }

    /// @brief Construtor que inicializa a lista com um nó
    /// @param valor Valor com que o nó será iniciado
    Lista(T valor)
    {
        cabeca = new No<T>(valor);
        cauda = cabeca;
    }

    /// @brief Construtor cópia
    /// @param lista Lista com os elementos que serão inicializados na lista
    Lista(const Lista<T> &lista)
    {
        cabeca = nullptr;
        cauda = nullptr;

        if (lista.cabeca == nullptr)
            return;

        No<T> *atual = lista.cabeca;

        while (atual != nullptr)
        {
            inserir(atual->getValor());
            atual = atual->getProximo();
        }
    }

    /// @brief Destrutor padrão da classe
    /// @param NULL
    ~Lista()
    {
        No<T> *atual = cabeca;

        while (atual != nullptr)
        {
            No<T> *proximo = atual->getProximo();
            delete atual;
            atual = proximo;
        }
    }

    /// @brief Função para configurar o head/cabeça da lista
    /// @param cabeca Iterador para o nó que será a cabeça da lista
    void setCabeca(No<T> *cabeca)
    {
        this->cabeca = cabeca;
    }

    /// @brief Função para configurar o tail/cauda da lista
    /// @param cauda Iterador para o nó que será a cauda da lista
    void setCauda(No<T> *cauda)
    {
        this->cauda = cauda;
    }

    /// @brief Função que retorna um ponteiro indicando o head/cabeça da lista
    /// @return Iterador para a cabeça da lista
    No<T> *getCabeca() const
    {
        return cabeca;
    }
    /// @brief Função que retorna um ponteiro indicando o tail/cauda da lista
    /// @return Iterador para a cauda da lista
    No<T> *getCauda() const
    {
        return cauda;
    }

    /// @brief Função para inserir um elemento na lista
    /// @param valor Valor que será inserido no novo fim da lista
    void inserir(T valor)
    {
        No<T> *novo = new No<T>(valor);

        if (cabeca == nullptr)
        {
            cabeca = novo;
            cauda = cabeca;
        }
        else
        {
            cauda->setProximo(novo);
            cauda = novo;
        }
    }

    /// @brief Função para inserir todos os elemeneos de outra lista na lista
    /// @param lista Lista com os elementos a serem adicionados
    void adicionarElementos(const Lista<T> &lista)
    {
        No<T> *atual = lista.cabeca;

        while (atual != nullptr)
        {
            inserir(atual->getValor());
            atual = atual->getProximo();
        }
    }

    /// @brief Função para excluir um elemento da lista
    /// @param valor Valor que será removido da lista
    void remover(T valor)
    {
        if (cabeca == nullptr)
        {
            return;
        }

        if (cabeca->getValor() == valor)
        {
            No<T> *temp = cabeca;
            cabeca = cabeca->getProximo();
            delete temp;
            return;
        }

        No<T> *atual = cabeca->getProximo();
        No<T> *anterior = cabeca;

        while (atual != nullptr)
        {
            if (atual->getValor() == valor)
            {
                anterior->setProximo(atual->getProximo());
                delete atual;
                return;
            }

            anterior = atual;
            atual = atual->getProximo();
        }
    }

    // Função com problema
    void removerElementos(const Lista<T> &lista)
    {
        Lista<T> *listaTemp = new Lista<T>();
        No<T> *atual = cabeca;

        while (atual != nullptr)
        {
            if (lista.buscar(atual->getValor()) == nullptr)
            {
                listaTemp->inserir(atual->getValor());
            }

            atual = atual->getProximo();
        }

        *this = *listaTemp;

        delete listaTemp;
    }

    /// @brief Função que returna o tamanho da lista
    /// @return Tamanho da lista
    int tamanho() const
    {
        int size = 0;
        No<T> *atual = cabeca;

        while (atual != nullptr)
        {
            size++;
            atual = atual->getProximo();
        }

        return size;
    }

    /// @brief Função que busca um elemento na lista. Caso o encontre retorna um ponteiro para ele, caso não, retorna um nullptr
    /// @param valor Valor do elemento a ser procurado na lista
    /// @return Interador para o elemento ou nullptr
    No<T> *buscar(T valor) const
    {
        No<T> *atual = cabeca;

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

    Lista<T> operator+(const Lista<T> &lista) const
    {
        Lista<T> novaLista;

        novaLista.adicionarElementos(*this);
        novaLista.adicionarElementos(lista);

        return novaLista;
    }

    // Lista<T> operator-(const Lista<T> &lista) const{
    //   Lista<T> novaLista;

    //  novaLista.adicionarElementos(*this);
    //  novaLista.removerElementos(lista);

    //  return novaLista;
    //}

    // friend void operator>>(Lista<T> &lista, No<T> *no);
    //
    // friend void operator<<(Lista<T> &lista, T valor);
};

#endif // LISTA_HPP