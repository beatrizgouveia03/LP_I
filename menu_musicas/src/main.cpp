#include <iostream>

#include "utilities.hpp"

using namespace std;

int main()
{
    Lista<Musica> musicas = configuracaoInicialMusicas();
    cout << "Musicas configuradas..\n";
    Lista<Playlist> playlists = configuracaoInicialPlaylists(musicas);
    cout << "Playlists configuradas..\n";

    auto itr = playlists.getCabeca();
    auto end = playlists.getCauda();

    while (itr != end->getProximo())
    {
        cout << itr->getValor().getNome() << endl;

        itr = itr->getProximo();
    }

    return 0;
}