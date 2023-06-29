#include "channelVoice.h"

/*Constructors and destructor */

ChannelVoice::ChannelVoice(){/* Empty */};

ChannelVoice::ChannelVoice(const string name)
{
  this->setName(name);
};

ChannelVoice::~ChannelVoice(){/* Empty */};

/* Get method */

Message ChannelVoice::getLastMessage() const
{ 
  return this->lastMessage;
};

/* Set method */

void ChannelVoice::setLastMessage(const Message lastMessage)
{
  this->lastMessage = lastMessage;
};

/* Other methods */

void ChannelVoice::listChannel() const
{
  cout << lastMessage.getDateHour() << " ";
  cout << lastMessage.getSendFrom() << " : ";
  cout << lastMessage.getContent()  << endl;

};