#include<iostream>
#include<vector>
using namespace std;

int houseRobber(int idx, vector<int> arr, vector<int>& dp)
{

    if(idx==0)
    {
        return dp[idx] = arr[0];
    }

    if(idx<0)
    {
        return 0;
    }

    if(dp[idx]!=-1)
    {
        return dp[idx];
    }

    else
    {
        int pick = arr[idx] + houseRobber(idx-2, arr, dp);
        int not_pick = 0 + houseRobber(idx-1, arr, dp);

        return dp[idx] = max(pick, not_pick);
    }

}

int main()
{
    vector<int> arr = {1,2,3,1};

    int n = arr.size();

    vector<int> dp(n,-1);

    cout<< houseRobber(n-1, arr, dp);
    

}