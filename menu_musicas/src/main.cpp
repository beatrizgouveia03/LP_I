#include <iostream>

#include "utilities.hpp"

using namespace std;

int main()
{
    Lista<Playlist> App = configuracaoInicial();

    auto begin = App.getCabeca(), end = App.getCauda();

    while(begin != end){
        cout << begin->getValor().getNome() << endl;
        begin = begin->getProximo();
    }

    return 0;
}