#include "InputText.h"


void  InputText(std::string* text)
{
    system("cls");
    std::cout << "Enter: ";
    
    while (true)
    {
        std::string buffer = "";
        std::getline(std::cin, buffer);
        std::cin.sync();
        if (buffer.empty())
            break;
        *text +=buffer + "\n";

    }
    //text = nullptr;
}
