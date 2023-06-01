#include <iostream>

#include "utilities.hpp"

using namespace std;

int main()
{
    Lista<Musica> *musicas = configuracaoInicialMusicas();
    Lista<Playlist> *playlists = configuracaoInicialPlaylists(musicas);

    menuPrincipal(musicas, playlists);


    delete musicas;
    delete playlists;

    return 0;
}