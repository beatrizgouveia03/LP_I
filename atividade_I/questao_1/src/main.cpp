#include <utilities.h>

int main()
{
    std::vector<Funcionario> funcionarios = configuracaoInicial();
    bool fim = false;
    int acao;

    while (!fim)
    {
        std::cout << "Escolha uma acao: \n 1-Cadastrar funcionário\n 2-Obter info de um departamento\n 3-Aumentar o salário de um departamento\n 4-Sair\n";
        tratarEntrada(acao);

        switch (acao)
        {
        case 1:
            cadastrarFuncionario(&funcionarios);
            break;
        case 2:
            porDepartamento(funcionarios);
            break;
        case 3:
            aumentoSalario(&funcionarios);
            break;
        case 4:
        default:
            fim = true;
            break;
        }
    }

    return 0;
}