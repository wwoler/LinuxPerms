#pragma once
#include <string>
#include <fstream>
#include <iostream>

class User
{
public:
	User() = default;

	User(std::string const& name,
		std::string const& login,
		std::string const& pass) :
		_name(name),
		_login(login),
		_pass(pass)
	{}

private:

	std::string _name;
	std::string _login;
	std::string _pass;

public:

	friend std::ostream& operator <<(std::ostream& os, User const& user);

	friend std::fstream& operator >>(std::fstream& is, User& user);
};
