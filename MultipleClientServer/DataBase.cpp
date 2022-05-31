#include "DataBase.h"
#include<sqlite3.h>
#include<iostream>
#include <vector>
#include <string>
using namespace std;
int DataBase::callback(void* NotUsed, int argc, char** argv, char** azColName)
{
	for (int i = 0; i < argc; i++) {
		// column name and value
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}
void DataBase::SqliteConnection(string typeQRY, string qry)
{
	const char* s = R"(C:\Users\hamod\Downloads\Project\Project\ChatApplication\bin\Debug\ChatDataBase.db)";

	vector<string>type;
	string result;
	type.push_back("createDB");
	type.push_back("createT");
	type.push_back("select");
	type.push_back("insert");
	type.push_back("update");
	type.push_back("delete");
	for (auto it = type.begin(); it != type.end(); it++)
	{
		if (*it == typeQRY)
		{
			result = typeQRY;
			break;

		}
	}


	sqlite3* DB;
	char* messageError;

	string sql;
	sql = qry;
	int exit = sqlite3_open(s, &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK) {
		cerr << "Error in " << result << "Data function." << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Records " << result << " Successfully!" << endl;


}



//int DataBase::createDB(const char* s)
//{
//	sqlite3* DB;
//
//	int exit = 0;
//	exit = sqlite3_open(s, &DB);
//
//	sqlite3_close(DB);
//	return 0;
//
//
//}
//
//int DataBase::createTable(string Q)
//{
//	const char* dir = R"(U:\Data Structure\Project\ChatApplication\bin\Debug\ChatDataBase.db)";
//	sqlite3* DB;
//	char* messageError;
//
//	string sql =
//
//		"CREATE TABLE Users("
//		"id		INT PRIMARY KEY NOT NULL, "
//		"username	TEXT NOT NULL, "
//		"password	TEXT NOT NULL,"
//		"phone      TEXT  NOT NULL, "
//		"email		TEXT NOT NULL, "
//		"contacts TEXT,"
//		"Bio TEXT);";
//
//
//
//	/* "CREATE TABLE COMPANY("  \
//		"ID INT PRIMARY KEY     NOT NULL," \
//		"NAME           TEXT    NOT NULL," \
//		"AGE            INT     NOT NULL," \
//		"ADDRESS        CHAR(50)," \
//		"SALARY         REAL */
//
//	try
//	{
//		/* Execute SQL statement */
//		int exit = 0;
//		exit = sqlite3_open(dir, &DB);
//		//- sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)
//		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//		if (exit != SQLITE_OK) {
//			cerr << "Error in createTable function." << endl;
//			sqlite3_free(messageError);
//		}
//		else
//			cout << "Table created Successfully" << endl;
//		sqlite3_close(DB);
//	}
//	catch (const exception& e)
//	{
//		//cerr is the standard error stream which is used to output the errors immediately 
//		cerr << e.what();
//	}
//
//	return 0;
//}
//
//
//int DataBase::insertData(string Q)
//{
//	const char* dir = R"(C:\Users\hamod\Downloads\Project\Project\ChatApplication\bin\Debug\ChatDataBase.db)";
//	sqlite3* DB;
//	char* messageError;
//	string sql;
//	sql = Q;
//
//	int exit = sqlite3_open(dir, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//	if (exit != SQLITE_OK) {
//		cerr << "Error in insertData function." << endl;
//		sqlite3_free(messageError);
//	}
//	else
//		cout << "Records inserted Successfully!" << endl;
//
//	return 0;
//}
//
//int DataBase::updateData(string Q)
//{
//
//	sqlite3* DB;
//	char* messageError;
//	const char* dir = R"(U:\Data Structure\Project\ChatApplication\bin\Debug\ChatDataBase.db)";
//
//	string sql;
//	sql = Q;
//	/*"UPDATE COMPANY set SALARY = 23000.00 where ID=1; " \
//		"SELECT * from COMPANY";*/
//
//	int exit = sqlite3_open(dir, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//	if (exit != SQLITE_OK) {
//		cerr << "Error in updateData function." << endl;
//		sqlite3_free(messageError);
//	}
//	else
//		cout << "Records updated Successfully!" << endl;
//
//	return 0;
//}
//int DataBase::deleteData(string Q)
//{
//	sqlite3* DB;
//	char* messageError;
//	const char* dir = R"(U:\Data Structure\Project\ChatApplication\bin\Debug\ChatDataBase.db)";
//	string sql = "DELETE  FROM USERS where ID=5;"\
//		"Select * from Users";
//
//	int exit = sqlite3_open(dir, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
//	if (exit != SQLITE_OK) {
//		cerr << "Error in deleteData function." << endl;
//		sqlite3_free(messageError);
//	}
//	else
//		cout << "Records deleted Successfully!" << endl;
//
//	return 0;
//}
//
//int DataBase::selectData(string Q)
//{
//	const char* dir = R"(U:\Data Structure\Project\ChatApplication\bin\Debug\ChatDataBase.db)";
//
//	string sql = "SELECT * FROM USERS;";
//
//	sqlite3* DB;
//	char* messageError = nullptr;
//
//
//
//	int exit = sqlite3_open(dir, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
//	//exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
//
//
//	return 0;
//}



// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */

//int DataBase::createDB(const char* s)
//{
//    sqlite3* DB;
//
//    int exit = 0;
//    exit = sqlite3_open(s, &DB);
//
//    sqlite3_close(DB);
//    return 0;
//
//  
//}
//
//int DataBase::createTable(const char* s)
//{
//	sqlite3* DB;
//	char* messageError;
//
//	string sql =
//
//		"CREATE TABLE Users("
//		"id		INT PRIMARY KEY NOT NULL, "
//		"username	TEXT NOT NULL, "
//		"password	TEXT NOT NULL,"
//		"phone      TEXT  NOT NULL, "
//		"email		TEXT NOT NULL, "
//		"contacts TEXT,"
//		"Bio TEXT);";
//		
//	
//
//	/* "CREATE TABLE COMPANY("  \
//		"ID INT PRIMARY KEY     NOT NULL," \
//		"NAME           TEXT    NOT NULL," \
//		"AGE            INT     NOT NULL," \
//		"ADDRESS        CHAR(50)," \
//		"SALARY         REAL */
//
//	try
//	{
//		/* Execute SQL statement */
//		int exit = 0;
//		exit = sqlite3_open(s, &DB);
//		//- sqlite3_exec(sqlite3*, const char *sql, sqlite_callback, void *data, char **errmsg)
//		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//		if (exit != SQLITE_OK) {
//			cerr << "Error in createTable function." << endl;
//			sqlite3_free(messageError);
//		}
//		else
//			cout << "Table created Successfully" << endl;
//		sqlite3_close(DB);
//	}
//	catch (const exception& e)
//	{
//		//cerr is the standard error stream which is used to output the errors immediately 
//		cerr << e.what();
//	}
//
//    return 0;
//}
//
//
//int DataBase::insertData(const char* s)
//{
//	sqlite3* DB;
//	char* messageError;
//	string sql
//		("INSERT INTO USERS(ID, USERNAME, EMAIL, PHONE, ADDRESS, PASSWORD) "  
//		"VALUES(1, 'Muhammad Fawzi', 'fawzi@gmail.com', '01211732155', 'California', '123456'); " 
//		"INSERT INTO USERS (ID ,USERNAME,EMAIL,PHONE,ADDRESS,PASSWORD) "  
//		"VALUES (2, 'ahmed osmaa', 'osmaa@gmail.com', '01211732156', 'Texas','123456' ); ");
//	/*("INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
//	"VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
//	"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
//	"VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
//	"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
//	"VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
//	"INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
//	"VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );");*/
//	int exit = sqlite3_open(s, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//	if (exit != SQLITE_OK) {
//		cerr << "Error in insertData function." << endl;
//		sqlite3_free(messageError);
//	}
//	else
//		cout << "Records inserted Successfully!" << endl;
//
//	return 0;
//}
//
//int DataBase::updateData(const char* s)
//{
//	sqlite3* DB;
//	char* messageError;
//
//	string sql= ("UPDATE USERS SET USERNAME = 'OSAMAA' WHERE ID = 2");
//	/*"UPDATE COMPANY set SALARY = 23000.00 where ID=1; " \
//		"SELECT * from COMPANY";*/
//
//	int exit = sqlite3_open(s, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
//	if (exit != SQLITE_OK) {
//		cerr << "Error in updateData function." << endl;
//		sqlite3_free(messageError);
//	}
//	else
//		cout << "Records updated Successfully!" << endl;
//
//	return 0;
//}
//int DataBase::deleteData(const char* s)
//{
//	sqlite3* DB;
//	char* messageError;
//
//	string sql ="DELETE  FROM USERS where ID=5;"\
//		"Select * from Users";
//
//	int exit = sqlite3_open(s, &DB);
//	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
//	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
//	if (exit != SQLITE_OK) {
//		cerr << "Error in deleteData function." << endl;
//		sqlite3_free(messageError);
//	}
//	else
//		cout << "Records deleted Successfully!" << endl;
//
//	return 0;
//}
//
//int DataBase::selectData(const char* s)
//{
//	string sql = "SELECT * FROM USERS;";
//	
//	//sqlite3* DB;
//	//char* messageError;
//
//	//
//	///* "SELECT * from COMPANY"; */
//
//	//int exit = sqlite3_open(s, &DB);
//	///* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
//	//exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
//
//	
//	return 0;
//}


