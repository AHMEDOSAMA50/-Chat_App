#pragma once
#include <iostream>
#include "Chatroom.h"
#include <stack>
#include <list>
using namespace std;


class user
{
public: 
	
	int id;
	int mobile_num;
	string password;
	string f_name;
	string l_name;
	string bio;
	stack<user> contacts;
	list<Chatroom> user_chatrooms;

public:

	user();
};

