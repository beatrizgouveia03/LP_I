#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include <string>
#include <Animal.h>

class Zoo
{
private:
  std::vector<Animal> animais;
public:
    Zoo();
    Zoo(std::vector<Animal> animais);

    void setAnimais(std::vector<Animal> animais);

    void getEspecie(std::string especie);
    std::vector<Animal> getAnimais();
    
};

#endif