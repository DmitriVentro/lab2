#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void pole_view(char** pole);
void player(char** pole);
void compuhter(char** pole);
char who_is_the_winner(char** pole);
int main()
{
	setlocale(LC_ALL, "Russian");
	char round;
	round = ' ';
	cout << "��� ���� ��������-������\n�� ������ ������ ������ ����������\n";
	char** pole;
	pole = new char* [3];
	for (int i = 0; i < 3; i++)
		pole[i] = new char[3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			pole[i][j] = ' ';
	do
	{
		pole_view(pole);
		player(pole);
		round = who_is_the_winner(pole);
		if (round != ' ')
			break;
		compuhter(pole);
		round = who_is_the_winner(pole);
	} while (round == ' ');
	if (round == 'X')
		cout << "�����������, �� ��������!\n";
	else
		cout << "��� ������� ���������... ������ ������ � ����.\n";
	pole_view(pole);
	return 0;
}
void pole_view(char** pole) //���������� ����.
{
	for (int i = 0; i < 3; i++)
	{
		cout << pole[i][0] << " | " << pole[i][1] << " | " << pole[i][2];
		if (i != 2) cout << "\n \n";
	}
	cout << endl;
}


void player(char** pole) //��� ������.
{
	int x, y;
	cout << "�������� ������\n������:"; cin >> x;
	cout << "�������: "; cin >> y;
	x--; y--;
	if (x < 0 || y < 0 || x>2 || y>2 || pole[x][y] != ' ')
	{
		cout << "������\n";
		player(pole);
	}
	else pole[x][y] = 'X';
}


void compuhter(char** pole) //��� ����������.
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			if (pole[i][j] == ' ') break;
		if (pole[i][j] == ' ') break; //�����, ����� ����� �� ����� �� i.
	}
	if (i * j == 9)
	{
		cout << "GAME OVER\n";
		exit(0);
	}
	else
		pole[i][j] = 'O';
}


char who_is_the_winner(char** pole)
{
	int i;
	for (i = 0; i < 3; i++)
		if (pole[i][0] == pole[i][1] && pole[i][0] == pole[i][2]) //�������� �����.
			return pole[i][0];
	for (i = 0; i < 3; i++)
		if (pole[0][i] == pole[1][i] && pole[0][i] == pole[2][i]) //�������� ��������.
			return pole[0][i];
	if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2]) //�������� ������� ���������.
		return pole[0][0];
	if (pole[0][2] == pole[1][1] && pole[1][1] == pole[2][0]) //�������� �������������� ���������.
		return pole[0][2];
	return ' ';
}

