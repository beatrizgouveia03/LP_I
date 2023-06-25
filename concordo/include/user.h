#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
private:
  int id;
  string name;
  string email;
  string password;
public:
  /* Constructors and destructor */

  User();

  User(const string name, const string email, const string password, const int id);

  ~User();

  /* Get methods */

  int getID() const;

  string getName() const;

  string getEmail() const;

  string getPassword() const;

  /* Set methods */

  void setID(const int id);

  void setName(const string name);

  void setEmail(const string email);

  void setPassword(const string password);

  /* Other methods */

  bool operator==(const User other);
};

#endif