#include "Message.h"

Message::Message(const std::string& nameUserFrom,
	const std::string& nameUserTo,
	const std::string& text) :
	nameUserFrom_(nameUserFrom),
	nameUserTo_(nameUserTo),
	text_(text)
{
}



const std::string& Message::getNameFrom() const
{
	return nameUserFrom_;
}



const std::string& Message::getNameTo() const
{
	return nameUserTo_;
}



const std::string& Message::getText() const
{
	return text_;
}