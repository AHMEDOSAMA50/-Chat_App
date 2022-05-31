#include "user.h"
#include <iostream>
#include <string>
#include <cassert>
#include"Message.h"
using namespace std;

//auto_incremented ID
static int curr_id = 0;

users::users(string username, string password, string email, string mobile_num, string bio)
{
	this->id = ++curr_id;
	this->email = email;
	this->bio = bio;
	this->imgurl = "";
	this->password = password;
	this->username = username;
	this->mobile_num = mobile_num;
	this->contacts = {};
	app_users.push(curr_id);
}

//this constructor called when a new user continuing without signing in so we just assign him an id 
users::users()
{
	this->id = ++curr_id;
	app_users.push(curr_id);

}

void users::setmobileNum(int m)
{
	this->mobile_num = m;
}

string users::getmobileNum()
{
	return mobile_num;
}

void users::setpassword(string p)
{
	this->password = p;
}

string users::getpassword()
{
	return password;
}

void users::setusername(string u)
{
	this->username = u;
}

string users::getusername()
{
	return username;
}

void users::setbio(string bio)
{
	this->bio = bio;
}

string users::getbio()
{
	return bio;
}

void users::setimgurl(string imgurl)
{
	this->imgurl = imgurl;
}

string users::getimgurl()
{
	return imgurl;
}

void users::set_user_contacts(stack<string> contacts)
{
	this->contacts = contacts;
}

stack<string> users::get_user_contacts()
{
	return contacts;
}

void users::set_email(string e)
{
	this->email = e;
}

void users::set_message(string msg)
{
	Message ms(msg);
	//message.set_message_txt(msg);
	messages.push(msg);
	messages_list.push_back(msg);
}

void users::undo_message()
{
	if (messages.empty())
	{
		cout << "No Messages to delete";
	}
	else {
		for (int i = 0; i < 1; i++)
		{
			messages.pop();
		}
	}
}

string users::getemail()
{
	return email;
}

int users::get_id()
{
	return id;
}

void users::get_messages()
{
	while (!messages.empty())
	{
		string s = messages.top();
		messages_list.push_front(s);
		messages.pop();
	}
	for (string x : messages_list)
	{
		cout << x;
		cout << endl;
	}
	cout << endl;
}

stack<int> users::get_user_chatrooms()
{
	return chatrooms;
}

void users::view_userData()
{
	cout << "id:" << id << endl;
	cout << "username:" << username << endl;
	cout << "passwovd:" << password << endl;
	cout << "email:" << email << endl;
	cout << "mobileNumber:" << mobile_num << endl;
	cout << "Bio:" << bio << endl;
	while (!contacts.empty()) {
		cout << "contact:" << contacts.top() << endl;
		contacts.pop();
	}
	cout << endl;
	while (!chatrooms.empty())
	{
		cout << "chatroom_id" << chatrooms.top() << endl;
		messages.pop();
	}
	cout << endl;

}

void users::add_Newcontact(string mobileNumber)
{
	contacts.push(mobile_num);
}

void users::add_p2p_chatroom(users user, users contact)
{
	chatroom p2pchat(user.get_id(), contact.get_id());
	int chat_id = p2pchat.get_chatroom_id();
	user.chatrooms.push(chat_id);
	contact.chatrooms.push(chat_id);
}

void users::create_chatgroup(users  user, users contact1, users contact2)
{
	chatroom groupchat(user.get_id(), contact1.get_id(), contact2.get_id());
	int chat_id = groupchat.get_chatroom_id();
	user.chatrooms.push(chat_id);
	contact1.chatrooms.push(chat_id);
	contact2.chatrooms.push(chat_id);
}

void users::add_Newcontact_togroup(int contact_id, int chatroom_id)
{
	//search through the list of chatrooms id's and add a contatc id to it
}
