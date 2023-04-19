#include "Playlist.hpp"

Playlist::Playlist(){}

Playlist::Playlist(string nome, Lista<Musica> musicas) {
    this->nome = nome;
    this->musicas = musicas;
}

Playlist::~Playlist(){}

void Playlist::setNome(string nome){
    this->nome = nome;
}

void Playlist::setMusicas(Lista<Musica> musicas){
    this->musicas = musicas;
}

string Playlist::getNome(){
    return this->nome;
}

Lista<Musica> Playlist::getMusicas(){
    return this->musicas;
}

void Playlist::addMusica(Musica m)
{
    this->musicas.inserir(m);
}

void Playlist::remMusica(Musica m){
   this->musicas.remover(m);
}

No<Musica>* Playlist::findMusica(Musica m){
    auto begin = this->musicas.getCauda();
    auto end = this->musicas.getCabeca();

    while(begin != end){
        if(begin->getValor().getTitulo() == m.getTitulo()){
            return begin;
        }
        begin = begin->getProximo();
    }

    return nullptr;
}