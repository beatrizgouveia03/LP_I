#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <Musica.hpp>

class Playlist
{
private:
   string nome;
   /*vetor musicas; IMPLEMENTAR*/ 
public:
    //CONSTRUTORES
    Playlist();
    Playlist(string nome /*, vetor musicas*/);

    //DESTRUTORRES

    ~Playlist();

    //FUNÇÕES
    void addMusica(Musica m);
    void remMusica(Musica m);

    Musica* findMusica(Musica m);

};





#endif