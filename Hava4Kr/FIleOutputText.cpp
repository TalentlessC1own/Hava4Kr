#include "FIleOutputText.h"

void FileOutputText(std::string text)
{
	if (text.empty())
	{
		std::cout << "Enter text first" << std::endl;
		return;
	}
	std::ofstream FileRecorder = CheckFileOutput();
	FileRecorder << text;
	FileRecorder.close();
}
