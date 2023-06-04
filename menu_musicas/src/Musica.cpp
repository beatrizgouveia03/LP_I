#include "Musica.hpp"

#include <ostream>

Musica::Musica() {}

Musica::Musica(string t, string a)
{
    titulo = t;
    artista = a;
}

Musica::~Musica() {}

void Musica::setTitulo(string t)
{
    titulo = t;
}

void Musica::setArtista(string a)
{
    artista = a;
}

string Musica::getTitulo() const
{
    return titulo;
}

string Musica::getArtista() const
{
    return artista;
}

bool Musica::operator==(const Musica &musica)
{
    if (titulo == musica.getTitulo())
    {
        return true;
    }

    return false;
}

ostream &operator<<(ostream &cout, const Musica &m)
{
    cout << m.artista << " - " << m.titulo << endl;

    return cout;
}
