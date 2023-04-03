#include <Zoo.h>
#include <Animal.h>
#include <cstring>
#include <iostream>

Zoo::Zoo() {};

Zoo::Zoo(std::vector<Animal> animais) {
    this->animais = animais;
}

void Zoo::setAnimais(std::vector<Animal> animais) {
    this->animais = animais;
}

void Zoo::getEspecie(std::string especie) {
    for(auto a : this->animais) {
        auto esp = a.getEspecie();
        if(!strcmp(especie.c_str(), esp.c_str())){
            std::cout << a.getNome() << " " << a.getIdade() << std::endl;
        }
    }
}

std::vector<Animal> Zoo::getAnimais() {
    return this->animais;
}
