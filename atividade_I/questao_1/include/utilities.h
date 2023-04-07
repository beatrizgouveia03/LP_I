#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>

#include <Funcionario.h>

template <typename T>
void tratarEntrada(T &var)
{
    std::string entrada;
    getline(std::cin, entrada);
    std::istringstream ss(entrada);

    ss >> var;

    return;
}

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

void cadastrarFuncionario(std::vector<Funcionario> *funcionarios)
{
    Funcionario novo;
    std::string entrada;
    double salario;

    std::cout << "Informe o nome do novo funcionário:\n";
    tratarEntrada(entrada);
    novo.setNome(entrada);

    std::cout << "Informe o departamento:\n";
    tratarEntrada(entrada);
    novo.setDepartamento(entrada);

    std::cout << "Informe o salário:\n";
    tratarEntrada(salario);
    novo.setSalario(salario);

    funcionarios->push_back(novo);
    std::cout << "Funcionário cadstrado!\n\n";

    return;
}

void porDepartamento(std::vector<Funcionario> funcionarios)
{
    std::string departamento;

    std::cout << "Digite o nome do departamento:\n";
    tratarEntrada(departamento);

    std::cout << departamento << std::endl;
    for (Funcionario f : funcionarios)
    {
        auto dep = f.getDepartamento();
        if (!strcmp(dep.c_str(), departamento.c_str()))
        {
            std::cout << f.getNome() << " " << f.getSalario() << std::endl;
        }
    }
    std::cout << std::endl;

    return;
}

void aumentoSalario(std::vector<Funcionario> *funcionarios)
{
    int porcentagem;
    std::string departamento;

    std::cout << "Informe o departamento:\n";
    tratarEntrada(departamento);

    std::cout << "Informe o aumento a ser feito:(Por exemplo '15' para um aumento de 15%)\n";
    tratarEntrada(porcentagem);

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

    std::cout << "Salário reajustado.\n\n";

    return;
}