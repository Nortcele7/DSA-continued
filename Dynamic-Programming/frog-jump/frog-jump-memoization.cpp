#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int frogJump(int idx, vector<int> arr, vector<int>& dp)
{
  
    if(idx==0)
    {
        return dp[idx]=0;
    }

    int jump1, jump2=INT_MAX;

    if(dp[idx]!=-1)
    {
        return dp[idx];
    }

    else
    {
        
        jump1 = frogJump(idx-1, arr, dp) + abs(arr[idx]-arr[idx-1]);

        if(idx>1)
        {
            jump2 = frogJump(idx-2, arr, dp)+abs(arr[idx]-arr[idx-2]);
        }

        return dp[idx] = min(jump1, jump2);

    }

}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};

    int idx = arr.size()-1;

    vector<int> dp(idx+1, -1);

    cout<< frogJump(idx, arr, dp);
    
    

}