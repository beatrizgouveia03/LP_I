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

Playlist::Playlist(Playlist *playlist)
{
    this->nome = playlist->getNome();
    this->musicas = playlist->getMusicas();
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

void Playlist::addMusica(Playlist musicas)
{
    Lista<Musica> *base = musicas.getMusicas();

    this->musicas->adicionarElementos(base);

    return;
}

void Playlist::remMusica(Musica m)
{
    this->musicas->remover(m);
    return;
}

void Playlist::remMusica(Playlist musicas)
{
    Lista<Musica> *base = musicas.getMusicas();

    this->musicas->removerElementos(base);
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

Lista<Musica> *Playlist::operator+(const Playlist &playlist) const
{
    Lista<Musica> m = new Lista<Musica>(this->musicas);
    m = m + playlist.musicas;

    return &m;
}

Lista<Musica> *Playlist::operator+(const Musica &musica) const{
    Lista<Musica> m = new Lista<Musica>(this->musicas);
    m << musica;

    return &m;
}

Lista<Musica> *Playlist::operator-(const Playlist &playlist) const{
    Lista<Musica> m = new Lista<Musica>(this->musicas);
    m = m - playlist.musicas;

    return &m;
}

Lista<Musica> *Playlist::operator-(const Musica &musica) const{
    Lista<Musica> m = new Lista<Musica>(this->musicas);
    m.remover(musica);

    return &m;
}
void operator<<(Playlist &playlist, Musica &musica){
    *playlist.musicas << musica;
}

void operator>>(Playlist &playlist, Musica &musica){
   Lista<Musica> *base = playlist.getMusicas();

   base->remover(musica);

   playlist.setMusicas(base);
}
