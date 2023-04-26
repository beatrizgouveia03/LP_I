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

            if (baseMusicas->buscar(m) != nullptr)
            {
                cout << "\nMúsica já existe na lista!\n";
                break;
            }

            baseMusicas->inserir(m);
            cout << "\nMúsica Cadastrada!\n\n";

            break;
        case 2:
            cout << "Digite o nome da música a ser removida: ";
            getline(cin, entry);
            m.setTitulo(entry);

            if (baseMusicas->buscar(m) != nullptr)
            {
                baseMusicas->remover(m);
                cout << "\nMúsica removida!\n\n";
                break;
            }
            cout << "/nMúsica não encontrada!\n\n";
            break;
        case 3:
        {
            menuListagemMusicas(baseMusicas);
            break;
        }
        case 4:
            return;
        default:
            cout << "Opção inválida!\n";
            break;
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

            if (basePlaylists->buscar(p) != nullptr)
            {
                basePlaylists->inserir(p);
                cout << "\nPlaylist Cadastrada!\n\n";
                break;
            }
            cout << "\nPlaylist já existente\n\n";
            break;
        case 2:
            cout << "Digite o nome da playlist a ser removida: ";
            getline(cin, entry);
            p.setNome(entry);

            if (basePlaylists->buscar(p) != nullptr)
            {
                basePlaylists->remover(p);
                cout << "\nPlaylist removida!\n\n";
            }
            cout << "\nPlaylist não encontrada\n\n";
            break;
        case 3:
        {
            menuListagemPlaylists(basePlaylists);
            break;
        }
        case 4:
            return;
        default:
            cout << "Opção inválida!\n";
            break;
        }
    }
}

void menuListagemMusicas(Lista<Musica> *baseMusicas)
{
    cout << "\nLISTAGEM DE MÚSICAS\n\n";

    No<Musica> *itr = baseMusicas->getCabeca();

    int count = 1;
    while (itr != nullptr)
    {
        Musica m = itr->getValor();
        cout << "[" << count << "] " << m;

        itr = itr->getProximo();
        count++;
    }
    cout << endl;

    return;
}

void menuListagemPlaylists(Lista<Playlist> *basePlaylists)
{
    cout << "\nLISTAGEM DE PLAYLISTS\n";

    No<Playlist> *itr = basePlaylists->getCabeca();

    int count = 1;
    while (itr != nullptr)
    {
        Playlist p = itr->getValor();

        cout << p << endl;

        itr = itr->getProximo();
        count++;
    }
    cout << endl;

    return;
}

void menuMusicasEmPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        string playlist;

        menuListagemPlaylists(basePlaylists);

        cout << "Digite o número da playlist: " << endl;
        getline(cin, playlist);
        int acao = stoi(playlist);

        No<Playlist> *p = basePlaylists->getCabeca();

        while (acao > 1)
        {
            p = p->getProximo();
            acao--;
        }

        int acao2;
        string entry;

        cout << "\nGERENCIAR PLAYLIST: " << p->getValor().getNome() << endl;
        cout << "1 - Adicionar música\n2 - Remover música\n3 - Listar músicas\n4 - Sair\n";
        cout << "Digite a sua ação: ";

        cin >> acao2;
        getline(cin, entry);

        switch (acao2)
        {
        case 1:
        {
            string musica;
            menuListagemMusicas(baseMusicas);

            cout << "Digite o número da música: " << endl;
            getline(cin, musica);
            acao = stoi(musica);

            No<Musica> *musicaEscolhida = baseMusicas->getCabeca();

            while (acao > 1)
            {
                musicaEscolhida = musicaEscolhida->getProximo();
                acao--;
            }

            if (p->getValor().getMusicas()->buscar(musicaEscolhida->getValor()) != nullptr)
            {
                cout << "\nMúsica já existente na Playlist!\n\n";
                break;
            }

            p->getValor().getMusicas()->inserir(musicaEscolhida->getValor());
            cout << "\nMúsica Cadastrada!\n\n";
            break;
        }
        case 2:
        {
            string musica;
            menuListagemMusicas(baseMusicas);

            cout << "Digite o número da música: " << endl;
            getline(cin, musica);
            acao = stoi(musica);

            No<Musica> *musicaEscolhida = baseMusicas->getCabeca();

            while (acao > 1)
            {
                musicaEscolhida = musicaEscolhida->getProximo();
                acao--;
            }

            if (p->getValor().getMusicas()->buscar(musicaEscolhida->getValor()) != nullptr)
            {
                p->getValor().getMusicas()->remover(musicaEscolhida->getValor());
                cout << "\nMúsica Removida!\n\n";
                break;
            }
            cout << "\nMúsica não localizada na Playlist!\n\n";
            break;
        }
        case 3:
            menuListagemMusicas(p->getValor().getMusicas());
            break;
        case 4:
            return;
        default:
            cout << "Opção inválida!\n";
            break;
        }
    }
}