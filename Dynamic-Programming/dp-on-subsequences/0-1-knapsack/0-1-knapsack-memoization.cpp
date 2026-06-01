#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(int index, int wt, vector<int>& weight, vector<int>& val, vector<vector<int>>& dp)
{

    // Base Case

    if(index==0)
    {
        if(wt>=weight[index])
        {
            return val[index];
        }

        else
        {
            return 0;
        }
    }

    if(dp[index][wt]!=-1)
    {
        return dp[index][wt];
    }

    else
    {
        int not_take = f(index-1, wt, weight, val, dp);

        int take = INT_MIN;

        if(wt>=weight[index])
        {
            take = val[index]+f(index-1, wt-weight[index], weight, val, dp);
        }

        return dp[index][wt] = max(not_take, take);

    }


}

int main()
{

    vector<int> weight = {3,2,4};
    vector<int> val = {30, 40, 60};

    int n = weight.size();

    int wt = 6;

    vector<vector<int>> dp(n, vector<int>(wt+1, -1));

    cout<<f(n-1,wt, weight, val, dp);

}
