#include "FileInput.h"

void FileInput(std::string* text)
{
	std::ifstream file;
	std::string file_name;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::cin >> file_name;
		try
		{
			file.open(file_name);
			std::cout << "Sucefull file open " << std::endl;
			break;
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect file name or way.Try again ." << std::endl;
			continue;


		}
	}
	std::string buff;
	while (true)
	{
		try
		{
			std::getline(file, buff);
			*text += buff + "\n";
		}
		catch (const std::exception&)
		{
			break;
		}
	}
	std::cin.clear();
	std::cin.ignore();

}
