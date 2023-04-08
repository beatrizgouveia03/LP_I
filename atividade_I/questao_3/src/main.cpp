#include <utilities.h>

int main()
{
    int acao;
    bool fim = false;
    std::vector<Livro> Biblioteca = configuracaoInicial();

    while (!fim)
    {
        std::cout << "Escolha uma ação:\n 1-Criar livro\n 2-Obter info de um livro\n 3-Obter média geral\n 4-Sair\n";
        tratarEntrada(acao);

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