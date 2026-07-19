#include<iostream>
#include<vector>
using namespace std;

int main()
{

    int numRows = 5;
    vector<vector<int>> arr(numRows);

    vector<vector<int>> dp(numRows, vector<int>(numRows, 0));

    dp[0][0] = 1;

    for(int i=0; i<numRows; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
 
    for(int i=2; i<numRows; i++)
    {
        for(int j=1; j<i; j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    for (int i = 0; i < numRows; i++)
    {
        arr[i].resize(i + 1);  // Resizes each row as row 0 = can hold 1 element  row 2 = can hold 2 elements

        for (int j = 0; j <= i; j++)
        {
            arr[i][j] = dp[i][j];
        }
    }

    // Print Pascal's Triangle
    for (auto &row : arr)
    {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

}