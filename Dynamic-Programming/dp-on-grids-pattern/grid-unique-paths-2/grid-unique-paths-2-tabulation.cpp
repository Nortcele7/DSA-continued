#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(obstacleGrid[i][j]==1)
            {
                curr[j] = 0;
            }
            else
            {
                if(i==0 && j==0)
                {
                    curr[j] = 1;
                }
                else
                {
                    int left=0, up=0;

                    if(j>0)
                    {
                        left = curr[j-1];
                    }
                    if(i>0)
                    {
                        up = prev[j];
                    }
                    curr[j] = left+up;
                }
            }
        }
        prev=curr;
    }

    cout<<prev[n-1];


}