#include "Contact.hpp"

std::string Contact::get_first_name() const
{
	return (this->first_name);
}

std::string Contact::get_last_name() const
{
	return (this->last_name);
}

std::string Contact::get_nickname() const
{
	return (this->nickname);
}

std::string Contact::get_phone_number() const
{
	return (this->phone_number);
}

std::string Contact:: get_secret() const
{
	return (this->darkest_secret);
}

int	Contact::set_first_name(std::string	first_name)
{
	if (first_name == "")
		return (1);
	for	(size_t i = 0; i < first_name.length(); i++)
	{
		if (!isalpha(first_name[i]))
		{
			if (isspace(first_name[i]))
				continue ;
			else
				return (1);
		}
	}
	if (first_name.length() > 10)
	{
		first_name[9] = '.';
		first_name.erase(10, first_name.length() -10);
	}
	this->first_name = first_name;
	return (0);
}

int	Contact::set_last_name(std::string last_name)
{
	if (last_name == "")
		return (1);
	for (size_t i = 0; i < last_name.length(); i++)
	{
		if (!isalpha(last_name[i]))
		{
			if (isspace(last_name[i]))
				continue ;
			else
				return (1);
		}
	}
	if (last_name.length() > 10)
	{
		last_name[9] = '.';
		last_name.erase(10, last_name.length() - 10);
	}
	this->last_name = last_name;
	return (0);
}

int	Contact::set_nickname(std::string nickname)
{
	if (nickname == "")
		return (1);
	for (size_t i = 0; i < nickname.length(); i++)
	{
		if (!isalpha(nickname[i]))
		{
			if (isspace(nickname[i]))
				continue;
			else
				return (1);
		}
	}
	if (nickname.length() > 10)
	{
		nickname[9] = '.';
		nickname.erase(10, nickname.length() - 10);
	}
	this->nickname = nickname;
	return (0);
}

int	Contact::set_phone_number(std::string phone_number)
{
	if (phone_number == "")
		return (1);
	for (size_t i = 0; i < phone_number.length(); i++)
		if (!isdigit(phone_number[i]))
			return (1);
	if (phone_number.length() > 10)
	{
		phone_number[9] = '.';
		phone_number.erase(10, phone_number.length() - 10);
	}
	this->phone_number = phone_number;
	return (0);
}

int	Contact::set_secret(std::string darkest_secret)
{
	if (darkest_secret == "")
		return (1);
	for (size_t i = 0; i < darkest_secret.length(); i++)
		if (isdigit(darkest_secret[i]))
			return (1);
	if (darkest_secret.length() > 10)
	{
		darkest_secret[9] = '.';
		darkest_secret.erase(10, darkest_secret.length() - 10);
	}
	this->darkest_secret = darkest_secret;
	return (0);
}

Contact::Contact()
{
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Contact destructor called" << std::endl;
}
