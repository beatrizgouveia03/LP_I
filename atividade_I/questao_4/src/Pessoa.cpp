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

void Pessoa::getDados() {
    std::cout << "Nome: " << this->getNome() << std::endl;
    std::cout << "Idade: " << this->getIdade() << std::endl;
    std::cout << "Altura: " << std::fixed << std::setprecision(2) <<this->getAltura() << "\n\n";
}