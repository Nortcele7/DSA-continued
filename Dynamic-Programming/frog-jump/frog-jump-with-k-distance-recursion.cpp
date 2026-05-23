#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int frogJump(int idx, vector<int> arr, int k)
{
    if(idx==0)
    {
        return 0;
    }

    int min_val = INT_MAX;

    for(int i=1; i<=k; i++)
    {
        if(idx-i>=0)
        {
            int jump1 = frogJump(idx-i, arr, k)+abs(arr[idx]-arr[idx-i]);
            min_val = min(min_val, jump1);
        }
    }

    return min_val;


}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};

    cout<< frogJump(5, arr, 3);
    
    

}