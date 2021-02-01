
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>



// need to add the clipboard part and it's doooneee ha!

int main()
{
	std::string line;
	std::vector<std::string> lines;
	std::ifstream myFile{"lines.txt"};
	if (myFile.is_open())
	{
		while (myFile >> line)
		{
			lines.push_back(line);
		}
		myFile.close();
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
			std::cout << "you pasted something" << std::endl;
		}
	}
}

