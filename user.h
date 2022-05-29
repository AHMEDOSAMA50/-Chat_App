#pragma once
#include "chatroom.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class users{

private:

	int id;
	string mobile_num;
	string email;
	string password;
	string username;
	string bio;
	string imgurl;
	vector <string> contacts;
	vector <int> chatrooms;
	vector <int> app_users;


public:
	users(string username, string password, string email, string mobile_num, string bio);
	users();
	void setmobileNum(int m);
	void setpassword(string p);
	void setusername(string u);
	void setbio(string bio);
	void setimgurl(string imgurl);
	void set_user_contacts(vector<string> contacts);
	void set_email(string e);
	int get_id();
	string getmobileNum();
	string getpassword();
	string getusername();
	string getbio();
	string getimgurl();
	vector<string> get_user_contacts();
	string getemail();
	vector<int> get_user_chatrooms();
	void view_userData();
	void add_Newcontact(string mobileNumber);
	void add_p2p_chatroom(users user,users contact);
	void create_chatgroup(users user, users contact1,users contact2);
	void add_Newcontact_togroup(int contact_id,int chatroom_id);
};
