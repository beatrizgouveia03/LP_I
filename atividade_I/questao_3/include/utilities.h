#include <iomanip>
#include <cstring>
#include <sstream>
#include <iostream>

#include <Livro.h>

template <typename T>
void tratarEntrada(T &var)
{
    std::string entrada;
    getline(std::cin, entrada);
    std::istringstream ss(entrada);

    ss >> var;

    return;
}

std::vector<Livro> configuracaoInicial() {
    std::vector<Livro> base;
    std::string livros[] = {"1984", "O Senhor dos Anéis", "A Culpa é das Estrelas", "A Revolução dos Bichos", "Dom Casmurro"};
    std::string autores[] = {"George Orwell", "J.R.R. Tolkien", "John Green", "George Orwell", "Machado de Assis"};
    std::vector<std::vector<double>>  notas = {{4.5, 6.5, 7}, {7.6, 8.4, 5.3}, {8.7, 9.0, 6.8}, {5.4, 6.3, 5.6}, {7.4, 6.9, 7.8}};

    for(int i=0; i<5; ++i){
        Livro novo(livros[i], autores[i], notas[i]);
        base.push_back(novo);
    }

    return base;
}


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
    tratarEntrada(entrada);
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

    tratarEntrada(livro);

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