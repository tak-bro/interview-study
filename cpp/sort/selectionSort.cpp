#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

#define SIZE 100

using namespace std;

void selectionSort(int arr[], int n);

int main()
{
    int array[SIZE];
    srand((unsigned)time(0)); 
    for(int i=0; i<SIZE; i++){ 
        array[i] = (rand()%10000)+1; 
    }

    selectionSort(array, 100);

    for(int i = 0; i < 100; i++){
        cout << array[i] << endl;
    }
    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, minIndex, tmp;
    for (i = 0; i < n-1; i++){
        minIndex = 1;
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex != 1){
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

