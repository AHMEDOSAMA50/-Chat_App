#include "user.h"
#include <map>
#include "Chatroom.h"

user::user(int id)
{
	this->id = id;

}

void user::add_new_contacts(string contact_username, int contact_mobile_num,int contact_id,int user_id)
{
	user new_user(contact_id);
   	user user(user_id);
	new_user.mobile_num = contact_mobile_num;
	new_user.username = contact_username;

	user.user_contacts.push(new_user);
	new_user.user_contacts.push(user);


	cout << "contact added successfully" << endl;
}

void user::add_p2p_chatroom(int contact_id,int chatroom_id,int user_id)
{
	user new_user(contact_id);
	Chatroom chatroom(chatroom_id);
	chatroom.p2pchat(contact_id,user_id,chatroom_id);

}

void user::add_chatgroup()
{
}
