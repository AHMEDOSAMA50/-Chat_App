#pragma once
#include<iostream>
#include"Chatroom.h"
#include<stack>
using namespace std;
class user:Chatroom
{
public: int id;
	int mobile_num;
	string password;
	string f_name;
	string l_name;
	string bio;
	Chatroom chat;
	stack<user>contacts;
public:
	user();
	~user();
};

