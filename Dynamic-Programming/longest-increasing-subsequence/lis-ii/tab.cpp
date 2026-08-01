#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> arr = {4,2,1,4,3,4,5,8,15};
    int k = 3;

    int n = arr.size();

    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    int len;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=i-1; j>=-1; j--)
        {
            len = 0 + dp[i+1][j+1];

            if(j==-1 || arr[i]>arr[j] && arr[i]-arr[j]<=k)
            {
                len = max(len, 1+dp[i+1][i+1]);
            }

            dp[i][j+1] = len;
        }
    }

    cout<<dp[0][0];



}