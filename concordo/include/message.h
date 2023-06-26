#ifndef MESSAGE_H
#define	MESSAGE_H

#include <string>

using namespace std;

class Message
{
private:
  string dateHour;
  int sendFrom;
  string content;
public:
  /* Constructors and destructor */

  /*!
   * Default constructor that creates an empty message.
   */
  Message();

  /*!
   * Constructor that initializes the with a date/hour, 
   * the user id that sent the message and its content.
   *
   * \param dateHour The date/hours of the message.
   * \param sentFrom The user id that sent the message.
   * \param content The content of the message.
   */
  Message(const string dateHour, const int sendFrom, const string content);

  /*!
   * Default destructor.
   */
  ~Message();

  /* Get methods */

  /*!
   * Retrieves the date/hour of the message.
   *
   * \return The date/hour of the message.
   */
  string getDateHour() const;

  /*!
   * Retrieves the user id that sent the message.
   *
   * \return The user id that sent the message.
   */
  int getSendFrom() const;

  /*!
   * Retrieves the content of the message.
   *
   * \return The content of the message.
   */
  string getContent() const;

  /* Set methods */

  /*!
   * Sets date/hour of the message.
   *
   * \param dateHour The date/hour of the message.
   */
  void setDateHour(const string dateHour);

  /*!
   * Sets the user id that sent the message.
   *
   * \param sendFrom The user id that sent the message.
   */
  void setSendFrom(const int sendFrom);

  /*!
   * Sets content of the message.
   *
   * \param dateHour The content of the message.
   */
  void setContent(const string content);

  /* Other methods */

  /*!
   * Equality operator for comparing messages.
   *
   * \param other The message to compare with.
   * \return True if the messages are equal, false otherwise.
   */
  bool operator==(const Message other);
};

#endif