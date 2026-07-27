#include<iostream>
#include<vector>
using namespace std;

int f(int index, int buy, vector<int>& prices, vector<vector<int>>& dp)
{
    int n = prices.size();

    if(index>=n)
    {
        return 0;
    }

    if(dp[index][buy]!=-1)
    {
        return dp[index][buy];
    }

    if(buy)
    {
        return dp[index][buy] = max(-prices[index]+f(index+1, 0, prices, dp), 0+f(index+1, 1, prices, dp));
    }

    else
    {
        return dp[index][buy] = max(prices[index]+f(index+2, 1, prices, dp), 0+f(index+1, 0, prices, dp));
    }

}

int main()
{
    vector<int> prices = {1,2,3,0,2};

    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));

    cout<<f(0, 1, prices, dp);
}