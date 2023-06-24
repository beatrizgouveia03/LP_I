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
  auto aux = findUser(user);
  delete aux;
};

void System::remServer(const Server server)
{
  auto aux = findServer(server);
  delete aux;
};

User *System::findUser(const User user)
{
  for(auto u : allUsers){
    if(u == user) return &u;
  }
};

Server *System::findServer(const Server server)
{
  for (auto s : allServers)
  {
    if (s == server)
      return &s;
  }
};