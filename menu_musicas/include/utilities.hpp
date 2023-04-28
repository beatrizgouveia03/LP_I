#include "Lista.hpp"
#include "Playlist.hpp"

// Configuração Inicial
Lista<Musica> configuracaoInicialMusicas();

Lista<Playlist> configuracaoInicialPlaylists(Lista<Musica> *baseMusicas);

// Menus
void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuMusicasEmPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuListagemMusicas(Lista<Musica> *baseMusicas);

void menuListagemPlaylists(Lista<Playlist> *basePlaylists);

//Tratamento da entrada
void tratarAcao(int *acao);

bool isNumber(string entry);
