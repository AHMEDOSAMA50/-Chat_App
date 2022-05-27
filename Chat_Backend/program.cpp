#include <iostream>
#include <sqlite3.h>
#include "DataBase.h"
#include "user.h"
using namespace std;

int main()
{
	
	users user1("Klevy", "K9", "ahmed@gmail.com", "0213123231", "i love cussing");
	users user2("Bahaa", "HDY123", "ahmed@gmail.com", "0213123231", "i love bullying");
	users user3("Hassana", "fuck!!", "ahmed@gmail.com", "0213123231", "i love doing shit!");

	user1.view_userData();
	user2.view_userData();
	user3.view_userData();


}



