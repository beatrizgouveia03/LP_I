#ifndef SYSTEM_M
#define SYSTEM_H

#include "server.h"
#include "user.h"

class System
{
private:
  vector<User> allUsers;
  vector<Server> allServers;
  int nextID = 1;
  bool userIsLogged = false;
  int userLoggedID;
  Server* serverLogged;
  Channel* channelLogged;
public:
  /* Constructors and destructor*/

  /*!
   * Default constructor that creates an empty system.
   */
  System();

  /*!
   * Constructor that initializes the server with a list of users and servers.
   *
   * \param allUsers The vector of users of the system
   * \param allServers The vector of servers of the system
   */
  System(vector<User> allUsers, vector<Server> allServers);

  /*!
   * Default destructor.
   */
  ~System();

  /* Get methods */

  /*!
   * Retrieves the users from the system.
   *
   * \return A vector containing the users from the system.
   */
  vector<User> getAllUsers() const;

  /*!
   * Retrieves the servers from the system.
   *
   * \return A vector containing the servers from the system.
   */
  vector<Server> getAllServers() const;

  /*!
   * Retrieves the logged user ID in the system.
   *
   * \return The logged user ID in the system.
   */
  int getUserLoggedID() const;

  /*!
   * Retrieves the server that is being visualized in the system.
   *
   * \return The server that is being visualized in the system.
   */
  Server* getServerLogged() const;

  /*!
   * Retrieves the channel that is being visualised in the system.
   *
   * \return The channel that is being visualised in the system.
   */
  Channel* getChannelLogged() const;  

  /* Set methods */

  /*!
   * Sets the users of the system.
   *
   * \param allUsers A vector containing the users to be set for the system.
   */
  void setAllUsers(const vector<User> allUsers);

  /*!
   * Sets the servers of the system.
   *
   * \param allServers A vector containing the servers to be set for the system.
   */
  void setAllServers(const vector<Server> allServers);

  /*!
   * Sets the logged user ID in the system.
   *
   * \param userLogged The logged user ID in the system.
   */
  void setUserLoggedID(const int userLoggedID);

  /*!
   * Sets the server that is being visualized in the system.
   *
   * \param serverLogged The server that is being visualized in the system.
   */
  void setServerLogged(Server *serverLogged = nullptr);

  /*!
   * Sets the channel that is being visualized in the system.
   *
   * \param channelLogged The channel that is being visualized in the system.
   */
  void setChannelLogged(Channel *channelLogged = nullptr); 

  /* Other methods */

  /*!
   * Checks if the user is logged in.
   *
   * \return True if the user is logged in, false otherwise.
   */
  bool isLogged();

  /*!
   * Disconnects the user from the system.
   */
  void disconnect();

  /*!
   * Adds a user to the list of the system.
   *
   * \param user The user to be added.
   */
  void addUser(const User user);

  /*!
   * Adds a server to the list of the system.
   *
   * \param server The server to be added.
   */
  void addServer(const Server server);

  /*!
   * Removes a user from the list of the system.
   *
   * \param user The user to be removed.
   */
  void remUser(const User user);

  /*!
   * Removes a server from the list of the system.
   *
   * \param server The server to be removed.
   */
  void remServer(const Server server);

  /*!
   * Finds a user from the system.
   *
   * \param email The email of the user to be found.
   * \return A pointer to the found user, or nullptr if not found.
   */
  User *findUser(const string email);

  /*!
   * Finds a user from the system.
   *
   * \param id The id of the user to be found.
   * \return A pointer to the found user, or nullptr if not found.
   */
  User *findUser(const int id);

  /*!
   * Finds a server from the system.
   *
   * \param name The name of the server to be found.
   * \return A pointer to the found server, or nullptr if not found.
   */
  Server *findServer(const string name);

};

#endif