#include <iostream>
#include <sstream>
#include "utilities.h"


using namespace std;

int main(){
  System system;
  bool quit = false;

  while(true){
    string entry;
    string command;

    getline(cin, entry);

    istringstream ss(entry);
    ss >> command;

    if (command == "quit")
    {
      quit = true;
    }
    else if (command == "create-user")
    { 
      if(!system.isLogged())
      {
        string email;
        string senha;
        string name;

        ss >> email >> senha;
        getline(ss, name);
        name.erase(0,1);

        createUser(system, email, senha, name);
      }
      else
      {
        cout << "\"Usuário já logado\"\n";
      }
    }
    else if (command == "login")
    {
      if (!system.isLogged())
      {
        string email;
        string senha;

        ss >> email >> senha;

        login(system, email, senha);
      }
    
      else
      {
        cout << "\"Usuário já logado\"\n";
      }
    }
    else if(command == "disconnect"){
      if(system.isLogged()){
        system.disconnect();
        cout << "\"Desconectando usuário " << system.findUser(system.getUserLoggedID())->getEmail() << "\"\n";
      }
      else{
        cout << "\"Não está conectado\"\n";
      }
    }
    else if(command == "create-server"){
      if(system.isLogged()){
        string name;
        ss >> name;
        
        createServer(system, name);
      }
      else{
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "set-server-desc"){
      if (system.isLogged())
      {
        string name;
        string description;

        ss >> name;
        getline(ss, description);
        description.erase(0, 1);

        setDescription(system, name, description);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if(command == "set-server-invite-code"){
      if (system.isLogged())
      {
        string name;
        string code;

        ss >> name >> code;

        setCode(system, name, code);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if(command == "list-servers"){
      if(system.isLogged()){
        for(Server s : system.getAllServers()){
          cout << s.getName() << endl;
        }
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "remove-server")
    {
      if (system.isLogged())
      {
        string name;

        ss >> name;

        removeServer(system, name);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "enter-server")
    {
      if (system.isLogged())
      {
        string name;
        string code;

        ss >> name >> code;

        enterServer(system, name, code);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "leave-server")
    {
      if (system.isLogged())
      {
        leaveServer(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "list-participants")
    {
      if (system.isLogged())
      {
        listParticipants(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "list-channels")
    {
      if (system.isLogged())
      {
        listChannels(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "create-channel")
    {
      if (system.isLogged())
      {
        string name;
        string type;

        ss >> name >> type;

        createChannel(system, name, type);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "enter-channel")
    {
      if (system.isLogged())
      {
        string name;

        ss >> name;

        enterChannel(system, name);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }
    else if (command == "leave-channel")
    {
      if (system.isLogged())
      {
        leaveChannel(system);
      }
      else
      {
        cout << "\"Não está conectado\"\n";
      }
    }

    if (quit)
    {
      cout << "\"Saindo do concordo\"\n";
      break;
    }

  }
  return 0;
}