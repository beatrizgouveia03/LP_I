#include <iostream>

#include "utilities.hpp"

using namespace std;

int main()
{
    Lista<Musica> musicas = configuracaoInicialMusicas();
    cout << "Musicas configuradas..\n";
    Lista<Playlist> playlists = configuracaoInicialPlaylists(&musicas);
    cout << "Playlists configuradas..\n";

    cout << endl;

    // Teste baseMusicas
    cout << "Teste baseMusicas..\n";
    menuListagemMusicas(&musicas);

    // Teste basePlaylist
    cout << "Teste basePlaylist..\n";
    menuListagemPlaylists(&playlists);
   

    menuPrincipal(&musicas, &playlists);

    return 0;
}