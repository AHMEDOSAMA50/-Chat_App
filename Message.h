#include<iostream>
#include"user.h"
using namespace std;
class Message:user
{
	protected:int message_id;
protected: string txt;
		 
public:
	string message;
	Message();
	~Message();
	void set_message_id(int m_id);
	int get_message_id();
	void set_user_id(int u_id);
	int get_user_id();

};

