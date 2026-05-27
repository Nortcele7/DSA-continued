#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximumFallingPathSum(int i, int j, vector<vector<int>> arr, vector<vector<int>>& dp)
{

    if(i<0 || j<0 || j>=arr[0].size())
    {
        return INT_MIN;
    }

    
    if(i==0)
    {
        return arr[i][j];
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    else
    {

        int up = maximumFallingPathSum(i-1, j, arr, dp);
        int leftd = maximumFallingPathSum(i-1, j-1, arr, dp);
        int rightd = maximumFallingPathSum(i-1, j+1, arr, dp);

        if(up!=INT_MIN)
        {
            up+=arr[i][j];
        }

        if(leftd!=INT_MIN)
        {
            leftd+=arr[i][j];
        }

        if(rightd!=INT_MIN)
        {
            rightd+=arr[i][j];
        }

        return dp[i][j]=max(up, max(leftd, rightd));

    }



}

int main()
{

    vector<vector<int>> arr = {{2,1,3}, {6,5,4}, {7,8,9}};

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int max_val = INT_MIN;


    for(int j=m-1; j>=0; j--)
    {
        max_val = max(max_val, maximumFallingPathSum(n-1, j, arr, dp));
    }

    cout<<max_val;

}