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
	cout << "Это игра Крестики-Нолики\nВы будете играть против компьютера\n";
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
		cout << "Поздравляем, вы победили!\n";
	else
		cout << "Вас победил компьютер... Теперь живите с этим.\n";
	pole_view(pole);
	return 0;
}
void pole_view(char** pole) //показывает поле.
{
	for (int i = 0; i < 3; i++)
	{
		cout << pole[i][0] << " | " << pole[i][1] << " | " << pole[i][2];
		if (i != 2) cout << "\n \n";
	}
	cout << endl;
}


