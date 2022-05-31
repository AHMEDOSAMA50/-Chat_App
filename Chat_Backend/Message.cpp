#include "Message.h"
#include<iostream>
using namespace std;

Message::Message(string text)
{
	this->txt = text;
	static int curr_id = 0;
	this->message_id = ++curr_id;
}

void Message::set_message_id(int msg_id)
{
	this->message_id = msg_id;
}

void Message::set_message_txt(string txt)
{
	this->txt = txt;
}

int  Message::get_message_id()
{
	return message_id;
}
