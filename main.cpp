
#include <iostream>
#include <Windows.h>





int main()
{
	while (true)
	{
		Sleep(120);
		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x56))
		{
			std::cout << "you pasted something" << std::endl;
		}
	}
}

