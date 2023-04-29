#include "utilities.hpp"

#include <iostream>

void menuPrincipal(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        int acao = -1;

        cout << "\nMENU PRICIPAL\n";
        cout << "1 - Gerenciar Músicas\n2 - Gerenciar Playlists\n3 - Gerenciar Músicas em Playlists\n4 - Tocar músicas\n5 - Sair\n";
        cout << "Digite a opção da sua ação: ";
        tratarAcao(&acao);
        if (acao == -1)
        {
            continue;
        }

        switch (acao)
        {
        case 1:
            menuMusicas(baseMusicas, basePlaylists);
            break;
        case 2:
            menuPlaylists(baseMusicas, basePlaylists);
            break;
        case 3:
            menuMusicasEmPlaylists(baseMusicas, basePlaylists);
            break;
        case 4:
            menuTocarMusicas(baseMusicas, basePlaylists);
            break;
        case 5:
            return;
        default:
            cout << "Opção inválida\n\n";
            break;
        }
    }
}

void menuMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylist)
{
    while (true)
    {
        int acao = -1;
        string entry;
        Musica m;

        cout << "\nMENU MÚSICAS\n";
        cout << "1 - Adicionar música\n2 - Remover música\n3 - Listar músicas\n4 - Sair\n";
        cout << "Digite a opção da sua ação: ";
        tratarAcao(&acao);
        if (acao == -1)
        {
            continue;
        }

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
        {
            int acao2 = -1;
            menuListagemMusicas(baseMusicas);

            cout << "Digite o número da música: " << endl;
            tratarAcao(&acao2);
            if (acao2 == -1)
            {
                continue;
            }

            No<Musica> *m = baseMusicas->getCabeca();

            while (acao2 > 1)
            {
                m = m->getProximo();
                if (m == nullptr)
                {
                    cout << "\nNão existe nenhuma música com este número!\n\n";
                    return;
                }
                acao2--;
            }

            No<Playlist> *p = basePlaylist->getCabeca();

            while (p != nullptr)
            {
                Playlist p2 = p->getValor();

                if (p2.findMusica(m->getValor()) != nullptr)
                {
                    p->getValor().remMusica(m->getValor());
                }
                p = p->getProximo();
            }

            baseMusicas->remover(m->getValor());

            cout << "\nMúsica removida!\n\n";
            break;
        }
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

void menuPlaylists(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        string entry;
        int acao = -1;
        Playlist p;

        cout << "\nMENU PLAYLISTS\n";
        cout << "1 - Adicionar playlist\n2 - Remover playlist\n3 - Listar playlists\n4 - Gerenciar Músicas em Playlists\n5 - Sair\n";
        cout << "Digite a opção da sua ação: ";
        tratarAcao(&acao);
        if (acao == -1)
        {
            continue;
        }

        switch (acao)
        {
        case 1:
            cout << "Digite o nome da playlist: ";
            getline(cin, entry);
            p.setNome(entry);

            if (basePlaylists->buscar(p) != nullptr)
            {
                cout << "\nPlaylist já existente!\n\n";
                break;
            }
            basePlaylists->inserir(p);
            cout << "\nPlaylist Cadastrada!\n\n";
            break;
        case 2:
        {
            int acao2 = -1;

            menuListagemPlaylists(basePlaylists);
            cout << "Digite o número da playlist a ser removida: ";
            tratarAcao(&acao2);
            if (acao2 == -1)
            {
                continue;
            }

            No<Playlist> *p2 = basePlaylists->getCabeca();

            while (acao2 > 1)
            {
                p2 = p2->getProximo();
                if (p2 == nullptr)
                {
                    cout << "\nNão existe nenhuma playlist com este número!\n\n";
                    return;
                }
                acao--;
            }

            basePlaylists->remover(p2->getValor());
            cout << "\nPlaylist removida!\n\n";
            break;
        }
        case 3:
        {
            menuListagemPlaylists(basePlaylists);
            break;
        }
        case 4:
            menuMusicasEmPlaylists(baseMusicas, basePlaylists);
            break;
        case 5:
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

        cout << "-- " << count << " --\n"
             << p << endl;

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
        int acao = -1;

        menuListagemPlaylists(basePlaylists);

        cout << "Digite o número da playlist: (digite 0 para sair) " << endl;
        tratarAcao(&acao);
        if (acao == -1)
        {
            continue;
        }
        else if (acao == 0)
        {
            return;
        }

        No<Playlist> *p = basePlaylists->getCabeca();

        while (acao > 1)
        {
            p = p->getProximo();
            if (p == nullptr)
            {
                cout << "\nNão existe nenhuma playlist com este número!\n\n";
                return;
            }
            acao--;
        }

        bool sair = false;

        while (!sair)
        {

            int acao2 = -1;

            cout << "\nGERENCIAR PLAYLIST: " << p->getValor().getNome() << endl;
            cout << "1 - Adicionar música\n2 - Remover música\n3 - Listar músicas\n4 - Sair\n";
            cout << "Digite a opção da sua ação: ";
            tratarAcao(&acao2);
            if (acao2 == -1)
            {
                continue;
            }

            switch (acao2)
            {
            case 1:
            {
                int acao3 = -1;
                menuListagemMusicas(baseMusicas);

                cout << "Digite o número da música: " << endl;
                tratarAcao(&acao3);
                if (acao3 == -1)
                {
                    continue;
                }

                No<Musica> *musicaEscolhida = baseMusicas->getCabeca();

                while (acao3 > 1)
                {
                    musicaEscolhida = musicaEscolhida->getProximo();
                    if (musicaEscolhida == nullptr)
                    {
                        cout << "\nNão existe nenhuma música com este número!\n\n";
                        return;
                    }
                    acao3--;
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
                int acao = -1;
                menuListagemMusicas(baseMusicas);

                cout << "Digite o número da música: " << endl;
                tratarAcao(&acao);
                if (acao == -1)
                {
                    continue;
                }

                No<Musica> *musicaEscolhida = baseMusicas->getCabeca();

                while (acao > 1)
                {
                    musicaEscolhida = musicaEscolhida->getProximo();
                    if (musicaEscolhida == nullptr)
                    {
                        cout << "\nNão existe nenhuma música com este número!\n\n";
                        return;
                    }
                    acao--;
                }

                if (p->getValor().findMusica(musicaEscolhida->getValor()) != nullptr)
                {
                    p->getValor().remMusica(musicaEscolhida->getValor());
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
                sair = true;
                return;
            default:
                cout << "Opção inválida!\n";
                break;
            }
        }
    }
}

void menuTocarMusicas(Lista<Musica> *baseMusicas, Lista<Playlist> *basePlaylists)
{
    while (true)
    {
        int acao = -1;

        menuListagemPlaylists(basePlaylists);

        cout << "Digite o número da playlist: (digite 0 para sair) " << endl;
        tratarAcao(&acao);
        if (acao == -1)
        {
            continue;
        }
        else if (acao == 0)
        {
            return;
        }

        No<Playlist> *p = basePlaylists->getCabeca();

        while (acao > 1)
        {
            p = p->getProximo();
            if (p == nullptr)
            {
                cout << "\nNão existe nenhuma playlist com este número!\n\n";
                return;
            }
            acao--;
        }

        bool sair = false;

        int indiceMusica = 0;

        while (indiceMusica < p->getValor().getMusicas()->tamanho())
        {

            Musica musicaAtual = p->getValor().getMusicas()->buscarPorIndice(indiceMusica)->getValor();

            cout << "\nTocando: " << musicaAtual.getArtista() << " - " << musicaAtual.getTitulo() << endl;
            if (indiceMusica < p->getValor().getMusicas()->tamanho() - 1)
                cout << "1 - Próxima" << endl;
            if (indiceMusica > 0)
                cout << "2 - Anterior" << endl;
            cout << "Para sair, digite 0" << endl;
            cout << "Digite a opção da sua ação: ";
            tratarAcao(&acao);
            if (acao == -1)
            {
                continue;
            }
            else if (acao == 1 && indiceMusica == p->getValor().getMusicas()->tamanho() - 1)
            {
                acao = 3;
            }
            else if (acao == 2 && indiceMusica == 0)
            {
                acao = 3;
            }

            switch (acao)
            {
            case 1:
                indiceMusica++;
                break;
            case 2:
                indiceMusica--;
                break;
            case 0:
                sair = true;
                return;
            default:
                cout << "Opção inválida!\n";
                break;
            }
        }
    }
}