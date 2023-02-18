#include "Message.h"


std::ostream& operator <<(std::ostream& os, Message const& mess)
{
	os  << mess._text     << ' '
		<< mess._sender   << ' '
		<< mess._receiver << '\n';

	return os;
}

std::fstream& operator >>(std::fstream& is, Message& mess)
{
	is >> mess._text >> mess._sender >> mess._receiver;

	return is;
}