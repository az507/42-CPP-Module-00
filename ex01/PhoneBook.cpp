#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{

}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::addEntry(std::string contactDetails[])
{
	if (indexFillContact == MAX_CONTACTS)
		indexFillContact = 0;
	contactsArr[indexFillContact++].fillContact(contactDetails);
}

static std::string	resizeStr(std::string text)
{
	std::string	newstr;

	if (text.length() <= 10)
		return (text);

	newstr.assign(text).replace(9, text.length(), ".");

	return (newstr);
}

static int	getIndexFromUser(void)
{
	int	index;

	for ( ; ; )
	{
		std::cout << "Which contact to display: ";
		std::cin >> std::noskipws >> index;

		if (std::cin.eof())
			return (EOF);
		else if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid number." << std::endl;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (std::cin.gcount() > 1)
				std::cout << "Non-numeric character left in stream." << std::endl;
			else if (index < 1 || index > MAX_CONTACTS)
				std::cout << "Number not within range of contacts." << std::endl;
			else
				break ;
		}
	}
	return (index);
}

int	PhoneBook::displayEntries(void) const
{
	int	index;
	int	i;

	for (i = 0; i < MAX_CONTACTS; ++i)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << resizeStr(contactsArr[i].getContactInfo(FIRST_NAME)) << "|";
		std::cout << std::setw(10) << resizeStr(contactsArr[i].getContactInfo(LAST_NAME)) << "|";
		std::cout << std::setw(10) << resizeStr(contactsArr[i].getContactInfo(NICKNAME)) << "|" << std::endl;
	}

	index = getIndexFromUser();
	if (index-- == EOF)
		return (EOF);

	for (i = 0; i < INFO_FIELDS_NBR; ++i)
		std::cout << ::contactFields[i] << ": " << contactsArr[index].getContactInfo(i) << std::endl;

	return (!EOF);
}

int	PhoneBook::indexFillContact = 0;

