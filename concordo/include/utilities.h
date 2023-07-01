#include <ctime>
#include <chrono>
#include <iostream>

#include "system.h"

/*!
 * Creates a new user in the system.
 *
 * \param system The adress of the system.
 * \param email The email of the user.
 * \param password The password of the user.
 * \param name The name of the user.
 */
void createUser(System &system, string email, string password, string name){
  if(system.findUser(email) == nullptr){
    User newUser(name, email, password, system.getAllUsers().size()+1);
    system.addUser(newUser);

    cout << "\"Usuário criado\"\n";
  }
  else{
    cout << "\"Usuário já existe\"\n";
  }
};

/*!
 * Logs in a user to the system.
 *
 * \param system The adress of the system.
 * \param email The email of the user.
 * \param password The password of the user.
 */
void login(System &system, string email, string password){
  if(system.findUser(email) != nullptr){
    User *user = system.findUser(email);
    if(user->getPassword() == password){
      system.setUserLoggedID(user->getID());
      system.setServerLogged();
      system.setChannelLogged();
      cout << "\"Logado como " << email << "\"\n";
    }
    else{
      cout << "\"Senha ou usuário inválidos!\"\n";
    }
  }
  else{
    cout << "\"Senha ou usuário inválidos!\"\n";
  }
}

/*!
 * Creates a new server in the system.
 *
 * \param system The adress of the system.
 * \param name The name of the server.
 */
void createServer(System &system, string name){
  if(system.findServer(name) == nullptr){
    Server newServer(name);
    newServer.setOwnerID(system.getUserLoggedID());
    newServer.addParticipantID(system.getUserLoggedID());
    system.addServer(newServer);

    cout << "\"Servidor criado\"\n";
  }
  else
  {
    cout << "\"Servidor com esse nome já existe\"\n";
  }
}

/*!
 * Sets the description of a server.
 *
 * \param system The adress fo the system.
 * \param name The name of the server.
 * \param description The new description for the server.
 */
