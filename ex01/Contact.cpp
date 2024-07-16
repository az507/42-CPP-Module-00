#include "Contact.hpp"

std::string const	contactFields[INFO_FIELDS_NBR] = {	"First name", "Last name", "Nickname",
								"Phone number", "Darkest secret"	};

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

void	Contact::fillContact(std::string contactDetails[5])
{
	this->_firstName = contactDetails[FIRST_NAME];
	this->_lastName = contactDetails[LAST_NAME];
	this->_nickname = contactDetails[NICKNAME];
	this->_phoneNumber = contactDetails[PHONE_NUMBER];
	this->_darkestSecret = contactDetails[DARKEST_SECRET];
}

std::string	Contact::getContactInfo(int contactInfoType) const
{
	switch (contactInfoType)
	{
		case FIRST_NAME:
			return (this->_firstName);
		case LAST_NAME:
			return (this->_lastName);
		case NICKNAME:
			return (this->_nickname);
		case PHONE_NUMBER:
			return (this->_phoneNumber);
		case DARKEST_SECRET:
			return (this->_darkestSecret);
	}
	return (std::string());
}

