#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

void quicSortWrapper(vector<int>&, int n);
void quicSort(vector<int>&, int left, int right);

int main()
{
	srand((unsigned int)time(NULL));
	vector<int> unsortdata(100);
	generate(unsortdata.begin(), unsortdata.end(), rand);

	quicSortWrapper(unsortdata, unsortdata.size());

	for(int i = 0; i < unsortdata.size(); i++)
		cout << unsortdata[i] << endl;

	return 0;
}

void quicSortWrapper(vector<int>& data, int n)
{
	quicSort(data, 0, n-1);
}

void quicSort(vector<int>& data, int left, int right)
{
	int i = left, j = right;
	int tmp = 0;
	int pivotInx = (left + right) / 2;
	int pivot = data[pivotInx];

	while (i <= j){
		while (data[i] > pivot)
			i++;
		while (data[j] < pivot)
			j--;

		if (i <= j){
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quicSort(data, left, j);
	if (i < right)
		quicSort(data, i, right);
}
