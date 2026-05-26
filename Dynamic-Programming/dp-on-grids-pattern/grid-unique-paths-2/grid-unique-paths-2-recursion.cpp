#include<iostream>
#include<vector>
using namespace std;

int uniquePaths2(int i, int j, vector<vector<int>>& obstacleGrid)
{

    if(i<0 || j<0)
    {
        return 0;
    }

    if(obstacleGrid[i][j]==1)
    {
        return 0;
    }

    if(i==0 && j==0)
    {
        return 1;
    }

    int left = uniquePaths2(i, j-1, obstacleGrid);
    int up = uniquePaths2(i-1, j, obstacleGrid);
    return left+up;

}

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    cout<<uniquePaths2(2,2, obstacleGrid);


}