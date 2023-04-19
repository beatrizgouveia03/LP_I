#include "Lista.hpp"
#include "Playlist.hpp"

Lista<Playlist> configuracaoInicial() {
    string titulo[] = {"I'm good", "I'm believer", "I want it that way", "Alejandro", "Applause", "Californication"};
    string artista[] = {"David Guetta", "Smash Mounth", "Backstreet Boys", "Lady Gaga", "Lady Gaga", "Red Hot Chili Peppers"};

    Lista<Playlist> *base = new Lista<Playlist>();

    Lista<Musica> *musicas =  new Lista<Musica>();
    Playlist  *play  = new Playlist();
    play->setNome("Elson William");

    for(int i=0; i<6; i+=2){
        Musica *m = new Musica(titulo[i], artista[i]);
        musicas->inserir(*m);
    }
    play->setMusicas(*musicas);

    base->inserir(*play);

    return *base;
}