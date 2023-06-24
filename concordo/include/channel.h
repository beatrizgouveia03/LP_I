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

  Channel();

  Channel(const string name);

  ~Channel();

  /* Get method */

  string getName() const;

  /* Set method */

  void setName(const string name);
};

#endif