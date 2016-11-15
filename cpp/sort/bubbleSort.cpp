#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;

void bubbleSort(vector<int>&, int);

int main(){
    srand(time(NULL));
    vector<int> unsortedData(100);
    generate(unsortedData.begin(), unsortedData.end(), rand);

    bubbleSort(unsortedData, unsortedData.size());

    for(vector<int>::iterator iter = unsortedData.begin(); iter != unsortedData.end(); ++iter) {
        cout << *iter << endl;
    }

    return 0;
}

void bubbleSort(vector<int>& data, int size)
{
    bool bSwapped = true;
    int j, tmp = 0;

    while (bSwapped) {
        bSwapped = false;
        j++;
        for (int i = 0; i < size - j; i++) {
            if (data[i] > data[i + 1]) {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                bSwapped = true;
            }
        }
    }
}



