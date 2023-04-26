#include "Playlist.hpp"

#include <ostream>

Playlist::Playlist() {}

Playlist::Playlist(string nome)
{
    this->nome = nome;
}

Playlist::Playlist(string nome, Lista<Musica> *musicas)
{
    this->nome = nome;
    this->musicas = musicas;
}

Playlist::~Playlist() {}

void Playlist::setNome(string nome)
{
    this->nome = nome;
}

void Playlist::setMusicas(Lista<Musica> *musicas)
{
    this->musicas = musicas;
    return;
}

string Playlist::getNome()
{
    return this->nome;
}

Lista<Musica> *Playlist::getMusicas()
{
    return this->musicas;
}

void Playlist::addMusica(Musica *m)
{
    if(musicas == nullptr){
        musicas = new Lista<Musica>(*m);
        return;
    }
    this->musicas->inserir(*m);
    return;
}

void Playlist::remMusica(Musica *m)
{
    this->musicas->remover(*m);
    return;
}

No<Musica> *Playlist::findMusica(Musica *m)
{
    No<Musica> *begin = this->musicas->getCauda();
    No<Musica> *end = this->musicas->getCabeca();

    while (begin != end)
    {
        if (begin->getValor().getTitulo() == m->getTitulo())
        {
            return begin;
        }
        begin = begin->getProximo();
    }

    return nullptr;
}

bool Playlist::operator==(Playlist &playlist)
{
    if (this->getNome() == playlist.getNome())
    {
        return true;
    }

    return false;
}

ostream &operator<<(ostream &cout, Playlist &p)
{
    cout << "Nome: " << p.getNome() << endl;
    cout << "Musicas: " << endl;

    if (p.getMusicas() == nullptr)
    {
        cout << "Nenhuma música encontrada" << endl;
        return cout;
    }

    No<Musica> *itr = p.getMusicas()->getCabeca();
    int count = 1;

    while (itr != nullptr)
    {
        Musica m = itr->getValor();
        cout << "[" << count << "] " << m;

        itr = itr->getProximo();
        count++;
    }

    return cout;
}
