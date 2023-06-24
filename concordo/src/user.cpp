#include "user.h"

/* Constructors and destructor */

User::User(){/* Empty */};

User::User(const string name, const string email, const string password)
{
  this->id = 0;
  this->name = name;
  this->email = email;
  this->password = password;
};

User::~User(){/* Empty */};

/* Get methods */

int User::getID() const 
{
  return this->id;
};

string User::getName() const
{
  return this->name;
};

string User::getEmail() const
{
  return this->email;
};

string User::getPassword() const
{
  return this->password;
};

/* Set methods */

void User::setID(const int id)
{
  this->id = id;
};

void User::setName(const string name)
{
  this->name = name;
};

void User::setEmail(const string email)
{
  this->email = email;
};

void User::setPassword(const string password)
{
  this->password = password;
};

/* Other methods */

bool User::operator==(const User other){
  return id == other.id;
};