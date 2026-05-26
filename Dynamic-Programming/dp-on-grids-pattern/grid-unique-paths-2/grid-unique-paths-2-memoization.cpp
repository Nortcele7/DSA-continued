#include<iostream>
#include<vector>
using namespace std;

int uniquePaths2(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
{

    // First check bounds
    if(i<0 || j<0)
    {
        return 0;
    }

    // Then check if the obstacle is present or not
    // If the obstacle is present then it will not be valid path so we will return 0;
    if(obstacleGrid[i][j]==1)
    {
        return 0;
    }

    // If the upper two cases passed then at (0,0) we will have our one valid path
    // So, if we reach (0,0) from (m-1, n-1) then it will be a single valid path
    if(i==0 && j==0)
    {
        return 1;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    else
    {
        int left = uniquePaths2(i, j-1, obstacleGrid, dp);
        int up = uniquePaths2(i-1, j, obstacleGrid, dp);
        return dp[i][j] = left+up;
    }

}

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));


    cout<<uniquePaths2(2,2, obstacleGrid, dp);


}