void setDescription(System &system, string name, string description){
  if(system.findServer(name) != nullptr){
    Server* server = system.findServer(name);
    if(server->getOwnerID() == system.getUserLoggedID()){
      server->setDescription(description);

      cout << "\"Descrição do servidor \'" << name << "\' modificada!\"\n";
    }
    else{
      cout << "\"Você não pode alterar a descrição de um servidor que não foi criado por você\"\n";
    }
  }
  else{
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

/*!
 * Sets the invitation code of a server.
 *
 * \param system The adress fo the system.
 * \param name The name of the server.
 * \param code The new invitation code for the server.
 */
void setCode(System &system, string name, string code){
  if (system.findServer(name) != nullptr)
  {
    Server *server = system.findServer(name);
    if (server->getOwnerID() == system.getUserLoggedID())
    {
      server->setCodeInvite(code);
      if(code != ""){
        cout << "\"Código de convite do servidor \'" << name << "\' modificado!\"\n";
      }
      else {
        cout << "\"Código de convite do servidor \'" << name << "\' removido!\"\n";
      }
    }
    else
    {
      cout << "\"Você não pode alterar o código de convite de um servidor que não foi criado por você\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

/*!
 * Removes a new server from the system.
 *
 * \param system The adress of the system.
 * \param name The name of the server.
 */
void removeServer(System &system, string name){
  if (system.findServer(name) != nullptr)
  {
    Server *server = system.findServer(name);
    if (server->getOwnerID() == system.getUserLoggedID())
    {
      system.remServer(*server);
      cout << "\"Servidor \'" << name << "\' removido\"\n";
    }
    else
    {
      cout << "\"Você não é o dono do servidor \'" << name << "\'\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
};

/*!
 * Enters a server.
 *
 * \param system The adress of the system.
 * \param name The name of the server.
 * \param code The invite code for the server.
 */
void enterServer(System &system, string name, string code){
  if(system.findServer(name) != nullptr){
    Server* server = system.findServer(name);
    if(server->getCodeInvite() == code || server->getOwnerID() == system.getUserLoggedID()){
      server->addParticipantID(system.getUserLoggedID());
      server->setUserID(system.getUserLoggedID());
      system.setServerLogged(server);
      cout << "\"Entrou no servidor com sucesso\"\n";
    }
    else{
      cout << "\"Servidor requer código de convite\"\n";
    }
  }
  else
  {
    cout << "\"Servidor \'" << name << "\' não existe\"\n";
  }
}

/*!
 * Leaves the server being visualized.
 *
 * \param system The adress of the system.
 */
void leaveServer(System &system){
  if(system.getServerLogged() != nullptr){
    Server *server = system.findServer(system.getServerLogged()->getName());
    server->setUserID(-1);
    system.setServerLogged();
    cout << "\"Saindo do servidor \'" <<  server->getName() << "\'\"\n";
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Lists all the participants of the server being visualized.
 *
 * \param system The adress of the system.
 */
void listParticipants(System &system){
  if (system.getServerLogged() != nullptr)
  {
    Server* server = system.getServerLogged();
    for (int partID : server->getParticipantIDs())
    {
      User *part = system.findUser(partID);
      cout << part->getName() << endl;
    }
  }
  else 
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Lists all the channels of the server being visualized.
 *
 * \param system The adress of the system.
 */
void listChannels(System &system)
{
  if (system.getServerLogged() !=  nullptr)
  {
    Server* server = system.getServerLogged();
    cout << "#canais de texto\n";
    for (Channel* c : server->getChannels())
    {
      if (ChannelText *ct = dynamic_cast<ChannelText *>(c))
      {
        cout << ct->getName() << endl;
      }
    }
    cout << "#canais de audio\n";
    for (Channel *c : server->getChannels())
    {
      if (ChannelVoice *cv = dynamic_cast<ChannelVoice *>(c))
      {
        cout << cv->getName() << endl;
      }
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

void createChannel(System &system, string name, string type){
  if (system.getServerLogged() != nullptr)
  {
    Server* server = system.findServer(system.getServerLogged()->getName());

    if(type == "texto"){
      for (Channel *c : server->getChannels())
      {
        if (ChannelText *ct = dynamic_cast<ChannelText *>(c))
        {
          if (ct->getName() == name){
            cout << "\"Canal de texto \'" << name << "\' já existe!\"\n";
            return;
          }
        }
      }
      ChannelText newChannel(name);
      system.addChannel(newChannel);
      server->addChannel(system.findTextChannel(name));

      cout << "\"Canal de texto \'" << name << "\' criado\"\n";
    }
    else if (type == "voz")
    {
      for (Channel *c : server->getChannels())
      {
        if (ChannelVoice *ct = dynamic_cast<ChannelVoice *>(c))
        {
          if (ct->getName() == name)
          {
            cout << "\"Canal de voz \'" << name << "\' já existe!\"\n";
            return;
          }
        }
      }
      ChannelVoice newChannel(name);
      system.addChannel(newChannel);
      server->addChannel(system.findVoiceChannel(name));

      cout << "\"Canal de voz \'" << name << "\' criado\"\n";
    }
    else{
      cout << "Tipo de canal inválido.\n Tipos de canais disponíveis:\n - texto\n - voz\n";
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Enters a channel of the server being visualized.
 *
 * \param system The adress of the system.
 * \param name The name of the channel.
 */
void enterChannel(System &system, string name)
{
  if (system.getServerLogged() != nullptr)
  {
    if(system.getChannelLogged() == nullptr){
      Server *server = system.findServer(system.getServerLogged()->getName());
    
      for (Channel *c : server->getChannels())
      {
        if (c->getName() == name)
        {
          system.setChannelLogged(c);
          cout << "\"Entrou no canal \'" << name << "\'\"\n";
          return;
        }
      } 
      cout << "\"Canal \'" << name << "\' não existe\"\n";
    }
    else{
      cout << "\"Você já está visualizando um canal!\"\n";
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

/*!
 * Leaves the channel being visualized.
 *
 * \param system The adress of the system.
 */
void leaveChannel(System &system)
{
  if (system.getServerLogged() != nullptr)
  {
    if (system.getChannelLogged() != nullptr)
    {
      system.setChannelLogged(nullptr);
      cout << "\"Saindo do canal\"\n";
    }
    else
    {
      cout << "\"Você não está visualizando nenhum canal!\"\n";
    }
  }
  else
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
  }
}

string formatDateTime(const chrono::system_clock::time_point &timePoint, const string &format)
{
  time_t currentTime = chrono::system_clock::to_time_t(timePoint);
  tm *timeinfo = localtime(&currentTime);

  const int bufferSize = 100;
  char buffer[bufferSize];

  strftime(buffer, bufferSize, format.c_str(), timeinfo);

  return string(buffer);
}

void sendMessage(System &system, string content){
  Server* s = system.getServerLogged();
  Channel* c = system.getChannelLogged();
  int userID = system.getUserLoggedID();
  string sendFrom = system.findUser(userID)->getName();

  if (s == nullptr)
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
    return;
  }
  if(c == nullptr){
    cout << "\"Você não está visualizando nenhum canal!\"\n";
    return;
  }
  chrono::system_clock::time_point now = chrono::system_clock::now();
  string dateHour = formatDateTime(now, "<%d/%m/%Y - %H:%M>");

  Message newMessage(dateHour, sendFrom, content);

  if (ChannelVoice *ct = dynamic_cast<ChannelVoice *>(c))
  {
    ct->setLastMessage(newMessage);
  }
  else
  {
    ChannelText *cv = dynamic_cast<ChannelText *>(c);
    cv->addMessage(newMessage);
  }
}

void listMessages(System &system){
  Server *s = system.getServerLogged();
  Channel *c = system.getChannelLogged();

  if (s == nullptr)
  {
    cout << "\"Você não está visualizando nenhum servidor\"\n";
    return;
  }
  if (c == nullptr)
  {
    cout << "\"Você não está visualizando nenhum canal!\"\n";
    return;
  }

  if (ChannelVoice *ct = dynamic_cast<ChannelVoice *>(c)){
    if(ct->getLastMessage() != Message()){
      ct->listChannel();
    }
    else{
      cout << "\"Sem mensagem para exibir\"\n";
    }
  }else{
    ChannelText *cv = dynamic_cast<ChannelText *>(c);
    if(!(cv->getMessages().empty())){
      cv->listChannel();
    }
    else
    {
      cout << "\"Sem mensagens para exibir\"\n";
    }
  }
}

