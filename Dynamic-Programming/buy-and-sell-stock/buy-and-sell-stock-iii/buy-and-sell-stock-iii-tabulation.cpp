#include<iostream>
#include<vector>
using namespace std;

int f(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp)
{

    if(cap==0)
    {
        return 0;
    }

    if(ind==prices.size())
    {
        return 0;
    }

    if(dp[ind][buy][cap]!=-1)
    {
        return dp[ind][buy][cap];
    }

    if(buy)
    {
        return dp[ind][buy][cap] = max(-prices[ind]+f(ind+1, 0, cap, prices, dp), 0+f(ind+1, 1, cap, prices, dp));
    }

    else
    {
        return dp[ind][buy][cap] = max(prices[ind]+f(ind+1, 1, cap-1, prices, dp), 0+f(ind+1, 0, cap, prices, dp));
    }
    

}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

    for(int j=0; j<2; j++)
    {
        for(int k=0; k<3; k++)
        {
            dp[n][j][k] = 0;
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<2; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=1; k<3; k++)
            {
                if(j==1)
                {
                    dp[i][j][k] = max(-prices[i]+dp[i+1][0][k], 0+dp[i+1][1][k]);
                }
                else
                {
                    
                    dp[i][j][k] = max(prices[i]+dp[i+1][1][k-1], 0+dp[i+1][0][k]);
                }
            }
        }
    }

    cout<<dp[0][1][2];

}