#include "channelText.h"

/* Constructors and destructor */

ChannelText::ChannelText(){/* Empty */};

ChannelText::ChannelText(const vector<Message> messages)
{
  this->messages = messages;
};

ChannelText::~ChannelText(){/* Empty */};

/* Get method */

vector<Message> ChannelText::getMessages() const
{
  return this->messages;
};

/* Set method */

void ChannelText::setMessages(const vector<Message> messages)
{
  this->messages = messages;
};

/* Other methods */

void ChannelText::addMessage(const Message message
){
  messages.push_back(message);
};

void ChannelText::remMessage(const Message message)
{
  Message* aux = findMessage(message);
  delete aux;
};

Message *ChannelText::findMessage(const Message message)
{
  return nullptr;
};

void ChannelText::printMessages() const
{
  for(Message m : messages){
    cout << m.getDateHour() << " ";
    cout << m.getSendFrom() << " : ";
    cout << m.getContent()  << endl;
  }
};