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

  /*!
   * Default constructor that creates an empty text channel.
   */
  ChannelText();

  /*!
   * Constructor that initializes the text channel with a name.
   *
   * \param name  The name of the text channel
   */
  ChannelText(const string name);

  /*!
   * Default destructor.
   */
  ~ChannelText();

  /* Get method */

  /*!
   * Retrieves the messages from the text channel.
   *
   * \return A vector containing the messages from the text channel.
   */
  vector<Message> getMessages() const;

  /* Set method */

  /*!
   * Sets the messages of the text channel.
   *
   * \param messages The vector of messages to be set for the text channel.
   */
  void setMessages(const vector<Message> messages);

  /* Other methods */

  /*!
   * Adds a message to the text channel.
   *
   * \param message The message to be added.
   */
  void addMessage(const Message message);

  /*!
   * Removes a message from the text channel.
   *
   * \param message The message to be removed.
   */
  void remMessage(const Message message);

  /*!
   * Finds a message from the text channel.
   *
   * \param message The message to be found.
   * \return A pointer to the found message, or nullptr if not found.
   */
  Message* findMessage(const Message message);

  /*!
   * Prints all the messages from the text channel.
   */
  void printMessages() const;
};

#endif