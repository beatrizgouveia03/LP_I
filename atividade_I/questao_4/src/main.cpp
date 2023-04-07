#include <utilities.h>

int main()
{
    std::vector<Pessoa> pessoas = configuracaoInicial();
    bool fim = false;
    int acao;

    while (!fim)
    {
        std::cout << "Escolha uma acao: \n 1-Cadastrar nova pessoa\n 2-Obter info de uma pessoa\n 3-Comparar pessoas\n 4-Sair\n";
        tratarEntrada(acao);

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
        default:
            fim = true;
            break;
        }
    }

    return 0;
}