#include<iostream>
#include"user.h"
using namespace std;



class Message
{
	
public:
	int msgID;
	int user_id;
	string txt;
	string status;


		 
public:

	Message();
	void set_message_id(int);
	int get_message_id();
	void set_user_id(int);
	int get_user_id();
	
};

