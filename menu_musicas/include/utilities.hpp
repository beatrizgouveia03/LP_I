/*!
 *   @file utilities.hpp
 *   @brief Definição de funções utilizadas no main e nos menus
 *   @date 01 de maio de 2023
 *   @author Beatriz G. Gadelha
 */

#include "Lista.hpp"
#include "Playlist.hpp"

/*!
    Essa função cria uma Lista<Musica> para ser a base inicial das músicas e a retorna.

    @return Lista<Musica>
*/
Lista<Musica> configuracaoInicialMusicas();

/*!
    Essa função cria uma Lista<Playlist> para ser a base inicial das playlists,
    tomando como parâmetro a base de músicas configuradas anteriormente e a retorna.

    @param Lista<Musica> *baseMusicas
    @return Lista<Playlist>
*/
Lista<Playlist> configuracaoInicialPlaylists(Lista<Musica> *baseMusicas);

// Menus
void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuMusicasEmPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuTocarMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists);

void menuListagemMusicas(Lista<Musica> *baseMusicas);

void menuListagemPlaylists(Lista<Playlist> *basePlaylists);

// Tratamento da entrada
void tratarAcao(int *acao);

bool isNumber(string entry);
