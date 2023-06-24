#ifndef SYSTEM_M
#define SYSTEM_H

#include "channel.h"
#include "server.h"
#include "user.h"

class System
{
private:
  vector<User> allUsers;
  vector<Server> allServers;
  User userLogged;
  Server serverLogged;
  Channel channelLoged;
public:
  /* Constructors and destructor*/

  System();

  System(vector<User> allUsers, vector<Server> allServers);

  ~System();

  /* Get methods */ 

  vector<User> getAllUsers() const; 

  vector<Server> getAllServers() const; 

  User getUserLogged() const; 

  Server getServerLogged() const; 

  Channel getChannelLoged() const;  

  /* Set methods */ 

  void setAllUsers(const vector<User> allUsers); 
   
  void setAllServers(const vector<Server> allServers);

  void setUserLogged(const User userLogged);  

  void setServerLogged(const Server serverLogged);  

  void setChannelLoged(const Channel channelLoged); 

  /* Other methods */ 

  void addUser(const User user); 

  void addServer(const Server server); 

  void remUser(const User user);

  void remServer(const Server server);

  User *findUser(const User user);

  Server *findServer(const Server server);

};

#endif