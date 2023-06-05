#include "utilities.hpp"

#include <iostream>

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

    Playlist play = p->getValor();
    bool sair = false;

    while (!sair)
    {

      int acao2 = -1;

      cout << "\nGERENCIAR PLAYLIST: " << play.getNome() << endl;
      cout << "1 - Adicionar música\n2 - Remover música\n3 - Listar músicas\n4 - Sair\n";
      cout << "Digite a opção da sua ação: ";
      tratarAcao(&acao2);
      if (acao2 == -1)
      {
        continue;
      }

      switch (acao2)
      {
        // Adicionar música
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

        Lista<Musica> *musicas = play.getMusicas();
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

        if (musicas->buscar(musicaEscolhida->getValor()) != nullptr)
        {
          cout << "\nMúsica já existente na Playlist!\n\n";
          break;
        }

        musicas->inserir(musicaEscolhida->getValor());
        cout << "\nMúsica Cadastrada!\n\n";
        break;
      }
      // Remover músicas
      case 2:
      {
        int acao3 = -1;
        menuListagemMusicas(play.getMusicas());

        cout << "Digite o número da música: " << endl;
        tratarAcao(&acao3);
        if (acao3 == -1)
        {
          continue;
        }

        Lista<Musica> *musicas = play.getMusicas();
        No<Musica> *musicaEscolhida = musicas->getCabeca();

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

        play.remMusica(musicaEscolhida->getValor());
        cout << "\nMúsica Removida!\n\n";
        break;
      }
      // Listar músicas
      case 3:
      {
        menuListagemMusicas(play.getMusicas());
        break;
      }
      // Sair
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