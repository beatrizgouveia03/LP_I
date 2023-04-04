#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario
{
private:
    std::string nome;
    double salario;
    std::string departamento;

public:
    Funcionario(std::string nome, std::string departamento, double salario);
    Funcionario();

    std::string getDepartamento();
    std::string getNome();
    double getSalario();

    void setSalario(double salario);
    void setNome(std::string nome);
    void setDepartamento(std::string departamenot);
};

#endif