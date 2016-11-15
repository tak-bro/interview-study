#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n-1);
}

int factorial_iter(int n);
{
    int fact = 1;
    for(int i = n; i > 1; i--){
        fact *= i;
    }
    return fact;
}

int f[100] = { 0 };
int factorial_dynamic(int n)
{
    if(f[n])
        return f[n];

    if(n==0 || n==1){
        f[n] = 1;
        return f[n];
    }

    f[n] = n * factorial(n-1);
    return f[n];
}

int n_to_the_kth_power(int n, int k)
{
    if(k==0)
        return 1;
    else
        return n * n_to_the_kth_power(n, k-1);
}

int fibo(int n)
{
    if(n == 0 || n == 1)
        return n;
    return fibo(n-1) + fibo(n-2);
}

int fibo(int n)
{
    if(n==0 || n == 1)
        return n;

    int f0 = 0, f1 = 1, f2;
    for(int i = 2; i <= n; i++){
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

int fibo_dynamic(int n)
{
    static int saved[100] = { 0 };
    if(saved[n] != 0)
        return saved[n];

    if(n == 0 || n == 1){
        saved[n] = n;
        return saved[n];
    }

    saved[n] = fibo_dynamic(n-1) + fibo_dynamic(n-2);
    return saved[n];
}

void tower(int a, char from, char buf, char to)
{
    if(a==1){
        cout << "Move disc 1 from " << from << " to "<< to << "\n";
        return ;
    }
    else {
        tower(a-1, from, to, buf);
        cout << "Move disc " << a << " from " << from << " to " << to << "\n" ;
        tower(a-1, buf, from, to);
    }
}
