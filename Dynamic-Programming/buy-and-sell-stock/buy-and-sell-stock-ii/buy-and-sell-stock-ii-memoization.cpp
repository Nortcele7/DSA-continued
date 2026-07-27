#include<iostream>
#include<vector>
using namespace std;

int f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp)
{
    if(ind==prices.size())
    {
        return 0;
    }

    if(dp[ind][buy]!=-1)
    {
        return dp[ind][buy];
    }

    if(buy)
    {
        return dp[ind][buy] = max(-prices[ind]+f(ind+1, 0, prices, dp), 0+f(ind+1, 1, prices, dp));
    }

    else
    {
        return dp[ind][buy] = max(prices[ind]+f(ind+1, 1, prices, dp), 0+f(ind+1, 0, prices, dp));
    }


}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int n = prices.size();

    vector<vector<int>> dp (n, vector<int>(2, -1));

    cout<<f(0, 1, prices, dp);
}