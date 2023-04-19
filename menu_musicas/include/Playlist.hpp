#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Musica.hpp"
#include "Lista.hpp"

class Playlist
{
private:
   string nome;
   Lista<Musica> musicas; 
public:
    Playlist();
    Playlist(string nome ,Lista<Musica> musicas);

    ~Playlist();

    void setNome(string nome);
    void setMusicas(Lista<Musica> musicas);

    string getNome();
    Lista<Musica> getMusicas();

    void addMusica(Musica m);
    void remMusica(Musica m);

    No<Musica>* findMusica(Musica m);

};





#endif