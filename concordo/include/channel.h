#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

using namespace std;

class Channel
{
private:
  string name;
public:
  /*Constructors and destructor*/

  /*!
   * Default constructor that creates an empty channel.
   */
  Channel();

  /*!
   * Constructor that initializes the channel with a name.
   *
   * \param name The name of the channel.
   */
  Channel(const string name);

  /*!
   * Default destructor.
   */
  ~Channel();

  /* Get method */

  /*!
   * Retrieves the name of the channel.
   *
   * \return The name of the channel.
   */
  string getName() const;

  /* Set method */

  /*!
   * Sets the name of the channel.
   *
   * \param name The name to be set for the channel.
   */
  void setName(const string name);


  /* Other methods */

  /*!
   * Lists the channel in the terminal
   */
  virtual void listChannel() const = 0;
};

#endif
