#include <iostream>
#include <vector>
#include <cstring>
#include <Funcionario.h>

void porDepartamento(auto departamento, auto funcionarios) {
    std::cout << departamento << std::endl;  
    for( Funcionario f : funcionarios) {
        auto dep = f.getDepartamento();
        if(!strcmp(dep.c_str(), departamento.c_str())) {
            std::cout << f.getNome() << std::endl;
        }
    }
}


void aumentoSalario(auto departamento, auto funcionarios,  int porcentagem) {
    for (Funcionario f : *funcionarios)
    {
        std::string dep = f.getDepartamento();
        if (!strcmp(dep.c_str(), departamento.c_str()))
        {   
            double salario = f.getSalario();
            salario += salario*porcentagem/100;            
            
            f.setSalario(salario);

            std::cout << f.getSalario() << std::endl;
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

    for(std::string d :  departamento){
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