#include "Lista.hpp"
#include "Playlist.hpp"

//Configuração Inicial
Lista<Musica> configuracaoInicialMusicas();

Lista<Playlist> configuracaoInicialPlaylists(Lista<Musica> *baseMusicas);

//Menus
void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuMusicas(Lista<Musica> *baseMusicas);

void menuPlaylists(Lista<Playlist> *basePlaylists);
