#include "utilities.hpp"

Lista<Musica> configuracaoInicialMusicas()
{
    string titulo[] = {"I'm good", "I'm believer", "I want it that way", "Alejandro", "Applause", "Californication"};
    string artista[] = {"David Guetta", "Smash Mounth", "Backstreet Boys", "Lady Gaga", "Lady Gaga", "Red Hot Chili Peppers"};

    Lista<Musica> *baseMusicas = new Lista<Musica>();

    for (int i = 0; i < 6; i++)
    {
        Musica musica;
        musica.setTitulo(titulo[i]);
        musica.setArtista(artista[i]);

        baseMusicas->inserir(musica);
    }

    return *baseMusicas;
}

Lista<Playlist> configuracaoInicialPlaylists(Lista<Musica> *baseMusicas)
{
    Lista<Playlist> *basePlaylists = new Lista<Playlist>();

    Lista<Musica> *musicasPlaylist1 = new Lista<Musica>();
    Lista<Musica> *musicasPlaylist2 = new Lista<Musica>();

    auto itr = baseMusicas->getCabeca();
    auto end = baseMusicas->getCauda();

    int index = 0;

    while (itr != nullptr)
    {
        if (index % 2 == 0)
        {
            musicasPlaylist1->inserir(itr->getValor());
        }
        else
        {
            musicasPlaylist2->inserir(itr->getValor());
        }

        itr = itr->getProximo();
        index++;
    }

    Playlist *playlist1 = new Playlist("Top Hits 2002", musicasPlaylist1);
    Playlist *playlist2 = new Playlist("Good Vibes", musicasPlaylist2);

    basePlaylists->inserir(*playlist1);
    basePlaylists->inserir(*playlist2);

    return *basePlaylists;
}
