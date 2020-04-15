#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <random>
#include <Windows.h>
using namespace std;
void fV(int** a, int n, int m);
int lP(int** a, int n, int m, int s, int de);
void nbh(int nb[][2], int x, int y);
int aLNB(int** a, int n, int m, int x, int y);
void NG(int** a, int** a1, int n, int m);
int FC(int** a, int** a1, int n, int m, int x, int s, int su, int de, int det);
void CC(int** a, int** a1, int n, int m, int s, int su, int de, int det);
int main()
{
	setlocale(LC_ALL, "ru");
	int n, m, x = 0, s = 0, su = -50, de = 0, det = -50;
	cout << "������� ����������� ���� :";
	cin >> n;
	cin >> m;
	cout << "\n������ ����: " << n << " ����� � " << m << " ��������\n";
	int** field;
	field = new int* [n];
	for (int i = 0; i < n; i++)
		field[i] = new int[m];
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10000);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int num = dis(gen);
			if (num % 2 == 0)
				field[i][j] = 1;
			else
				field[i][j] = 0;
		}
	int** PreviousField;
	PreviousField = new int* [n];
	for (int i = 0; i < n; i++)
		PreviousField[i] = new int[m];
	int lp = -1;
	bool Edem = false;
	bool death = false;
	do
	{
		fV(field, n, m);
		Edem = FC(field, PreviousField, n, m, x, s, su, de, det) == 0;
		death = FC(field, PreviousField, n, m, x, s, su, de, det) == -2;
		CC(field, PreviousField, n, m, s, su, de, det);
		NG(field, PreviousField, n, m);
		lp = lP(field, n, m, s, de);
		if (Edem)
		{
			cout << "���� ������\n";
			return 0;
		}
		if (lp == 0 || death)
		{
			cout << "��� ������\n";
			return 0;
		}
		Sleep(100);
	} while (lp != 0 || !Edem);
	return 0;
}

void fV(int** a, int n, int m)
{
	//if (n <= 30 && m <= 30)
	//{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			{
				if (a[i][j] == 1)
					cout << '+';
				else
					cout << ' ';
				cout << '|';
			}
		}
		cout << endl;

	}
	cout << endl << "---------" << endl;
	//}
	//else
	cout << endl << "---------" << endl;
}

int lP(int** a, int n, int m, int s, int de) // ����� ���� ����� � ������� ������
{
	int count = 0, sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1)
			{
				count++;
				sum++;
				s++;
			}
	de = n * m - sum;
	cout << "����� ������ - " << sum << "   ̸����� ������ - " << de << endl;
	return count;
}

void nbh(int nb[][2], int x, int y)
{
	int k = 0;
	for (int i = x - 1; i <= x + 1; i++)
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (i == x && j == y)
				continue;
			nb[k][0] = i;
			nb[k][1] = j;
			k++;
		}
}

int aLNB(int** a, int n, int m, int x, int y)
{
	int count = 0;
	int nb[8][2];
	int x_, y_;
	nbh(nb, x, y);
	for (int i = 0; i < 8; i++)
	{
		x_ = nb[i][0];
		y_ = nb[i][1];
		if (x_ < 0 || y_ < 0)
			continue;
		if (x_ >= n || y_ >= m)
			continue;
		if (a[x_][y_] == 1)
			count++;
	}
	return count;
}

void NG(int** a, int** a1, int n, int m)
{
	int livingNB, p;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			p = a1[i][j];
			livingNB = aLNB(a1, n, m, i, j);
			if (p == 0)
			{
				if (livingNB == 3)
					a[i][j] = 1;
			}
			else
				if (livingNB < 2 || livingNB > 3)
					a[i][j] = 0;
		}
}

void CC(int** a, int** a1, int n, int m, int s, int su, int de, int det) //����������� ������� 
{
	unsigned int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			a1[i][j] = a[i][j];
			su = s;
			det = de;
		}
	}
}
int FC(int** a, int** a1, int n, int m, int x, int s, int su, int de, int det)  //�������� �� ����� � ����
{
	unsigned int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if ((a[i][j] != a1[i][j]) || ((s == su) || (de == det)))
			{


				return -1;

			}
		}
	}
	return 0;
}