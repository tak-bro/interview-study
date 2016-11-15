#include<iostream>

using namespace std;

void getPrimes(int a[])
{
    int nCnt = 0;
    for(int i = 0 ; i< 200; i++){
        int count = 0;
        for(int j = 1; j < i/2 +1; j++){
            if(i % j == 0)
                count++;
        }
        if(count == 1)
            a[nCnt++] = i;
    }
}

int main()
{
    int *primes = new int[100];
    getPrimes(primes);
    for(int i = 0; i < 200; i++) 
        cout << primes[i] << ",";
    cout << endl;

    return 0;
}


