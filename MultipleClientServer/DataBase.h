#pragma once
#include<string>

class DataBase
{
public:
	/*static int createDB(const char* s);
	static int createTable(std::string);
	static int insertData(std::string);
	static int updateData(std::string);
	static int deleteData(std::string);
	static int selectData(std::string);*/
	static int callback(void* NotUsed, int argc, char** argv, char** azColName);
	static void SqliteConnection(std::string, std::string);
};

