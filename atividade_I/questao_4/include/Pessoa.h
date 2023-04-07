#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa
{
private:
    std::string nome;
    int idade;
    double altura;
public:
    Pessoa();
    Pessoa(std::string nome, int idade, double altura);

    void setNome(std::string nome);
    void setIdade(int idade);
    void setAltura(double altura);

    std::string getNome();
    int getIdade();
    double getAltura();

    friend std::ostream& operator<<(std::ostream &cout, Pessoa &p);
    friend bool operator>(Pessoa &p1, Pessoa &p2);
};

#endif