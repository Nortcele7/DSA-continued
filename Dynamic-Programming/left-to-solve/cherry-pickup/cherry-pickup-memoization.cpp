#include<iostream>
#include<vector>
using namespace std;

int cherryPickUp(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp)
{
    if(i<0 || j<0)
    {
        return -1e8;
    }

    if(arr[i][j]==-1)
    {
        return -1e8;
    }

    if(i==0 && j==0)
    {
        return arr[i][j];
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    else
    {
        int left = arr[i][j] + cherryPickUp(i, j-1, arr, dp);
        int up = arr[i][j] + cherryPickUp(i-1, j, arr, dp);

        return dp[i][j]=max(left, up);

    }

}

int main()
{
    vector<vector<int>> arr = {{0,1,-1},{1,0,-1},{1,1,1}};

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout<<cherryPickUp(n-1, n-1, arr, dp);


}