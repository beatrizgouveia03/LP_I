#include <iostream>

#include <Animal.h>

Animal::Animal() {};

Animal::Animal(std::string nome, std::string especie, int idade) {
    this->nome = nome;
    this->especie = especie;
    this->idade = idade;
}

std::string Animal::getNome() {
    return  this->nome;
}

std::string Animal::getEspecie()
{
    return this->especie;
}

int Animal::getIdade() {
    return this->idade;
}

void Animal::setNome(std::string nome) {
    this->nome = nome;
}

void Animal::setEspecie(std::string especie)
{
    this->especie = especie;
}

void Animal::setIdade(int idade)
{
    this->idade = idade;
}

std::ostream& operator<<(std::ostream &cout, Animal &a)
{
    std::cout << "Nome: " << a.getNome() << std::endl;
    std::cout << "Idade: " << a.getIdade() << std::endl;
    std::cout << "Espécie: " << a.getEspecie() << std::endl;

    return cout;
};