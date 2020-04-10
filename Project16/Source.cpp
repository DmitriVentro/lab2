
#include <iostream>
using namespace std;
void sys_cin(float** arr, float* y, int length);
void sys_out(float** arr, float* y, int length);
float* gausses_method(float** arr, float* y, int length);
/*
�������� ������ ������ ��� �������� �����������������:
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
*/
int main()
{
	setlocale(LC_ALL, "");
	float** arr, * y, * x;
	int length;
	cout << "������� ���������� ���������: ";
	cin >> length;
	arr = new float* [length];
	y = new float[length];
	sys_cin(arr, y, length);
	sys_out(arr, y, length);
	//ineedmoreammo!!11!
	x = gausses_method(arr, y, length);
	for (int i = 0; i < length; i++)
		cout << "x[" << i << "]=" << x[i] << endl;
	return 0;
}
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
		cout << " = " << y[i] << endl;
	}
	return;
}
float* gausses_method(float** arr, float* y, int length)
{
	float* x, max;
	int k, index;
	const float eps = 0.00001;  // ��������
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
		// ������������ �����
		if (max < eps)
		{
			// ��� ��������� ������������ ���������
			cout << "������� �������� ���������� ��-�� �������� ������� ";
			cout << index << " ������� A" << endl;
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

		

