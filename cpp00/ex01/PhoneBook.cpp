#include "PhoneBook.hpp"

void	PhoneBook::add_contact()
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickename = "";
	std::string darkest_secret = "";
	std::string phone_number = "";
	int bool_a = 0;

	while (std::cin.good() && (first_name.empty() || bool_a == 1))
	{
		bool_a = 0;
		std::cout << "First name : ";
		getline(std::cin, first_name);
		if (first_name.empty())
			std::cout << "Invalid input" << std::endl;
		if (contact[contact_number % 8].set_first_name(first_name) == 1)
		{
			std::cout << "Invalid input" << std::endl;
			bool_a = 1;
		}
	}

	while (std::cin.good() && (last_name.empty() || bool_a == 1))
	{
		bool_a = 0;
		std::cout << "Last name : " ;
		getline(std::cin, last_name);
		if (last_name.empty())
			std::cout << "Invalid input" << std::endl;
		if (contact[contact_number % 8].set_last_name(last_name) == 1)
		{
			std::cout << "Invalid input" << std::endl;
			bool_a = 1;
		}
	}
	while (std::cin.good() && (nickename.empty() || bool_a == 1))
	{
		bool_a  = 0;
		std::cout << "Nickname : ";
		getline(std::cin, nickename);
		if (nickename.empty())
			std::cout << "Invalid input" << std::endl;
		if(contact[contact_number % 8].set_nickname(nickename) == 1)
		{
			std::cout << "Invalid input" << std::endl;
			bool_a = 1;
		}
	}

	while (std::cin.good() && (phone_number.empty() || bool_a == 1))
	{
		bool_a = 0;
		std::cout << "Phone number : ";
		getline(std::cin, phone_number);
		if (phone_number.empty())
			std::cout << "Invalid input" << std::endl;
		if(contact[contact_number % 8].set_phone_number(phone_number) == 1)
		{
			std::cout << "Invalid input" << std::endl;
			bool_a = 1;
		}
	}

	while (std::cin.good() && (darkest_secret.empty() || bool_a == 1))
	{
		bool_a = 0;
		std::cout << "Darkest secret : ";
		getline(std::cin, darkest_secret);
		if (darkest_secret.empty())
			std::cout << "Invalid input" << std::endl;
		contact[contact_number % 8].set_secret(darkest_secret);
	}

	this->contact_number++;
	std::cout << "The contact has been added successfully" << std::endl;
	std::cin.clear();
}

void	PhoneBook::search_contact() const
{
	int	contact_number_2 = 0;
	std::string	str;

	std::cout << "Enter a contact number : ";
	getline(std::cin, str);
	contact_number_2 = atoi(str.c_str());
	if (contact_number_2 < 0 || contact_number_2 > 7)
		std::cerr << "Invalid input" << std::endl;
	else
	{
		std::cout << "first name : " << contact[contact_number_2].get_first_name() << std::endl;
		std::cout << "last name : " << contact[contact_number_2].get_last_name() << std::endl;
		std::cout << "nickname : " << contact[contact_number_2].get_nickname() << std::endl;
		std::cout << "phone number : " << contact[contact_number_2].get_phone_number() << std::endl;
		std::cout << "secret : " << contact[contact_number_2].get_secret() << std::endl;
	}
}

void	PhoneBook::display_contact() const
{
	std::cout << "|--------------Contact Display--------------|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;

	for (size_t i = 0; i < 8; i++)
	{
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << contact[i].get_first_name();
		std::cout << '|' << std::setw(10) << contact[i].get_last_name();
		std::cout << '|' << std::setw(10) << contact[i].get_nickname();
		std::cout << '|' << std::endl;
	}

	std::cout << "|-------------------------------------------|" << std::endl;
	search_contact();
}

void	PhoneBook::display_center() const
{
	std::cout << "|-------------------------------------------------------|" << std::endl;
	std::cout << "|		Press ADD for add contact		|" << std::endl;
	std::cout << "|		Press SEARCH for search contact		|" << std::endl;
	std::cout << "|		Press EXIT for exit			|" << std::endl;
	std::cout << "|-------------------------------------------------------|" << std::endl;
}

int	main()
{
	PhoneBook	Phonebook;
	std::string	input;

	Phonebook.display_center();
	std::cout << "-> ";
	while (getline(std::cin, input))
	{
		if (input == "ADD")
			Phonebook.add_contact();
		else if (input == "SEARCH")
			Phonebook.display_contact();
		else if (input == "EXIT")
			break;
		else
			std::cerr << "Invalid input" << std::endl;
		std::cout << "-> ";
	}
	return (0);
}

PhoneBook::PhoneBook()
{
	this->contact_number = 0;
	std::cout << "PhoneBook constructor called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called" << std::endl;
}


