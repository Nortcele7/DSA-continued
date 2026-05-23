#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int frogJump(int n, vector<int> arr, int k, vector<int>& dp)
{

    if(n==0)
    {
        return dp[n]=0;
    }

    int jump1;
    int min_val = INT_MAX;

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    else
    {
        for(int i=1; i<=k; i++)
        {
                if(n-i>=0)
                {
                    jump1 = frogJump(n-i, arr, k, dp) + abs(arr[n]-arr[n-i]);
                    min_val = min(min_val, jump1);
                }
        }


        return dp[n]=min_val;
    }

}


int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};

    int n = arr.size();

    vector<int> dp(n, -1);

    cout<< frogJump(n-1, arr, 3, dp);
    
    

}