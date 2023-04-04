#include <Livro.h>

Livro::Livro(){};

Livro::Livro(std::string titulo, std::string autor, std::vector<double> notas)
{
    this->titulo = titulo;
    this->autor = autor;
    this->notas = notas;
}

void Livro::setTitulo(std::string titulo) {
    this->titulo = titulo;
}

void Livro::setAutor(std::string autor) {
    this->autor = autor;
}

void Livro::setNotas(std::vector<double> notas) {
    this->notas = notas;
}

std::string Livro::getTitulo() {
    return this->titulo;
}

std::string Livro::getAutor() {
    return this->autor;
}

double Livro::getMedia() {
    double media = 0;

    for(double n : this->notas) {
        media += n;
    }

    media /= this->notas.size();

    return media;
}