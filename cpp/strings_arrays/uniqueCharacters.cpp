#include<iostream>

using namespace std;

void uniqueCharsA(char *s)
{
    int arr[256] = { 0 };
    while (*s) {
        arr[*s]++;
        if( arr[*s] > 1 ) {
            cout << *s << " is not unique" << endl;
            return ;
        }
        s++;
    }
    cout << "unique" << endl;
    return ;
}

int main()
{
    uniqueCharsA("adasdad");
    uniqueCharsA("kljadxs");
    return 0;
}


        
