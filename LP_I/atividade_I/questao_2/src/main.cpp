#include <iostream>
#include <vector>
#include <string>
#include <Zoo.h>
#include <Animal.h>

int main() {
    Zoo z1;
    std::vector<Animal> animais;
    std::string nome[] = {"Ana", "Marco", "Polo", "Rico", "Lissandra", "Melissa"};
    std::string especie[] = {"Macaco", "Cobra", "Tartaruga"};
    int idade[] = { 5, 10, 26, 30, 50, 70};

    for(int i=0; i<3; ++i) {
        Animal entrada(nome[i], especie[i], idade[i]);

        animais.push_back(entrada);

        entrada.setNome(nome[5-i]);
        entrada.setEspecie(especie[3-i]);
        entrada.setIdade(idade[5-i]);

        animais.push_back(entrada);
    }

    z1.setAnimais(animais);

    for( auto e : especie) {
        std::cout << e << std::endl;
        z1.getEspecie(e);
        std::cout << std::endl;
    }




    return 0;
}