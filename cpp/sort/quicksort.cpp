#include<iostream>
using namespace std;

void quickSortWrapper(int[], int);
void quickSort(int[], int, int);

void quickSortWrapper(int arr[], int nSize)
{
	quickSort(arr, 0, nSize-1);
}

void quickSort(int arr[], int left, int right) 
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main()
{
	int test[] = { 0, 23, 3432, 234234, 2, 123, 34232,4324,324,324,32432};
	int length = end(test) - begin(test);
	quickSortWrapper(test, length);

	for(int i = 0; i < length; i++)
		cout << test[i] << ' ';

	cout <<endl;
	return 0;
}
