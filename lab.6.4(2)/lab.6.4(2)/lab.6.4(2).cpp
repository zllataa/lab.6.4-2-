#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}



void Print(int* a, const int size, int i)
{
	cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Min(int* a, const int size, int i, int min)
{
	if (a[i] < min )
		min = a[i];
	if (i < size - 1)
		return Min(a, size, i + 1, min);
	else
		return min;
}
int Sum(int* a, const int size, int i, int S)
{
	S += a[i];
	if (i < size - 1)
		return Sum(a, size, i + 1, S);
	else
		return S;
}


void Sort(int* a, const int size) 
{
	for (int i = 0; i < size - 1; i++)
	{
		int y = a[i];
		int iy = i;
		for (int j = i + 1; j < size; j++)
		{
			if (y == 0)
			{
				y = a[j];
				iy = j;
			}

		}
		a[iy] = a[i];
		a[i] = y;
	}
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 5;
	int a[n];
	int Low = -10;
	int High = 10;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "min = " << Min(a, n, 1, a[0]) << endl;
	cout << "S = " << Sum(a, n, 0, 0) << endl;
	Sort(a, n);
	Print(a, n, 0);
	return 0;
}

