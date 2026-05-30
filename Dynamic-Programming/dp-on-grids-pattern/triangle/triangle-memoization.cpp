#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int triangle(int i, int j, vector<vector<int>> arr, vector<vector<int>>& dp)
{

    if(i==0 && j==0)
    {
        return arr[i][j];
    }

    if(i<0 || j<0 || j>i)
    {
        return INT_MAX;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    else
    {

        int up = triangle(i-1, j, arr, dp);
        int diagonal = triangle(i-1, j-1, arr, dp);

        if(up!=INT_MAX)
        {
            up+=arr[i][j];
        }

        if(diagonal!=INT_MAX)
        {
            diagonal+=arr[i][j];
        }

        return dp[i][j] = min(up, diagonal);

    }

    

}

int main()
{
    vector<vector<int>> arr = {{2},{3,4},{6,5,7},{4,1,8,3}};

    int n = arr.size();

    vector<vector<int>> dp(n);

    for(int i=0; i<n; i++)
    {
        dp[i] = vector<int>(i+1, -1);
    }

    int min_val = INT_MAX;

    for(int j=n-1; j>=0; j--)
    {
        int path = triangle(n-1, j, arr, dp);
        min_val = min(min_val, path);
    }

    cout<<min_val;


}