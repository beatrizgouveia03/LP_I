#ifndef CHANNELVOICE_H
#define CHANNELVOICE_H

#include <iostream>
#include "channel.h"
#include "message.h"

class ChannelVoice : public Channel
{
private:
  Message lastMessage;
public:
  /*Constructors and destructor */

  ChannelVoice();

  ChannelVoice(const Message lastMessage);

  ~ChannelVoice();

  /* Get method */

  Message getLastMessage() const;

  /* Set method */

  void setLastMessage(const Message lastMessage);

  /* Other methods */

  void printLastMessage() const;


};

#endif