#include <Livro.h>

Livro::Livro(){};

Livro::Livro(std::string titulo, std::string autor, std::vector<int> notas)
{
    this->titulo = titulo;
    this->autor = autor;
    this->notas = notas;
}