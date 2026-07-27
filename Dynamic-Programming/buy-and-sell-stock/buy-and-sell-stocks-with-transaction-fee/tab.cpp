#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    int n = prices.size();

    vector<vector<int>>dp(n+1, vector<int>(2, 0));

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<2; j++)
        {
            dp[i][1] = max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);

            dp[i][0] = max(prices[i]+dp[i+1][1]-fee, 0+dp[i+1][0]);
        }
    }

    cout<<dp[0][1];


}