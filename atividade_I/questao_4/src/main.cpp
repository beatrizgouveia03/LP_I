#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <Pessoa.h>

template <typename T>
T comparar(T &p1, T &p2){
    return (p1 > p2 ? p1: p2);
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
            p.getDados();
        }
    }

    return;
}

void compararPessoas(std::vector<Pessoa> base)
{
    std::string entry, pessoa;
    int acao, p1, p2, n = 1;

    std::cout << "Informe o método de comparação: (1 - Nome, 2 - Idade, 3 - Altura, 4 - Pessoa)\n";
    getline(std::cin, entry);
    std::istringstream ss(entry);

    ss >> acao;

    std::cout << "Escolha as duas pessoas a serem comparadas: \n";
    for (Pessoa p : base)
    {
        std::cout << n << " - " << p.getNome() << std::endl;
    }
    getline(std::cin, entry);
    std::istringstream ss(entry);

    ss >> p1 >> p2;

    auto pi = *(base.begin()+p1), pf = *(base.begin()+p2);

    switch (acao)
    {
    case 1:
        std::cout << "O maior é " << comparar(pi.getNome(), pf.getNome()) << std::endl;
        break;
    case 2:
        std::cout << "O maior é " << comparar(pi.getIdade(), pf.getIdade()) << std::endl;
        break;
    case 3:
        std::cout << "O maior é " << comparar(pi.getAltura(), pf.getAltura()) << std::endl;
        break;
    case 4:
        std::cout << "O maior é " << comparar(pi, pf) << std::endl;
        break;
    default:
        break;
    }

    return;
}

void imprimirPessoa(std::vector<Pessoa> base) {
    std::string entry;

    std::cout << "Informe o nome da pessoa: \n";
    getline(std::cin, entry);

    for(Pessoa p : base) {
        std::string nome = p.getNome();
        if(!strcmp(nome.c_str(), entry.c_str())){
        std::cout << p << std::endl;
       }
    }
}

int main()
{
    std::vector<Pessoa> pessoas;
    std::string entrada;
    bool fim = false;
    int acao;

    pessoas = configuracaoInicial();

    while (!fim)
    {
        std::cout << "Escolha uma acao: \n 1-Cadastrar nova pessoa\n 2-Obter info de uma pessoa\n 3-Comparar pessoas\n 4-Imprimir pessoa\n 5-Sair\n";
        getline(std::cin, entrada);

        std::istringstream ss(entrada);
        ss >> acao;

        switch (acao)
        {
        case 1:
            cadastrarPessoa(&pessoas);
            break;
        case 2:
            obterInfo(pessoas);
            break;
        case 3:
            compararPessoas(pessoas);
            break;
        case 4:
            imprimirPessoa(pessoas);
            break;
        case 5:
        default:
            fim = true;
            break;
        }
    }

    return 0;
}