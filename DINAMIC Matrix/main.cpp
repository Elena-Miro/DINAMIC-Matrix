#include <iostream>
using namespace std;
void printMatrix(int** matrix, size_t n, size_t m)
{
	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)



			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int maxMatrix(int** matrix, size_t n, size_t m)
{
	int max = matrix[0][0];
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)



			if (max < matrix[i][j])
				max = matrix[i][j];
	}
	return max;
}

int kolNullMatrix(int** matrix, size_t n, size_t m)
{
	int count = 0;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)

			if (matrix[i][j] == 0)
				count++;
	}

	return count;
}

void nullMinusMatrix(int** matrix, size_t n, size_t m)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
			if (matrix[i][j] < 0)
				matrix[i][j] = 0;
	}
}
int main()
{
	size_t n;
	cout << "Enter amount of n in matrix: ";
	cin >> n;
	size_t m;
	cout << "Enter amount of m in matrix: ";
	cin >> m;
	int** matrix = new int* [n];
	for (size_t i = 0; i < n; i++)
		matrix[i] = new int[m];

	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < m; j++)
		{
			cout << "Enter " << j << " element of " << i << " n: ";
			cin >> matrix[i][j];
		}
	printMatrix(matrix, n, m);

	cout << "Max: " << maxMatrix(matrix, n, m) << endl;

	cout << "Kol null: " << kolNullMatrix(matrix, n, m) << endl;
	nullMinusMatrix(matrix, n, m);
	printMatrix(matrix, n, m);
	for (size_t i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
	return 0;
}