
#include <iostream>
#include <Windows.h>








int main()
{
	while (true)
	{
		Sleep(100);
		if (GetAsyncKeyState(VK_UP))
		{
			std::cout << "you pressed key up" << std::endl;
		}
	}
}

