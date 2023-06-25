#include <iostream>
#include "system.h"

void createUser(System &system, string email, string password, string name){
  if(system.findUser(email) == nullptr){
    User newUser(name, email, password);
    system.addUser(newUser);

    cout << "\"Usuário criado\"\n";
  }
  else{
    cout << "\"Usuário já existe\"\n";
  }
};

void login(System &system, string email, string password){
  if(system.findUser(email) != nullptr){
    User *user = system.findUser(email);
    if(user->getPassword() == password){
      system.setUserLogged(*user);
      cout << "\"Logado como " << email << "\"\n";
    }
    else{
      cout << "\"Senha ou usuário inválidos!\"\n";
    }
  }
  else{
    cout << "\"Senha ou usuário inválidos!\"\n";
  }
}


