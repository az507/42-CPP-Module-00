#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cctype>

int	(*initErrorCheckingPointers(std::string *errorMsg, int contactInfoType))(int)
{
	switch (contactInfoType)
	{
		case FIRST_NAME:
		case LAST_NAME:
		case NICKNAME:
			*errorMsg = "Non alphabetical character detected.";
			return (&std::isalpha);
		case PHONE_NUMBER:
			*errorMsg = "Non numeric character detected.";
			return (&std::isdigit);
	}
	return (NULL);
}

bool	isValidContactDetail(std::string contactDetail, int contactInfoType)
{
	int (*charCmpFunc)(int);
	std::string errorMsg;

	charCmpFunc = initErrorCheckingPointers(&errorMsg, contactInfoType);
	if (charCmpFunc && !errorMsg.empty())
	{
		for (std::string::iterator it = contactDetail.begin();
			it != contactDetail.end(); ++it)
		{
			if (!(*charCmpFunc)(*it) && !std::isspace(*it))
			{
				std::cout << errorMsg << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

int	saveContactDetails(PhoneBook *phoneBook)
{
	std::string	input;
	std::string	contactDetails[INFO_FIELDS_NBR];
	int		i = 0;

	while (i < INFO_FIELDS_NBR)
	{
		std::cout << ::contactFields[i] << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (EOF);
		else if (input.empty() || input.find_first_not_of(" \t", 0) == std::string::npos)
			continue ;
		else if (!isValidContactDetail(input, i))
			std::cout << "Invalid contact detail." << std::endl;
		else
			contactDetails[i++].assign(input);
	}
	phoneBook->addEntry(contactDetails);
	return (!EOF);
}

int	main(void)
{
	std::string	command;
	PhoneBook	phoneBook;
	int		result = !EOF;

	for ( ; ; )
	{
		std::cout << "Enter a command to interact with the PhoneBook { ADD, SEARCH, EXIT }: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			result = EOF;
		else if (command.empty() || command.find_first_not_of(" \t", 0) == std::string::npos)
			continue ;
		else if (!command.compare("EXIT"))
			break ;
		else if (!command.compare("ADD"))
			result = saveContactDetails(&phoneBook);
		else if (!command.compare("SEARCH"))
			result = phoneBook.displayEntries();
		else
			std::cout << "Invalid command." << std::endl;

		if (result == EOF) { std::cout.put('\n'); break ; }
	}
	std::cout.flush();
}

