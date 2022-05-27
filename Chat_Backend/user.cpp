#include "user.h"
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
	//add to our app_users
}

//this constructor called when a new user continuing without signing in so we just assign him an id 
users::users()
{
	this->id = ++curr_id;
	//add to our app_users
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

void users::setuser_contacts(list<users> contacts)
{
	this->contacts = contacts;
}

list<users> users::getuser_contacts()
{
	return contacts;
}

void users::set_email(string e)
{
	this->email = e;
}

string users::getemail()
{
	return email;
}

int users::get_id()
{
	return id;
}


void users::view_userData()
{
	cout << "id:" << id << endl; 
	cout << "username:" << username << endl;
	cout << "passwovd:" << password << endl; 
	cout << "email:" << email << endl; 
	cout << "mobileNumber:" << mobile_num << endl; 
	cout << "Bio:" << bio << endl; 
	cout << "------------------------------" << endl;
}

void users::add_Newcontact(int mobileNumber,int user_id)
{
	//searching through our users whose user has this mobilenumber and add that user to the contacts list of the user_id

	
}

void users::add_p2p_chatroom(int user_id, int contact_id)
{
	//calling chatroom p2p_constructor to set a p2p_chatroom      note:->:chatroom has 2 constructor one for a group and another for p2p
	//adding user by user to the p2p chatroom created by the implemeted function in chatroom class    note:->: it should only accept 2 users only if a user try to add a new one error must be shown 
	//note that the chatrooms_list of the 2 users must be updated  all that in the implemented functiob p2pchatroom
	//the group chatroom has the same functionality as above execpt you can add more than 2 people and you should update the list of chatrooms of every user added
}

void users::create_chatgroup(int user_id)
{
	//taking user-id who makes the group and initialize a group_chat with this user_id  --*()*--  and he had another function called (add_newcontact_togroup) .

}

void users::add_Newcontact_togroup(int contact_id,int chatroom_id)
{
	//you will add the contact_id to the chatroom_id 
	//the list of the users of this chatroom must be updated with the new one

}


//you should always update the list of every user enter a new chatroom   (chatrooms)
//don't forget that a user can't add a person to his chatroom or his group except he is in his contacts so you must consider that