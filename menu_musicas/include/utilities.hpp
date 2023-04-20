#include "Lista.hpp"
#include "Playlist.hpp"

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

Lista<Playlist> configuracaoInicialPlaylists(Lista<Musica> baseMusicas)
{
    Lista<Playlist> *basePlaylists = new Lista<Playlist>();
    Playlist playlist1("Playlist 1");
    Playlist playlist2("Playlist 2");

    cout << " Configurando playlist...\n";

    auto itr = baseMusicas.getCabeca();
    auto end = baseMusicas.getCauda();

    while (itr != end->getProximo())
    {
        playlist1.addMusica(itr->getValor());

        itr = itr->getProximo();

        playlist2.addMusica(itr->getValor());

        itr = itr->getProximo();
    }

    cout << " Músicas configuradas...\n";

    basePlaylists->inserir(playlist1);
    cout << " Playlist adicionada...\n";
    basePlaylists->inserir(playlist2);
    cout << " Playlist adicionada...\n";

    return *basePlaylists;
}
