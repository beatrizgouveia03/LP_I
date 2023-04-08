#include <cstring>
#include <sstream>
#include <iostream>

#include <Zoo.h>
#include <Animal.h>

template <typename T>
void tratarEntrada(T &var)
{
    std::string entrada;
    getline(std::cin, entrada);
    std::istringstream ss(entrada);

    ss >> var;

    return;
}

Zoo configuraçãoInicial()
{
    std::vector<Animal> animais;
    std::string nome[] = {"Ana", "Marco", "Polo", "Rico", "Lissandra", "Melissa"};
    std::vector<std::string> especie = {"Macaco", "Cobra", "Tartaruga"};
    int idade[] = {5, 10, 26, 30, 50, 70};

    for (int i = 0; i < 3; ++i)
    {
        Animal entrada(nome[i], especie[i], idade[i]);

        animais.push_back(entrada);

        entrada.setNome(nome[5 - i]);
        entrada.setEspecie(especie[2 - i]);
        entrada.setIdade(idade[5 - i]);

        animais.push_back(entrada);
    }

    Zoo base(animais, especie);

    return base;
}

void adicionarAnimal(Zoo *base)
{
    std::string entrada;
    Animal novo;
    bool achei = false;
    int idade;

    std::cout << "Informe o nome do animal:\n";
    tratarEntrada(entrada);
    novo.setNome(entrada);

    std::cout << "Informe a espécie do animal:\n";
    for (auto e : base->getEspecies())
    {
        std::cout << " *"<< e << std::endl;
    }
    tratarEntrada(entrada);
    novo.setEspecie(entrada);

    std::cout << "Informe a idade do animal:\n";
    tratarEntrada(idade);
    novo.setIdade(idade);

    base->cadastrarAnimal(novo);
    std::string especie = novo.getEspecie();

    for (auto e : base->getEspecies())
    {
        if (!strcmp(e.c_str(), especie.c_str()))
        {
            achei = true;
            break;
        }
    }

    if (!achei)
    {
        base->cadastrarEspecie(especie);
    }

    std::cout << "Animal cadastrado!\n\n";

    return;
}

void pesquisarEspecie(Zoo base)
{
    std::string especie;

    std::cout << "Digite o nome da espécie:\n";
    for (auto e : base.getEspecies())
    {
        std::cout << " *" << e << std::endl;
    }

    tratarEntrada(especie);

    std::cout << std::endl;

    for (Animal a : base.getAnimais())
    {
        std::string esp = a.getEspecie();
        if (!strcmp(esp.c_str(), especie.c_str()))
        {
            std::cout << "Nome: " << a.getNome() << std::endl;
            std::cout << "Idade: " << a.getIdade() << "\n\n";
        }
    }

    std::cout << std::endl;

    return;
}

void removerIdade(Zoo *base)
{
    int idade;
    std::vector<Animal> novo, animais = base->getAnimais();

    std::cout << "Informe a idade mínima para os animais que serão retirados:\n";
    tratarEntrada(idade);

    for (Animal a :animais)
    {
        int id = a.getIdade();

        if (id >= idade) {   continue;}

        novo.push_back(a);
    }

    base->setAnimais(novo);

    std::cout << "Operação concluída!!\n\n";

    return;
}

void listarAnimais(Zoo base)
{
    std::vector<Animal> animais = base.getAnimais();

    for (Animal a : animais)
    {
        std::cout << a;
        std::cout << std::endl;
    }

    std::cout << std::endl;

    return;
}