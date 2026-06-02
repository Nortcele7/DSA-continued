#include<iostream>
#include<vector>

using namespace std;

int f(int index, int target, vector<int>& arr, vector<vector<int>>& dp)
{

    if(index==0)
    {
        if(target%arr[index]==0)
        {
            return 1;
        } 
        else
        {
            return 0;
        } 
    }

    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }

    else
    {

        int not_take = f(index-1, target, arr, dp);

        int take = 0;

        if(target>=arr[index])
        {
            take = f(index, target-arr[index], arr, dp);
        }

        return dp[index][target] = not_take + take;

}


}

int main()
{
    vector<int> arr = {1,2,3};

    int n = arr.size();

    int target = 4;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    cout<<f(n-1, target, arr, dp);



}