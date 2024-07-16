#include <iostream>
#include <string>
#include <cctype>

std::string	capitaliseString(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); ++it)
		*it = std::toupper(*it);
	return (str);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int i = 1; i < argc; ++i)
		std::cout << capitaliseString(static_cast<std::string>(argv[i]));

	std::cout << std::endl;
}

