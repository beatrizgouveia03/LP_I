#include <iostream>
#include <vector>
#include <cstring>
#include <Zoo.h>
#include <Animal.h>


Zoo removerIdade(Zoo entrada, int idade) {
    Zoo novo;
    std::vector<Animal> animais;    
    for( Animal a : entrada.getAnimais()) {
        if(a.getIdade() >= idade){
            continue;
        }
        animais.push_back(a);
    }

    novo.setAnimais(animais);

    return novo;
}

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
        entrada.setEspecie(especie[2-i]);
        entrada.setIdade(idade[5-i]);

        animais.push_back(entrada);
    }

    z1.setAnimais(animais);

    for( auto e : especie) {
        std::cout << e << std::endl;
        z1.getEspecie(e);
        std::cout << std::endl;
    }

    z1 = removerIdade(z1, 40);

    for( Animal a : z1.getAnimais()) {
        std::cout << a.getNome() << " " << a.getEspecie() << " " << a.getIdade() << std::endl;
    }

    return 0;
}