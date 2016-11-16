#include<iostream>
#include<vector>

using namespace std;

int kadane(vector<int>& data)
{
  int sum_of_subarray = data[0];
  int max_end = v[0];
  int begin_temp = 0;
  int begin = 0, end = 0;
  
  for (size_t i = 1; i < data.size(); i++) {
    if (max_end < 0) {  // reset beginning of subarray
      max_end = data[i];
      begin_temp = i;
    } else {
      max_end += v[i];
    }
    
    if (max_end >= sum_of_subarray) {
      sum_of_subarray = max_end;
      begin = begin_temp;
      end = i;
    }
  }  
  return sum_of_subarray;
}

int main()
{
  vector<int> data = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  cout << "resut = " << kadane(data) << endl;

  return 0;
}
