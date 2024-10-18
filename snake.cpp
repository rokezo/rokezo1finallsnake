#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

int main() {
	srand(time(0));
	system("title Snake Game");
	system("mode con cols=70 lines=31");
	MoveWindow(GetConsoleWindow(), 50, 50, 2000, 2000, true);

	const int width = 50, height = 30;
	const int max_length = 50;
	int array_X[max_length];
	int array_Y[max_length];
	int length = 1;
	array_X[0] = width / 2;
	array_Y[0] = height / 2;
	int dx = 1, dy = 0;
	int X_apple;
	int Y_apple;
	do {
		X_apple = rand() % (width - 2) + 1;
		Y_apple = rand() % (height - 2) + 1;
	} while (X_apple != array_X[length - 1] && Y_apple != array_Y[length - 1]);

	int sleep_time = 100;

	char snake = '*';
	char apple = 'o';
	char head = 1;
	COORD c;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false };
	SetConsoleCursorInfo(h, &cci);

	SetConsoleTextAttribute(h, 4);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			char s;
			if (x == 0 && y == 0)
				s = '#';
			else if (x == 0 && y == height - 1)
				s = '#';
			else if (y == 0 && x == width - 1)
				s = '#';
			else if (y == height - 1 && x == width - 1)
				s = '#';
			else if (y == 0 || y == height - 1)
				s = '#';
			else if (x == 0 || x == width - 1)
				s = '#';
			else s = ' ';
			cout << s;
		}
		cout << "\n";
	}

	c.X = X_apple;
	c.Y = Y_apple;
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 12);
	cout << apple;

	c.X = array_X[0];
	c.Y = array_Y[0];
	SetConsoleCursorPosition(h, c);
	SetConsoleTextAttribute(h, 10);
	cout << head;

	bool flag = true;
	do {
		Sleep(sleep_time);

		if (_kbhit()) {
			int k = _getch();
			if (k == 0 || k == 224)
				k = _getch();
			switch (k) {
			case 80:
				dy = 1;
				dx = 0;
				break;
			case 72:
				dy = -1;
				dx = 0;
				break;
			case 75:
				dy = 0;
				dx = -1;
				break;
			case 77:
				dy = 0;
				dx = 1;
				break;
			case 27:
				flag = false;
				break;
			}
		}

		int X = array_X[length - 1] + dx;
		int Y = array_Y[length - 1] + dy;
		if (X == 0 || X == width - 1 || Y == 0 || Y == height - 1) {
			flag = false;
		}
		else if (X == X_apple && Y == Y_apple) {
			c.X = array_X[length - 1];
			c.Y = array_Y[length - 1];
			SetConsoleCursorPosition(h, c);
			cout << snake;

			length++;
			c.X = array_X[length - 1] = X;
			c.Y = array_Y[length - 1] = Y;
			SetConsole
