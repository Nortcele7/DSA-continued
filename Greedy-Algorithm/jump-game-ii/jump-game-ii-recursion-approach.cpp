#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int f(int idx, int jump, vector<int>& arr)
{

    int n = arr.size();

    if(idx>=n-1)
    {
        return jump;
    }

    int min_val = INT_MAX;

    for(int i=1; i<=arr[idx]; i++)
    {
        min_val = min(min_val, f(idx+i, jump + 1, arr));
    }

    return min_val;




}

int main()
{

    vector<int> arr = {2,3,1,1,4};

    cout<<f(0,0, arr);

}