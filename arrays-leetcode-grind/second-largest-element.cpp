#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main()
{
    vector<int> arr = {1,2,9,5,3};

    int n = arr.size();

    int max_val = INT_MIN;

    for(int i=0; i<n; i++)
    {
        max_val = max(max_val, arr[i]);
    }

    int sec_largest = INT_MIN;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<max_val)
        {
            sec_largest = max(sec_largest, arr[i]);
        }
    }

    cout<<sec_largest;


}