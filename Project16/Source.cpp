#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>
	using::std::cout;
using::std::cin;
namespace shooters_task
{
	void results(int** n, int* n1, int a, int b)
	{
		int s;
		for (int i = 0; i < a; i++)
		{
			s = 0;
			for (int j = 0; j < b; j++)
				s += n[i][j];
			n1[i] = s;
		}
		cout << "\nResults: ";
		for (int i = 0; i < a; i++)
			cout << n1[i] << " ";
	}
	void winners(int* n, int a)
	{
		int max, maxI;
		max = n[0];
		for (int i = 0; i < a; i++)
		{
			if (n[i] > max)
				max = n[i];
		}
		cout << "\n" << max << "\nWINNERS:\n";
		for (int i = 0; i < a; i++)
		{
			if (n[i] == max)
			{
				cout << "Shooter number " << i + 1 << std::endl;
			}
		}

	}
}
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
			cout << std::endl;
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
		cout << std::endl;
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

				}
				cout << std::endl;
			}
		}
		else if (max >= 0 || max == a)
		{
			cout << "Нету отрицательных значений для реализации";
		}
		else if (min <= 0 || min == INT_MAX)
		{
			cout << "Нету положительных значений для реализации";
		}
		else
		{
			cout << "Нету как отрицательных, так и положительных значений";
		}
	}
	void show_test_variables()
	{
		cout << "\n\t\t\t\t\tТестовые значения:\n"
			<< "\t\t\t\t\t\ a = -40, b = 40, rows = 4\n"
			<< "\t\t\t\t\t\ a = -40, b = 20, rows = 4\n"
			<< "\t\t\t\t\t\ a = -40, b = 20, rows = 5\n";
	}
}
namespace menu
{
	void all_menu()
	{
		cout << "1. Задания варианта (Вариант 2)\n"
			<< "2. Состязания по стрельбе\n"
			<< "3. Метод Гаусса\n"
			<< "4. Игра - жизнь\n"
			<< "0 - Выход\n"
			<< ">>> ";
	}
	void variant_menu()
	{
		cout << "Вариант 2\n"
			<< "1. Первое задание\n"
			<< "2. Второе задание\n"
			<< "0 - Выход\n"
			<< ">>> ";
	}
	void shooters_menu()
	{
		cout << "\t!Приветствую в состязании!\n";
		cout << "Есть только два выбора:\n";
		cout << std::endl;
		cout << "1 - Рандомное заполнение\n";
		cout << "2 - Заполнение вручную\n";
		cout << "0 - Выход\n";

	}
	void gl_menu()
	{
		cout << "\t!Приветствую в игра-жизнь!\n";
		cout << "Есть только два выбора:\n";
		cout << std::endl;
		cout << "1 - Рандомное заполнение\n";
		cout << "2 - Заполнение вручную\n";
		cout << "0 - Выход\n";

	}
}
namespace second_task
{
	void input_size(int& n, int& m)
	{
		cout << "Введите m:\n"; cin >> m;
		cout << "Введите n:\n"; cin >> n;
		cout << std::endl;
	}
	void arr_decl(int** arr_A, int** arr_C, int** t_arr_A, int* vec_B, int* vec_D, int m, int n)
	{
		//arr_A
		for (int i = 0; i < m; i++)
		{
			arr_A[i] = new int[n];
		}
		//arr_C
		for (int i = 0; i < n; i++)
		{
			arr_C[i] = new int[n];
		}
		//new_arr_A
		for (int i = 0; i < m; i++)
		{
			t_arr_A[i] = new int[n];
		}
		//New

	}
	void input_file(int** arr_A, int** arr_C, int* vec_B, int* vec_D, int m, int n)
	{
		std::string way = "D:\\who\\r.txt";
		std::ifstream file_in;
		file_in.open(way);
		//arr_A
		cout << "A(m,n):\n\n";
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				file_in >> arr_A[i][j];
				cout << arr_A[i][j] << "\t";
			}
			cout << std::endl;
		}
		system("pause");
		cout << std::endl;
		//arr_C
		cout << "C(n,m):\n\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				file_in >> arr_C[i][j];
				cout << arr_C[i][j] << "\t";
			}
			cout << std::endl;
		}
		system("pause");
		cout << std::endl;
		//vec_B
		cout << "B(m):\n\n";
		for (int i = 0; i < m; i++)
		{
			file_in >> vec_B[i];
			cout << vec_B[i] << " ";
		}
		system("pause");
		cout << std::endl;
		//vec_D
		cout << "D(n):\n\n";
		for (int i = 0; i < n; i++)
		{
			file_in >> vec_D[i];
			cout << vec_D[i] << " ";
		}
		system("pause");
		cout << std::endl;
	}
	void transp_arr_A(int** arr_A, int** t_arr_A, int& n, int& m)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				t_arr_A[i][j] = arr_A[j][i];
		int temp = n;
		n = m;
		m = temp;
	}
	void AtxB(int** t_arr_A, int* vec_B, int* New, int n, int m)
	{
		for (int i = 0; i < n; i++)
		{
			New[i] = 0;
			for (int j = 0; j < m; j++)
			{
				New[i] += t_arr_A[i][j] * vec_B[j];
			}
		}
		cout << "Матрица A умноженная на вектор B: " << std::endl;
		for (int i = 0; i < m; i++) cout << New[i] << std::endl;
		system("pause");
	}
	void C_x_ten(int** arr_C, int n, int m)
	{
		cout << "Умножение Cx10:\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr_C[i][j] = arr_C[i][j] * 10;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%5d ", arr_C[i][j]);
			}
			cout << std::endl;
		}
		cout << std::endl;
		system("pause");
	}
	void CxD(int** arr_C, int* vec_D, int* New_1, int n, int m)
	{
		for (int i = 0; i < n; i++)
		{
			New_1[i] = 0;
			for (int j = 0; j < m; j++)
			{
				New_1[i] += arr_C[i][j] * vec_D[j];
			}
		}
		cout << "Матрица Cx10 умноженная на вектор D: " << std::endl;
		for (int i = 0; i < m; i++) cout << New_1[i] << std::endl;
		system("pause");
	}
	void subtraction(int* New, int* New_1, int m)
	{
		for (int i = 0; i < m; i++)
		{
			New[i] = New[i] - New_1[i];
		}
		cout << std::endl;
		cout << "Разница:\n";
		for (int i = 0; i < m; i++) cout << New[i] << std::endl;
		cout << std::endl;
	}
}
namespace game_life_task
{
	void fieldView(int** a, int n, int m) //вывод поля
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1)
					cout << '*';
				else
					cout << ' ';
				cout << ' ';
			}
			cout << std::endl;
		}
	}

	int livingPoints(int** a, int n, int m) //счет живых точек
	{
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1)
					count++;
		return count;
	}

	void neighborhood(int nb[][2], int x, int y) //координаты соседей точки
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

	int amountLivingNB(int** a, int n, int m, int x, int y) //кол-во живых соседей у клетки[x][y]
	{
		int count = 0;
		int nb[8][2];
		int x_, y_;
		neighborhood(nb, x, y);
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

	void NextGen(int** a, int** a1, int n, int m) //следующее поколение точек
	{
		int livingNB, p;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				p = a1[i][j];
				livingNB = amountLivingNB(a1, n, m, i, j);
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

	void CopyCopy(int** a, int** a1, int n, int m) //копирование прошлого поля
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a1[i][j] = a[i][j];
	}
	int FieldsCompare(int** a, int** a1, int n, int m) //сравнение полей
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a != a1)
					return -1;
		return 0;
	}
}
namespace gauss_task
{
	void sys_cin(float** arr, float* y, int length)
	{
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = new float[length];
			for (size_t j = 0; j < length; j++)
			{
				cout << "arr[" << i << "][" << j << "]= ";
				cin >> arr[i][j];
			}
		}
		for (size_t i = 0; i < length; i++)
		{
			cout << "y[" << i << "]=";
			cin >> y[i];

		}
	}
	void sys_out(float** arr, float* y, int length)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				cout << arr[i][j] << "*x" << j;
				if (j < length - 1)
					cout << " + ";
			}
			cout << " = " << y[i] << std::endl;
		}
		return;
	}
	float* gausses_method(float** arr, float* y, int length)
	{
		float* x, max;
		int k, index;
		const float eps = 0.00001;  // точность
		x = new float[length];
		k = 0;
		while (k < length)
		{
			max = abs(arr[k][k]);
			index = k;
			for (int i = k + 1; i < length; i++)
			{
				if (abs(arr[i][k]) > max)
				{
					max = abs(arr[i][k]);
					index = i;
				}
			}
			// Перестановка строк
			if (max < eps)
			{
				// нет ненулевых диагональных элементов
				cout << "Решение получить невозможно из-за нулевого столбца ";
				cout << index << " матрицы A" << std::endl;
				return 0;
			}
			for (int j = 0; j < length; j++)
			{
				float temp = arr[k][j];
				arr[k][j] = arr[index][j];
				arr[index][j] = temp;
			}
			float temp = y[k];
			y[k] = y[index];
			y[index] = temp;

			for (int i = k; i < length; i++)
			{
				float temp = arr[i][k];
				if (abs(temp) < eps) continue;
				for (int j = 0; j < length; j++)
					arr[i][j] = arr[i][j] / temp;
				y[i] = y[i] / temp;
				if (i == k)  continue;
				for (int j = 0; j < length; j++)
					arr[i][j] = arr[i][j] - arr[k][j];
				y[i] = y[i] - y[k];
			}
			k++;
		}

		for (k = length - 1; k >= 0; k--)
		{
			x[k] = y[k];
			for (int i = 0; i < k; i++)
				y[i] = y[i] - arr[i][k] * x[k];
		}
		return x;
	}


}
int main()
{
	setlocale(LC_ALL, "");
	menu::all_menu();
	int main_num;
	cin >> main_num;
	switch (main_num)
	{
	case 1:
	{
		int var_num;
		menu::variant_menu();
		cin >> var_num;

		switch (var_num)
		{

		case 1:
		{
			int rows, cols, a, b;
			first_task::show_test_variables();
			first_task::enter_values(rows, cols, a, b);
			int** arr = new int* [rows];
			int max = a;
			int imax = 0, jmax = 0;
			int imin = 0, jmin = 0;
			int min = INT_MAX;
			first_task::show_arr(arr, rows, cols);
			first_task::fill_arr(arr, rows, cols, a, b);
			first_task::red_area_analyze(arr, rows);
			first_task::red_area_show_element(arr, rows, min, imin, jmin);
			first_task::green_area_analyze(arr, cols);
			first_task::green_area_show_element(arr, cols, a, max, imax, jmax);
			first_task::modification(arr, cols, a, max, min, jmax, imax, imin, jmin, rows);
			delete[] arr;
			break;
		}
		case 2:
		{
			int m, n, num;//2v
			second_task::input_size(n, m);
			int** arr_A = new int* [m];//2v
			int** arr_C = new int* [n];//2v
			int* vec_B = new int[m];//2v
			int* vec_D = new int[m];//2v
			int** t_arr_A = new int* [m];//2v
			int* New = new int[m];//2v
			int* New_1 = new int[m];//2v
			second_task::arr_decl(arr_A, arr_C, t_arr_A, vec_B, vec_D, m, n);
			second_task::input_file(arr_A, arr_C, vec_B, vec_D, m, n);
			second_task::transp_arr_A(arr_A, t_arr_A, n, m);
			second_task::AtxB(t_arr_A, vec_B, New, n, m);
			second_task::C_x_ten(arr_C, n, m);
			second_task::CxD(arr_C, vec_D, New_1, n, m);
			second_task::subtraction(New, New_1, m);
		}
		default:
			break;
		}
		break;
	}
	case 2:
	{
		menu::shooters_menu();
		int n, m = 1;
		int sh_num;
		cin >> sh_num;
		switch (sh_num)
		{
		case 1:
		{
			n = rand() % 31;
			m = rand() % 11;
			break;
		}
		case 2:
		{
			cout << "Enter n and m\n";
			cin >> n;
			cin >> m;
			break;
		}
		default:
			break;
		}
		srand(time(NULL));
		while (n == 0 || m == 0 || n == 1 || m == 1);
		cout << "number of shooters:" << n << "\nnumber of shots:" << m << "\n";
		int** a;
		a = new int* [n];
		for (int i = 0; i < n; i++)
			a[i] = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = rand() % 11;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%5d", a[i][j]);
			}
			cout << std::endl;
		}
		int* res;
		res = new int[n];
		shooters_task::results(a, res, n, m);
		shooters_task::winners(res, n);
	}
	case 3:
	{
		/*
		Тестовые данные просто для проверки работоспособности:
			3
			2
			4
			1
			5
			2
			1
			2
			3
			4
			36
			47
			37
		Вставлять поочерёдно ну ты поняла ок
		*/

		float** arr, * y, * x;
		int length;
		cout << "Введите количество уравнений: ";
		cin >> length;
		arr = new float* [length];
		y = new float[length];
		gauss_task::sys_cin(arr, y, length);
		gauss_task::sys_out(arr, y, length);
		//ineedmoreammo!!11!
		x = gauss_task::gausses_method(arr, y, length);
		for (int i = 0; i < length; i++)
			cout << "x[" << i << "]=" << x[i] << std::endl;
		return 0;

		break;
	}
	case 4:
	{
		menu::gl_menu();
		int n, m, gl_num;
		cin >> gl_num;
		switch (gl_num)
		{
		case 1:
		{
			n = rand() % 21;
			m = rand() % 21;
			break;
		}
		case 2:
		{
			cout << "Введите n и m";
			cin >> n;
			cin >> m;
		}
		default:
			break;
		}
		while (n < 4 || m < 4);
		cout << "\nРазмерность Вселенной: " << n << " Строки и " << m << " колонки\n";
		int** field; //задаем поле (многомерный массив)
		field = new int* [n];
		for (int i = 0; i < n; i++)
			field[i] = new int[m];
		std::random_device rd; //заполнение случайно точками
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
		int** PreviousField; //задаем поле для запоминания предыдущего поколения
		PreviousField = new int* [n];
		for (int i = 0; i < n; i++)
			PreviousField[i] = new int[m];
		int livingpoints = -1;
		bool Edem = false;
		do
		{
			game_life_task::fieldView(field, n, m);                                   //показ поля
			game_life_task::CopyCopy(field, PreviousField, n, m);                     //копируем поле
			game_life_task::NextGen(field, PreviousField, n, m);                      //генерируем новое
			Edem = game_life_task::FieldsCompare(field, PreviousField, n, m) == 0;    //сравниваем поля
			livingpoints = game_life_task::livingPoints(field, n, m);                 //проверяем количество живых клеток
			if (Edem)
				cout << "Эдемов сад\n";                              //Эдемов сад
			if (livingpoints == 0)
				cout << "ВЫ МЕРТВЫ\n";                                 //все cдохли. конец.
			Sleep(2000); //прерывание цикла, чтобы пользователь успел увидеть поле
		} while (livingpoints != 0 || !Edem);
		return 0;
	}
	default:
		break;
	}

	return 0;
}
