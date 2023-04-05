#ifndef PESSOA_H
#define PESSOA_H

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

    void getDados();
};

#endif