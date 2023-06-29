#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include "channel.h"

using namespace std;

class Server
{
private:
  int ownerID;
  int userID;
  string name;
  string description;
  string codeInvite;
  vector<Channel *> channels;
  vector<int> participantIDs;
public:
  /* Constructors and destructor */

  /*!
   * Default constructor that creates an empty server.
   */
  Server();

  /*!
   * Constructor that initializes the server with a name.
   *
   * \param name  The name of the server
   */
  Server(const string name);

  /*!
   * Default destructor.
   */
  ~Server();

  /* Get methods */

  /*!
   * Retrieves the server owner id.
   *
   * \return The server owner id.
   */
  int getOwnerID() const;

  /*!
   * Retrieves the user id that is visualizing the server.
   *
   * \return The user id that is visualizing the server.
   */
  int getUserID() const;

  /*!
   * Retrieves the name of the server.
   *
   * \return The name of the server.
   */
  string getName() const;

  /*!
   * Retrieves the description of the server.
   *
   * \return The description of the server.
   */
  string getDescription() const;

  /*!
   * Retrieves the invitation code of the server.
   *
   * \return The invitation code of the server.
   */
  string getCodeInvite() const;

  /*!
   * Retrieves the channels of the server.
   *
   * \return A vector containing the channels of the server.
   */
  vector<Channel *> getChannels() const;

  /*!
   * Retrieves the participant ids from the server.
   *
   * \return A vector containing the participant ids from the server.
   */
  vector<int> getParticipantIDs() const;

  /* Set methods */

  /*!
   * Sets the server owner's name of the channel.
   *
   * \param userID The server owner's name to be set for the channel.
   */
  void setOwnerID(const int userID);

  /*!
   * Sets the server owner id of the channel.
   *
   * \param userID The server owner id to be set for the channel.
   */
  void setUserID(const int userID);

  /*!
   * Sets the name of the server.
   *
   * \param name The name to be set for the server.
   */
  void setName(const string name);

  /*!
   * Sets the description of the server.
   *
   * \param description The description to be set for the server.
   */
  void setDescription(const string description);

  /*!
   * Sets the invitation code of the server.
   *
   * \param codeInvite The invitation code to be set for the server.
   */
  void setCodeInvite(const string codeInvite);

  /*!
   * Sets the channels of the server.
   *
   * \param channels A vector containing the channels to be set for the server.
   */
  void setChannels(const vector<Channel *> channels);

  /*!
   * Sets the participant ids of the server.
   *
   * \param participantIDs A vector containing the participant ids to be set for the server.
   */
  void setParticipantIDs(const vector<int> participantIDs);

  /* Other methods */

  /*!
   * Equality operator for comparing servers.
   *
   * \param other The server to compare with.
   * \return True if the servers are equal, false otherwise.
   */
  bool operator==(const Server other);

  /*!
   * Adds a participant id to the list of the server.
   *
   * \param id The participant id to be added.
   */
  void addParticipantID(const int id);

  /*!
   * Adds a channel to the list of the server.
   *
   * \param channel The channel to be added.
   */
  void addChannel(Channel* channel);
};

#endif