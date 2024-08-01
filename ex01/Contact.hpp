#ifndef CONTACT_HPP
# define CONTACT_HPP

# define INFO_FIELDS_NBR 5
# define MAX_CONTACTS 8

# include <string>
# include <iostream>

enum	contactInfoType
{
	firstname = 0,
	lastname,
	nickname,
	phonenumber,
	darkestsecret
};

extern const std::string	contactFields[INFO_FIELDS_NBR];

class	Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		fillContact(std::string []);

		std::string	getContactInfo(int) const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
