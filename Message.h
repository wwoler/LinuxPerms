#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Message
{
public:

	Message() = default;

	Message(std::string const& text,
		std::string const& sender,
		std::string const& receiver) :
		_text(text),
		_sender(sender),
		_receiver(receiver)
	{}

	~Message() = default;

private:

	std::string _text;
	std::string _sender;
	std::string _receiver;

public:

	friend std::ostream& operator <<(std::ostream& os, Message const& mess);
	friend std::fstream& operator >>(std::fstream& is, Message& mess);
};