#include<iostream>

using namespace std;

int fact(int n);
int temp[100] = { 0 };

int main()
{
	int factorial;
	factorial = fact(5);
	cout << "Factorial is "<< factorial << endl;

	return 0;
}

int fact(int num)
{
	if (num == 0 || num == 1){
		return 1;
	} else {
		if (temp[num] != 0)
			return temp[num];
		else
			return temp[num] = (num * fact(num - 1));
	}
}

