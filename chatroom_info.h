#pragma once
#include"user.h"
#include"Chatroom.h"
class chatroom_info:user,Chatroom {
public:
	chatroom_info();
	void set_user_id(int u_id);
	int get_user_id();
	void set_chatroom_id(int ch_id);
	int get_chatroom_id();
	void lastseen();
};
