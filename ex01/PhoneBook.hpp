#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <cstdio>

class 	PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void		addEntry(std::string []);
		int		displayEntries(void) const;

	private:
		Contact		contactsArr[MAX_CONTACTS];

		static int	indexFillContact;
};

#endif
