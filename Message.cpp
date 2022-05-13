#include "Message.h"
#include "user.h"
user use;
void Message::set_message_id(int m_id)
{
	message_id = m_id;
}
int Message::get_message_id()
{
	return message_id;
}
void Message::set_user_id(int u_id)
{
	use.id = u_id;
}
int Message::get_user_id()
{
	return id;
}
