/* "John Rambo" is an engaging console-based C++ game that brings the legendary
character to life.In this game, players take control of Rambo, guiding him through
various obstacles, destroying crates, and combating computer - operated tanks.The
gameplay is reminiscent of classic console - based games, where the character moves
upwards automatically, giving the illusion of forward movement*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<ctime>
void lifeCheck(); // Check the Life of Rambo where maximum lives are 3
void forwardMovement(); // It moves the objects backwards which gives illusion of forward movement of rambo
void tank(); // They are Computer Operated Tanks which can shoot bullets and if the tanks collide with rambo it dies. 3 Tanks will be for level 1 and 5 for level 2
void setup(); // It stores the initial values of variables of games
void draw(); // Its draws the whole map of the game with crates, Rambo, Tanks, road and obstacles with it
void position(); // Its controls the position of rambo using arrow keys
void bullets(); // It controls the bullets shoot by Rambo. If They hit the tanks or crates they destroy
void bulletsTank(); // It controls the bullets of the tank. Rambo loses a life if teh bullet hit it.
void obstacle1(); // It cotrols the obstacles in the map. If rambo collide with any of the three obstacles it will lose a life
void levelCheck(); // The game has two levels and this functions checks the level of the game
void road(); // It is a speed road where the speed of the Rambo will be increased to 1.5x
void crates(); // It controls the crates which can collide with rambo and Rambo will lose its life. If Rambo hits 5 crates by shooting. It gains one life
using namespace std;
const int width = 50;
const int height = 30;
char map[height][width];
int xp1, yp1, xp2, yp2, yb, xt1, yt1, xtank1, xtank2, ytank1, ytank2, life, oby1, obx1, oby2, obx2, oby3, obx3, rx, ry, cx, cy;

int movement = (rand() % (width - 5)) + 2;
char name[20];
bool borderLeft = false;
bool borderRight = true;
bool level1;
bool level2;
bool level1Over;
bool level2Over;
bool gameOver;
bool tank1Destroy = false;
int distanceRambo;
int tanks;
int cratesLife;
void setup() {
	gameOver = false;
	distanceRambo = 0;
	cratesLife = 0;
	level1Over = false;
	level2Over = false;
	level1 = true;
	xp1 = width / 2;
	yp1 = height - 2;
	xp2 = (width / 2) + 1;
	yp2 = height - 2;
	yb = yp1 - 1;
	oby1 = (rand() % (height - 15)) + 2;
	obx1 = (rand() % (width - 10)) + 2;
	oby2 = (rand() % (height - 15)) + 2;
	obx2 = (rand() % (width - 10)) + 2;
	oby3 = (rand() % (height - 15)) + 2;
	obx3 = (rand() % (width - 10)) + 2;
	xtank1 = movement;
	xtank2 = movement + 3;
	xt1 = xtank1;
	yt1 = 5;
	ytank1 = 4;
	ytank2 = 1;
	life = 3;
	rx = width / 2 - 1;
	ry = 0;
	cx = rand() % (width - 4) + 2;
	cy = rand() % (height - 4) + 2;
	system("color 0A");
}
void draw()
{
	system("cls");
	distanceRambo = distanceRambo + 2;
	cout << distanceRambo << " Meters Achieved" << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {
			if (j == 0 || j == width - 1) {
				map[i][j] = '|';
			}
			else if (i == 0 || i == height - 1) {
				map[i][j] = '-';
			}
			else {
				map[i][j] = ' ';
			}

		}
	}
	if (tank1Destroy == false)
	{
		map[yt1][xt1] = '|';
		tank();
	}
	crates();
	obstacle1();
	road();
	map[yp1][xp1] = 'R';
	map[yp2][xp2] = 'A';
	map[yb][xp1] = '|';
	Sleep(10);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
}
void tank()
{
	Sleep(10);
	for (int i = ytank2; i <= ytank1; i++)
	{
		for (int j = xtank1; j <= xtank2; j++)
		{
			if (i == ytank2 || i == ytank1)
			{
				map[i][j] = '-';
			}
			else
			{
				map[i][j] = '|';
			}
		}
	}
	if ((xtank2 != width - 1) && borderLeft == true) {
		xtank2++;
		xtank1++;

	}
	else if (xtank2 == width - 1) {
		borderRight = true;
		borderLeft = false;
	}
	if ((xtank1 != 2) && borderRight == true) {
		xtank2--;
		xtank1--;
	}
	else if (xtank1 == 2) {
		borderLeft = true;
		borderRight = false;
	}
	for (int i = ytank2; i <= ytank1; i++)
	{
		if (i == yp1 || i == yp2) {

			for (int j = xtank1; j <= xtank2; j++)
			{
				if (j == xp1 || j == xp2) {
					life--;
					PlaySound(TEXT("deadsound"), NULL, SND_SYNC);


					Sleep(1000);
					break;
				}
			}
			break;

		}

	}


}
void position() {
	if (_kbhit())
	{
		map[yp1][xp1] = ' ';
		switch (_getch())
		{
		case 75:
			if (xp1 > 1) {
				xp1--;
				xp2--;

				PlaySound(TEXT("rambomove"), NULL, SND_SYNC);

			}
			break;
		case 77:
			if (xp1 < width - 2) {
				xp1++;
				xp2++;

				PlaySound(TEXT("rambomove"), NULL, SND_SYNC);

			}
			break;
		case 72:
			if (yp1 > 16)
			{
				yp1--;
				yp2--;
				yb--;

				PlaySound(TEXT("rambomove"), NULL, SND_SYNC);

			}
			break;
		case 80:
			if (yp1 < height - 1)
			{
				yp1++;
				yp2++;
				yb++;

				PlaySound(TEXT("rambomove"), NULL, SND_SYNC);

			}
			break;
		default:
			break;
		}
	}
}
void bullets() {
	if (yb == 1 || yb <= ytank1) {
		map[yb][xp1] = ' ';
		yb = yp1 - 1;
	}
	else {
		if (_kbhit()) {
			switch (_getch())
			{
			case 's':

				PlaySound(TEXT("rambofire"), NULL, SND_SYNC);

				while (yb > 1 || yb >= ytank1) {
					if (level1) {
						Sleep(50);
					}
					else if (level2) {
						Sleep(10);
					}
					map[yb][xp1] = ' ';
					yb = yb - 3;
					draw();
					if (yb <= ytank1 && yb >= ytank2) {
						for (int i = xtank1; i <= xtank2; i++) {
							if (xp1 == i) {
								tanks--;
								cout << "Tank has been hit" << endl;
								PlaySound(TEXT("tankdestroyed"), NULL, SND_SYNC);

								PlaySound(TEXT("jvh"), NULL, SND_SYNC);


								movement = (rand() % (width - 5)) + 2;
								xtank1 = movement;
								xtank2 = movement + 3;
								ytank1 = 4;
								ytank2 = 1;
								xt1 = xtank1;
								yt1 = 5;

							}
						}
					}
					if (yb <= cy) {
						for (int i = cx; i <= cx + 3; i++) {
							if (xp1 == i) {
								cy = rand() % (height - 4) + 2;
								cx = rand() % (width - 4) + 2;
								PlaySound(TEXT("cratedestroy"), NULL, SND_SYNC);


								cratesLife++;
								if (cratesLife == 5) {
									cout << "Life Has Been Increased" << endl;
									life++;

								}
							}
						}
					}
				}
				break;
			default:
				break;
			}
		}

	}

}
void bulletsTank() {

	Sleep(10);
	if (yt1 == ytank1 + 1 || yt1 == ytank1 + 10) {
		xt1 = xtank1;
	}
	if (yt1 == ytank1 + 10)
	{
		yt1 = ytank1 + 1;
	}
	else
	{
		yt1 += 1;
	}
	if ((xt1 == xp1 || xt1 == xp2) && (yt1 == yp1 || xt1 == yp2))
	{
		life--;
		PlaySound(TEXT("deadsound"), NULL, SND_SYNC);


		Sleep(10);
	}
}
void forwardMovement() {
	if (ytank1 != height - 12) {
		ytank1++;
		ytank2++;

	}
	if (oby1 != height - 1) {
		oby1++;
	}
	else {
		oby1 = (rand() % (height - 15)) + 2;
	}
	if (oby2 != height - 1) {
		oby2++;
	}
	else {
		oby2 = (rand() % (height - 15)) + 2;
	}
	if (oby3 != height - 1) {
		oby3++;
	}
	else {
		oby3 = (rand() % (height - 15)) + 2;
	}
	if (cy != height - 4) {
		cy++;
	}
	else {
		cy = rand() % (height - 4) + 2;
		cx = rand() % (width - 4) + 2;
	}
}
void obstacle1()
{
	for (int i = obx1; i < obx1 + 3; i++)
	{
		map[oby1][i] = 'H';
		if ((i == xp1 || i == xp2) && (yp1 == oby1 || yp2 == oby1)) {
			life--;

			PlaySound(TEXT("deadsound"), NULL, SND_SYNC);

			Sleep(10);
			break;
		}

	}
	for (int i = obx2; i < obx2 + 3; i++)
	{
		map[oby2][i] = 'H';
		if ((i == xp1 || i == xp2) && (yp1 == oby2 || yp2 == oby2)) {
			life--;
			PlaySound(TEXT("deadsound"), NULL, SND_SYNC);


			Sleep(10);
			break;
		}

	}
	for (int i = obx3; i < obx3 + 3; i++)

	{
		map[oby3][i] = 'H';
		if ((i == xp1 || i == xp2) && (yp1 == oby3 || yp2 == oby3)) {
			life--;
			PlaySound(TEXT("deadsound"), NULL, SND_SYNC);


			Sleep(10);
			break;
		}
	}
}
void lifeCheck() {
	if (life <= 0)
	{
		PlaySound(TEXT("dzanum"), NULL, SND_SYNC);

		cout << "You are Eliminated \n";
		Sleep(1000);
		gameOver = true;

	}
	else
	{
		cout << life << " lifes are left \n";
	}
	cout << cratesLife << " Crates Hit" << endl;

}
void tankLifeCheck() {
	if (tanks <= 0 && level1 == true) {
		cout << "You have won The LEVEL 1" << endl;
		PlaySound(TEXT("rambowin"), NULL, SND_SYNC);


		tank1Destroy = true;
		level1Over = true;
		level1 = false;
		cout << "Wait For 10 second to Start Level 2" << endl;
		Sleep(10000);
		level2 = true;
		level2Over = false;
		tank1Destroy = false;
		levelCheck();
	}
	if (tanks <= 0 && level2 == true) {
		cout << "You have won The LEVEL 2" << endl;
		PlaySound(TEXT("rambowin"), NULL, SND_SYNC);


		tank1Destroy = true;
		level2Over = true;
		gameOver = true;
		cout << "Wait for 10 Seconds" << endl;
		Sleep(10000);

	}
	else {
		cout << tanks << " Tanks are left" << endl;
	}
}
void levelCheck() {
	if (level1) {
		tanks = 3;
		cout << "Level 1" << endl;
	}
	else if (level2) {
		tanks = 5;
		cout << "Level 2" << endl;
	}
}
void road()
{
	for (int i = ry; i < height; i++)
	{
		for (int j = rx; j < rx + 3; j++)
		{
			if (j == rx || j == rx + 2)
			{
				map[i][j] = '|';
			}
			else
			{
				map[i][j] = ' ';
			}
		}
	}
}
void crates()
{
	for (int i = cy; i < cy + 3; i++)
	{
		for (int j = cx; j < cx + 3; j++)
		{
			if (i == cy || i == cy + 2)
			{
				map[i][j] = '-';
			}
			else if (j == cx || j == cx + 2)
			{
				map[i][j] = '|';
			}
			else
			{
				map[i][j] = 'C';
			}
		}
	}
	for (int i = cy; i < cy + 3; i++)
	{
		if (i == yp1 || i == yp2) {

			for (int j = cx; j < cx + 3; j++)
			{
				if (j == xp1 || j == xp2) {
					life--;
					PlaySound(TEXT("deadsound"), NULL, SND_SYNC);

					Sleep(10);
					break;
				}
			}
			break;
		}
	}
}
int main() {
	setup();
	levelCheck();
	while (gameOver != true) {
		forwardMovement();
		draw();
		bullets();
		position();
		bulletsTank();
		lifeCheck();
		tankLifeCheck();
		if (level1 && xp1 != rx + 1) {
			Sleep(50);
		}
		else if (level2 || xp1 == rx + 1) {
			Sleep(10);
		}
	}
	cout << "Game Over" << endl;
	cout << "Enter your Name" << endl;
	cin.getline(name, 20);
	ofstream outdata;
	outdata.open("Scores.txt", ios::app);
	outdata << name << " = " << distanceRambo << endl;
	system("pause");
	return 0;
}