#include<iostream>
#include<vector>
using namespace std;

int pascalsTriangle(int i, int j, vector<vector<int>>& dp)
{
    if(j==0)
    {
        return 1;
    }
    if(j==i)
    {
        return 1;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    return dp[i][j] = pascalsTriangle(i-1, j-1, dp)+pascalsTriangle(i-1, j, dp);
}

int main()
{

    int numRows = 5;
    vector<vector<int>> arr(numRows);

    vector<vector<int>> dp(numRows, vector<int>(numRows, -1));

    for(int i=0; i<numRows; i++){
        for(int j=0; j<=i; j++)
        {
            arr[i].push_back(pascalsTriangle(i, j, dp));
        }
    }

    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<=i; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}