#include <iostream>
#include "system.h"

void createUser(System &system, string email, string password, string name){
  if(system.findUser(email) == nullptr){
    User newUser(name, email, password, system.getAllUsers().size()+1);
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
      system.setServerLogged(Server());
      system.setChannelLoged(Channel());
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

void createServer(System &system, string name){
  if(system.findServer(name) == nullptr){
    Server newServer(name);
    newServer.setOwnerID(system.getUserLogged().getID());
    newServer.addParticipantID(system.getUserLogged().getID());
    system.addServer(newServer);

    cout << "\"Servidor criado\"\n";
  }
  else
  {
    cout << "\"Servidor com esse nome já existe\"\n";
  }
}

void setDescription(System &system, string name, string description){
  if(system.findServer(name) != nullptr){
    Server* server = system.findServer(name);
    if(server->getOwnerID() == system.getUserLogged().getID()){
      server->setDescription(description);

      cout << "\"Descrição do servidor \'" << name << "\' modificada!\"\n";
    }
    else{
      cout << "\"Você não pode alterar a descrição de um servidor que não foi criado por você\"\n";
    }
  }
  else{
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

void setCode(System &system, string name, string code){
  if (system.findServer(name) != nullptr)
  {
    Server *server = system.findServer(name);
    if (server->getOwnerID() == system.getUserLogged().getID())
    {
      server->setCodeInvite(code);
      if(code != ""){
        cout << "\"Código de convite do servidor \'" << name << "\' modificado!\"\n";
      }
      else {
        cout << "\"Código de convite do servidor \'" << name << "\' removido!\"\n";
      }
    }
    else
    {
      cout << "\"Você não pode alterar o código de convite de um servidor que não foi criado por você\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

void removeServer(System &system, string name){
  if (system.findServer(name) != nullptr)
  {
    Server *server = system.findServer(name);
    if (server->getOwnerID() == system.getUserLogged().getID())
    {
      system.remServer(*server);
      cout << "\"Servidor \'" << name << "\' removido\"\n";
    }
    else
    {
      cout << "\"Você não é o dono do servidor \'" << name << "\'\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
};

void enterServer(System &system, string name, string code){
  if(system.findServer(name) != nullptr){
    Server* server = system.findServer(name);
    if(server->getCodeInvite() == code || server->getOwnerID() == system.getUserLogged().getID()){
      server->addParticipantID(system.getUserLogged().getID());
      server->setUserID(system.getUserLogged().getID());
      system.setServerLogged(*server);
      cout << "\"Entrou no servidor com sucesso\"\n";
    }
    else{
      cout << "\"Servidor requer código de convite\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

void leaveServer(System &system){
  if(system.getServerLogged() != Server()){
    Server *server = system.findServer(system.getServerLogged().getName());
    server->setUserID(-1);
    system.setServerLogged(Server());
    cout << "\"“Saindo do servidor \'" <<  server->getName() << "\'\"\n";
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

void listParticipants(System &system){
  if (system.getServerLogged() != Server())
  {
    Server server = system.getServerLogged();
    for (int partID : server.getParticipantIDs())
    {
      User *part = system.findUser(partID);
      cout << part->getName() << endl;
    }
  }
  else 
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}
