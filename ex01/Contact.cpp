#include "Contact.hpp"

const std::string	contactFields[INFO_FIELDS_NBR] = {

	"First name",
	"Last name",
	"Nickname",
	"Phone number",
	"Darkest secret"
};

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

void	Contact::fillContact(std::string contactDetails[5])
{
	this->_firstName = contactDetails[firstname];
	this->_lastName = contactDetails[lastname];
	this->_nickname = contactDetails[nickname];
	this->_phoneNumber = contactDetails[phonenumber];
	this->_darkestSecret = contactDetails[darkestsecret];
}

std::string	Contact::getContactInfo(int contactInfoType) const
{
	switch (contactInfoType)
	{
		case firstname:
			return (this->_firstName);
		case lastname:
			return (this->_lastName);
		case nickname:
			return (this->_nickname);
		case phonenumber:
			return (this->_phoneNumber);
		case darkestsecret:
			return (this->_darkestSecret);
	}
	return (std::string());
}

