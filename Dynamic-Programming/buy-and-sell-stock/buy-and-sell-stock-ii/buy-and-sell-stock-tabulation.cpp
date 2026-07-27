#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int n = prices.size();

    vector<vector<int>> dp (n+1, vector<int>(2, -1));

    for(int j=0; j<2; j++)
    {
        dp[n][j] = 0;
    }

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<2; j++)
        {
            if(j==1)
            {
                dp[i][j] = max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);
            }
            else
            {
                dp[i][j] = max(prices[i]+dp[i+1][1], 0+dp[i+1][0]);
            }
        }
    }

    cout<<dp[0][1];
}