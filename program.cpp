#include <iostream>
#include <sqlite3.h>
#include "DataBase.h"
#include "chatroom.h"
#include "user.h"
using namespace std;

int main()
{
	/*DataBase db;*/

	users user1("memo","memo123","memeo@gmail.com","0123123123","love cooking");
	users user2("zezo","zezo123","zezo@gmail.com","01324222222","love taking pictures");
	users user3("soso","soso123","soso@gmail.com","0237842342","love surfing");

	user1.add_Newcontact("0123242342");
	user1.add_Newcontact("0762342342");
	user2.add_Newcontact("0827348213");
	user2.add_Newcontact("0234823423");
	user3.add_Newcontact("0234823422");
	user3.add_Newcontact("0242324233");


	user1.add_p2p_chatroom(user1, user2);
	user1.create_chatgroup(user1, user2, user3);
	user2.add_p2p_chatroom(user2, user3);

	user1.view_userData();
	user2.view_userData();
	user3.view_userData();




	//user1 chatrooms :    [1]   [2]   
	//user2 chatrooms :    [1]   [2]  [3]
	//user3 chatrooms :    [2]   [3]









	////delete statemnet
	//string sql = "DELETE  FROM Users where id=4;";
	//db.SqliteConnection("delete", sql);

}



