#pragma once
#include<iostream>
using namespace std;
class Message
{
	struct status {
		bool status_type;
		string date;
		string time;
	};

private:
	string txt;
	int message_id;

public:

	Message(string);

	void set_message_id(int);

	int get_message_id();

	//void set_message(string text);

	void set_message_txt(string);

	//void  undo_message();


};

