#ifndef CHANNELTEXT_H
#define CHANNELTEXT_H

#include <vector>
#include <iostream>
#include "channel.h"
#include "message.h"

class ChannelText : public Channel
{
private:
  vector<Message> messages; 
public:
  /* Constructors and destructor */

  ChannelText();

  ChannelText(const vector<Message> messages);

  ~ChannelText();

  /* Get method */

  vector<Message> getMessages() const;

  /* Set method */

  void setMessages(const vector<Message> messages);

  /* Other methods */

  void addMessage(const Message message);

  void remMessage(const Message message);

  Message* findMessage(const Message message);

  void printMessages() const;
};

#endif