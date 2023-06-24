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

  Message();

  Message(const string dateHour, const int sendFrom, const string content);

  ~Message();

  /* Get methods */

  string getDateHour() const;

  int getSendFrom() const;

  string getContent() const;

  /* Set methods */

  void setDateHour(const string dateHour);

  void setSendFrom(const int sendFrom);

  void setContent(const string content);

  /* Other methods */
  
  bool operator==(const Message other);
};

#endif