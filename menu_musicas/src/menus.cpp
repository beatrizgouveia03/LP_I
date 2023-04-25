#include "utilities.hpp"

#include <iostream>

void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        int acao;
        string entry;

        cout << "\nMENU PRICIPAL\n";
        cout << "1 - Gerenciar Músicas\n2 - Gerenciar Playlists\n3 - Gerenciar Músicas em Playlists\n4 - Sair\n";
        cout << "Digite a sua ação: ";

        cin >> acao;
        getline(cin, entry);

        switch (acao)
        {
        case 1:
            menuMusicas(baseMusicas);
            break;
        case 2:
            menuPlaylists(basePlaylists);
            break;
        case 3:
            menuMusicasEmPlaylists(baseMusicas, basePlaylists);
            break;
        case 4:
            return;
        default:
            cout << "Opção inválida\n\n";
            break;
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
        getline(cin, entry);

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
        {
            menuListagemMusicas(baseMusicas);
        }
        default:
            return;
        }
    }
}

void menuPlaylists(Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        int acao;
        Playlist p;
        string entry;

        cout << "\nMENU PLAYLISTS\n";
        cout << "1 - Adicionar playlist\n2 - Remover playlist\n3 - Listar playlists\n4 - Sair\n";
        cout << "Digite a sua ação: ";

        cin >> acao;
        getline(cin, entry);

        switch (acao)
        {
        case 1:
            cout << "Digite o nome da playlist: ";
            getline(cin, entry);
            p.setNome(entry);

            basePlaylists->inserir(p);
            cout << "\nPlaylist Cadastrada!\n\n";
            break;
        case 2:
            cout << "Digite o nome da playlist a ser removida: ";
            getline(cin, entry);
            p.setNome(entry);

            basePlaylists->remover(p);
            cout << "\nPlaylist removida!\n\n";
            break;
        case 3:
        {
            menuListagemPlaylists(basePlaylists);
            break;
        }
        default:
            return;
        }
    }
}

No<Musica> *menuListagemMusicas(Lista<Musica> *baseMusicas)
{
    int acao;
    string entry;

    cout << "\nLISTAGEM DE MÚSICAS\n\n";

    No<Musica> *itr = baseMusicas->getCabeca();

    int count = 1;
    while (itr != nullptr)
    {
        Musica m = itr->getValor();
        cout << "[" << count << "] " << m << endl;

        itr = itr->getProximo();
        count++;
    }
    cout << endl;

    cout << "Digite o número da música: " << endl;
    getline(cin, entry);
    acao = stoi(entry);

    No<Musica> *m = baseMusicas->getCabeca();

    while (acao > 1)
    {
        m = m->getProximo();
        acao--;
    }

    return m;
}

No<Playlist> *menuListagemPlaylists(Lista<Playlist> *basePlaylists)
{
    int acao;
    string entry;

    cout << "\nLISTAGEM DE PLAYLISTS\n";

    No<Playlist> *itr = basePlaylists->getCabeca();

    int count = 1;
    while (itr != nullptr)
    {
        Playlist p2 = itr->getValor();
        cout << "Playlist " << count << ": " << p2.getNome() << endl;

        itr = itr->getProximo();
        count++;
    }
    cout << endl;

    cout << "Digite o número da playlist: " << endl;
    getline(cin, entry);
    acao = stoi(entry);

    No<Playlist> *p = basePlaylists->getCabeca();

    while (acao > 1)
    {
        p = p->getProximo();
        acao--;
    }

    return p;
}

void menuMusicasEmPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        No<Playlist> *p = menuListagemPlaylists(basePlaylists);

        int acao;
        string entry;

        cout << "\nGERENCIAR PLAYLIST: " << p->getValor().getNome() << endl;
        cout << "1 - Adicionar música\n2 - Remover música\n3 - Listar músicas\n4 - Sair\n";
        cout << "Digite a sua ação: ";

        cin >> acao;
        getline(cin, entry);

        switch (acao)
        {
        case 1:
        {
            No<Musica> *musicaEscolhida = menuListagemMusicas(baseMusicas);

            p->getValor().getMusicas()->inserir(musicaEscolhida->getValor());
            cout << "\nMúsica adicionada!\n\n";
            break;
        }
        case 2:
        {
            No<Musica> *musicaEscolhida = menuListagemMusicas(baseMusicas);

            p->getValor().getMusicas()->remover(musicaEscolhida->getValor());
            cout << "\nMúsica removida!\n\n";
            break;
        }
        case 3:
            // implementar
        default:
            return;
        }
    }
}