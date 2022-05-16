#include "Chatroom.h"
#include "user.h"
#include "Message.h"
#include <list>
using namespace std;

Chatroom::Chatroom(int chatroom_id)
{
    this->chatroom_id = chatroom_id;

}
void Chatroom::list_users()
{
   
  
}
void Chatroom::list_messages()
{
    

}
void Chatroom::p2pchat(int user_id,int contact_id,int chatroom_id)
{
    Chatroom chatroom(chatroom_id);
    user user1(user_id);
    user user1(contact_id);

}

void Chatroom::groupchat()
{
}


Chatroom::~Chatroom()
{

}
