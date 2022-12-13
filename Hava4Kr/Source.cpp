#include "InputText.h"
#include <clocale>
#include <vector>
#include "Check.h"
#include "FIleOutputText.h"
#include "FileInput.h"
#include "SubStr.h"
#include <locale>
#include <Windows.h>

enum class Type
{
	console = 1,
	file,
	none
};
enum class Menu
{
	input = 1,
	change,
	repair,
	out,
	none
};

enum class RepairMenu
{
	InputFile = 1,
	UseEntered
};


int main()
{
	setlocale(LC_ALL, "ru_RU.cp1251");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "kHava 415 var 6 kr 4 " << std::endl;
	RepairMenu repairMenuItem;
	int interval = 0;
	setlocale(LC_ALL, "ru_RU.cp1251");
	const int Yes = 1;
	bool gHooks = false;
	int substrLen;
	std::string text = "";
	Menu menu_item = Menu::none;
	Type type = Type::none;
	int step;
	while (true)
	{

		
		std::cout << "\n1 - Input" << std::endl
			<< "2 - Change text" << std::endl
			<< "3 - repair text" << std::endl
			<< "4 - Exit" << std::endl;
		menu_item = static_cast<Menu>(CheckMenu(4));
		switch (menu_item)
		{
		case Menu::input:
			text.clear();
			std::cout << "1 - console\n2 - file" << std::endl;
			type = static_cast<Type>(CheckMenu(2));
			switch (type)
			{
			case Type::console:
				InputText(&text);
				std::cout << "Save to file?\n1.Yes\n2.No" << std::endl;
				if (CheckMenu(2) == Yes)
					FileOutputText(text);
				break;
			case Type::file:
				FileInput(&text);
				break;
			}
			break;
		
		case Menu::change:
			if (text.empty())
			{
				std::cout << "Enter text first" << std::endl;
				break;
			}
			
			std::cout << "Initial text: " << text << std::endl;
			std::cout << std::endl << "Characters: " << text.length() << "\nEnter the length of the substring.  " << std::endl;;
			substrLen = CheckIntValue();

			interval = static_cast<int>(text.length()) - substrLen;
			if (interval <= 0)
			{
				std::cout << "Substring greater than original text" << std::endl;
				break;
			}
			else {
				gHooks = Staples(text, '{');

				for (int i = 0; i < (interval - 1); i++)
				{
					std::string findSubstring = text.substr(i, substrLen); //выбор подстроки от позиции по количеству замены
				
					step = CheckSubstr(findSubstring, text, i); //шаг сдвига для поиска следующего фрагмента, пропуск пробелов и знаков препинания
					
					 
					if (step > 0) { i += step - 1; continue; }
					int textStartPos = 0;
					int sPos = i;
					int changes = 0;
					bool count = false;
					do {
						std::string::size_type n = text.find(findSubstring, sPos);
						if (n == std::string::npos) 
						{
							if (changes > 0)
							{
								i = i + (substrLen - 1);
							}
							break;
						}
						else
						{
							if (!count)
							{
								count = true;
								textStartPos = (int)n;
							}
							else
							{ 
								changes = СhangeText((int)n, textStartPos, substrLen, text, gHooks);
							}

							sPos = static_cast<int>(n) + substrLen;
						}

					} while (true);
				}

				std::cout << "Chenged: " << text << std::endl;

				std::cout << "Save to file?\n1.Yes\n2.No"<< std::endl;
				if (CheckMenu(2) == Yes)
					FileOutputText(text);
				break;
			}
		case Menu::repair:
			std::cout << "1 - Input text from file\n2 - Used entered text" << std::endl;
			repairMenuItem = static_cast<RepairMenu>( CheckMenu(2));
			switch (repairMenuItem)
			{
			case RepairMenu::InputFile:
				text.clear();
				FileInput(&text);
				break;
			case RepairMenu::UseEntered:
				if (text.empty() )
				{
					std::cout << "No text entered" << std::endl;
					continue;
				}
			}
			std::cout << "Initial text:\t " << text << std::endl;
			RepairStartText(text);
			std::cout << "Changed text:\t" << text << std::endl;
			std::cout << "Save to file?\n1.Yes\n2.No" << std::endl;
			if (CheckMenu(2) == Yes)
				FileOutputText(text);
			break;
		case Menu::out:
			return 0;
		}
		

	}
}

