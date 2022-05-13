#pragma once
#include<iostream>
#include"user.h"
#include "Message.h"
#include<string>
using namespace std;
class Chatroom:  Message,  user
{
    protected:int chat_id;
        string chat_type;
        char chatroom_type[10];
        list
    public:
        void list_users();
        void list_message();
        void chatroom_typ();
        Chatroom();
        ~Chatroom();

};


