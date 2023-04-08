#include <utilities.h>

int main()
{
    std::vector<Funcionario> funcionarios = configuracaoInicial();
    std::vector<std::string> departamento = {"FINANCEIRO", "RH", "VENDAS"};
    bool fim = false;
    int acao;

    while (!fim)
    {
        std::cout << "Escolha uma ação:\n 1-Cadastrar funcionário\n 2-Obter info de um departamento\n 3-Aumentar o salário de um departamento\n 4-Sair\n";
        tratarEntrada(acao);

        switch (acao)
        {
        case 1:
            cadastrarFuncionario(&funcionarios, &departamento);
            break;
        case 2:
            porDepartamento(funcionarios, departamento);
            break;
        case 3:
            aumentoSalario(&funcionarios, departamento);
            break;
        case 4:
        default:
            fim = true;
            break;
        }
    }

    return 0;
}