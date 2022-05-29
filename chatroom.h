#pragma once
#include "user.h"
#include "Message.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class chatroom
{

private:

	int chatroom_id;
	vector<int> chatroom_users_ids;
	map<int,string> users_messasges;
	
public:

	chatroom(int ,int);
	chatroom(int, int, int);
	void set_chatroom_id(int id);
	int get_chatroom_id();
	vector<int> get_chatroom_users_ids();
};

