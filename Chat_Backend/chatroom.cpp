#include "chatroom.h"

//auto_incremented ID
static int currchat_id = 0;

//constructor for p2p chatroom
chatroom::chatroom(int user_id,int contact_id)
{
	this->chatroom_id = ++currchat_id;
	chatroom_users_ids.push_back(user_id);
	chatroom_users_ids.push_back(contact_id);
}

//constructor for group chat
chatroom::chatroom(int user_id, int contact_id1, int contact_id2)
{
	this->chatroom_id = ++currchat_id;
	chatroom_users_ids.push_back(user_id);
	chatroom_users_ids.push_back(contact_id1);
	chatroom_users_ids.push_back(contact_id2);
}

void chatroom::set_chatroom_id(int id)
{
	this->chatroom_id = id;
}

int chatroom::get_chatroom_id()
{
	return chatroom_id;
}

vector<int> chatroom::get_chatroom_users_ids()
{
	return chatroom_users_ids;
}

//void chatroom::add_to_group(int contact_id)
//{
// add to the list of the chat_group the contact_id
// create new object of users with the contact_id
//	
//}
