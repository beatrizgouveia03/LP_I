#include <vector>
#include <cstring>
#include <sstream>
#include <iomanip>
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
    std::string departamento[] = {"FINANCEIRO", "RH", "VENDAS"};
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

void cadastrarFuncionario(std::vector<Funcionario> *funcionarios, std::vector<std::string> *departamentos )
{
    Funcionario novo;
    std::string entrada;
    double salario;
    bool dep = false;

    std::cout << "Informe o nome do novo funcionário:\n";
    getline(std::cin, entrada);
    novo.setNome(entrada);

    std::cout << "Informe o departamento:(Em letras maiúsculas apenas)\n"; 
    for(std::string d : *departamentos){
        std::cout << " - " << d << std::endl;
    }
    tratarEntrada(entrada);
    novo.setDepartamento(entrada);

    for (std::string d : *departamentos)
    {
        std::string dep = novo.getDepartamento();
        if (!strcmp(d.c_str(), dep.c_str()))
        {
            dep = true;
            break;
        }
    }

    if (!dep)
    {
        departamentos->push_back(novo.getDepartamento());
    }

    std::cout << "Informe o salário:\n";
    for(std::string d : *departamentos){
        for(Funcionario f :  *funcionarios){
            std::string dep = f.getDepartamento();
            if(!strcmp(d.c_str(), dep.c_str())){
                std::cout << " *" << d << " - R$" << std::fixed << std::setprecision(2) << f.getSalario() << std::endl; 
                break;
            }
        }
    }
    tratarEntrada(salario);
    novo.setSalario(salario);

    funcionarios->push_back(novo);

   
    std::cout << "Funcionário cadastrado!\n\n";

    return;
}

void porDepartamento(std::vector<Funcionario> funcionarios, std::vector<std::string> departamentos)
{
    std::string departamento;

    std::cout << "Digite o nome do departamento:(Em letras maiúsculas apenas)\n";
    for (std::string d : departamentos)
    {
        std::cout << " - " << d << std::endl;
    }
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

void aumentoSalario(std::vector<Funcionario> *funcionarios, std::vector<std::string> departamentos)
{
    int porcentagem;
    std::string departamento;

    std::cout << "Informe o departamento:\n";
    for (std::string d : departamentos)
    {
        std::cout << " - " << d << std::endl;
    }
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