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
      string email;
      string senha;
      string name;

      ss >> email >> senha;
      getline(ss, name);
      name.erase(0,1);

      createUser(system, email, senha, name);
    }
    else if (command == "login")
    {
      string email;
      string senha;

      ss >> email >> senha;

      login(system, email, senha);
    }
    else if(command == "disconnect"){
      if(system.isLogged()){
        system.disconnect();
        cout << "\"Desconectando usuário " << system.getUserLogged().getEmail() << "\"\n";
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
      string name;
      string description;

      ss >> name;
      getline(ss, description);
      description.erase(0, 1);

      setDescription(system, name, description);
    }

    if (quit)
    {
      cout << "\"Saindo do concordo\"\n";
      break;
    }

  }
  return 0;
}