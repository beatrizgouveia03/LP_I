#include "utilities.cpp"

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