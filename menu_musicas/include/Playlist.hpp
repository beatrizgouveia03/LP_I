#ifndef PLAYLIST_H
#define PLAYLIST_H

/*!
 *   @file Playlist.hpp
 *   @brief Definição da classe Playlist
 *   @date 01 de maio de 2023
 *   @author Beatriz G. Gadelha
 */

#include "Musica.hpp"
#include "Lista.hpp"

/// @brief Implementação de uma classe Playlist
class Playlist
{
private:
    /// @brief Nome da playlist
    string nome;
    /// @brief Lista de músicas da playlist
    Lista<Musica> *musicas = new Lista<Musica>();

public:
    /// @brief Construtor padrão da classe
    /// @param NULL
    Playlist();
    /// @brief Construtor que inicializa a playlist com um nome
    /// @param nome Nome da playlist
    Playlist(string nome);
    /// @brief Construtor que inicializa a playlist com um nome e uma lista de músicas
    /// @param nome Nome da playlist
    /// @param musicas Lista de músicas da playlist
    Playlist(string nome, Lista<Musica> *musicas);

    /// @brief Destrutor da classe
    /// @param NULL
    ~Playlist();

    /// @brief Função para configurar o nome da playlist
    /// @param nome Nome que será atribuído à playlist
    void setNome(string nome);
    /// @brief Função para configurar a lista de músicas da playlist
    /// @param musicas Lista de músicas que será atribuída à playlist
    void setMusicas(Lista<Musica> *musicas);

    /// @brief Função que retorna o nome da playlist
    /// @return Nome da playlist
    string getNome();
    /// @brief Função que retorna a lista de músicas da playlist
    /// @return Lista de músicas da playlist
    Lista<Musica> *getMusicas();

    /// @brief Função para adicionar uma música à playlist
    /// @param m Música que será adicionada à playlist
    void addMusica(Musica m);
    /// @brief Função para remover uma música da playlist
    /// @param m Música que será removida da playlist
    void remMusica(Musica m);

    /// @brief Função para encontrar uma música na playlist
    /// @param m Música que será procurada na playlist
    /// @return Iterador para a música encontrada
    No<Musica> *findMusica(Musica m);

    /// @brief Sobrecarga do operador de comparação
    /// @param playlist Playlist que será comparada
    /// @return True se as playlists forem iguais e false caso contrário
    bool operator==(Playlist &playlist);
    friend ostream &operator<<(ostream &cout, Playlist &p);
};

#endif // PLAYLIST_H