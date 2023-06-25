#include "system.h"

System::System(){/* Empty */};

System::System(vector<User> allUsers, vector<Server> allServers)
{
  this->allUsers = allUsers;
  this->allServers = allServers;    
};

System::~System(){/* Empty */};

/* Get methods */

vector<User> System::getAllUsers() const
{
  return this->allUsers;
};

vector<Server> System::getAllServers() const
{
  return this->allServers;
};

User System::getUserLogged() const
{
  return this->userLogged;
};

Server System::getServerLogged() const
{
  return this->serverLogged;
};

Channel System::getChannelLoged() const
{
  return this->channelLoged;
};

/* Set methods */

void System::setAllUsers(const vector<User> allUsers)
{
  this->allUsers = allUsers;
};

void System::setAllServers(const vector<Server> allServers)
{
  this->allServers = allServers;
};

void System::setUserLogged(const User userLogged)
{
  this->userIsLogged = true;
  this->userLogged = userLogged;
};

void System::setServerLogged(const Server serverLogged)
{
  this->serverLogged = serverLogged;
};

void System::setChannelLoged(const Channel channelLoged)
{
  this->channelLoged = channelLoged;
};

/* Other methods */

bool System::isLogged()
{
  return this->userIsLogged;
}

void System::disconnect()
{
  this->userIsLogged = false;
}

void System::addUser(const User user)
{
  allUsers.push_back(user);
};

void System::addServer(const Server server)
{
  allServers.push_back(server);
};

void System::remUser(const User user)
{
  auto aux = findUser(user.getEmail());
  delete aux;
};

void System::remServer(const Server server)
{
  auto aux = findServer(server.getName());
  delete aux;
};

User *System::findUser(const string email)
{
  for(int i=0; i<allUsers.size(); ++i){
    if(allUsers[i].getEmail() == email) return &allUsers[i];
  }
  return nullptr;
};

Server *System::findServer(const string name)
{
  for (int i = 0; i < allServers.size(); ++i)
  {
    if (allServers[i].getName() == name)
      return &allServers[i];
  }
  return nullptr;
};