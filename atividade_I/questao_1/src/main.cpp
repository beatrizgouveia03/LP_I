#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <Funcionario.h>

std::vector<Funcionario> configuracaoInicial()
{
    std::string nome[] = {"Ana Clara Queiroz", "Matheus França", "Marcia Maria", "João Marcelo", "Beatriz Santana", "Gustavo Homero"};
    std::string departamento[] = {"Financeiro", "RH", "Vendas"};
    double salario[] = {1500., 2750., 1000.};
    std::vector<Funcionario> base;

    for (int i = 0; i < 3; ++i)
    {
        Funcionario entrada(nome[i], departamento[i], salario[i]);

        base.push_back(entrada);

        entrada.setNome(nome[5 - i]);
        entrada.setDepartamento(departamento[2 - i]);
        entrada.setSalario(salario[2 - i]);

        base.push_back(entrada);
    }

    return base;
}

void cadastrarFuncionario(std::vector<Funcionario> *funcionarios) {
    Funcionario novo;
    std::string entrada;
    double salario;

    std::cout << "Informe o nome do novo funcionário:\n";
    getline(std::cin, entrada);
    novo.setNome(entrada);

    std::cout << "Informe o departamento:\n";
    getline(std::cin, entrada);
    novo.setDepartamento(entrada);

    std::cout << "Informe o salário:\n";
    getline(std::cin, entrada);
    std::istringstream ss(entrada);
    ss >> salario;

    novo.setSalario(salario);

    funcionarios->push_back(novo);

    return;
}

void porDepartamento(std::vector<Funcionario> funcionarios)
{
    std::string departamento;

    std::cout << "Informe o departamento:\n";
    getline(std::cin, departamento);

    std::cout << departamento << std::endl;
    for (Funcionario f : funcionarios)
    {
        auto dep = f.getDepartamento();
        if (!strcmp(dep.c_str(), departamento.c_str()))
        {
            std::cout << f.getNome() << " " << f.getSalario() << std::endl;
        }
    }

    return;
}

void aumentoSalario(std::vector<Funcionario> *funcionarios)
{
    int porcentagem;
    std::string departamento, entry;

    std::cout << "Informe o departamento:\n";
    getline(std::cin, departamento);

    std::cout << "Informe o aumento a ser feito:(Por exemplo '15' para um aumento de 15%)\n";
    getline(std::cin, entry);
    std::istringstream ss(entry);

    ss >> porcentagem;

    for (auto i = funcionarios->begin(); i != funcionarios->end(); ++i)
    {
        std::vector<Funcionario>::iterator funcio = i;
        std::string dep = funcio->getDepartamento();
        if (!strcmp(dep.c_str(), departamento.c_str()))
        {
            double salario = funcio->getSalario();
            salario += salario * porcentagem / 100;

            funcio->setSalario(salario);
        }
    }

    return;
}

int main()
{
    std::vector<Funcionario> funcionarios;
    std::string entrada;
    bool fim = false;
    int acao;

    funcionarios = configuracaoInicial();

    while (!fim)
    {
        std::cout << "Escolha uma acao: \n 1-Cadastrar funcionário\n 2-Obter info de um departamento\n 3-Aumentar o salário de um departamento\n 4-Sair\n";
        getline(std::cin, entrada);

        std::cout << entrada;

        std::istringstream ss(entrada);
        ss >> acao;

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