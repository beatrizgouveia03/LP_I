#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>

#include <Pessoa.h>

template <typename T>
T comparar(T p1, T p2)
{
    return (p1 > p2 ? p1 : p2);
}

std::vector<Pessoa> configuracaoInicial()
{
    std::vector<Pessoa> base;
    std::string nome[] = {"Emanuel Silva", "Beatriz Pereira", "Andre Augusto"};
    int idade[] = {15, 27, 35};
    double altura[] = {1.75, 1.62, 1.87};

    for (int i = 0; i < 3; ++i)
    {
        Pessoa novo(nome[i], idade[i], altura[i]);
        base.push_back(novo);
    }

    return base;
}

void cadastrarPessoa(std::vector<Pessoa> *base)
{
    Pessoa novo;
    std::string entrada;
    int idade;
    double altura;

    for (Pessoa p : *base)
    {
        std::string nome = p.getNome();
        if (!strcmp(entrada.c_str(), nome.c_str()))
        {
            std::cout << "Pessoa já cadastrada no sistema!!!\n";
            return;
        }
    }

    std::cout << "Informe o nome da pessoa:\n";
    getline(std::cin, entrada);
    novo.setNome(entrada);

    std::cout << "Informe a idade da pessoa:\n";
    std::cin >> idade;
    novo.setIdade(idade);

    std::cout << "Informe a altura da pessoa:\n";
    std::cin >> altura;
    novo.setAltura(altura);

    getline(std::cin, entrada);

    base->push_back(novo);
    std::cout << "Pessoa cadastrada!\n\n";

    return;
}

void obterInfo(std::vector<Pessoa> base)
{
    std::string entry;

    std::cout << "Informe o nome da pessoa: \n";
    getline(std::cin, entry);

    for (Pessoa p : base)
    {
        std::string nome = p.getNome();
        if (!strcmp(nome.c_str(), entry.c_str()))
        {
            std::cout << p << std::endl;
        }
    }
}

void compararPessoas(std::vector<Pessoa> base)
{
    std::string entry, pessoa;
    int acao, p1, p2, n = 1;

    std::cout << "Informe o método de comparação: (1 - Nome, 2 - Idade, 3 - Altura, 4 - Pessoa)\n";
    getline(std::cin, entry);
    std::istringstream sc(entry);

    sc >> acao;

    std::cout << "Escolha as duas pessoas a serem comparadas: \n";
    for (Pessoa p : base)
    {
        std::cout << n << " - " << p.getNome() << std::endl;
        n++;
    }
    getline(std::cin, entry);
    std::istringstream ss(entry);

    ss >> p1 >> p2;

    Pessoa pi = *(base.begin() + p1 - 1), pf = *(base.begin() + p2 - 1);
    Pessoa m;

    switch (acao)
    {
    case 1:
        std::cout << "O maior é " << comparar(pi.getNome(), pf.getNome()) << "\n\n";
        break;
    case 2:
        std::cout << "O maior é " << comparar(pi.getIdade(), pf.getIdade()) << "\n\n";
        break;
    case 3:
        std::cout << "O maior é " << comparar(pi.getAltura(), pf.getAltura()) << "\n\n";
        break;
    case 4:
        m = comparar(pi, pf);
        std::cout << "O maior é \n " << m << "\n\n";
        break;
    default:
        break;
    }

    return;
}