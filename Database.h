#pragma once
#include "User.h"
#include "Message.h"
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;


class DataBase
{
public:
	DataBase();
	~DataBase();

private:
	std::fstream users_stream;
	std::fstream messages_stream;

public:

	std::vector<User> read_users();

	std::vector<User> read_messages();

	void write_user(User const& user);

	void write_message(Message const& mess);

};


