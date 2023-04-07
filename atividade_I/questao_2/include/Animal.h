#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
private:
   std::string nome;
   std::string especie;
   int idade;

public:
   Animal();
   Animal(std::string nome, std::string especie, int idade);

   std::string getNome();
   std::string getEspecie();
   int getIdade();

   void setNome(std::string nome);
   void setEspecie(std::string especie);
   void setIdade(int idade);

   friend std::ostream &operator<<(std::ostream &cout, Animal &a);
};

#endif