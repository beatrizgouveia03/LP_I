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

  Server();

  Server(const string name);

  ~Server();

  /* Get methods */

  int getOwnerID() const;

  int getUserID() const;

  string getName() const;

  string getDescription() const;

  string getCodeInvite() const;

  vector<Channel *> getChannels() const;

  vector<int> getParticipantIDs() const;

  /* Set methods */

  void setOwnerID(const int userID);

  void setUserID(const int userID);

  void setName(const string name);

  void setDescription(const string description);

  void setCodeInvite(const string codeInvite);

  void setChannels(const vector<Channel *> channels);

  void setParticipantIDs(const vector<int> participantIDs);

  /* Other methods */

  bool operator==(const Server other);

  void addParticipantID(const int id);
};

#endif