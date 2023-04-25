#include "Lista.hpp"
#include "Playlist.hpp"

// Configuração Inicial
Lista<Musica> configuracaoInicialMusicas();

Lista<Playlist> configuracaoInicialPlaylists(Lista<Musica> *baseMusicas);

// Menus
void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuMusicas(Lista<Musica> *baseMusicas);

void menuPlaylists(Lista<Playlist> *basePlaylists);

No<Musica> *menuListagemMusicas(Lista<Musica> *baseMusicas);

No<Playlist> *menuListagemPlaylists(Lista<Playlist> *basePlaylists, Lista<Musica> *baseMusicas);

void menuMusicasEmPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);