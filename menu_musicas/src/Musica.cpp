#include <Musica.hpp>

Musica::Musica(){

}

Musica::Musica(string titulo, string artista){
    this->titulo = titulo;
    this->artista = artista;
}

void Musica::setTitulo(string titulo){
    this->titulo = titulo;
}

void Musica::setArtista(string artista){
    this->artista = artista;
}

string Musica::getTitulo(){
    return this->titulo;
}

string Musica::getArtista(){
    return this->artista;
}



