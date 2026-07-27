#include<iostream>
#include<vector>
using namespace std;

// Updated
int f(int index, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp)
{
    int n = prices.size();
    if(index==n)
    {
        return 0;
    }

    if(dp[index][buy]!=-1)
    {
        return dp[index][buy];
    }

    if(buy)
    {
        return dp[index][buy] = max(-prices[index]+f(index+1, 0, prices, fee, dp), 0+f(index+1, 1, prices, fee, dp));
    }

    else
    {
        return dp[index][buy] = max(prices[index]+f(index+1, 1, prices, fee, dp)-fee, 0+f(index+1, 0, prices, fee, dp));
    }

}

int main()
{
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    int n = prices.size();

    vector<vector<int>>dp(n, vector<int>(2, -1));

    cout<"This is the memoized solution";
    cout<<f(0, 1, prices, fee, dp);

}