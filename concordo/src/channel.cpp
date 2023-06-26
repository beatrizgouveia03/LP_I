#include "channel.h"

/*Constructors and destructor*/

Channel::Channel() {/* Empty */};

Channel::Channel(const string name)
{
  this->name = name;
};

Channel::~Channel(){/* Empty */};

/* Get method */

string Channel::getName() const
{
  return this->name;
};

/* Set method */

void Channel::setName(const string name)
{
  this->name = name;
};