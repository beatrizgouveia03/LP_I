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

void Playlist::addMusica(Musica m)
{
    this->musicas->inserir(m);
    return;
}

void Playlist::addMusica(Playlist musicas){
    auto it = musicas.getMusicas()->getCabeca();

    while(it != musicas.getMusicas()->getCauda()){
        this->musicas->inserir(it->getValor());
        it = it->getProximo();
    }
    return;
}

void Playlist::remMusica(Musica m)
{
    this->musicas->remover(m);
    return;
}

No<Musica> *Playlist::findMusica(Musica m)
{
    return this->musicas->buscar(m);
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

    No<Musica> *itr = p.getMusicas()->getCabeca();

    if (itr == nullptr)
    {
        cout << "Nenhuma música cadastrada!\n";
    }

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
