#include <iostream>
#include <fstream>
#include <string>
using::std::cout;
using::std::cin;
namespace task_2
{
	void input_size(int& n, int& m)
	{
		cout << "¬ведите m:\n"; cin >> m;
		cout << "¬ведите n:\n"; cin >> n;
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
	void AtxB
