#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};

    int n = arr.size()-1;

    vector<int> dp(n+1, -1);

    int k = 3;

    dp[0] = 0;

    // dp[1] = abs(arr[1]-arr[0]);

    int min_val, jump;

    for(int i=1; i<=n; i++)
    {
        min_val = INT_MAX;

        for(int j=1; j<=k; j++)
        {
            if(i-j>=0)
            {
                jump = dp[i-j] + abs(arr[i]-arr[i-j]);
                min_val = min(min_val, jump); 
            }
        }

        dp[i] = min_val;

    }

    cout<<dp[n];
    

}