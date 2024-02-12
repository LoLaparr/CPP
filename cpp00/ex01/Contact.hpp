#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	std::string	get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string	get_phone_number() const;
	std::string	get_secret() const;

	int	set_first_name(std::string first_name);
	int	set_last_name(std::string last_name);
	int	set_nickname(std::string nickname);
	int	set_phone_number(std::string phone_number);
	int	set_secret(std::string darkest_secret);

	Contact();
	~Contact();
};

#endif
