#include "system.h"

System::System(){/* Empty */};

System::System(vector<User> allUsers, vector<Server> allServers, vector<ChannelText> allTextChannels, vector<ChannelVoice> allVoiceChannels)
{
  this->allUsers = allUsers;
  this->allServers = allServers;    
  this->allTextChannels = allTextChannels;
  this->allVoiceChannels = allVoiceChannels;
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

vector<ChannelText> System::getAllTextChannels() const
{
  return this->allTextChannels;
};

vector<ChannelVoice> System::getAllVoiceChannels() const
{
  return this->allVoiceChannels;
};

int System::getUserLoggedID() const
{
  return this->userLoggedID;
};

Server* System::getServerLogged() const
{
  return this->serverLogged;
};

Channel* System::getChannelLogged() const
{
  return this->channelLogged;
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

void System::setAllTextChannels(const vector<ChannelText> allTextChannels)
{
  this->allTextChannels = allTextChannels;
};

void System::setAllVoiceChannels(const vector<ChannelVoice> allVoiceChannels)
{
  this->allVoiceChannels = allVoiceChannels;
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

void System::setChannelLogged(Channel *channelLogged)
{
  this->channelLogged = channelLogged;
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

void System::addChannel(const ChannelText channelT)
{
  allTextChannels.push_back(channelT);
};

void System::addChannel(const ChannelVoice channelV)
{
  allVoiceChannels.push_back(channelV);
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

ChannelText *System::findTextChannel(const string name)
{
  for (auto &c : allTextChannels)
  {
    if (c.getName() == name)
      return &c;
  }

  return nullptr;
};

ChannelVoice *System::findVoiceChannel(const string name)
{
  for (auto &c : allVoiceChannels)
  {
    if (c.getName() == name)
      return &c;
  }

  return nullptr;
};