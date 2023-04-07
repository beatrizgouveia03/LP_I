#include <Pessoa.h>
#include <iostream>
#include <iomanip>
#include <string>

Pessoa::Pessoa() {};

Pessoa::Pessoa(std::string nome, int idade, double altura) {
    this->nome = nome;
    this->idade = idade;
    this->altura = altura;
}

void Pessoa::setNome(std::string nome) {
    this->nome = nome;
}

void Pessoa::setIdade(int idade) {
    this->idade = idade;
}

void Pessoa::setAltura(double altura) {
    this->altura = altura;
}

std::string Pessoa::getNome() {
    return this->nome;
}

int Pessoa::getIdade() {
    return this->idade;
}

double Pessoa::getAltura() {
    return this->altura;
}

std::ostream& operator<<(std::ostream &cout, Pessoa &p){
    std::cout << "Nome: " << p.getNome() << std::endl;
    std::cout << "Idade: " << p.getIdade() << std::endl;
    std::cout << "Altura: " << std::fixed << std::setprecision(2) << p.getAltura() << std::endl;

    return cout;
}

bool operator>(Pessoa &p1, Pessoa &p2)
{
   return (p1.getIdade() > p2.getIdade() ? true : false );
}
