#include <Funcionario.h>

Funcionario::Funcionario(){}

Funcionario::Funcionario(std::string nome, std::string departamento, double salario) {
    this->nome = nome;
    this->departamento = departamento;
    this->salario = salario;
}

std::string Funcionario::getDepartamento() {
    return this->departamento;
}

double Funcionario::getSalario() {
    return this->salario;
}

std::string Funcionario::getNome() {
    return this->nome;
}

void Funcionario::setSalario(double salario) {
    this->salario = salario;
}

void Funcionario::setNome(std::string nome) {
    this->nome = nome;
}

void Funcionario::setDepartamento(std::string departamento) {
    this->departamento = departamento;
}
