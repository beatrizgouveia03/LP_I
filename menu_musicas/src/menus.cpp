#include "utilities.hpp"

#include <iostream>

void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        int acao;
        string entry;

        cout << "\nMENU PRICIPAL\n";
        cout << "1 - Gerenciar Playlists\n2 - Gerenciar Músicas\n3 - Sair\n";
        cout << "Digite a sua ação: ";

        cin >> acao;
        getline(cin, entry);

        switch (acao)
        {
        case 1:
            menuPlaylists(basePlaylists);
            break;
        case 2:
            menuMusicas(baseMusicas);
            break;
        case 3:
        default:
            return;
        }
    }
}

void menuMusicas(Lista<Musica> *baseMusicas)
{
    while (true)
    {
        int acao;
        Musica m;
        string entry;

        cout << "\nMENU MÚSICAS\n";
        cout << "1 - Adicionar música\n2 - Remover música\n3 - Listar músicas\n4 - Sair\n";
        cout << "Digite a sua ação: ";

        cin >> acao;
        getline(cin,entry);

        switch (acao)
        {
        case 1:
            cout << "Digite o nome da música: ";
            getline(cin, entry);
            m.setTitulo(entry);

            cout << "Digite o artista da música: ";
            getline(cin, entry);
            m.setArtista(entry);

            baseMusicas->inserir(m);
            cout << "\nMúsica Cadastrada!\n\n";
            break;
        case 2:
            cout << "Digite o nome da música a ser removida: ";
            getline(cin, entry);
            m.setTitulo(entry);

            baseMusicas->remover(m);
            cout << "\nMúsica removida!\n\n";
            break;
        case 3:
            //No<Musica> *itr = baseMusicas->getCabeca();
            //while (itr != nullptr)
            //{
            //  Musica m2 = itr->getValor();
            //  cout << "Música: " << m2.getTitulo() << endl;
            //  cout << "Artista: " << m2.getArtista() << endl;

            //    itr = itr->getProximo();
            //}
            //cout << endl;
            break;
        case 4:
        default:
            return;
        }
    }
}

void menuPlaylists(Lista<Playlist> *basePlaylists)
{

    // IMPLEMENTAR

    return;
}