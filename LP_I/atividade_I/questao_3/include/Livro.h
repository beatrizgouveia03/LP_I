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
    Livro(std::string titulo, std::string autor, std::vector<int> notas);

    void setTitulo(std::string titulo);
    void setAutor(std::string autor);
    void setNotas(std::vector<int> notas);
    
    double getMediadasNotas();

};

#endif