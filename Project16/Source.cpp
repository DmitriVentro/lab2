#include <iostream>
#include <math.h>
using namespace std;
namespace first_task {
	void enter_values(int& rows, int& cols, int& a, int& b)
	{
		cout << "Левая граница значений = ";
		cin >> a;
		cout << "Правая граница значений = ";          // Левая и правая граница значений в матрице
		cin >> b;
		cout << "Сколько столбцов X строк = ";
		cin >> rows;
		cout << "\n";
		cols = rows;                        //Количество столбиков в матрице
	}
	void show_arr(int** arr, int rows, int cols)
	{
		cout << "Матрица:\n";

		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
		}
	}
	void fill_arr(int** arr, int rows, int cols, int a, int b)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = a + rand() % (b - a + 1);
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void red_area_analyze(int** arr, int rows)
	{
		cout << "Выше главной и побочной диагональ:";
		for (int i = 0; i < rows; i++)
		{
			for (int j = i + 1; j < rows - i - 1; j++)
			{
				cout << arr[i][j] << " ";
			}
		}
		cout << endl;
		system("pause");
	}
	void red_area_show_element(int** arr, int rows, int& min, int& imin, int& jmin)
	{
		cout << "Минимальный положительный элемент: ";
		for (int i = 0; i < rows; i++)
		{
			for (int j = i + 1; j < rows - i - 1; j++)
			{

				if (arr[i][j] > 0)
				{
					if (arr[i][j] < min)
					{
						min = arr[i][j];
						imin = i;
						jmin = j;
					}
				}
			}
		}
		if (min > 0 && min != INT_MAX)
		{
			cout << min << "\n";; //Вывод минимального положительного числа выше гланой диагонали
			system("pause");
		}
		else {
			cout << "There aren`t positive elements\n";
		}

	}
	void green_area_analyze(int** arr, int cols)
	{
		cout << "Ниже побочной и главной:\n";

		for (int i = 1; i <= cols - 1; i++)
			for (int j = cols - i; j < cols - 1; ++j)
				if (i > j)
					cout << arr[i][j] << " ";
	}
	void green_area_show_element(int** arr, int cols, int a, int& max, int& imax, int& jmax)
	{
		cout << "Максимальный отрицательный: ";

		for (int i = 1; i <= cols - 1; i++)
		{
			for (int j = cols - i; j < cols - 1; ++j)
			{
				if (i > j)
				{
					if (arr[i][j] < 0)
					{
						if (arr[i][j] > max)
						{

							max = arr[i][j];
							imax = i;
							jmax = j;
						}
					}
				}
			}
		}
		if (max < 0 && max != a) {
			cout << max << "\n";; //Вывод максимального отрицательного

		}
		else {
			cout << "Отрицательных нету\n";

		}
		system("pause");
	}
	void modification(int** arr, int cols, int a, int max, int min, int jmax, int imax, int imin, int jmin, int rows)
	{
		if (max < 0 && max != a && min > 0 && min != INT_MAX) {
			cout << "Новая матрица: \n";
			int extra;
			extra = arr[imin][jmin];
			arr[imin][jmin] = arr[imax][jmax];
			arr[imax][jmax] = extra;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << arr[i][j] << "\t";

