#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Musica.hpp"
#include "Lista.hpp"

class Playlist
{
private:
    string nome;
    Lista<No<Musica *> *> *musicas;

public:
    Playlist();
    Playlist(string nome);
    Playlist(string nome, Lista<No<Musica *> *> *musicas);

    ~Playlist();

    void setNome(string nome);
    void setMusicas(Lista<No<Musica *> *> *musicas);

    string getNome();
    Lista<No<Musica *> *> *getMusicas();

    void addMusica(Musica *m);
    void remMusica(Musica *m);

    No<Musica *> *findMusica(Musica *m);
};

#endif