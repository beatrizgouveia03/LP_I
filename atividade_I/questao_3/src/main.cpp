#include <iostream>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <Livro.h>

void cadastrarLivro(std::vector<Livro> *base)
{
    std::string entrada, lixo;
    std::vector<double> notas;
    double nota;
    Livro novo;

    std::cout << "Informe o título do livro: \n";
    getline(std::cin, entrada);

    for (Livro l : *base)
    {
        std::string titulo = l.getTitulo();

        if (!strcmp(entrada.c_str(), titulo.c_str()))
        {
            std::cout << "Livro já cadastrado nessa biblioteca!!!\n\n";
            return;
        }
    }

    novo.setTitulo(entrada);

    std::cout << "Informe o autor desse livro: \n";
    getline(std::cin, entrada);
    novo.setAutor(entrada);

    std::cout << "Informe as notas de avaliação desse livro:(Escreva todas em uma linha separadas por um espaço) \n";
    getline(std::cin, entrada);
    std::istringstream ss(entrada);
    while (ss >> nota)
    {
        notas.push_back(nota);
    }
    novo.setNotas(notas);

    base->push_back(novo);
    std::cout << "Livro cadastrado!\n\n";

    return;
}

void obterInfo(std::vector<Livro> base)
{
    int livro, n = 1;
    std::string entrada;

    std::cout << "Escolha o livro: \n";
    if (base.size() == 0)
    {
        std::cout << "Biblioteca vazia.\n";
        return;
    }
    for (Livro l : base)
    {
        std::cout << n << " - " << l.getTitulo() << std::endl;
        n++;
    }

    getline(std::cin, entrada);
    std::istringstream ss(entrada);
    ss >> livro;

    std::vector<Livro>::iterator ind = base.begin() + (livro - 1);

    if (ind >= base.end())
    {
        std::cout << "Opção escolhida inválida\n\n";
        return;
    }

    std::cout << std::endl;
    std::cout << "Título: " << ind->getTitulo() << std::endl;
    std::cout << "Autor: " << ind->getAutor() << std::endl;
    std::cout << "Média das avaliações: " << std::fixed << std::setprecision(1) << ind->getMedia() << std::endl;
    std::cout << std::endl;

    return;
}

void mediaGeral(std::vector<Livro> base)
{
    double media_geral = 0;

    for (Livro l : base)
    {
        media_geral += l.getMedia();
    }

    media_geral /= base.size();

    std::cout << "A média de todas as avaliações de livros dessa biblioteca é: " << std::fixed << std::setprecision(1) << media_geral << "\n\n";
}

int main()
{
    int acao;
    std::string entrada;
    bool fim = false;
    std::vector<Livro> Biblioteca;

    while (!fim)
    {
        std::cout << "Escolha uma acao: \n 1-Criar livro\n 2-Obter info de um livro\n 3-Obter média geral\n 4-Sair\n";
        getline(std::cin, entrada);

        std::cout << entrada;

        std::istringstream ss(entrada);
        ss >> acao;

        switch (acao)
        {
        case 1:
            cadastrarLivro(&Biblioteca);
            break;
        case 2:
            obterInfo(Biblioteca);
            break;
        case 3:
            mediaGeral(Biblioteca);
            break;
        case 4:
            fim = true;
            break;
        default:
            fim = true;
            break;
        }
    }

    return 0;
}