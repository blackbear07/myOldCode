#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include "Hack.h"
#include <algorithm>

void SetColor(int text, int bg);

void startHaks(bool isHaks, bool isWallhack, bool isBunnyhop, bool isTriggerbot);

Hack hack;

int main()
{
	bool isHaks = false;
	bool isWallhack = false;
	bool isBunnyhop = false;
	bool isTriggerbot = false;

	setlocale(LC_ALL, "Russian");

	bool isExit = false;
	bool chekWrite = false;
	bool ishelp = false;

	std::string UserName = "ADMIN";
	std::string version = "1v.2u.7b.";
	std::string datetime = "NOT";
	std::string satys;
	std::string write = "";
	std::string errorMessage = "";

	IS_EXIT:
	std::thread thHaks(startHaks, isHaks, isWallhack, isBunnyhop, isTriggerbot);

	if (!isExit) {

		system("cls");
		SetColor(7, 0);
		std::cout << std::endl;
		std::cout << "     Bios Hack ";  
		SetColor(9, 0);
		std::cout << "     VERSION: "; 
		SetColor(10, 0);
		std::cout << version;
		std::cout << std::endl;
		std::cout << std::endl;
		SetColor(9, 0);
		std::cout << "     UserName: "; 
		SetColor(10, 0);
		std::cout << UserName; 
		SetColor(9, 0);
		std::cout << "  datetime: "; 
		SetColor(10, 0);
		std::cout << datetime << std::endl;
		std::cout << std::endl;
		SetColor(9, 0);
		std::cout << "     CS-GO: ";
		if (hack.Start()) {
			SetColor(10, 0);
			satys = "The game is working";
		}
		else {
			SetColor(12, 0);
			satys = "Game is not running";
		}
		std::cout << satys << std::endl;

		SetColor(9, 0);
		std::cout << std::endl;
		std::cout << "	MENU" << std::endl;
		std::cout << std::endl;

		SetColor(9, 0);
		std::cout << "	Wall Hack: ";
		if (isWallhack) {
			SetColor(10, 0);
			std::cout << "enable";
		}
		else {
			SetColor(12, 0);
			std::cout << "disabled";
		}
		std::cout << std::endl;

		SetColor(9, 0);
		std::cout << "	Trigger Bot: ";
		if (isTriggerbot) {
			SetColor(10, 0);
			std::cout << "enable";
		}
		else {
			SetColor(12, 0);
			std::cout << "disabled";
		}
		std::cout << std::endl;

		SetColor(9, 0);
		std::cout << "	Bunny Hop: ";
		if (isBunnyhop) {
			SetColor(10, 0);
			std::cout << "enable";
		}
		else {
			SetColor(12, 0);
			std::cout << "disabled";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		SetColor(7, 0);
		std::cout << "	HAKS: ";
		if (isHaks) {
			SetColor(10, 0);
			std::cout << "ENABLE";
		}
		else {
			SetColor(12, 0);
			std::cout << "DISABLED";
		}
		std::cout << std::endl;
		SetColor(7, 0);
		std::cout << "	HELP MENU: ";
		if (ishelp) {
			SetColor(10, 0);
			std::cout << "ENABLE";
		}
		else {
			SetColor(12, 0);
			std::cout << "DISABLED";
		}
		std::cout << std::endl;

		std::cout << std::endl;

		if (errorMessage != "") {
			SetColor(4, 0);
			std::cout << "	ERROR: ";
			SetColor(6, 0);
			std::cout << errorMessage << std::endl;
			errorMessage = "";
			std::cout << std::endl;
		}

		if (ishelp) {
			SetColor(7, 0);
			std::cout << "	|------------------------------------------------------------|" << std::endl;
			std::cout << "	|    HELP MENU                                               |" << std::endl;
			std::cout << "	|------------------------------------------------------------|" << std::endl;
			std::cout << "	|    ON MENU START FUNCTION COMMAND                          |" << std::endl;
			std::cout << "	|------------------------------------------------------------|" << std::endl;
			std::cout << "	| ALL    | WALL HACK   | TRIGGER BOT   | BUNNY HOP   | HACK  |" << std::endl;
			std::cout << "	|--------|-------------|---------------|-------------|-------|" << std::endl;
			std::cout << "	| allon  | wallhackon  | triggerboton  | bunnyhopon  | start |" << std::endl;
			std::cout << "	| an     | whon        | tbon          | bhon        | st    |" << std::endl;
			std::cout << "	|        | whn         | tbn           | bhn         |       |" << std::endl;
			std::cout << "	|        | 1+          | 2+            | 3+          |       |" << std::endl;
			std::cout << "	|------------------------------------------------------------|" << std::endl;
			std::cout << "	|    OFF MENU STOP FUNCTION COMMAND                          |" << std::endl;
			std::cout << "	|------------------------------------------------------------|" << std::endl;
			std::cout << "	| ALL    | WALL HACK   | TRIGGER BOT   | BUNNY HOP   | HACK  |" << std::endl;
			std::cout << "	|--------|-------------|---------------|-------------|-------|" << std::endl;
			std::cout << "	| alloff | wallhackoff | triggerbotoff | bunnyhopoff | stop  |" << std::endl;
			std::cout << "	| af     | whoff       | tboff         | bhoff       | sp    |" << std::endl;
			std::cout << "	|        | whf         | tbf           | bhf         |       |" << std::endl;
			std::cout << "	|        | 1-          | 2-            | 3-          |       |" << std::endl;
			std::cout << "	|------------------------------------------------------------|" << std::endl;
			std::cout << "	|   ON and OFF MENU DEFALUT FUNCTION COMMAND                 |" << std::endl;
			std::cout << "	|------------------------------------------------------------|" << std::endl;
			std::cout << "	| ALL    | WALL HACK   | TRIGGER BOT   | BUNNY HOP   | HACK  |" << std::endl;
			std::cout << "	|--------|-------------|---------------|-------------|-------|" << std::endl;
			std::cout << "	| all    | wallhack    | triggerbot    | bunnyhop    |       |" << std::endl;
			std::cout << "	| a      | whoff       | tbo           | bhoff       |       |" << std::endl;
			std::cout << "	|        | 1           | 2             | 3           |       |" << std::endl;
			std::cout << "	|------------------------------------------------------------|" << std::endl;
		}

		SetColor(13, 0);
		std::cout << "	write: ";
		SetColor(7, 0);
		std::cin >> write;
		std::cout << std::endl;
		SetColor(7, 0);
		transform(write.begin(), write.end(), write.begin(),::tolower);

		chekWrite = false;

		if (write == "exit" || write == "e" || write == "esc") {
			isExit = true;
			chekWrite = true;
		}

		if (write == "allon" || write == "an" || write == "wallhackon" || write == "whon" || write == "whn" || write == "1+") {
			isWallhack = true;
			chekWrite = true;
		}

		if (write == "alloff" || write == "af" || write == "wallhackoff" || write == "whoff" || write == "whf" || write == "1-") {
			isWallhack = false;
			chekWrite = true;
		}

		if (write == "all" || write == "a" || write == "wallhack" || write == "wh" || write == "1") {
			chekWrite = true;
			if (isWallhack) {
				isWallhack = false;
			}
			else {
				isWallhack = true;
			}
		}

		if (write == "allon" || write == "an" || write == "triggerboton" || write == "tbon" || write == "tbn" || write == "2+") {
			isTriggerbot = true;
			chekWrite = true;
		}

		if (write == "alloff" || write == "af" || write == "triggerbotoff" || write == "tboff" || write == "tbf" || write == "2-") {
			isTriggerbot = false;
			chekWrite = true;
		}

		if (write == "all" || write == "a" || write == "triggerbot" || write == "tb" || write == "2") {
			chekWrite = true;
			if (isTriggerbot) {
				isTriggerbot = false;
			}
			else {
				isTriggerbot = true;
			}
		}

		if (write == "allon" || write == "an" || write == "bunnyhopon" || write == "bhon" || write == "bhn" || write == "3+") {
			isBunnyhop = true;
			chekWrite = true;
		}

		if (write == "alloff" || write == "af" || write == "bunnyhopoff" || write == "bhoff" || write == "bhf" || write == "3-") {
			isBunnyhop = false;
			chekWrite = true;
		}

		if (write == "all" || write == "a" || write == "bunnyhop" || write == "bh" || write == "3") {
			chekWrite = true;
			if (isBunnyhop) {
				isBunnyhop = false;
			}
			else {
				isBunnyhop = true;
			}
		}

		if (write == "start" || write == "st") {
			chekWrite = true;
			if (isWallhack || isTriggerbot || isBunnyhop) {
				isHaks = true;
			}
			else {
				errorMessage = "nothing is connected";
			}
		}

		if (write == "stop" || write == "sp") {
			chekWrite = true;
			if (isHaks) {
				isHaks = false;
			}
			else {
				errorMessage = "The millet is not running";
			}
		}

		if (write == "help" || write == "h") {
			chekWrite = true;
			if (ishelp) {
				ishelp = false;
			}
			else {
				ishelp = true;
			}
		}
		if (write == "helpon" || write == "hn") {
			chekWrite = true;
			ishelp = true;
		}
		if (write == "helpoff" || write == "hf") {
			chekWrite = true;
			ishelp = false;
		}
	
		if (!chekWrite) {
			errorMessage = "there is no such command";
			chekWrite = false;
		}
		thHaks.detach();
		if (!isExit)
			goto IS_EXIT;
	}
	std::cout << "Выход ";
}

void SetColor(int text, int bg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); //Получаем дескриптор вывода на консоль
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));  //Устанавливаем атрибуты текста
}

void startHaks(bool isHaks = false, bool isWallhack = false, bool isBunnyhop = false, bool isTriggerbot = false) {
	while (isHaks)
	{
		if (isWallhack)
			hack.ShowWallHaks();
		if (isBunnyhop)
			hack.ShowBunnyHop();
		if (isTriggerbot)
			hack.ShowTriggerBot();
		if (!isHaks)
			break;
	}
}
