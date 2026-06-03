#include<iostream>
#include<vector>
using namespace std;

int count(int index, int target, vector<int>& arr, vector<vector<int>>& dp)
{

    if(target==0)
    {
        return 1;
    }

    if(index==0)
    {
        return (arr[index]==target);
    }

    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }

    else
    {

        int not_pick = count(index-1, target, arr, dp);
        int pick = 0;

        if(target>=arr[index])
        {
            pick = count(index-1, target-arr[index], arr, dp);
        }

        return dp[index][target] = pick+not_pick;

    }

}

int main()
{

    vector<int> arr = {1,2,2,3};

    int n = arr.size();

    int target = 3;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    cout<<count(n-1, target, arr, dp);

}