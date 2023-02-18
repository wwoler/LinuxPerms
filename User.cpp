#include "User.h"

std::ostream& operator <<(std::ostream& os, User const& user)
{
	os  << user._name  << ' '
		<< user._login << ' '
		<< user._pass  << '\n';

	return os;
}

std::fstream& operator >>(std::fstream& is, User& user)
{
	is >> user._login >> user._name >> user._pass;

	return is;
}