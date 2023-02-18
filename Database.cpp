#include "Database.h"

DataBase::DataBase()
{
	users_stream    = std::fstream("users.txt", std::ios::in | std::ios::out);
	messages_stream = std::fstream("messages.txt", std::ios::in | std::ios::out);

	if (!users_stream.is_open())
	{
		users_stream = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);

		if (!users_stream.is_open()) throw std::exception();

		fs::permissions("users.txt",
			fs::perms::group_all | fs::perms::others_all,
			fs::perm_options::remove);
	}

	if (!messages_stream.is_open())
	{
		messages_stream = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);

		if (!messages_stream.is_open()) throw std::exception();

		fs::permissions("messages.txt",
			fs::perms::group_all | fs::perms::others_all,
			fs::perm_options::remove);

	}
}

DataBase::~DataBase()
{
	users_stream.close();
	messages_stream.close();
}

std::vector<User> DataBase::read_users()
{
	users_stream.clear();
	users_stream.seekg(0, std::ios::beg);

	std::vector<User> vec;
	vec.reserve(15);
	User temp;

	users_stream.get();

	while (users_stream.good())
	{
		users_stream.unget();

		users_stream >> temp;
		vec.push_back(temp);

		users_stream.get();
		users_stream.get();
	}

	return vec;

}

std::vector<Message> DataBase::read_messages()
{
	messages_stream.clear();
	messages_stream.seekg(0, std::ios::beg);

	std::vector<Message> vec;
	vec.reserve(15);
	Message temp;

	messages_stream.get();

	while (messages_stream.good())
	{
		messages_stream.unget();

		messages_stream >> temp;
		vec.push_back(temp);

		messages_stream.get();
		messages_stream.get();
	}

	return vec;
}

void DataBase::write_user(User const& user)
{
	users_stream.clear();
	users_stream.seekp(0, std::ios::end);

	users_stream << user;

}

void DataBase::write_message(Message const& mess)
{
	messages_stream.clear();
	messages_stream.seekp(0, std::ios::end);

	messages_stream << mess;
}