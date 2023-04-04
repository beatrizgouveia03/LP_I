#ifndef LIVRO_H
#define LIVRO_H

#include <vector>
#include <string>

class Livro
{
private:
  std::string titulo;
  std::string autor;
  std::vector<double> notas;

public:
    Livro();
    Livro(std::string titulo, std::string autor, std::vector<double> notas);

    void setTitulo(std::string titulo);
    void setAutor(std::string autor);
    void setNotas(std::vector<double> notas);

    std::string getTitulo();
    std::string getAutor();
    double getMedia();
};

#endif