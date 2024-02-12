#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int	contact_number;
	void	search_contact() const;

public:
	void	add_contact();
	void	display_contact() const;
	void	display_center() const;
	PhoneBook();
	~PhoneBook();
};

#endif
