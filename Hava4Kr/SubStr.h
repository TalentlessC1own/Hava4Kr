#pragma once

#include<string>
#include <fstream>
#include <iostream>

bool Staples(std::string textic, char);

int ÑhangeText(int begin, int starPos, int length, std::string& text, bool& gHooks);

int CheckSubstr(std::string subs, std::string fullText, int curPos);

int RepairStartText(std::string& repText);

