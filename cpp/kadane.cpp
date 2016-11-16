#include<iostream>
#include<vector>

using namespace std;

int kadane(vector<int>& data)
{
  int sum_of_subarray = data[0];
  int max_end = data[0];
  int begin_temp = 0;
  int begin = 0, end = 0;
  
  for (size_t i = 1; i < data.size(); i++) {
    if (max_end < 0) {  // reset beginning of subarray
      max_end = data[i];
      begin_temp = i;
    } else {
      max_end += data[i];
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
  vector<int> data(9);
  data.push_back(-2);
  data.push_back(1);
  data.push_back(-3);
  data.push_back(4);
  data.push_back(-1);
  data.push_back(2);
  data.push_back(1);
  data.push_back(-5);
  data.push_back(4);
  cout << "resut = " << kadane(data) << endl;

  return 0;
}
