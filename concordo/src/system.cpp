#include "system.h"

System::System(){/* Empty */};

System::System(vector<User> allUsers, vector<Server> allServers, vector<ChannelText> allTextChannels, vector<ChannelVoice> allVoiceChannels)
{
  this->allUsers = allUsers;
  this->allServers = allServers;    
  this->allTextChannels = allTextChannels;
  this->allVoiceChannels = allVoiceChannels;
};

System::~System(){/* Empty */};

/* Get methods */

vector<User> System::get_all_users() const
{
  return this->allUsers;
}

vector<Server> System::get_all_servers() const
{
  return this->allServers;
}

vector<ChannelText> System::get_all_text_channels() const
{
  return this->allTextChannels;
};

vector<ChannelVoice> System::get_all_voice_channels() const
{
  return this->allVoiceChannels;
};

int System::get_user_logged_ID() const
{
  return this->userLoggedID;
};

Server* System::get_server_logged() const
{
  return this->serverLogged;
}

Channel* System::get_channel_logged() const
{
  return this->channelLogged;
};

/* Set methods */

void System::set_all_users(const vector<User> allUsers)
{
  this->allUsers = allUsers;
};

void System::set_all_servers(const vector<Server> allServers)
{
  this->allServers = allServers;
};

void System::set_all_text_channels(const vector<ChannelText> allTextChannels)
{
  this->allTextChannels = allTextChannels;
};

void System::set_all_voice_channels(const vector<ChannelVoice> allVoiceChannels)
{
  this->allVoiceChannels = allVoiceChannels;
};

void System::set_user_logged_ID(const int userLoggedID)
{
  this->userIsLogged = true;
  this->userLoggedID = userLoggedID;
};

void System::set_server_logged(Server *serverLogged)
{
  this->serverLogged = serverLogged;
};

void System::set_channel_logged(Channel *channelLogged)
{
  this->channelLogged = channelLogged;
};

/* Other methods */

bool System::is_logged()
{
  return this->userIsLogged;
}

void System::disconnect()
{
  this->userIsLogged = false;
}

void System::add_user(const User user)
{
  allUsers.push_back(user);
}

void System::add_server(const Server server)
{
  allServers.push_back(server);
}

void System::add_channel(const ChannelText channelT)
{
  allTextChannels.push_back(channelT);
};

void System::add_channel(const ChannelVoice channelV)
{
  allVoiceChannels.push_back(channelV);
};

void System::rem_user(const User user)
{
  for (auto it = allUsers.begin(); it != allUsers.end(); ++it)
  {
    if (*it == user)
    {
      allUsers.erase(it);
      return;
    }
  }
}

void System::rem_server(const Server server)
{
  for(auto it = allServers.begin(); it != allServers.end(); ++it){
    if(*it == server){
      allServers.erase(it);
      return;
    }
  }
}

User *System::find_user(const string email)
{
  for(auto& u : allUsers){
    if(u.get_email() == email) return &u;
  }
  return nullptr;
}

User *System::find_user(const int id)
{
  for (auto &u : allUsers)
  {
    if (u.get_ID() == id)
      return &u;
  }
  return nullptr;
}

Server *System::find_server(const string name)
{
  for (auto& s : allServers)
  {
    if (s.get_name() == name)
      return &s;
  }
  return nullptr;
}

ChannelText *System::find_text_channel(const string name)
{
  for (auto &c : allTextChannels)
  {
    if (c.get_name() == name)
      return &c;
  }

  return nullptr;
}

ChannelVoice *System::find_voice_channel(const string name)
{
  for (auto &c : allVoiceChannels)
  {
    if (c.get_name() == name)
      return &c;
  }

  return nullptr;
}

void System::saveUsers()
{
  ofstream archive("../data/users.txt");

  if (archive.is_open())
  {
    archive << allUsers.size() << endl;
    for (User u : allUsers)
    {
      archive << u.get_ID() << endl;
      archive << u.get_name() << endl;
      archive << u.get_email() << endl;
      archive << u.get_password() << endl;
    }
    archive.close();
  }
}

void System::saveServers()
{
  ofstream archive("../data/servers.txt");

  if (archive.is_open())
  {
    archive << allServers.size() << endl;
    for (Server s : allServers)
    {
      archive << s.get_owner_ID() << endl;
      archive << s.get_name() << endl;
      archive << s.get_description() << endl;
      archive << s.get_code_invite() << endl;
      archive << s.get_participant_IDs().size() << endl;
      for(int id : s.get_participant_IDs())
      {
        archive << id << endl;
      }
      archive <<  s.get_channels().size() << endl;
      for(Channel* c : s.get_channels())
      { 
        archive << c->get_name() << endl;
        if (ChannelText *ct = dynamic_cast<ChannelText *>(c))
        {
          archive << "TEXTO" << endl;
          archive << ct->get_messages().size() << endl;
          for(Message m : ct->get_messages())
          {
            archive << m.get_id_send_from() << endl;
            archive << m.get_date_hour() << endl;
            archive << m.get_content() << endl;
          }
        }
        else{
          ChannelVoice *cv = dynamic_cast<ChannelVoice *>(c);
          archive << "VOZ" << endl;
          Message m = cv->get_last_message();
          if( m.get_content() != "" )
          {
            archive << "1" << endl;
            archive << m.get_id_send_from() << endl;
            archive << m.get_date_hour() << endl;
            archive << m.get_content() << endl;
          }
          else{
            archive << "0" << endl;
          }
        }
      }
    }
    archive.close();
  }
}

void System::save()
{
  saveUsers();
  saveServers();
}

