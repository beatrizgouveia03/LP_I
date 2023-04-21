#include <iostream>

#include "utilities.hpp"

using namespace std;

int main()
{
    Lista<Musica> musicas = configuracaoInicialMusicas();
    cout << "Musicas configuradas..\n";
    Lista<Playlist> playlists = configuracaoInicialPlaylists(&musicas);
    cout << "Playlists configuradas..\n";

    // Teste baseMusicas
    cout << "Teste baseMusicas..\n";
    No<Musica>* itr = musicas.getCabeca();
    while (itr != nullptr) {
        Musica m = itr->getValor();
        cout << "Nome: " << m.getTitulo() << endl;
        cout << "Artista: " << m.getArtista() << endl;

        itr = itr->getProximo();
    }


    //Teste basePlaylist
    cout << "Teste basePlaylist..\n";

   No<Playlist>* itr2 = playlists.getCabeca();

   while (itr2 != nullptr)
   {
        Playlist p = itr2->getValor();
        cout << "Nome: " << p.getNome() << endl;
//
        Lista<Musica> *lm = p.getMusicas();
        No<Musica> *itr3 = lm->getCabeca();

        while (itr3 != nullptr){
            Musica m = itr3->getValor();
            cout <<  " Musica: " << m.getTitulo() << " " <<  m.getArtista() << endl;
            
            itr3 = itr3->getProximo();
        }
//
        itr2 = itr2->getProximo();
    }

        return 0;
}