#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <string>

using namespace std;

class Musica
{
private:
    string titulo;
    string artista;
public:
   Musica();
   Musica(string titulo, string artista);

   void setTitulo(string titulo);
   void setArtista (string artista);

   string getTitulo();
   string getArtista();
};

#endif