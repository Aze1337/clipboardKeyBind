
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>





// global variable
int current_line = 0;

int main()
{
	std::string line;
	std::vector<std::string> lines;
	std::ifstream myFile{ "lines.txt" };
	if (myFile.is_open())
	{
		while (myFile >> line)
		{
			lines.push_back(line);
		}
		myFile.close();
		if (OpenClipboard(nullptr))
		{
			const char* output = lines[0].c_str();
			current_line++;
			const size_t len = strlen(output) + 1;
			HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
			memcpy(GlobalLock(hMem), output, len);
			GlobalUnlock(hMem);
			EmptyClipboard();
			SetClipboardData(CF_TEXT, hMem);
			CloseClipboard();
		}
	}
	else
	{
		std::cout << "could not open lines.txt" << std::endl;
	}

	while (true)
	{
		Sleep(120);
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x56))
		{
			// clipboard implementation here
			if (OpenClipboard(nullptr))
			{
				if (current_line >= lines.size())
				{
					return 0;
				}
				const char* output = lines[current_line].c_str();
				current_line++;
				const size_t len = strlen(output) + 1;
				HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
				memcpy(GlobalLock(hMem), output, len);
				GlobalUnlock(hMem);
				EmptyClipboard();
				SetClipboardData(CF_TEXT, hMem);
				CloseClipboard();
			}
			std::cout << "you pasted something" << std::endl;
		}
	}
}