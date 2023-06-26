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

  /*!
   * Default constructor that creates an empty user.
   */
  User();

  /*!
   * Constructor that initializes the user with
   * its name, its email, its password and its id in the system.
   *
   * \param name  The name of the user
   * \param email  The email of the user
   * \param password  The password of the user
   * \param id  The id of the user
   */
  User(const string name, const string email, const string password, const int id);

  /*!
   * Default destructor.
   */
  ~User();

  /* Get methods */

  /*!
   * Retrieves the id of the user.
   *
   * \return The id of the user.
   */
  int getID() const;

  /*!
   * Retrieves the name of the user.
   *
   * \return The name of the user.
   */
  string getName() const;

  /*!
   * Retrieves the email of the user.
   *
   * \return The email of the user.
   */
  string getEmail() const;

  /*!
   * Retrieves the password of the user.
   *
   * \return The password of the user.
   */
  string getPassword() const;

  /* Set methods */

  /*!
   * Sets the id of the user.
   *
   * \param id The id to be set for the user.
   */
  void setID(const int id);

  /*!
   * Sets the name of the user.
   *
   * \param name The name to be set for the user.
   */
  void setName(const string name);

  /*!
   * Sets the email of the user.
   *
   * \param email The email to be set for the user.
   */
  void setEmail(const string email);

  /*!
   * Sets the password of the user.
   *
   * \param password The password to be set for the user.
   */
  void setPassword(const string password);

  /* Other methods */

  /*!
   * Equality operator for comparing users.
   *
   * \param other The user to compare with.
   * \return True if the users are equal, false otherwise.
   */
  bool operator==(const User other);
};

#endif