#include<iostream>
#include<vector>

using namespace std;

int f(int index, int N, vector<int>& price, vector<vector<int>>& dp)
{
    if(index==0)
    {
        return N*price[index];
    }

    if(dp[index][N]!=-1)
    {
        return dp[index][N];
    }

    else
    {

        int not_take = f(index-1, N, price, dp);

        int take = 0;

        if(N>=(index+1))
        {
            take = price[index] + f(index, N-(index+1), price, dp);
        }

        return dp[index][N] = max(take, not_take);

    }

}

int main()
{

    vector<int> price = {2,5,7,8,10};

    int n = price.size();

    vector<vector<int>>dp(n, vector<int>(n+1, -1));

    cout<<f(n-1, n, price, dp);



}