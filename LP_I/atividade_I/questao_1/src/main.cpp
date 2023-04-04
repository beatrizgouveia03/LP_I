#include <iostream>
#include <vector>
#include <cstring>
#include <Funcionario.h>

void porDepartamento(std::string departamento, std::vector<Funcionario> funcionarios) {
    std::cout << departamento << std::endl;  
    for(Funcionario f : funcionarios) {
        auto dep = f.getDepartamento();
        if(!strcmp(dep.c_str(), departamento.c_str())) {
            std::cout << f.getNome() << std::endl;
        }
    }
}


void aumentoSalario(std::string departamento,  std::vector<Funcionario> *funcionarios,  int porcentagem) {
    for (auto i = funcionarios->begin(); i != funcionarios->end(); ++i)
    {
        std::vector<Funcionario>::iterator funcio = i;
        std::string dep = funcio->getDepartamento();
        if (!strcmp(dep.c_str(), departamento.c_str()))
        {   
            double salario = funcio->getSalario();
            salario += salario*porcentagem/100;            
            
            funcio->setSalario(salario);
        }
    }
}

int main() {
    std::vector<Funcionario> funcionarios;
    std::string nome[] = {"Ana Clara Queiroz", "Matheus França", "Marcia Maria", "João Marcelo", "Beatriz Santana", "Gustavo Homero"};
    std::string departamento[] = {"Financeiro", "RH", "Vendas"};
    double salario[] = {1500., 2750., 1000.};

    for(int i=0; i<3; ++i) {
        Funcionario entrada(nome[i], departamento[i], salario[i]);
       
        funcionarios.push_back(entrada);

        entrada.setNome(nome[5-i]);
        entrada.setDepartamento(departamento[2-i]);
        entrada.setSalario(salario[2-i]);
       
        funcionarios.push_back(entrada);
    }

    for(auto d :  departamento){
        porDepartamento(d, funcionarios);
        std::cout << std::endl;
    }

    aumentoSalario(departamento[0], &funcionarios, 5);
    aumentoSalario(departamento[2], &funcionarios, 15);

    for (int i = 0; i < 3; ++i)
    {
        for (auto f : funcionarios)
        {
            auto dep = f.getDepartamento();
            if (!strcmp(dep.c_str(), departamento[i].c_str()))
            {
            std::cout << "Salário Final do " << departamento[i] << ": " << f.getSalario() << std::endl;
            break;
            }
        }
    }

    return 0;
}