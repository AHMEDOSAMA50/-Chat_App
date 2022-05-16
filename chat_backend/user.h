#pragma once
#include <iostream>
#include "Chatroom.h"
#include <list>
#include <stack>
using namespace std;


class user
{
public: 
	
	int id;
	int mobile_num;
	string password;
	string username;
	string bio;
	stack<user> user_contacts;
	list<Chatroom> user_chatrooms;

public:

	user(int);
	void add_new_contacts(string,int,int,int);
	void add_p2p_chatroom(int,int,int);
	void add_chatgroup();

};

