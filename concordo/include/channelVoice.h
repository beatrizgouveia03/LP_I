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

  /*!
   * Default constructor that creates an empty voice channel.
   */
  ChannelVoice();

  /*!
   * Constructor that initializes the voice channel with a name.
   *
   * \param name  The name of the voice channel
   */
  ChannelVoice(const string name);

  /*!
   * Default destructor.
   */
  ~ChannelVoice();

  /* Get method */

  /*!
   * Retrieves the last message from the voice channel.
   *
   * \return The last message from the voice channel.
   */
  Message getLastMessage() const;

  /* Set method */

  /*!
   * Sets the last message from the voice channel.
   *
   * \param lastMessage The message to be set for the voice channel.
   */
  void setLastMessage(const Message lastMessage);

  /* Other methods */

  /*!
   * Prints the last message from the voice channel.
   */
  void printLastMessage() const;
};

#endif