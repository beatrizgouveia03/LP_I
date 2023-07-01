#include "message.h"

/* Constructors and destructor */

Message::Message(){/* Empty */};

Message::Message(const string dateHour, const string sendFrom, const string content)
{
  this->dateHour = dateHour;
  this->sendFrom = sendFrom;
  this->content = content;
};

Message::~Message(){/* Empty */};

/* Get methods */

string Message::getDateHour() const
{
  return this->dateHour;
};

string Message::getSendFrom() const
{
  return this->sendFrom;
};

string Message::getContent() const
{
  return this->content;
};

/* Set methods */

void Message::setDateHour(const string dateHour)
{
  this->dateHour = dateHour;
};

void Message::setSendFrom(const string sendFrom)
{
  this->sendFrom = sendFrom;
};

void Message::setContent(const string content)
{
  this->content = content;
};

/* Other methods */

bool Message::operator==(const Message other){
  return dateHour == other.dateHour && sendFrom == other.sendFrom && content == other.content;  
};