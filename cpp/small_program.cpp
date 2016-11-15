#include<iostream>
#include<string>

using namespace std;

int strlen1(const char *s)
{
    int n = 0;
    while(*s++)
        n++;

    return n;
}

int strlen2(const char *s)
{
    int n = 0;
    while(s[n])
        n++;
    return n;
}

char* strcpy1(char s1[], const char s2[])
{
    for(int i = 0; i <= strlen(s2); i++)
    {
        s1[i] = s2[i];
    }
    return s1;
}

char* strcpy2(char *s1[], const char s2[])
{
    int i = 0, j = 0 ;
    while(s1[i++] = s2[j++]);
    return s1;
}

char *strdup(const char *s)
{
    char *p = malloc(strlen(s) + 1);
    if( p != NULL )
        strcpy(p, s);

    return p;
}

void *memcpy(void *destination, const void *source, size_t sz)
{
    char *dest = (char*)destination;
    char const *src = (char *)source;

    while(sz--)
        *dest++ = *src++;

    return destination;
}

int str2int(const string &str)
{
    int n = 0;
    int len = str.length();
    for( int i = 0 ; i < len; i++){
        n *= 10;
        n += str[i] - '0';
    }
    return n;
}

string int2str(int numb)
{
    int i = 0;
    int end = 10;
    char *temp = new char[end];

    for (i=0; numb > 0; i++) {
        temp[i] = (numb % 10) + '0';
        numb /= 10;
    }

    int len = i;
    int ii = 0;
    string s = new char[len];
    while(i > 0)
        s[i++] = temp[--i];
    s.erase(len);
    delete temp;

    return s;
}

double atof(char s[])
{
    double d = 0, power = 1;
    int sign = 1;
    int i = 0;

    if(s[i] == '-')
        sign = -1;
    i++;
    while(s[i]){
        if(s[i] == '.')
            break;
        d = d * 10 + (s[i] - '0');
        i++;
    }
    i++;

    power = 0.1;
    while(s[i]){
        d += (s[i] - '0') * power;
        power /= 10.0;
        i++;
    }

    return d*sign;
}


int reverse_int(int n)
{
    int m = 0;
    while( n >= 1) {
        m *= 10;
        m += n%10;
        n = n / 10;
    }
    return m;
}
















