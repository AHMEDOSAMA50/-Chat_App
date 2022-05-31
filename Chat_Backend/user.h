#pragma once
#include "chatroom.h"
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include "Message.h"
using namespace std;

class users {

public:
	stack <int> app_users;
	list<string> messages_list;

private:
	int id;
	string mobile_num;
	string email;
	string password;
	string username;
	string bio;
	string imgurl;
	stack <string> contacts;
	stack <int> chatrooms;
	stack <string> messages;

public:
	users(string username, string password, string email, string mobile_num, string bio);
	users();
	void setmobileNum(int m);
	void setpassword(string p);
	void setusername(string u);
	void setbio(string bio);
	void setimgurl(string imgurl);
	void set_user_contacts(stack<string> contacts);
	void set_email(string e);
	void set_message(string msg);
	void undo_message();
	int get_id();
	void get_messages();
	string getmobileNum();
	string getpassword();
	string getusername();
	string getbio();
	string getimgurl();
	stack<string> get_user_contacts();
	string getemail();
	stack<int> get_user_chatrooms();
	void view_userData();
	void add_Newcontact(string mobileNumber);
	void add_p2p_chatroom(users user, users contact);
	void create_chatgroup(users user, users contact1, users contact2);
	void add_Newcontact_togroup(int contact_id, int chatroom_id);
};
