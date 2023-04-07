#include <vector>
#include <iostream>

#include <Zoo.h>
#include <Animal.h>

Zoo::Zoo(){};

Zoo::Zoo(std::vector<Animal> animais, std::vector<std::string> especies)
{
    this->animais = animais;
    this->especies = especies;
}

void Zoo::setAnimais(std::vector<Animal> animais)
{
    this->animais = animais;
}

void Zoo::setespecies(std::vector<std::string> especies)
{
    this->especies = especies;
}

void Zoo::cadastrarAnimal(Animal animal)
{
    this->animais.push_back(animal);
}

void Zoo::cadastrarEspecie(std::string especie)
{
    this->especies.push_back(especie);
}

std::vector<std::string> Zoo::getEspecies()
{
    return this->especies;
}

std::vector<Animal> Zoo::getAnimais()
{
    return this->animais;
}

void Zoo::retirarAnimal(std::vector<Animal>::iterator animal)
{
    this->animais.erase(animal);
}
