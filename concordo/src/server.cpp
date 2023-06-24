#include "server.h"

/* Constructors and destructor */

Server::Server(){/* Empty */};

Server::Server(const string name)
{
  this->name = name;
};

Server::~Server(){/* Empty */};

/* Get methods */
int Server::getUserID() const
{
  return this->userID;
};

string Server::getName() const
{
  return this->name;
};

string Server::getDescription() const
{
  return this->description;
};

string Server::getCodeInvite() const
{
  return this->codeInvite;
};

vector<Channel *> Server::getChannels() const
{
  return this->channels;
};

vector<int> Server::getParticipantIDs() const
{
  return this->participantIDs;
};

/* Set methods */

void Server::setUserID(const int userID){
  this->userID = userID;
};

void Server::setName(const string name)
{
  this->name = name;
};

void Server::setDescription(const string description)
{
  this->description = description;
};

void Server::setCodeInvite(const string codeInvite)
{
  this->codeInvite = codeInvite;
};

void Server::setChannels(const vector<Channel *> channels)
{
  this->channels = channels;
};

void Server::setParticipantIDs(const vector<int> participantIDs)
{
  this->participantIDs = participantIDs;
};

/* Other methods */

bool Server::operator==(const Server other){
  return name == other.name && description == other.description;
};