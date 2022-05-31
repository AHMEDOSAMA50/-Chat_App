#include <iostream>
#include <sqlite3.h>
#include "DataBase.h"
#include "chatroom.h"
#include "user.h"
using namespace std;

void main()
{
	users use1("sadasdsa", "sdcsdcasdasda", "asdxasdasddasd", "0324234234234", "oadadawdasdasd");
	users use2("sadasdsa", "sdcsdcasdasda", "asdxasdasddasd", "0324234234234", "oadadawdasdasd");
	users use3("sadasdsa", "sdcsdcasdasda", "asdxasdasddasd", "0324234234234", "oadadawdasdasd");


	use1.set_message("aefadasdasdasd");
	use1.set_message("aefadasdasdasd");


	use2.set_message("weadwadawsdasd");
	use2.set_message("asdasdasdasd");
	

	use1.get_messages();
	use2.get_messages();
	use3.get_messages();

}



