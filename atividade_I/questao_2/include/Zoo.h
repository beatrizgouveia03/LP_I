#ifndef ZOO_H
#define ZOO_H

#include <Animal.h>

class Zoo
{
private:
  std::vector<Animal> animais;
  std::vector<std::string> especies;

 public:
    Zoo();
    Zoo(std::vector<Animal> animais, std::vector<std::string> especies);

    void setAnimais(std::vector<Animal> animais);
    void setespecies(std::vector<std::string> especies);

    void cadastrarAnimal(Animal animal);
    void cadastrarEspecie(std::string especie);

    std::vector<std::string> getEspecies();
    std::vector<Animal> getAnimais();

    void retirarAnimal(std::vector<Animal>::iterator animal);
};

#endif