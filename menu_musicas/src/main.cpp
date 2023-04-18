#include <iostream>

#include "No.hpp"
#include "Lista.hpp"
#include "Musica.hpp"

using namespace std;

int main()
{
    Lista<Musica> lista;

    Musica musica1("Musica 1", "Artista 1");

    lista.inserir(musica1);

    No<Musica> *atual = lista.getCabeca();

    cout << lista.getCabeca()->getValor().getTitulo() << endl;

    return 0;
}