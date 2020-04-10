#include <iostream>
#include <fstream>
#include <string>
using::std::cout;
using::std::cin;
namespace task_2
{
	void input_size(int& n, int& m)
	{
		cout << "Введите m:\n"; cin >> m;
		cout << "Введите n:\n"; cin >> n;
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
		cout << std::endl;
		//vec_B
		cout << "B(m):\n\n";
		for (int i = 0; i < m; i++)
		{
			file_in >> vec_B[i];
			cout << vec_B[i] << " ";
		}
		cout << std::endl;
		//vec_D
		cout << "D(m):\n\n";
		for (int i = 0; i < n; i++)
		{
			file_in >> vec_D[i];
			cout << vec_D[i] << " ";
		}
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
int main()
{
	setlocale(LC_ALL, "");
	int m, n;
	task_2::input_size(n, m);
	int** arr_A = new int* [m];
	int** arr_C = new int* [n];
	int* vec_B = new int[m];
	int* vec_D = new int[m];
	int** t_arr_A = new int* [m];
	int* New = new int[m];
	int* New_1 = new int[m];
	task_2::arr_decl(arr_A, arr_C, t_arr_A, vec_B, vec_D, m, n);
	task_2::input_file(arr_A, arr_C, vec_B, vec_D, m, n);
	task_2::transp_arr_A(arr_A, t_arr_A, n, m);
	task_2::AtxB(t_arr_A, vec_B, New, n, m);
	task_2::C_x_ten(arr_C, n, m);
	task_2::CxD(arr_C, vec_D, New_1, n, m);
	task_2::subtraction(New, New_1, m);
	return 0;
}
