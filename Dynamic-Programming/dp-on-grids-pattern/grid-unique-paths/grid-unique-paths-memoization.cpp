#include<iostream>
#include<vector>
using namespace std;

int gridUniquePaths(int i, int j, vector<vector<int>>& dp)
{

    if(i==0 && j==0)
    {
        return 1;
    }

    if(i<0 || j<0)
    {
        return 0;
    }

    // If there is already a value in dp then we use that value instead of recalculating
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    else{

        int left = gridUniquePaths(i, j-1, dp);
        int up = gridUniquePaths(i-1, j, dp);

        return dp[i][j] = left+up;

        // We will store the newly computed value which can be used later

    }

}

int main()
{
    int m=3, n=7;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    cout<<gridUniquePaths(m-1, n-1, dp);



}