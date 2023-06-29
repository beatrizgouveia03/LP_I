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

int System::getUserLoggedID() const
{
  return this->userLoggedID;
};

Server* System::getServerLogged() const
{
  return this->serverLogged;
};

Channel* System::getChannelLoged() const
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

void System::setUserLoggedID(const int userLoggedID)
{
  this->userIsLogged = true;
  this->userLoggedID = userLoggedID;
};

void System::setServerLogged(Server *serverLogged)
{
  this->serverLogged = serverLogged;
};

void System::setChannelLoged(Channel *channelLoged)
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
  for (auto it = allUsers.begin(); it != allUsers.end(); ++it)
  {
    if (*it == user)
    {
      allUsers.erase(it);
      return;
    }
  }
};

void System::remServer(const Server server)
{
  for(auto it = allServers.begin(); it != allServers.end(); ++it){
    if(*it == server){
      allServers.erase(it);
      return;
    }
  }
};

User *System::findUser(const string email)
{
  for(auto& u : allUsers){
    if(u.getEmail() == email) return &u;
  }
  return nullptr;
};

User *System::findUser(const int id)
{
  for (auto &u : allUsers)
  {
    if (u.getID() == id)
      return &u;
  }
  return nullptr;
};

Server *System::findServer(const string name)
{
  for (auto& s : allServers)
  {
    if (s.getName() == name)
      return &s;
  }
  return nullptr;
};