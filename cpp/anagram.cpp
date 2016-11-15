#include<iostream>
using namespace std;

bool anagram(char s1[], char s2[])
{
	bool isNull = ( s1 == NULL || s2 == NULL);
	bool isSameLength = ( strlen(s1) != strlen(s2) );
	if( isNull || isSameLength )
		return false;

	int bit[256] = { 0 };
	int length = strlen(s1);
	for( int i = 0; i < length; i++ ){
		bit[ s1[i] ]++;
		bit[ s2[i] ]--;
	}

	for( int i = 0; i < length; i++ )
	{
		if( bit[i] != 0 )
			return false;
	}

	return true;
}

int main()
{
	char *test = "hamlet";
	char *test2 = "letham";

	if( anagram(test, test2) )
		cout << "anagram !" << endl;
	else 
		cout << "not" << endl;

	return 0;
}
