#pragma once
#include <iostream>
#include <list>
#include <vector>
using namespace std;


class users{

public:
    vector<users> App_users;

private:

	int id;
	string mobile_num;
	string email;
	string password;
	string username;
	string bio;
	string imgurl;
	list<users> contacts;
	//list<chatroom> chatrooms;


public:

	users(string username, string password, string email, string mobile_num, string bio);
	users();
	void setmobileNum(int m);
	string getmobileNum();
	void setpassword(string p);
	string getpassword();
	void setusername(string u);
	string getusername();
	void setbio(string bio);
	string getbio();
	void setimgurl(string imgurl);
	string getimgurl();
	void setuser_contacts(list<users> contacts);
	list<users> getuser_contacts();
	void set_email(string e);
	string getemail();
	int get_id();
	void view_userData();
	void add_Newcontact(int mobileNumber,int use_id);
	void add_p2p_chatroom(int user_id, int contact_id);
	void create_chatgroup(int user_id);
	void add_Newcontact_togroup(int contact_id,int chatroom_id);
};
