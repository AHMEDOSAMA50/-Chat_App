#pragma once
#include<iostream>
#include"user.h"
#include "Message.h"
#include<string>
#include <ctime>
using namespace std;



class Chatroom
{
protected:

        int chatroom_id;
        string chatroom_typ;
        string lastseen;
        list<user> users;
        list<Message> messages;

    

public:
        Chatroom(int);
        void list_users();
        void list_messages();
        void groupchat();
        void p2pchat(int,int,int);
        ~Chatroom();

};


