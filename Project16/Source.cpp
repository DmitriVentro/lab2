#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;
void MENU();                                                       //����
void fieldView(int** a, int n, int m);                             //����������� ����
int livingPoints(int** a, int n, int m);                           //����� �����
void neighborhood(int nb[][2], int x, int y);                      //�������� �����
int amountLivingNB(int** a, int n, int m, int x, int y);           //���-�� ����� �������
void NextGen(int** a, int** a1, int n, int m);                     //��������� ��������� �����
void CopyCopy(int** a, int** a1, int n, int m);                    //����������� �������� ����
int FieldsCompare(int** a, int** a1, int n, int m);                //��������� �����
int main()
{
	int n, m, key;
	MENU();
	cout << endl << ":"; cin >> key;
	srand(time(NULL)); //����� ������� ������� ������� ����
	do
		switch (key)
		{
		case 1:
			n = rand() % 21;
			m = rand() % 21;
			break;
		case 2:
			cout << "Enter n and m\n";
			cin >> n;
			cin >> m;
			break;
		case 0:
			cout << "Goodbye! See you soon!\n";
			break;
		default:
			cout << "ERROR!\n";
			break;
		}
	while (n < 4 || m < 4);
	cout << "\nSize of the field: " << n << " rows and " << m << " columns\n";
	int** field; //������ ���� (����������� ������)
	field = new int* [n];
	for (int i = 0; i < n; i++)
		field[i] = new int[m];
	std::random_device rd; //���������� �������� �������
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10000);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			int num = dis(gen);
			if (num % 2 == 0)
				field[i][j] = 1;
			else
				field[i][j] = 0;
		}
	int** PreviousField; //������ ���� ��� ����������� ����������� ���������
	PreviousField = new int* [n];
	for (int i = 0; i < n; i++)
		PreviousField[i] = new int[m];
	int livingpoints = -1;
	bool Edem = false;
	do
	{
		fieldView(field, n, m);                                   //����� ����
		CopyCopy(field, PreviousField, n, m);                     //�������� ����
		NextGen(field, PreviousField, n, m);                      //���������� �����
		Edem = FieldsCompare(field, PreviousField, n, m) == 0;    //���������� ����
		livingpoints = livingPoints(field, n, m);                 //��������� ���������� ����� ������
		if (Edem)
			cout << "Edem Garden\n";                              //������ ���
		if (livingpoints == 0)
			cout << "YOU DIED\n";                                 //��� ������. �����.
		Sleep(2000); //���������� �����, ����� ������������ ����� ������� ����
	} while (livingpoints != 0 || !Edem);
	return 0;
