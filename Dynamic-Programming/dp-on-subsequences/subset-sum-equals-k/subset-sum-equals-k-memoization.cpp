#include<iostream>
#include<vector>
using namespace std;

bool subset(int index, int target, vector<int>& arr, vector<vector<int>>& dp)
{
    if(target==0)
    {
        return true;
    }

    if(index==0)
    {
        return arr[index]==target;
    }

    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }

    else
    {
        bool not_take = subset(index-1, target, arr, dp);

        bool take = false;

        if(target>=arr[index])
        {
            take = subset(index-1, target-arr[index], arr, dp);
        }

        return dp[index][target] = take||not_take;
    }

}

int main()
{

    vector<int> arr = {2,3,1,1};

    int n=arr.size();

    int target = 4;

    vector<vector<int>> dp (n, vector<int>(target+1, -1));

    cout<<subset(n-1, target, arr, dp);

}