#include "SubStr.h"
bool Staples(std::string textic, char smb)
{
	int start1 = 0, end1 = 0, end2 = 0, i = 0;
	bool digit = false;
	char smb2 = ' ';
	if (smb == '{') smb2 = '}';
	if (smb == '[') smb2 = ']';
	int size = static_cast<int>(textic.size());
	for (i = 0; i < size; i++)
	{
		if (textic[i] == smb)start1 = i;
		if (textic[i] == ',' && start1 > 0)end1 = i;
		if (textic[i] == smb2 && end1 > 0) {
			end2 = i; break;
		}
	}
	if (end2 > 0)
	{
		for (i = start1 + 1; i < end1; i++)
			if (isdigit(textic[i])) digit = true;
			else
				digit = false;

		for (i = end1 + 1; i < end2; i++)
			if (isdigit(textic[i])) digit = true;
			else
				digit = false;
	}

	if (digit)return true;
	else
		return false;
}
int ÑhangeText(int begin, int starPos, int length, std::string& text, bool& gHooks)
{
	std::string chText;

	if (gHooks == true)
		chText = "[" + std::to_string(starPos + 1) + ", " + std::to_string(length) + "]";
	else
		chText = "{" + std::to_string(starPos + 1) + ", " + std::to_string(length) + "}";

	text.replace(begin, length, chText);

	return 1;
}
int CheckSubstr(std::string subs, std::string fullText, int curPos)
{
	int step = 0, startPos = 0, endPos = 0;
	std::string ftext = fullText.substr(curPos); 
	bool gHooks = false;
	int size = static_cast<int>(subs.size());
	for (int i = 0; i < size; i++)
	{
		if (subs[i] == ' ' || ispunct(subs[i]) > 0)step = 1;
		if (isdigit(subs[i]) > 0)step = 1; 
		if (subs[i] == '{' && gHooks == true) 
		{
			startPos = static_cast<int>(ftext.find('{'));
			endPos = static_cast<int>(ftext.find('}'));
			if (startPos > endPos) step = endPos - startPos;
		}
		if (subs[i] == '{' && gHooks == false)step = 1;
		if (subs[i] == '[' && gHooks == true)
		{
			startPos = static_cast<int>(ftext.find('['));
			endPos = static_cast<int>(ftext.find(']'));
			if (startPos < endPos) step = endPos - startPos;
		}
	}

	return step;
}


int RepairStartText(std::string& repText)
{
	std::string tempText = repText;
	std::string changeText;
	char smb, smb2;
	int startPos = 0, endPos = 0, mPos = 0;
	int num1 = 0, len = 0, dl = 0;
	if (Staples(repText, '[')) { smb = '['; smb2 = ']'; }
	else { smb = '{'; smb2 = '}'; }
	do {
		startPos = static_cast<int>(tempText.find(smb));
		endPos = static_cast<int>(tempText.find(smb2));
		if (startPos == -1 || endPos == -1)break;
		mPos = static_cast<int>(tempText.find(','));
		dl = mPos - startPos;
		num1 = stoi(tempText.substr(startPos + 1, dl)) - 1;
		dl = endPos - mPos - 1;
		len = stoi(tempText.substr(mPos + 1, dl)); 
		changeText = repText.substr(num1, len);
		dl = endPos - startPos + 1;
		tempText.replace(startPos, dl, changeText);
	} while (startPos > 0);
	repText = tempText;

	return 1;
}